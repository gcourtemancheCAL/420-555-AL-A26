# Exercices FreeRTOS et tasks

Réalisez ces exercices sur le ESP32.

## Exercice 1

Faites un circuit simple dans lequel vous allez connecter 3 DELs à différent GPIO de votre ESP32.

### Exercice 1.1

En écrivant  votre code entièrement et uniquement dans les fonctions loop et setup, faites clignoter les DELs en continu selon les paramètres suivants : 
- 500ms actif
- 500ms inactif

### Exercice 1.2

En écrivant  votre code entièrement et uniquement dans les fonctions loop et setup, modifiez le code de la fonction précédente afin de faire clignoter les DELs en continu selon les paramètres suivants : 
- DEL 1 : 500ms actif, 500ms inactif
- DEL 2 : 500ms actif, 1000ms inactif
- DEL 3 : 1000ms actif, 500ms inactif

### Exercice 1.3

En écrivant  votre code entièrement et uniquement dans les fonctions loop et setup, modifiez le code de la fonction précédente afin de faire clignoter les DELs en continu selon les paramètres suivants : 
- DEL 1 : 500ms actif, 500ms inactif
- DEL 2 : 300ms actif, 850ms inactif
- DEL 3 : 700ms actif, 1000ms inactif

### Exercice 1.4

Modifiez le code de la question précédente afin d'utiliser des tasks pour faire clignoter les lumières. Créez 3 fonctions distinctes (une pour chaque task) qui s'occupe de faire clignoter une DEL en particulier.

### Exercice 1.5

Modifiez le code de la question précédente afin d'utiliser une seule fonction pour chacunes des 3 tasks.

**Pour y arriver :** 
- Créez une structure contenant un identifiant de GPIO, une durée actif et une durée inactif
- Créez une instance de cette structure pour chacune des DELs.
- Passez le pointeur vers cette instance comme user context à chaque task.

## Exercice 2

Connectez les composants suivants à votre ESP32 : 
- 2 DELs pour le clignotement.
- 3 DELs d'index
- 1 buzzer actif
- 1 bouton

Programmez 3 séquence de clignotement facilement distinguable pour vos DELs de clignotement.

Programmez aussi 3 séquences musicales de plusieurs notes de durée variable. Vos séquences musicales devraient être facilement distinguable.

Les DELs d'index servent à indiquer quelle séquence est en train de jouer : 
- Lorsque la première séquence est choisie, la première DEL est allumée.
- Lorsque la seconde séquence est choisie, la deuxième DEL est allumée.
- Lorsque la troisième séquence est choisie, la troisième DEL est allumée. 

Créez les tasks suivantes : 
- `led_ctrl_task` : Fait jouer en boucle la séquence de clignotement choisie.
- `buzzer_ctrl_task` : Fait jouer en boucle la contrôle la chanson jouer sur le buzzer selon la séquence choisie

Lorsqu'on appuie sur le bouton, la séquence choisie passe à la suivante en respectant les règles suivantes :
- Les DELs d'index sont mises à jour.
- Les DELs de clignotement s'éteigne.
- Le buzzer s'arrête.
- Suivante une pause de 1 seconde, la nouvelle séquence choisie commence à jouer.

Utilisez les outils de synchronization apropriés afin de garantir le bon fonctionnement de votre programme.




