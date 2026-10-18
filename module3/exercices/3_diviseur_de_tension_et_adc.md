# Exercies - Diviseur de tension et ADC

## Exercice 1

Considérant la vue schématique suivante : 

<img src="img/Pasted image 20260929121425.png" width="400" />

### Exercice 1.1

Reproduisez le circuit sur votre platine. Jouez avec le potentiomètre et observez le comportement de la DEL. Vous devriez obtenir quelque chose de similaire à ceci : 

<img src="img/Pasted image 20260930125041.png" width="400" />

### Exercice 1.2

Une fois fait, calculez la tension en 2 (V_out) du circuit suivant lorsque la résistance entre 3 et 2 est de 4kΩ et la résistance entre 3 et 1 est de 10kΩ.

<img src="img/Pasted image 20260929134028.png" width="400" />

>[!warning] Pour calculer la tension en 2, il faut aussi considérer les éléments qui suivent. Dans ce cas ci, il va falloir calculez la résistance totale en tenant compte du 1kΩ suivant. Vous pouvez utiliser le schéma suivant pour réaliser vos calculs. Avec les paramètres donnés, ils sont fonctionellement équivalents.
>
> <img src="img/Pasted image 20260929134008.png" width="400" />

### Exercice 1.3

Maintenant, calculez la tension en 2 pour ce circuit en considérant les mêmes paramètres. Vous pouvez prendre pour aquis que la tension de seuil de la DEL est de 1.8V.

<img src="img/Pasted image 20260929121425.png" width="400" />

>[!warning] Maintenant qu'il y a une DEL dans le chemin, on ne peut pas simplement calculer la résistance équivalente. Il va falloir sortir notre loi d'Ohm et nos muscles algébriques. La simplification suivante du circuit s'applique tout de même : 
>
> <img src="img/Pasted image 20260929134601.png" width="400" />

## Exercice 2

Nous allons vouloir créer un système d'éclairage automatique en utilise une photorésistance. 

<img src="img/Pasted image 20260929150921.png" width="400" />

**Matériel requis :** 
- Une photorésistance
- Une résistance de 1kΩ
- Une résistance de 220Ω
- Une DEL
- Votre ESP32

**Les branchements :** 
- Une broche en INPUT connectée à un diviseur de tension créé à l'aide de votre photorésistance et de votre résistance de 1kΩ.
- Une borche en sortie contrôlant l'intensité de la DEL connectée en série avec la résistance de 220Ω.

**L'objectif du système :** L'ESP32 va lire une mesure de luminosité et allumer une DEL en conséquence. Plus il fait noir, plus l'illumination de la DEL est intense.

### Exercice 2.1

Commencez par déterminer comment la valeur de résistance de la photorésistance change avec la luminosité. Lorsqu'il fait clair, est-ce que la résistance monte ou descend? Faites un circuit de test pour valider le comportement.

### Exercice 2.2

Faites un schéma KiCAD du circuit final que vous allez réaliser. 

**Question :** La photorésistance va être votre première ou deuxième résistance? Pourquoi?

### Exercice 2.3

Calculez la tension de sortie de votre diviseur de tension lorsque la photorésistance a les valeurs suivantes : 
- 1kΩ
- 5kΩ
- 10kΩ

### Exercice 2.4

Réalisez le circuit et programmez le ESP32.

Vous allez probablement devoir faire une ronde de calibration pour vous ajuster aux valeurs réels obtenues dans votre environnement de test.

## Exercice 3

### Le joystick

<img src="img/Pasted image 20260930143109.png" width="300" />

**Branchements du joystick :** 
- Le GND se connecter au GND de votre ESP32
- On branche l'alimentation au 3.3V de votre ESP32.
- VRX, VRY, et SW se branchent sur des GPIO en mode lecture

 >[!important] : même s'il est écrit 5V sur votre joystick, on veut le brancher au 3.3V.

VRX et VRY sont les broches de sorties de deux potentiomètres : la tension en VRX et VRY ca s'ajuster selon la position du joystick.

SW est un bouton complètement ordinaire inclu dans votre joystick.

### Exercice 3.1
En utilisant le joystick faisant parti de votre trousse, reproduisez le circuit suivant : 

[Liens si le vidéo n'apparait pas directement](./video/joystick.mp4)

<video controls width="800">
	<source src="./video/joystick.mp4">
</video>

Vous remarquerez que les 4 DELs représentent chacune l'une des directions cardinales et qu'elles s'allument lorsque le joystick est tiré dans cette direction.
### Exercice 3.2

Ajoutez un klaxon à l'aide d'un buzzer passif. Le klaxon doit s'actionner tant que le bouton du joystick est enfoncé.

Gardez en tête le circuit recommendé par le manufacturié : 

<img src="img/Pasted image 20260918070704.png" width="600" />

