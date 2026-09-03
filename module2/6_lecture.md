# Lecture 

## pinmode


Le GPIO doit être configuré en mode INPUT au setup : 

```arduino
void setup() {  pinMode(13, INPUT);    // Sets the digital pin 13 as output}
```

Il existe aussi le mode INPUT_PULLUP qui va automatiquement configuré une résistance tirant le broche vers le haut. 

```arduino
void setup() {  pinMode(13, INPUT_PULLUP);    // Sets the digital pin 13 as output}
```

## Lecture de l'état de la broche


## Pullup et pulldown

Lorsqu'un GPIO est mis en mode `INPUT`, il entre dans un mode dans lequel il mesure le courant en entrée comparativement à son 3.3V.

Si la broche est connectée au `GND`, le signal est considéré comme `LOW`. Si la broche est connectée au 3.3V, le signal est considéré comme `HIGH`

**Question :** que se passe-t-il si la broche n'est connectée à rien?

Une pratique commune consiste à relier la broche en lecture au `GND` ou au `VCC` - le signal par défaut étant tiré respectivement vers le bas ou le haut.

Ce lien est fait à l'aide d'une résistance. On va souvent utiliser une résistance de 10kΩ.  

Lorsqu'une broche de lecture n'est ni tiré vers le bas, ni tiré vers le haut nous disons qu'elle est **flottante**. Le résultat d'une lecture sur une broche **flottante** est imprévisible. C'est une mauvaise chose.
### pulldown

![[Pasted image 20260902160940.png]]

Une résistance de 10kΩ est utilisé devant le `GND` et une résistance de 1kΩ suit le bouton.

En temps normal : la tension en D4 est tiré vers le 0V.

Lorsque l'on appuie sur le bouton : La tension en D4 monte. Le signal détecté est `HIGH`.
### pullup

![[Pasted image 20260902162746.png]]

Une résistance de 10kΩ est utilisé devant le après le 3.3V, et une résistance de 1kΩ précède le bouton.

En temps normal : la tension en D4 est tiré vers le 3.3V. Le signal détecté est `HIGH`.

Lorsque l'on appuie sur le bouton : La tension en D4 chute. Le signal détecté est `LOW`.



