## Exercice 1

#### Exercice 1.1

Faites un circuit dans lequel : 
- GPIO 12 est en entrée.
- GPIO 13 est en sortie.
- Lorsqu'un bouton connecté à GPIO 12 est appuyé, utilisez GPIO 13 pour allumer une DEL.
- Lorsque le bouton est relâché, la DEL doit s'éteindre.

Ce circuit doit être fait avec une résistance en pulldown.
#### Exercice 1.2

Refaites le circuit en 1.1 mais cette fois ci faites votre connexion en pullup. N'utilisez pas la résistance interne au ESP.
## Exercice 2

Pour cet exercice vous devrez réalisé le circuit suivant : 
- Vous aurez besoin de 3 DELs, chacune contrôllé par un GPIO différent
- Vous aurez besoin d'un bouton en entrée
- Placez les DELs en ligne
- Lorsqu'on appuie sur le bouton, on veux incrémenter un compteur. 
- Le nombre de DEL allumé doit correspondre à la valeur du compteur.
- Lorsqu'on dépasse 3, on recommence à zéro.

<img src="img/Pasted image 20260903092429.png" width="500" />

Commencez en faisant le schéma de votre circuit sur KiCad. 

Ensuite, faites le sur votre platine d'essai et programmez votre ESP.

## Exercice 3

Nous allons reprendre avec un exercice similaire à l'[Exercice 1 des exercices précédents](./1_ex_intro_esp.md#exercice-1). 

Nous allons toute fois changer la logique un peu : 

<img src="img/Pasted image 20260915145709.png" width="500" />

Nous allons aussi ajouter un bouton poussoir accompagner d'une DEL bleue pour demander un passage piéton. 

Lorsque quelqu'un appuie sur le bouton :
- la DEL bleue s'allume pour indiquer qu'un piéton à demander à traverser.
- Lorsque la lumière rouge s'allume, faire clignoter la lumière bleue pendant 5 secondes pour indiquer aux piétons qu'il est sécuritaire de traverser.
- Une fois le passage piéton terminé, continuer le cycle normalement. 

## Exercice 4

Nous allons reprendre à partir de l'[Exercice 5.3 des exercices précédents](./1_ex_intro_esp.md#exercice-53)

Cette fois ci, nous allons vouloir deux animations différentes ainsi qu'un interrupteur qui nous permette d'identifier quelle animation jouer.

Lorsque nous changeons d'animation :
- On veut une courte pause pendant laquelle la DEL ne s'allume pas.
- On veut ensuite faire flasher trois fois les couleurs rouges, vertes et bleues en succession.
- Finalement, on commence la nouvelle animation du début.

N'oubliez pas de gérer le cas où on change la position de l'interrupteur avant que la séquence d'amorce ne soit complétée. Dans cette situation, nous voulons recommencer la séquence d'amorce.

## Exercice 5

Nous allons faire un piano à 3 touches. 
- Les touches vont générés les notes E4(330Hz),  G4 (392Hz), et A4 (440Hz)
- Lorsqu'un interrupteur est activé, nous voulons monter les notes jouées d'un octave. La fréquence jouée doit donc doubler.

Le schéma suivant est une approximation du circuit que vous avez à faire : 

<img src="img/Pasted image 20260903095323.png" width="500" />

**Attention  :**
- Une grosse erreur est répétée. Identifiez cette erreur et corrigez là.
- Je n'ai pas porté attention aux broches utilisées. Validez qu'elles sont correctes pour vos besoins.
- Une seule note peut être jouée à la fois.









