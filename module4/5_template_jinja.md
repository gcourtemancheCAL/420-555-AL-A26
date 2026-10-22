# Les templates Jinja

## Comprendre le patron « Model-Template-View » avec une BD

## Démo --- Les templates Jinja

- Afficher les données à l'utilisateur
- Générer le HTML
- Appel des templates à partir des vues
- Passer des données aux templates
- Les variables Jinja

---

## Templates HTML

Les templates HTML doivent se trouver dans le dossier `templates`.

### Structure du projet

```
cartes_memoire.py
│
├── static
│   └── flasklogo.png
│
├── templates
│   └── bienvenue.html
```

### `cartes_memoire.py`

```
from flask import Flask, render_template

app = Flask(__name__)

@app.route("/")
def bienvenue():
    return render_template("bienvenue.html")
```

### `bienvenue.html`

```
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>Bienvenue!</title>
</head>
<body>
    <h1>Bienvenue sur ma page!</h1>
    <p>
        Page de démonstration de Flask pour le cours 420-555.
    </p>
    <img src="/static/flasklogo.png">
</body>
</html>
```

---

## Passer une variable à une template

Le premier argument de `render_template` est le nom du fichier HTML.  
Suivent ensuite les variables à passer aux templates.

### Vue Flask

```
from flask import Flask, render_template

app = Flask(__name__)

@app.route("/")
def bienvenue():
    return render_template(
        "bienvenue.html",
        message="Voici un message de la vue."
    )
```

### Récupération des variables dans les templates

```
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>Bienvenue!</title>
</head>
<body>
    <h1>Bienvenue sur ma page!</h1>
    <p>
        Page de démonstration de Flask pour le cours 420-555.
    </p>
    <img src="/static/flasklogo.png">
    <p>
        {{message}}
    </p>
</body>
</html>
```

---

## Lire une BD

Le navigateur effectue une requête :

```
HTTP GET /carte
```

vers :

```
127.0.0.1:5000/carte
```

Le serveur récupère une carte dans la BD et la transmet au template :

```
def vue_carte():
    return render_template(
        "carte.html",
        carte=db[0]
    )
```

Le résultat présenté dans le navigateur est, par exemple :

```
Carte

Question: Bonjour

Réponse: Guten Tag
```

Le déroulement illustré est donc :

```
Navigateur
    |
    | HTTP GET /carte
    v
Serveur Flask
    |
    | lecture
    v
   BD
    |
    | données
    v
render_template("carte.html", carte=db[0])
    |
    v
Navigateur
```

---

## Lire une BD sous format JSON

**Note :**

En Python, pour accéder à une valeur d'un dictionnaire :

```
dict["clé"]
```

En Jinja, la notation suivante est possible :

```
dict.clé
```

### `cartes_memoire.py`

```
from flask import Flask, render_template
import json

def charge_db():
    with open("cartes_db.json") as f:
        return json.load(f)

db = charge_db()

app = Flask(__name__)

@app.route("/")
def bienvenue():
    return render_template(
        "bienvenue.html",
        message="Voici un message de la vue."
    )

@app.route("/carte")
def vue_carte():
    uneCarte = db[0]
    return render_template("carte.html", carte=uneCarte)
```

### `carte.html`

```
<head>
    <meta charset="UTF-8">
    <title>Cartes mémoires</title>
</head>
<body>
    <h1>Carte</h1>
    Question: {{carte.question}} <br>
    Réponse: {{carte.reponse}}
</body>
</html>
```

### `cartes_db.json`

```
[
    {
        "question": "Bonjour",
        "reponse": "Guten Tag"
    },
    {
        "question": "Au revoir",
        "reponse": "Auf Wiedersehen"
    },
    {
        "question": "Chien",
        "reponse": "Hund"
    },
    {
        "question": "Merci",
        "reponse": "Danke"
    }
]
```

Une fois chargé par `json.load`, le fichier JSON devient une structure  
Python équivalente à une liste de dictionnaires :

```
[
    {'question': 'Bonjour', 'reponse': 'Guten Tag'},
    {'question': 'Au revoir', 'reponse': 'Auf Wiedersehen'},
    {'question': 'Chien', 'reponse': 'Hund'},
    {'question': 'Merci', 'reponse': 'Danke'}
]
```

---

## Résultat

L'application Flask utilise donc les vues pour récupérer les données et  les transmettre aux templates Jinja, qui génèrent le HTML présenté dans  le navigateur.