
## Exercice 1

Pour cet exercice, nous allons nous faire une classe utilitaire permettant de facilement gérer le debouncing pour nos futures projets.

Dans votre sketch, commencez par inclure le fichier `FunctionalInterrupt` - il vient surcharger la méthode attachInterrupt de sorte à ce qu'on puisse lui passer une lambda en paramètre (et non juste un pointeur de fonction).

```arduino
#include <FunctionalInterrupt.h>
```

Écrivez une classe "DebouncedInput" qui respecte l'interface suivante : 

```
class DebouncedInput {
public:
	DebouncedInput(int pin, bool pullup = false, int debouncingTimerMs = 10);
	~DebouncedInput();
	
	// Retourne la valeur debouncé du GPIO. 
	bool read();
	// Retourne la valeur sans debouncing du GPIO. 
	bool readRaw();
	
	// Appelé par l'ISR pour mettre à jour l'état de la broche.
	void IRAM_ATTR tick();
	
	// Ces fonctions sont supprimées - elles ne sont donc pas à implémenter
	DebouncedInput(const DebouncedInput&) = delete;
	DebouncedInput(DebouncedInput&&) = delete;
	DebouncedInput& operator=(const DebouncedInput&) = delete;
	DebouncedInput& operator=(DebouncedInput&&) = delete;
	
private:
	// À vous de déterminez les variables à utiliser!
}
```

Dans le constructeur de votre classe, vous allez vouloir attaché un interrupt sur votre GPIO à l'aide d'une lambda : 

```arduino
attachInterrupt(digitalPinToInterrupt(pin), [this]() IRAM_ATTR { 
	this->tick();
}, mode);
```

À vous de compléter le reste :
- Choisissez le bon mode pour l'interrupt
- Assurez-vous de détacher l'interrupt dans le destructeur.
- Déterminez la logique et les variables requises pour faire fonctionner la classe.
- Testez!
	- Testez avec un bouton. 
		- Validez dans une boucle la valeur débouncé vs la valeur telle quelle.
	- Testez avec deux boutons. Vous devriez pouvoir créer plusieurs instances de votre classe sans problème.

## Exercice 2

Reprenez l'exercice <a href="2_ex_io.md#exercice-2">2_ex_io::exercice 2</a>. Cette fois-ci, utilisez votre classe de DebouncedInput. 

## Exercice 3

L'image suivante présente une tentative de circuit de debouncing : 

<img src="img/Pasted image 20260915112547.png" width="500" />

Outre le manque d'hystérésis, ce circuit n'accompli pas entièrement sa fonction. Identifions pourquoi à l'aide des mathématiques.

<img src="img/Pasted image 20260915115250.png" width="500" />

**En présumant une tension à la source de 3.3V :**
- Calculez la tension en A avant que l'on appuie sur le bouton.
- Calculez la tension en A lorsque nous appuyons sur le bouton et que le capaciteur est entièrement déchargé.
- Calculez la tension en A lorsque nous appuyons sur le bouton et que le capaciteur est entièrement chargé.
- Calculez la tension en A lorsque nous relâchons le bouton. Prenons pour acquis que le capaciteur va fournir 3.3V de tension. 

**Suivant les calculs réalisés :**
- Est-ce que le capaciteur aura un impact sur le bounce lorsque nous appuyons sur le bouton?
- Est-ce que le capaciteur aura un impact sur le bounce lorsque nous relâchons le bouton?

## Exercice 4

Nous allons créer un petit jeu de réflexe!

Matériel :
- 3 DELs vertes : Ces DELs représentent les points du joueur.
- 3 DELS rouges : Ces DELs représentent les vies du joueur.
- 1 DEL bleue : L'indicateur d'action.
- 1 bouton : Le bouton sur lequel le joueur doit appuyer.

L'objectif du jeu :
- Une lumière va s'allumer temporairement à intervalle irrégulier.
- Le joueur doit appuyer sur le bouton le plus rapidement possible après son activation.
	- Si le bouton est appuyé assez rapidement, il gagne 1 point.
	- Si le bouton est appuyé en avance OU trop en retard, il perd une vie.
- Lorsque le joueur gagne 3 points, il gagne la partie.
- Lorsque les vies du joueur tombent à 0, il perd la partie.
- Le joueur commence avec 3 vies.

Au départ : toutes les lumières clignotent quelques secondes avant de se stabiliser sur leur état de départ.

Sur victoire :
	- Éteindre toutes les lumières
	- Faire clignoter les lumières vertes pendant quelques secondes. 
	- Éteindre toutes les lumières pendant un court moment. 
	- Recommencer le jeu.
