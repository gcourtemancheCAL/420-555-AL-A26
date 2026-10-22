# Exercices - Flask

## Exercice 1

Soit le circuit suivant :

<img src="img/ex1-page-1-image-02.png" width="300" />

Créez une page web qui sera hébergée localement sur un serveur web Flask. Une fois le serveur démarré :

```bash
python app.py
```

Votre page web donnera l’état courant de LED 17, soit l’un des deux cas suivants :

<img src="img/ex1-page-1-image-04.png" width="300" />

<img src="img/ex1-page-1-image-06.png" width="300" />

## Exercice 2 : contrôle d’une LED avec une page web

Sur votre Raspberry Pi, créez la structure de fichiers suivantes :

<img src="img/page-1-image-01.png" width="300" />

Le fichier app.py contiendra la logique de votre programme, index.html sera la seule page web de votre panneau de contrôle et style.css permettra de styliser votre page, par exemple pour la couleur. Sur votre Raspberry Pi, faites les branchements nécessaires pour une seule LED.

Au départ, votre page web aura cette allure :

<img src="img/page-1-image-03.png" width="500" />

Chaque clic sur le lien « Allumer la LED » ou « Éteindre la LED » aura pour conséquence d’allumer ou d’éteindre la LED sur votre platine et de conserver l’action dans un historique (vide au départ).  

Seules les trois dernières actions seront montrées dans l’historique. Voici quelques exemples : 

<img src="img/page-2-image-04.png" width="500" />

<img src="img/page-2-image-05.png" width="500" />

<img src="img/page-2-image-06.png" width="500" />

<img src="img/page-2-image-07.png" width="500" />

## Exercice 3 - Flask et les formulaires

Écrire une application Flask qui utilise un formulaire pour contrôler une LED à partir du texte saisi dans un champ de texte de la manière suivante :

Tout autre saisie que « on » ou « off » n’aura aucune conséquence.

<img src="img/ex2-page-1-image-02.png" width="500" />