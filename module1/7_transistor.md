# Transistor (NPN)

Un transistor est un composant qui permet de contrôler un courant plus grand avec un petit courant.

Dans ce cours, nous allons principalement utiliser le transistor NPN. Dans votre trousse, c'est le S8050. À ne pas confondre avec un transistor S8550 qui est un transistor PNP. Leur fonctionnement diffère de manière non-intuitive. 

On utilise souvent le transistor NPN comme un interrupteur, mais il peut aussi servir d'amplificateur.

<img src="img/Pasted image 20260819151827.png" width="300" />

- **B** = Base (Contrôle)
- **C** = Collecteur (connecté au +)
- **E** = Emetteur  (connecté au -)

## Mode Actif

Le transistor entre en mode actif lorsque `V_c > V_b > V_e`

Le courant qui circule dans le transistor provient de la base et de l'émetteur. On peut estimer le courant en C à l'aide de la formule suivante : `I_C ≈ β x I_B` où β est un facteur d'amplification variable propre au transistor. Le courant en E deviendrait donc `I_C + I_B` ou `β + 1 x I_B`.

<img src="img/mode-active-model_2.png" width="300" />

**Important :** Les transistors se comportent comme des diodes, donc il y a une tension  directe d'approximativement 0.7V entre B et E. Ce seuil doit être franchi par la tension en B pour entrer en mode actif.

La tension en E va être approximativement égale à `V_B - 0,7V`. 

Bien entendu, l'ensemble de l'oeuvre va se balancer sur l'ensemble des composants dans le circuit. Donc si une résistance suffisamment élevée suit l'émetteur, l'ensemble des paramètres vont s'ajuster de façon à s'équilibrer dans le respect des règles précédentes. 

### Exemple 1

<img src="img/Pasted image 20260820132900.png" width="400" />

On peut estimer certains paramètres du circuit ainsi : 

```
V_e = V_b - 0.7, V_e = 0 puisque connecté au ground.
Donc V_b = 0.7V
Donc V en R_v = 3.0V - 0.7V = 2.3V.
Donc I en R_v = 2.3V/10kΩ = 0.23mA
I_E = (β + 1) x 0.23mA = 23.23mA  
```

### Exemple 2

<img src="img/Pasted image 20260820141707.png" width="400" />

```
V_e = V_b - 0.7
I_e = V_e/1000 = (V_b - 0,7)/1000
I_b = I_e / 101 = (V_b - 0,7)/1000/101 = (V_b - 0,7)/101000
V_rb = I_b * 10000 = (V_b - 0,7)/101000 * 10000 = 10000(V_b - 0,7)/101000
V_rb = (10000V_b - 7000)/101000
V_rb = 3-V_b = (10000V_b - 7000)/101000
303000 - 101000V_b = 10000V_b - 7000
310000 = 111000V_b
2.79 = V_b # On a la tension en B, on peut calculer le reste
V_e = V_b - 0.7 = 2.09
I_e = 2.09 / 1000 = 2.09mA 

# On commence ici a se valider. Normalement on devrait pouvoir obtenir que I_rb = 101I_e
I_rb = (3-2.79)/10000 = 0.021mA
I_e  = 101I_rb = 0.021 * 101 = 2.12mA
2.12mA ≈ 2.09mA => La différence provient de mes arrondissements
```


## Mode Saturation

En mode **Saturation**, le transistor va, à toute fin pratique, court circuité entre C et E. Il va - néanmoins - avoir une perte de tension d'environ 0.2-0.3V entre C et E.

Dans ce mode, le courant en C n'est pas pratiquement plus contrôlé par le courant en B. 

Le mode saturation est atteint lorsque `V_B > V_C && V_B > V_E && V_BE > V_th` où V_th est un seuil propre au transistor (généralement notre 0.7V). 

<img src="img/mode_saturation-model.png" width="300" />
