# IDE Arduino

Espressif propose une suite d'outils pour développer et travailler avec leur équipement. L'installation et l'utilisation de ces outils peut cependant être complexe. Il en devient encore plus complexe lorsque vient le temps d'intégrer des librairies externes à nos projets.

Nous allons donc utiliser l'IDE d'Arduino afin de nous simplifier la vie. Pour la complexité des projets sur lesquels nous allons travailler, cette option est très satisfaisante. 

## Site Arduino

https://docs.arduino.cc/

## Installation

https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing/

## Ajout d'un répertoire de librairies

Dans les préférences, ajouter : `http://arduino.esp8266.com/stable/package_esp8266com_index.json` dans les bibliothèques additionnelles

<img src="img/Pasted image 20260826194901.png" width="800" />

## Documentations

https://arduino-esp8266.readthedocs.io/en/latest/reference.html

## Première application

<img src="img/Pasted image 20260826194956.png" width="800" />

Choisir dans le menu d'outils la plateforme Generic ESP8266

<img src="img/Pasted image 20260826195411.png" width="800" />

Vous devriez par la suite le voir apparaître dans votre barre de navigation

<img src="img/Pasted image 20260826195403.png" width="800" />

Maintenant, essayons une première application pour valider notre configuration et aussi pour explorer le processus avec ce type de circuit.

Remplacez le code de votre IDE avec le code suivant :

```c
int pin = 2;

int count = 0;

void setup() {
  // initialize GPIO 2 as an output.
  pinMode(pin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(pin, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
  
}
```

Branchez un câble USB Micro entre votre ordinateur et le 8266, la LED bleue devrait s'allumer et votre ordinateur devrait détecter un port série RS-232. Dans l'interface des outils dans port, vous pouvez sélectionner le port série qui fut ajouté

<img src="img/Pasted image 20260826195335.png" width="800" />

Maintenant, cliquez sur la flèche pointant vers la droite pour compiler et déployer votre première application dans votre 8266. Vous devriez voir les étapes apparaître dans une console et si tout fonctionne correctement, la LED bleue sur le board devrait clignoter à un intervalle de 2 secondes.

>[!warning] S'il y a un problème, pressez le bouton sur le 8266 qui le redémarrera. Peut-être que le programme va se mettre à faire le clignotement. Sinon, essayez de nouveau. 

>[!warning] Sur linux, vous aurez possiblement  à ajouter le groupe `uucp` ou `dialout` à votre utilisateur

<img src="img/Pasted image 20260826195139.png" width="800" />
