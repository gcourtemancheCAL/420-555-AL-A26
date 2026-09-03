# GPIO

Définition : General Purpose Input Output

Ce sont des broches qui peuvent être utilisés pour des tâches assez générales (i.e. elles n'ont pas de rôle prédéterminé). Les signaux qui y sont gérés sont digitaux - on va donc se limiter à deux états distincts : `HIGH` et `LOW`.

Les GPIOs travaillent sur du 3.3V.

Les broches supportent 2 modes : 
- `Input` : Permet de lire l'état du signal reçu.
- `Output` : Permet d'émettre un signal souhaité.

**Exemple avec API arduino :**

```cpp
int pin {2}; // Les variables globales sont en DRAM
const int timeout_ms { 1000 }; // Les constantes sont en memoire flash.

// setup est appele une fois au demarage de l'appareil.
void setup() {
  pinMode(pin, OUTPUT);
}

// loop est appele en continu.
void loop() {
  digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(timeout_ms);              // wait for a second
  digitalWrite(pin, LOW);    // turn the LED off by making the voltage LOW
  delay(timeout_ms);               // wait for a second
}
```

[API arduino](https://docs.arduino.cc/language-reference/)

### Configuration de la console

Ici il n'y a pas d'écran mais le port RS-232 créé sur votre ordinateur permet de recevoir des sorties texte. Donc ici ajoutons un "Bonjour chef!" au démarrage de votre application. Pour y parvenir vous aurez deux choses à ajouter. 

```c
  Serial.begin(115200);
  delay(10);
```

et

```C
Serial.println("Bonjour chef!");
```

À vous de figurer le reste. Pour voir le contenu de votre port série, dans le menu outils vous pouvez utiliser `serial Monitor`. Il est important de prendre la bonne vitesse pour recevoir le texte correctement, sinon vous aurez des symboles « aléatoires ». 

