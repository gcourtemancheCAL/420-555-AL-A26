# ISR

Un `ISR` (Interrupt Service Request) consiste en un bloc de code automatiquement exécuté par le processeur lorsqu'un évènement hardware survient.

Le code d'un `ISR` va interrompre (temporairement) l'exécution du reste du programme si nécessaire. Dans le cas de notre processeur Tensilica à 1 core, les ISR vont toujours interrompre le code régulier.

Un seul ISR peut s'exécuter à la fois. 

Il est donc _très_ important de s'assurer que nos ISR s'éxecute rapidement et promptement.
- Ne pas faire trop de chose dans un ISR
- Ne pas faire d'opération bloquante
- Ne pas faire des opérations qui dépendent sur le résultat d'un ISR pour se compléter

Concrètement : 
- Pas de `delay()`
- Pas de `millis()` ni de `micros()`
- Pas de I2C, ni de SPI.
- Pas de Serial
- **Pas d'accès flash**

Mais diantre! Qu'est-ce qu'un accès flash et en quoi est-ce un problème? 

Votre code est storé en mémoire flash. Pour lire le code à exécuter, le processeur à besoin de lire en flash. Donc si le code de votre ISR, et qu'un ISR ne doit pas lire en flash, votre ISR ne pourra pas être invoqué et cela peut causer une core panic.

## IRAM et DRAM

Les fonctions utilisées comme ISR doivent être placées en IRAM (Instruction RAM - un espace SRAM réservé aux instructions). 

```Arduino
void IRAM_ATTR handler() {
	//stuff
}
```

Les fonctions en IRAM vont toujours occupés un espace SRAM - les accès flash ne vont donc pas être nécessaires.

Un effet secondaire de cette pratique est que la fonction va être plus rapide (ou du moins il n'y aura pas de délais de fetch d'instruction).

**Attention :** L'espace IRAM est limité.

Les variables utilisés par votre ISR ne doivent pas être en flash non plus - nous allons donc vouloir les placer en DRAM. La DRAM est un espace SRAM réservé pour les données.

Par défaut, dans la plupart des cas, les variables globales sont automatiquement placées en DRAM.

## ISR arduino

Les librairies arduinos nous donnent accès à une quantité limité d'ISR sur les broches GPIO. Dans le cas du ESP8266, nous pouvons enregistrer des ISR sur chacun des GPIOs qui écoutent sur les évènements suivants : 
- **LOW** : invoqué continuellement tant que la broche est `LOW`. **Probablement pas ce que vous voulez et de toute façon ce n'est pas supporté par le ESP8266.**
- **CHANGE** : invoqué lorsqu'il y a changement.
- **RISING** : invoqué lorsque le signal passe à `HIGH`
- **FALLING** : invoqué lorsque le signal passe à `LOW`

**Nb.** Un seul ISR peut être enregistré par broche.

**Exemple  :**

```Arduino
#include <atomic>

int pin = 12;

// On utilise une variable atomique en remplacement d'une variable volatile
// pour eviter des optimisations facheuses.
// Le ESP8266 est tres limite en matiere d'ops atomique donc on peut uniquement
// utiliser le load et le store (helas! pas de exchange ni de CAS)
//
// On pourrait s'en tirer ici avec memory_order_relaxed mais les cas ou c'est 
// raisonable sont tellement
// rares, niches et particuliers que je prefere simplement ne pas l'illustrer.
// Simplement par bonne pratique on va utiliser acq et rel.
std::atomic<int> change_cntr {0};

void IRAM_ATTR onCHANGE(){
	int c = change_cntr.load(std::memory_order_acquire);
	change_cntr.store(c+1, std::memory_order_release);
}

void setup() {
	Serial.begin(115200);
	
	pinMode(pin, INPUT);
	attachInterrupt(digitalPinToInterrupt(pin), onCHANGE, CHANGE);
	
	Serial.println("");
	Serial.println("READY");
}

void loop() {
	if( change_cntr.load(std::memory_order_relaxed) != 0 )
	{
		// On desactive temporairement les interrupts juste pour etre certains 
		// qu'on est exact dans nos manipulations (et pour pallier 
		// au manque de exchange!).
		// Ce n'est cependant pas si critique que ca pour notre exemple.
		// Exercice pour les motives (tu sais t'es qui) : en faire une 
		// implementation RAII.
		noInterrupts();
		int v = change_cntr.load(std::memory_order_acquire);
		change_cntr.store(0, std::memory_order_release);
		interrupts();
		Serial.print("CHANGE cnt=");
		Serial.println(v, DEC);
	}
}
```

![[Pasted image 20260903142827.png]]

**Reproduisez le circuit suivant et testez votre interrupt. Que remarquez-vous?**