Sur défaite : la même procédure qu'en cas de victoire, mais on fait clignoter les lumières rouges à la place des vertes.

Voici un exemple de ce à quoi pourrait représenter le jeu à la fin : 

<img src="img/Pasted image 20260917104839.png" width="800" />

## Exercice 4.1

Sur KiCad, produisez le schéma de circuit à réaliser.

## Exercice 4.2

Maintenant, réalisez le sur votre platine d'essaie. Programmez votre ESP avec la logique demandée.

## Exercice 5

Ajoutons nous un nouveau composant super simple d'utilisation : le shift register!

<img src="img/Pasted image 20260915150249.png" width="800" />

Le 74HC595 nous permet de contrôller jusqu'à 8 composants différents en utilisant seulement que 3 GPIO de notre ESP. 

[!tip] En fait on peut enchaîner nos 74HC595 et contrôler encore plus de composants!

#### Les broches du 74HC595 :

- Les broches Q0 à Q7 sont des broches de sorties. Le signal sortant (`LOW` ou `HIGH`) est dynamiquement contrôlé par notre ESP. 
- `DS` est l'une des broches utilisés pour contrôler les signaux sortants. Cette broche est connectée à l'un de nos GPIO.
- `OE` va essentièlement toujours être à `LOW` dans nos cas d'utilisations. Brancher le directement au GND.
- `STCP` et `SHCP` sont des broches de clocks qui nous permettent de mettre à jour les signaux émis. Ces broches sont connectés à notre ESP.
- `CLEAR` permet de clearer l'état de nos broches de sorties. On va généralement le laisser sur `HIGH` et contrôler nos sorties programmatiquement.
- Q7S est utilisée lorsqu'on veut brancher en chaîne nos 74HC595. Il serait donc connecté directement au DS du 74HC595 suivant.

#### Branchements logiques :

<img src="img/Pasted image 20260915151959.png" width="500" />

#### Fonctionnement du shift register :

Notre shift register contient 8 registres (1 bit chaque) qu'il peut manipuler. Une fois ces registres assignés à une valeur désirés, il peut "déplacer" ces registres vers ses broches de sorties et émettre un signal spécifique en continue.

Pour ce faire, notre shift register peut obéir à deux commandes : 
- `Shift` : Chaque registre prend la valeur du registre précédent et assigne la valeur au premier registre
- `Latch` : Met à jour l'état des broches de sorties selon la valeur des registres.

Un `shift` est invoqué sur le 74HC595 lorsque la tension en SHCP (ou SRCLK) monte. La valeur en R0 devient le signal reçu en DS (ou SER). 

Un `latch` est invoqué sur le 74HC595 lorsque la tension en STCP (ou RCLK) monte. 

##### Exemple :

État inital :

| R0 | R1 | R2 | R3 | R4 | R5 | R6 | R7 |
|---| ---| --- | - | - | - |- | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |

| Q0 | Q1 | Q2 | Q3 | Q4 | Q5 | Q6 | Q7 |
|---| ---| --- | - | - | - |- | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |

On `shift(1)`

| R0 | R1 | R2 | R3 | R4 | R5 | R6 | R7 |
|---| ---| --- | - | - | - |- | - |
| 1 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |

| Q0 | Q1 | Q2 | Q3 | Q4 | Q5 | Q6 | Q7 |
|---| ---| --- | - | - | - |- | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |

On `shift(0)`

| R0 | R1 | R2 | R3 | R4 | R5 | R6 | R7 |
|---| ---| --- | - | - | - |- | - |
| 0 | 1 | 0 | 0 | 0 | 0 | 0 | 0 |

| Q0 | Q1 | Q2 | Q3 | Q4 | Q5 | Q6 | Q7 |
|---| ---| --- | - | - | - |- | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |

On `shift(1)`

| R0 | R1 | R2 | R3 | R4 | R5 | R6 | R7 |
|---| ---| --- | - | - | - |- | - |
| 1 | 0 | 1 | 0 | 0 | 0 | 0 | 0 |

| Q0 | Q1 | Q2 | Q3 | Q4 | Q5 | Q6 | Q7 |
|---| ---| --- | - | - | - |- | - |
| 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |

On `latch()`

| R0 | R1 | R2 | R3 | R4 | R5 | R6 | R7 |
|---| ---| --- | - | - | - |- | - |
| 1 | 0 | 1 | 0 | 0 | 0 | 0 | 0 |

| Q0 | Q1 | Q2 | Q3 | Q4 | Q5 | Q6 | Q7 |
|---| ---| --- | - | - | - |- | - |
| 1 | 0 | 1 | 0 | 0 | 0 | 0 | 0 |

