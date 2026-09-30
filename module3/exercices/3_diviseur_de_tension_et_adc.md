# Exercies diviseur de tension et ADC

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

Matériel requis : 
- Une photorésistance
- Une résistance de 1kΩ
- Une résistance de 220Ω
- Une DEL
- Votre ESP32

Les branchements : 
- Une broche en INPUT connectée à un diviseur de tension créé à l'aide de votre photorésistance et de votre résistance de 1kΩ.
- Une borche en sortie contrôlant l'intensité de la DEL connectée en série avec la résistance de 220Ω.

L'objectif du système : plus il fait noir, plus l'illumination de la DEL est intense.

### Exercice 2.1

Commencez par déterminer comment la valeur de résistance de la photorésistance change avec la luminosité. Lorsqu'il fait clair, est-ce que la résistance monte ou descend? Faites un circuit de test pour valider le comportement.

### Exercice 2.2

Faites un schéma KiCAD du circuit final que vous allez réaliser. 

La photorésistance va être votre première ou deuxième résistance? Pourquoi?

### Exercice 2.3

Calculez la tension de sortie de votre diviseur de tension lorsque la photorésistance a les valeurs suivantes : 
- 1kΩ
- 5kΩ
- 10kΩ

### Exercice 2.4

Réalisez le circuit et programmez le ESP32.

Vous allez probablement devoir faire une ronde de calibration pour vous ajuster aux valeurs réels de votre environnement de test.

## Exercice 3

Exercice avec joystick

## Exercice 4

Nous allons vouloir faire un circuit allumant automatiquement un ventilateur lorsqu'il fait trop chaud.

### Exercice 4.1

La première étape consiste à se faire un circuit permettant de mesurer la température ambiante. À cet effet, nous allons utiliser une résistance dont la valeur change avec la température (un thermistor).

<img src="img/Pasted image 20260929173252.png" width="300" />

Comme avec la photorésistance, nous allons vouloir commencer en faisant un circuit nous permettant de voir comment la résistance de notre thermistor change selon la température. 

### Exercice 4.2

Nous allons ensuite connecter un diviseur de tension composé de notre thermistor à l'une des broches de notre ESP32. Nous allons vouloir utiliser le ESP32 pour allumer une DEL bleue lorsqu'il fait trop chaud.

### Exercice 4.3 - Moteur contrôlé par transistor

>[!danger] Cet exercice introduise des éléments présentants des **risques** pour votre ESP32. Il est important de faire très attention aux éléments suivants sous risque d'endommager ou briser votre matériel : 
> - Ne **jamais** faire et défaire des branchements pendant que vos équipements sont alimentés.
> - Assurez-vous de respecter à la lettre les schémas fournis.
> - Assurez-vous que les branchements en séries sont réellement en séries.
> - Ne connectez **jamais** votre moteur directement à l'un des GPIO des votre ESP32.

>[!danger] Cet exercice va combiner 2 sources d'alimentation distinctes : l'alimentation 5V USB et l'alimentation 5V provenant de votre bloc d'alimentation. **Vous allez devoir connecter le GND du ESP au GND du power supply**.

Nous allons remplacer la DEL bleue par un moteur qui s'allume lorsqu'il fait chaud. Dans un monde idéal, notre moteur aurait des hélices qui pousseraient de l'air.

**Vous allez avoir besoin du matériel suivant :** 
- 2 résistance 220Ω
- Une diode 1N4001
- Un moteur DC 5V
- Un transistor NPN 8050 (ou équivalent)
- Un bloc d'alimentation avec batterie 9V

**La diode 1N4001 :** 

<img src="img/Pasted image 20260929175757.png" width="400" />

**Schéma du circuit :** 

<img src="img/Pasted image 20260929180049.png" width="700" />

### Diode flyback (i.e. explication sur la diode weird)

Un moteur électrique en actuation va toujour générer une charge électrique en opposition à celle qui l'active. Lorsque nous coupons l'alimentation du moteur, cette charge va pousser temporairement dans le sens contraire. Notre moteur va donc temporairement se comporter comme un générateur. 

**Cette charge électrique doit être gérée. Toujours.** 

Si on ne la gère pas : 
- Cette charge pourrait endomager le transistor.
- Si la tension générée par le moteur est suffisament élevée, elle pourait même passer à travers le transistor et bruler le ESP32
- Elle pourrait aussi créer du bruit électrique dans le reste du circuit et endomager d'autres composants.

La diode 1N4001 est ce qu'on appel une diode de flyback. C'est un diode qui peut transporter un courant élevé sans risque pour sa santé. 

En opération normale : elle est placée à l'envers et ne va rien faire.

Lorsque l'on éteint l'alimentation du moteur, elle va fourir un chemin de retour entre les broches de notre moteur qui va ainsi permettre de dissiper la charge générée.

>[!attention] Dès qu'il est question de moteur ou de _coil_, il faut penser à gérer les charges inductives. L'utilisation d'une diode de flyback est l'un des moyens les plus simples.

### Exercice 4.4 - Moteur contrôlé par un relais

