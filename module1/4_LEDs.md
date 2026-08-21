# Les DELs

Une diode électroluminescente (DEL) est une diode générant de lumière lorsqu'un courant passe au travers.

De façon générale, les diodes sont polarisé - le courant peut traverser une diode uniquement dans une direction.

<img src="img/Pasted image 20260817142950.png" width="300" />

La "tension directe de la LED" fait référence à la tension à laquelle une diode électroluminescente (LED) commence à conduire l'électricité et à émettre de la lumière. On l'appelle également couramment la "tension de mise en marche" ou la "tension de seuil" de la LED. En anglais : *forward voltage*.

Les DELs vont engendrer une chute de tension équivalente dans le circuit.

<img src="img/Pasted image 20260817143146.png" width="300" />

 L'application d'un courant supérieure à la tolérance de la DEL peut potentiellement l'endommager. Pour limiter le courant à travers une LED et la protéger, une résistance limitatrice de courant est à utiliser en série avec la LED dans un circuit.

**Important :** nos DELs vertes et bleues ont un courant maximal de 10mA. Pour les autres couleurs, nous allons généralement commencer en prenant pour acquis un courant cible de 20mA.

## Calculez la résistance idéale pour une DEL

La formule avec laquelle nous allons travailler est assez simple - nous avons juste besoin de connaître quelques valeurs: 
- LED Forward Voltage - Généralement trouvé sur la fiche technique LED (F) 
- Courant cible - Également disponible sur la fiche technique (C) 
- Tension d'entrée - C'est la tension de notre alimentation (B) 

La résistance idéale est (B – F) / C, c’est-à-dire: 
- Pour calculer la résistance idéale en ohms, nous allons simplement soustraire la tension directe F de la LED de la tension d'entrée B en volts et la diviser par le courant LED C (en ampères, pas en milliampères !) 

**Exemple :**

Avec une LED jaune et une tension de 3.0V : 

```
B = notre tension d'entrée = 3,0 V
F = notre tension directe de LED = 2,2 V (LED jaune) 
C = notre courant cible = 20 mA	

3.0V - 2.2V = 0.8V
0.8V / 0.020A = 40 Ohms
```

### Attention : DELs en parallèle

https://www.youtube.com/shorts/3jenmFVNxOo

