# Debouncing

En testant l'exemple du chapitre précédent, vous avez probablement remarqué que de changer la valeur de l'interrupteur pouvait causer de drôles de résultats : 

<img src="img/Pasted image 20260903143758.png" width="200" />

Ce sont mes résultats après avoir changer la valeur de l'interrupteur une seule fois.

Cela arrive parce que la mécanique de nos composants est imparfaite et résulte en des *bonds* (bounce) au niveau du signal résultant. 

**Signal *bouncy***

<img src="img/Pasted image 20260903092823.png" width="500" />

Nous allons devoir gérer ce signal afin de le *debounce*

<img src="img/Pasted image 20260903092916.png" width="500" />

## Debouncing software

Les approches de debouncing logiciel consiste à valider que le résultat reste stable pour un certains lapse de temps. Cela peut mener à du code un peu complexe par moment mais dans notre situation ça reste la solution à privilégier.

[Exemple de debouncing logiciel.](https://docs.arduino.cc/built-in-examples/digital/Debounce/)

## Debouncing hardware

Une solution alternative consiste à faire le debouncing au niveau matériel. Une approche typique consiste en l'utilisation d'un filtre RC. Un filtre RC est ainsi appelé parce qu'il combine une résistance et un capaciteur afin de filtrer certaines fréquences de signal.

**N.b. :** Un filtre hardware peut difficile à faire correctement - les résistances et le capaciteurs doivent respecter des valeurs très précises. Il est aussi - pour être certains d'avoir un signal propre - nécessaire d'ajouter de l'hystérésis à notre circuit (généralement via un trigger Schmitt).

### Capaciteur

Un capaciteur est une espèce de petite pile électronique.

Initialement, le capacité est sans charge. Dans cette situation, il va se comporter comme une résistance de 0 ohms - le courant va le traverser dans son entièreté.

La résistance effective du capaciteur va augmenter au fur et à mesure que le capaciteur accumule une charge. 

Lorsque pleinement chargé, il cesse de laisser passer du courant - agissant ainsi comme un interrupteur ouvert.

Une fois qu'on coupe l'alimentation du capaciteur, il va commencer à se decharger en fournissant une tension équivalente à celle reçu. Il va donc alimenter le reste du circuit pendant un court lapse de temps.

### Exemple 1

#### Circuit de base - GPIO Active HIGH avec PULLDOWN

<img src="img/Pasted image 20260903144747.png" width="500" />

#### Altération avec filtre RC

**Schéma :**

<img src="img/Pasted image 20260915112309.png" width="500" />

**Circuit :**

<img src="img/Pasted image 20260915112409.png" width="500" />

**Explication :**

- Le GPIO est tiré vers le bas. Un signal LOW est détecté.
- Lorsque nous appuyons sur le bouton, le capaciteur est vide. Il va donc laisser passer l'entièreté du courant vers le GNd. Le GPIO va continuer à détecter un signal LOW. 
- Pendant que le bouton bounce rapidement, le capaciteur laisse la majorité de courant passer vers le GND.
- Lorsque le bouton se stabilise, le capaciteur se charge. La tension au GPIO monte.
- Éventuellement un point de bascule est atteint et le  GPIO détecte un signal HIGH.