En réalité le moteur peut demander un courant qui dépasse ce que votre transistor peut fournir. C'est d'autant plus vrai si l'on commence à mettre de la résistance sur la tige rotative du moteur. Plusieurs modèles de BJT pourraient supporter notre moteur ou on pourrait aussi utiliser transistor de type MOSFET.

On va utiliser un autre composant qui est typiquement utiliser pour contrôler des tension et des charges élevés : le relai.

#### Le relais

<img src="img/Pasted image 20260929192017.png" width="400" />

Un relais est un interrupteur contrôlé électriquement. Son fonctionnement est électromécanique : un électroaimant contrôle la position de l'interrupteur.

Les broches A1 et A2 permettent d'alimenter un électroaimant. Lorsqu'un courant les traverse, l'électroaimant s'active et la change laquelle de 12 et 14 est connectée à 11.

Les deux broches 11 sont connectés entre elle. Le principe est le même que sur un bouton poussoir. Cette broche peut être connectée à l'une de 12 ou 14 :
- 12 est la broche dites "nominally closed" (NC). Cela signifie que le circuit entre 11 et 12 est fermé lorsqu'aucun courant ne traverse A1 et A2.
- 14 est la broche dites "nominally open" (NO). Cela signifie que le circuit entre 11 et 14 est ouvert lorsqu'aucun courant ne traverse A1 et A2.

Lorsqu'un courant traverse A1 et A2, le circuit entre 11 et 12 s'ouvre, et le circuit entre 11 et 14 se ferme.

Comme un transistor, un relais nous permet de contrôler l'actuation d'un interrupteur à l'aide d'une charge électrique.

**En différence d'un transistor :** 
- Le fonctionnement est mécanique.
- Le courant traversant A1 et A2 peut être entièrement disocié du courant traversant le 11 et 12/14.
- Un relais peut contrôler un courant et une tension beaucoup plus élevé. En fait, nos relais supportent un courant allant jusqu'à 3 ampères pour une tension de 30V DC (vs 500mA pour nos S8050)!

### Exercice 4.4.1 - Tester le HK4100F

Reproduisez le circuit suivant afin de tester les branchements avec le HK4100F : 

<img src="img/Pasted image 20260929194851.png" width="400" />

Appuyer sur le bouton devrait changer la DEL qui s'allume. Vous devriez entendre un _click_ lorsque l'aimant s'active.

### Exercice 4.4.2 - Le vrai circuit. Vous êtes prêt?

**Le circuit de controle du moteur :** 

<img src="img/Pasted image 20260929194919.png" width="600" />

>[!danger] Le relais nous permet de traiter le circuit du ESP et le circuit du moteur comme deux circuits indépendants. **Il ne faut pas connecter les GND ensemble.**

**Le circuit complété :** 

<img src="img/Pasted image 20260930124155.png" width="600" />

**Précisions sur le circuit complété :** 
- Le bloc d'alimentation fournit du courant à un rail d'alimentation seulement (sur la photo : celui du haut).
- Le ESP32 fournit 5V sur le second rail d'alimentation (les deux fils blancs). Ce rail n'est utilisé que pour le coil du relais. 
- Les GND du bloc d'alimentation et du ESP32 ne sont pas reliés. Ces deux alimentations sont entièrement indépendantes. 
- Le ESP32 contrôle la base du transistor via un GPIO. Le signal provient du fil orange et traverse les deux résistances de 220 ohm en série.
- La diode de flyback est directement au dessus du relais - c'était plus compact comme ça.
- On voit mal le snubber RC sur cette photo.
- Mon moteur est déffectueux. J'ai donc ajouté un DEL en parallèle (la DEL verte) au moteur pour mieux visualiser le comportement du relais. 
- J'ai pris beaucoup d'espace sur la platine pour essayer de rendre le circuit un peu plus lisible. Si vous avez de la difficulté à l'aborder, suivez une chose à la fois.

**On voit mieux le snubber RC sur cette photo :** 

<img src="img/Pasted image 20260930124849.png" width="300" />

**Vidéo du circuit:**

<a href="./video/relais.mp4"> Liens si le vidéo n'apparait pas directement</a>

[Liens si le vidéo n'apparait pas directement](./video/relais.mp4)

<video controls width="800">
	<source src="video/relais.mp4">
</video>

#### Relais et diode de flyback

<img src="img/Pasted image 20260930111414.png" width="300" />

Le coil du relais doit être accompagné aussi d'un mécanisme pour gérer la charge inverse.

#### Snubber RC

Remarquez le petit circuit en parallèle avec le moteur : 

<img src="img/Pasted image 20260929195025.png" width="300" />

Cet agencement de résistance et de capaciteur est appelé un **snubber RC**. Il joue un rôle similaire à la diode de flyback. 

Normalement, les valeurs pour la résistance et le capaciteur sont choisis empiriquement selon le modèle de moteur. Dans notre cas, comme on a peu de matériel disponible, on va y aller avec notre plus petite résistance et notre plus petit capaciteur.

Utilisez un de vos petits capaciteurs en céramique : 

<img src="img/Pasted image 20260929195128.png" width="300" />


