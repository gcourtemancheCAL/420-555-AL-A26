# Écriture

## pinmode

Le GPIO doit être configuré en mode OUTPUT au setup : 

```arduino
void setup() {  pinMode(13, OUTPUT);    // Sets the digital pin 13 as output}
```


## digitalWrite

```arduino
void loop() {  
digitalWrite(13, HIGH); // Sets the digital pin 13 on  
delay(1000);            // Waits for a second  
digitalWrite(13, LOW);  // Sets the digital pin 13 off  
delay(1000);            // Waits for a second
}
```

## PWM

**Définition :** Un signal PWM (pulse width modulation) est un signal qui cycle rapidement entre ``HIGH`` et `LOW`.  Le rapport entre le durée d'un signal actif vs la période est appelé **Rapport cyclique**, ou **duty cycle** en anglais. 

e.g. : Un rapport cyclique de 30% signifie que pour une période de 1 seconde la signal va être `HIGH` pendant 300ms.

Certains appareils (e.g. le arduino) vont avoir des circuit de PWM hardware connectés à certaines broches. Le ESP8266 réalise les fonctions de PWM en software et peut donc utiliser la plupart des GPIOs à cet effet. Le ESP8266 peut donc émuler un signal PWM sur les GPIO0 à GPIO15.

Le PWM nous permet de simuler un signal d'intensité variable. 

Considérant le circuit suivant : 

<img src="img/Pasted image 20260902111158.png" width="800" />

Le code suivant va donc graduellement augmenter l'intensité de la DEL et, une fois l'intensité maximale atteinte, recommencer de 0.
  
```arduino

constexpr int gpio5 = 5;

void setup() {
	pinMode(gpio5, OUTPUT);
}

void loop() {
	static unsigned int intensity = 0;
	intensity += 10;
	analogWrite(gpio5, intensity % 256); # Max = 255
	delay(50);
}
```


## Tone

Génère une tonalité sur une broche.

```arduino
#define BUZZER_PIN D0 // Example pin
void setup() {  
	pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {  
	tone(BUZZER_PIN, 1000, 1000); // 1 kHz tone  
	delay(1500); // 1 seconde de son, 500 ms de silence
}
```

