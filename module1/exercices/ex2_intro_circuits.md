# Exercices - Introduction aux circuits

## Question 1

### Question 1.1
Calculer la valeur idéale de résistance pour des LEDs rouges, jaunes, vertes et bleues avec un voltage fourni par deux batteries de 1.5 volts en série. Si le courant direct (forward voltage) de la LED est supérieur à la tension d’entrée, quelle solution peut-on envisager avec la résistance ?

### Question 1.2

Faites un schéma de ce circuit sur KiCad en utilisant les résistances les plus appropriées parmi celles dans votre trousse. Utilisez les étiquettes pour indiquer la valeur de résistance sur KiCad.

### Question 1.3

Reproduisez ce circuit sur votre platine d'essai.

## Question 2

### Question 2.1

En théorie, combien de LEDs rouge pouvez-vous connecter en série sur une batterie de 5 volts avant qu’elles ne brillent plus? Combien de LEDs vertes? Expliquez votre raisonnement.

### Question 2.2

Testez sur votre platine d'essai.

## Question 3

En utilisant vos deux batteries de 1,5 volts branchées en série, branchez en parallèles 4 leds rouges avec la bonne résistance sur chaque branche. 

- Quelle est la charge de vos batteries?
- Quelle courant va-t-être consommé par votre circuit?
- Pendant combien de temps vos batteries vont pouvoir alimenter les DELs?

## Question 4

En utilisant deux piles AA branchées en série comme alimentation, reproduisez le circuit suivant sur votre platine d'essai :

<img src="img/Pasted image 20260819144807.png" width="400" />

Ce circuit utilise comme matériel : 
- Une DEL rouge
- Une résistance
- Un interrupteur à trois broche
- Un "active buzzer".

**Questions :** 
- Quelle est la résistance idéale pour ce circuit? Laquelle utilisez-vous?
- Calculez la quantité de courant qui passe par la DEL.
- À l'aide d'un multimètre, mesurez la quantité de courant qui passe par la DEL. Est-ce que ça correspond? Pourquoi?
- À l'aide du multimètre, mesurez la valeur de votre résistance. Est-ce que ça correspond?
- À l'aide du multimètre, mesurez le courant qui passe par l'ensemble de votre circuit.

## Question 5

### Question 5.1

Reproduisez le circuit suivant en utilisant un moteur DC, une source d'alimentation 5V et un potentiomètre : 

<img src="img/Pasted image 20260820154055.png" width="400" />

Collez un petit bout de papier sur le moteur afin de bien pouvoir observer son mouvement.

**Potentiomètre :** 

Un potentiomètre est une résistance ajustable.

<img src="img/Pasted image 20260820153321.png" width="300" />

Dans notre cas à nous, nous sommes seulement intéressé à connecter VCC à l'alimentation de notre circuit et OUT à notre moteur. 

Une fois le circuit complété, l'ajustement du bouton va nous permettre de contrôler la vitesse du moteur.

### Question 5.2

Inverser la polarité des connexions (potentiomètre sur négatif, moteur sur positif). Que remarquez vous?

## Question 6

Sans reproduire le circuit, calculez le courant qui le traverse : 

<img src="img/Pasted image 20260820161941.png" width="400" />

## Question 7

Reproduisez le circuit suivant dans KiCad :

<img src="img/Pasted image 20260820162339.png" width="400" />

Il contient plusieurs problèmes. Expliquez et corrigez les dans un nouveau schéma.