### Exercice 5 - Pour de vrai maintenant

Nous allons faire un circuit simple dans lequel 4 DELs sont contrôlées par notre shift register.

<img src="img/Pasted image 20260915155522.png" width="800" />

**Ce que contient notre circuit :**

- Un bouton connecté à un GPIO en pullup. Pensez à le debouncé!
- Un 74HC595 contrôlé par notre ESP
- 4 DELs controlées par le 74HC595 

**Fonctionnement**

Au démarrage, la première DEL (connectée à QA sur le schéma) est allumée.

Lorsqu'on appuie sur le bouton, le ESP va `shift` le signal : 
- Après une première actuation, QA devient inactif et QB devient actif (aucune DEL allumée)
- Après une seconde actuation, QB devient inactif et QC devient actif (la seconde DEL allumée)
- ...

Une fois les 8 registres passées, nous devons recommencer du début. 

**Code**

Pour votre programme, implémentez les fonctions `latch` et `shift`. Le pseudo code vous est donné  : 

```arduino
void shift(int v) {
	DS = v;
	SHCP = HIGH;
	SHCP = LOW;
}

void latch() {
	STCP = HIGH;
	STCP = LOW;
}
```

>[!important] Vous aurez potentièlement besoin d'ajouter des délaies.

### Exercice 6

Il est commun d'utiliser des masques de bits pour contrôller l'état des registres du 74HC595. 

D'ailleurs, arduino fournit la fonction [shiftOut](https://docs.arduino.cc/language-reference/en/functions/advanced-io/shiftOut/) pour simplifier la manipulation d'un 74HC595 :
- Cette méthode prend un entier en paramètre qui représente l'état des différents registres. Prend un octet en paramètres pour la valeur des registres
- Chaque bit de l'octet est "shifté" l'un après l'autre.
- shiftOut peut opérer dans deux directions : 
	- poid fort vers poid faible
	- ou bien poid faible vers poid fort
- Il est tout de même nécessaire de "latch" le 74HC595 par la suite.

#### Lights out

Dans cette exercice, nous allons faire une implémentation du puzzle de [*lights out*](https://fr.wikipedia.org/wiki/Lights_Out_(jeu)) dans une grille 2x2.

Vous aurez besoin de 4 DELs et de 4 bouton. Placez les DELs et les boutons dans une disposition similaire à celle ci.

<img src="img/Pasted image 20260916115757.png" width="500" />

Vous pouvez reproduire quelque chose de similaire à ça sur votre platine d'essaie : 

<img src="img/Pasted image 20260916125644.png" width="500" />

Lorsque nous appuyons sur un bouton, on fait basculer l'état de la lumière correspondante ainsi que de toutes celles lui touchant.

Par exemple, une première actuation pourrait nous mettre dans cet état : 

<img src="img/Pasted image 20260916120048.png" width="500" />

Et une seconde nous amènerait dans cet état : 

<img src="img/Pasted image 20260916120142.png" width="500" />

Une partie est gagnée lorsque les 4 lumières sont allumées.  Dans quel cas on fait comme Jean-Marc Parent et on flash nos lumières quelques secondes avant de recommencer.

<img src="img/Pasted image 20260916120414.png" width="500" />

#### Schéma de circuit 

Bien que pas strictement nécessaire ici, nous allons tout de même utiliser le 74HC595 pour se pratiquer.

<img src="img/Pasted image 20260916114943.png" width="800" />

>[!warning] Les boutons sont connectés au 3.3V et le 74HC595 est connecté au 5V.

>[!information] Les boutons sont en pullup. Il est possible d'utiliser le pullup interne du ESP. Il est aussi possible d'utiliser des GPIOs différents si ça simplifie les branchements.

Voici un exemple de branchement sur platine (1 seul bouton et une seule DEL sont branchés) :

<img src="img/Pasted image 20260916131745.png" width="600" />

Utiliser 2 plaquettes pourrait faciliter la gestion des câbles. 

#### Implémentation

Voici quelques contraintes d'implémentation à respecter :
- On va garder l'état de nos lumières en tout temps dans un byte. Chaque bit va représenter l'état d'une DEL.
- Pour basculer les bits, utilisez l'opérateur binaire XOR.
	- **Cheevos** 
		- Utilisez un seul XOR par actuation d'un bouton.
		- Calculez dynamiquement le masque XOR pour chaque bouton.
- On va utiliser `shiftOut` pour mettre à jour le 74HC595.
- Faites attention au debouncing.

