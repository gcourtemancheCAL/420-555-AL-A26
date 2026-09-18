# Exercices

## Exercice 1

À l'aide de DEL de couleur connecté à votre ESP8266, reproduisez la logique suivante : 

<img src="img/Pasted image 20260827154559.png" width="800" />

## Exercice 2

#### Exercice 2.1

Reproduisez le circuit d'exemple de PWM.

L'évolution de 'intensité de la lumière peut être représentée à l'aide d'un graphique comme celui ci : 

<img src="img/Pasted image 20260902112016.png" width="600" />

#### Exercice 2.2

Modifiez le code de façon à avoir un effet de respiration (breathing). L'intensité de la lumière devrait donc évoluer comme représenté par ce graphique : 

<img src="img/Pasted image 20260902112226.png" width="600" />

## Exercice 3

### Exercice 3.1

**Circuit :**

Le circuit suivant utilise un buzzer passif.

<img src="img/Pasted image 20260902114431.png" width="600" />

Code : 

```arduino
constexpr int gpio15 = 15;
void setup() {
	pinMode(gpio15, OUTPUT);
}  

void loop() {
	tone(gpio15, 1000, 1000);
	delay(1500);
}
```

**Question :** Avant de reproduire le circuit, décrivez ce qu'il fait.

Ensuite, reproduisez le circuit et flashez le esp avec le code fournit.

### Exercice 3.2

Reproduisez le schéma du circuit et modifiez le de sorte à pouvoir contrôller le volume à l'aide d'un potentiomètre.

Testez votre schéma sur votre platine d'essaie.

### Exercice 3.3

Reproduisez le schéma du circuit et modifiez le de sorte à ce que le tonalité joue uniquement si vous appuyez sur un bouton. 

Testez votre schéma sur votre platine d'essaie.

### Exercice 3.4

Voici un schéma des branchements recommendés provenant du manufacturier :

<img src="img/Pasted image 20260918070704.png" width="600" />

Corrigez votre circuit afin de respecter ce schéma en tenant compte des éléments suivants :
- Dans le schéma, votre ESP8266 est la source d'oscillation (connecté à la base du transistor)
- Votre potentiomètre est la résistance entre la source d'oscillation et la base du transistor.

## Exercice 4

À partir du code suivant : 

```arduino
const int sing_along_song[][2] = {
	// {frequence, duree en ms}
	{220, 364},
	{247, 364},
	{262, 364},
	{220, 182},
	{247, 364},
	{262, 364},
	{220, 182},
	{247, 364},
	{262, 364},
	{0, 1000} //pause
};
```

Vous allez devoir programmer votre esp8266 de sorte à jouer ce morceau musical en boucle. Nous voulons : 
- Un intérrupteur pour activer/désactiver le son
- Un moyen d'ajuster le volume

1. Faites le schéma sur kicad du circuit.
2. Reproduisez le circuit et programmez le.
3. Identifiez la chanson (**très important**). 

## Exercice 5 - DEL RGB

Une vieille légende Cherokee stipule que deux loups vivent en vous  : le premier est noirceur et désespoir, le deuxième est un gamer 1337 avec un setup de DEL RGB vraiment sick.

Nous allons rendre honneur à ce second loup en utilisant une DEL RGB.

<img src="img/Pasted image 20260902144527.png" width="600" />

La DEL RGB consiste éssentiellement en 3 DELs en parallèle avec une anode commune. Nous allons donc vouloir brancher l'anode à une source d'alimentation 3.3V et pour allumer les différentes couleurs nous allons vouloir connecter les différentes pattes vers le GND.

#### Exercice 5.1

Reproduisez le circuit suivant (ou un circuit similaire) en utilisant des résistances de 220Ω : 

![[Pasted image 20260902145216.png]]

**Question :** est-ce que les connexions entre les interrupteurs et le 3.3V ont un quelconque impact? En d'autres mots, peut-on les retirer?

**Question :** Pourquoi est-ce qu'il y une résistances devant 3 des 4 pattes? Pourions nous les remplacer par une seule résistance sur l'anode?

Expérimentez avec les interrupteurs et le bouton et identifiez quelle patte contrôle quelle couleur. 

#### Exercice 5.2

Ajustez votre circuit et programmez votre esp de sorte à ce votre DEL RGB change de couleur à chaque seconde dans l'ordre suivant : rouge -> vert -> bleu.

Vous allez devoir utiliser un GPIO en OUTPUT par couleur.  Lorsque le GPIO est à low, il va faire office de 'sink' pour le courant de la DEL et compléter le circuit. 

#### Exercice 5.3

Choisissez l'un des thèmes suivant : 
- Magma
- Grim, Kvlt et frostbitten
- Arc-en-ciel
- Licorne
- Cyberpunk
- Forêt viride

Programmez une animation de votre DEL selon le thème choisi en utilisant le PWM. 

**Nb : Un PWM de 255 va garder la broche à `HIGH` 100% du temps. C'est l'équivalent de garder la DEL éteinte.**

Vous pouvez utiliser la fonction `sin` afin de reproduire un effet cyclique.

**Exemple de code :**

```arduino
void loop() {
	static double t = 0;
  
	int r = 255 - max(min((int)(sin(t/4) * 60 + 160), 255), 0);
	int g = 255 - max(min((int)(sin(t/4) * 50 + 80), 255), 0);
	int b = 255;

	analogWrite(red, r);
	analogWrite(green, g);
	analogWrite(blue, b);

	t++;
	delay(50);
}
```

Une fois terminé, montrez moi votre animation de DEL. Je vais vous donner une note sur 10. 

[Félicitations, vous avez brisé le plafond de verre.](https://www.youtube.com/watch?v=s-09gNDsPzQ)