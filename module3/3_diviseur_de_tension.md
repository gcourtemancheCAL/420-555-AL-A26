# Diviseur de tension 

Un diviseur de tension est un circuit combinant deux résistance afin de réduire la tension au point se situant entre les résistances.

<img src="img/Pasted image 20260928155151.png" width="300" />

>[!warning] Un diviseur de tension va consommer du courant en continu.

On peut donc calculer la tension en A : 

La somme de toutes les hausses et des chutes de tension est égal à 0 : 
`VCC - V_R1 - V_R2 = 0`

La tension en A est donc la tension source moins la chute de tension en R1
`V_A = VCC - V_R1`

Comme R2 est la seule résistance restantes, R2 doit amener la tension à 0. IPSO FACTO `V_A = V_R2`

Par la loi d'ohm :
```
I = VCC / (R1 + R2)
V_A = V_R2 = I * R2
```

Donc :`V_A = VCC * R2 / (R1 + R2)`

Qui peut être formulé ainsi : **La tension de sortie correspond à une fraction de la tension d’entrée, déterminée par le rapport entre la seconde résistance et la résistance totale**

## Diviseur de tension avec résistance variable

Plusieurs capteurs existent qui vont fonctionner en ajustant la valeur d'une résistance selon certains facteurs environementaux : 
- Photorésistance
- Thermistor
- Senseurs FSR (force sensitive resistor)
- Jauge extensométrique

Ces capteurs peuvent être inclues dans un diviseur de tension. En mesurant la tension résultante on peut donc mesurer le facteur environemental à l'oeuvre.

Les valeurs de R1 et de R2 vont être choisis en fonction des éléments suivants de sorte à contraindre les valeurs de tensions possible dans une plage prédéterminée. 

On va aussi essayer de limiter le courant qui circule au repos. À cet effet, on va viser utiliser les valeurs de résistances les plus élevés nous permettant de mesurer avec précision les changements de tension.

### Résistance variable avant A : 

<img src="img/Pasted image 20260929092518.png" width="400" />

**Calcul de la tension en A :**  `V_A = VCC * R2 / (R1 + RV + R2)`

**Impact :** Si RV monte, la tension en A diminue. Si RV baisse, la tension en A monte.

NB : R1 peut être 0Ω si les circonstances le permettent. 

### Résistance variable après A : 

<img src="img/Pasted image 20260929094713.png" width="400" />

**Calcul de la tension en A :**  `V_A = VCC * (RV + R2) / (R1 + RV + R2)`

**Impact :** Si RV monte, la tension en A monte. Si RV baisse, la tension en A baisse.

NB : R2 peut être 0Ω si les circonstances le permettent. 

## Potentiomètre

Jusqu'à présent, on n'a utilisé le potentiomètre que comme une simple résistance variable. En fait, si on utilise les 3 pattes de notre potentiomètre il permet de contrôler la tension en OUT via le principe d'un diviseur de tension.

<img src="img/Pasted image 20260928160920.png" width="200" />

### Fonctionnement du potentiomètre : 

<img src="https://arduinogetstarted.com/images/tutorial/how-it-works-rotary-potentiometer.gif" width="800" />

### KiCAD

<img src="img/Pasted image 20260929084933.png" width="400" />

