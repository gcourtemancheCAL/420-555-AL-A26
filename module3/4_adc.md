# ADC

**Définition :** *Analog to digital converter.* Module convertissant un signal analogue (tension variable) en valeur digitale (un nombre).

Un ADC est un module qui va nous permettre de mesurer la tension à un point dans notre circuit. Ainsi, en combinant notre ADC à un diviseur de tension, on peut commencer à mesurer des facteurs environementaux. 

Le ESP32 contient 2 modules d'ADC. Chaque module gère une certaine quantité de canaux différents.  Le module est en conflit avec le module de WiFi donc on ne peut pas l'utiliser lorsque le ESP32 se connect au réseau. Vous pouvez consulter la documentation d'Espressif pour voir quel GPIO est connecté sur quel module ADC. 

L'ADC du ESP32 a une résolution de 12 bits lui permettant de retourner des valeurs entre 0 et 4095.

L'ADC du ESP32 avec une atténuation de 11 décibel (i.e. la valeur par défaut) supporte une tension maximale de 3.3V. 

On utilise la méthode `analogRead` pour lire les valeurs de notre ADC.

```arduino
int analogPin = A3; // potentiometer wiper (middle terminal) connected to analog pin 3                    
					// outside leads to ground and VCC
int val = 0;  // variable to store the value read

void setup() {  
	Serial.begin(9600);
}
void loop() {  
	val = analogRead(analogPin);
	Serial.println(val);
	delay(200);
}
```

