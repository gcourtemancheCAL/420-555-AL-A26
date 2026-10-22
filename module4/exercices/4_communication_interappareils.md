# Exercices - Communication inter-appareils

## Exercices - i2c

### Exercice 1 - Écriture vers appareil

Voici un circuit simplifié de ce que vous allez devoir réaliser : 

<img src="img/Pasted image 20261008134913.png" width="600" />

Travail à réaliser :
- Le Raspberry Pi va faire office de master i2c
- Sur le Pi il va y avoir un serveur flask hébergeant une page web simple sur laquelle se trouve un formulaire permettant à l'utilisateur d'entrée une intensité entre 0% et 100%.
- Lorsque le formulaire est soumis, le Pi va envoyer cette information au ESP32 via i2c. 
- Sur réception de l'information, le ESP32 va envoyer un signal PWM correspondant à l'intensité choisie sur la DEL.

Notes pour les branchements : 
- Le ESP32 peut être alimenté directement à partir de la sortie 5V du Pi. Il peut aussi être alimenté à partir de votre bloc d'alimentation 5V.
- Le GND du ESP32 va devoir être partagé avec le PI.

### Exercice 2 - Écriture et lecture

Le Pi et le ESP32 vont être branchés en i2c comme dans l'exercice précédent.

Cette fois ci, nous allons brancher deux senseurs à notre ESP32 : un thermistor et une photorésistance. 

Ces senseurs vont être branchés aux ADC de notre ESP32 dans une arrangement nous permettant de mesurer la température et la luminosité.

Opérations i2c : 
- Le Pi va pouvoir sélectionner le senseur à lire en envoyant un octet de données (0=thermistor, 1=photoresistance)
- Le Pi va pouvoir lire la valeur de lecture de l'ADC. Comme la résolution de l'ADC du ESP32 est de 12 bits, le ESP32 va devoir envoyer 2 octets de données.
	- Pour le thermistor : 0 = très froid, 4095 = très chaud.
	- Pour la photorésistance : 4095 = claire, 0 = obscur
	
### Exercice 3 - BLE

Reproduisez les exercices précédents, mais cette fois-ci en utilisant Bluetooth BLE.