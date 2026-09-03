# Debouncing

En testant l'exemple du chapitre précédent, vous avez probablement remarqué que de changer la valeur de l'interrupteur pouvait causer de drôles de résultats : 

![[Pasted image 20260903143758.png]]

Ce sont mes résultats après avoir changer la valeur de l'interrupteur une seule fois.

Cela arrive parce que la mécanique de nos composants est imparfaite et résulte en des *bonds* (bounce) au niveau de la connectivité. 

**Signal *bouncy***

![[Pasted image 20260903092823.png]]

Nous allons devoir gérer ce signal afin de le *debounce*

![[Pasted image 20260903092916.png]]

## Debouncing software

Les approches de debouncing logiciel consiste à valider que le résultat reste stable pour un certains lapse de temps. Cela peut mener à du code un peu complexe par moment.

[Exemple de debouncing logiciel.](https://docs.arduino.cc/built-in-examples/digital/Debounce/)

## Debouncing hardware

Une solution alternative consiste à faire le debouncing au niveau matériel. Une approche typique consiste en l'utilisation d'un filtre RC. Un filtre RC est ainsi appelé parce qu'il combine une résistance et un capaciteur afin de filtrer certaines fréquences de signal.

**N.b. : Un filtre RC à lui-seul ne garanti pas qu'une seule actuation va être détecté.**
### Capaciteurs

capaciteurs

### Exemple 1

#### Circuit de base - GPIO Active HIGH avec PULLDOWN

![[Pasted image 20260903144747.png]]

#### Altération avec filtre RC

![[Pasted image 20260903145518.png]]

**Explication**
1. Lorsqu'on appuie initialement sur le bouton, le capaciteur est vide.
2. Il agit donc comme un court circuit - le GPIO détecte toujours une tension vide.
3. Les _bounciness_ initial ne produit pas un signal assez constant pour charger le capaciteur
4. Lorsque le signal se stabilise, le capaciteur se charge et le circuit s'ouvre.
5. Le GPIO détecte maintenant la tension haute.

