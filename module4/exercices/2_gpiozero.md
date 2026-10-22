# Exercices - GPIOZero

## Exercice 1

Sur vos platines d'essais, faires les différents circuits vous permettant de tester les script d'exemples.

## Exercice 2

Pour cet exercice vous devrez réalisé le circuit suivant à l'aide de votre Pi : 
- Vous aurez besoin de 3 DELs, chacune contrôllé par un GPIO différent
- Vous aurez besoin d'un bouton en entrée
- Placez les DELs en ligne
- Lorsqu'on appuie sur le bouton, on veux incrémenter un compteur. 
- Le nombre de DEL allumé doit correspondre à la valeur du compteur.
- Lorsqu'on dépasse 3, on recommence à zéro.

<img src="img/Pasted image 20260903092429.png" width="500" />

## Exercice 3


Reproduisez sur platine d'essaie le schéma suivant en utilisant votre Pi et un buzzer passif : 

<img src="img/Pasted image 20261008095435.png" width="500" />

En utilisant les classes les plus apropriés de la librairie GPIO Zero, écrivez un script python faisant en sorte que le buzzer joue en continue tant et aussi longtemps que le bouton est gardé enfoncé.

>[!notice] Portez attention au schéma. Certains paramètres d'initialisation de vos classes vont dépendre de comment les GPIOs sont branchés.

