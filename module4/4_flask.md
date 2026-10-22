# Flask

Flask est un **micro framework open-source de développement web en Python**.

On va l'utiliser pour créer un serveur web sur le RaspPi sur lequel une interface HTML contrôlera un circuit.

## Avantages

- **Simple et minimaliste**
    - Petite application dans un fichier `.py`
- **Flexible**
    - On choisit les composantes
- **Bien documenté**
- **Populaire**

## Installation

```
python -m pip install flask
```

ou :

```
pip install flask
```

Flask utilise notamment :

- **Werkzeug** : pour le HTTP
- **Jinja2** : pour les templates

## Une première application

La fonction `bienvenue()` est maintenant associée au répertoire racine  de l'application.

```
# cartes_memoire.py

from flask import Flask

app = Flask(__name__)  # __name__ est le nom du programme

@app.route("/")  # ces 3 lignes sont une "view function"
def bienvenue():
    return "<h2>Bienvenue dans mon application!</h2>"

# Si vous voulez tout contrôler à partir de votre Python
# Il faut le démarrer en ligne de commande :
# $ python cartes_memoire.py

# if __name__ == '__main__':
#     app.run(debug=True, host='127.0.0.1', port=5000)
```

### Exécuter l'application

```
export FLASK_APP=cartes_memoire.py
export FLASK_DEBUG=1
flask run
```

ou :

```
python -m flask run
```

Le serveur va être lancé sur le port 5000 par défaut.

## Déploiement en réseau local

Pour rendre votre site visible sur un réseau local :

```
flask run --host=0.0.0.0
```

Accessible à tous, mais bloqué par le CÉGEP selon les notes du cours.

Il est également possible d'utiliser directement l'adresse IP fournie  
par l'OS du Raspberry Pi :

```
flask run --host=192.168.16.1
```

À l'intérieur du réseau local, branchez-vous sur votre interface web  
avec l'adresse :

```
http://192.168.16.1:5000/
```

## Un ajout en mode développement

```
# cartes_memoire.py

from flask import Flask

app = Flask(__name__)

@app.route("/")  # ces 3 lignes sont une "view function"
def bienvenue():
    return "<h2>Bienvenue dans mon application!</h2>"

@app.route("/bonjour")  # le nom de la fonction peut != URL
def bonjour():
    return "<h2>Bonjour!</h2>"
```

**Notez la recharge automatique en mode DEBUG!**

La route `/bonjour` est alors accessible à l'adresse :

```
http://localhost:5000/bonjour
```

## Comment Flask associe les URLs aux « view functions »

L'application possède notamment les routes suivantes :

```
/static/<filename>  -> static
/                   -> bienvenue
/bonjour            -> bonjour
```

Flask associe donc chaque URL définie avec app.route(...) à une  fonction Python.

## Fichiers statiques

Sauvegardez l'image suivante au nom de `flasklogo.png` dans un dossier  appelé `static`.

<img src="img/Pasted image 20261007132605.png" width="600" />

Ce répertoire peut être utile pour :

- des images;
- du CSS;
- du JavaScript.

Avec votre serveur en marche, pointez votre navigateur vers :

```
http://localhost:5000/static/flasklogo.png
```

