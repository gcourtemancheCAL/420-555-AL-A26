# Ajoutons de la logique à notre application

Comment communiquer dans le sens inverse d'une variable : **HTML vers  
Python**.

---

## Paramètres dans les URLs

Un paramètre peut être intégré directement dans une route Flask.

```
@app.route("/carte/<int:index>")
def vue_carte(index):
    uneCarte = db[index]
    return render_template("carte.html", carte=uneCarte)
```

`<int:x>` devra être associé à un entier dans l'URL.

Par exemple :

```
/carte/0
```

Dans ce cas, `x` sera égal à `0`.

Si l'URL ne contient pas d'entier : **erreur 404**.

Si on omet le mot-clé `int`, n'importe quelle chaîne de caractères fera  
l'affaire.

---

## Retourner une erreur pour une carte inexistante

On peut importer `abort` de Flask :

```
from flask import Flask, render_template, abort
```

Puis gérer une carte inexistante avec une exception :

```
@app.route("/carte/<int:index>")
def vue_carte(index):
    try:
        uneCarte = db[index]
        return render_template("carte.html", carte=uneCarte)
    except IndexError:
        abort(404)
```

---

## Pour éviter le hard-coding

Dans un template Jinja, `url_for()` permet de générer l'URL associée à  
une vue.

```
<a href="{{ url_for('bienvenue') }}">Accueil</a>
```

Avec un argument :

```
<a href="{{ url_for('vue_carte', i=3) }}">Carte 2</a>
```

`url_for()` retourne l'URL pour une vue.

- Le premier argument est le nom de la fonction.
- Les autres arguments seront passés à la vue.

---

## Naviguer à travers les cartes

### `cartes_memoire.py`

```
@app.route("/carte/<int:index>")
def vue_carte(index):
    try:
        uneCarte = db[index]
        return render_template("carte.html", carte=uneCarte, i=index)
    except IndexError:
        abort(404)
```

### Première version de `carte.html`

```
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>Cartes mémoires</title>
</head>
<body>
    <h1>Carte</h1>

    Question: {{carte.question}} <br>
    Réponse: {{carte.reponse}}

    <p>
        <a href="/">Bienvenue</a>
        <br>

        <button>
            <a href="/carte/{{i+1}}">
                Carte suivante
            </a>
        </button>
    </p>
</body>
</html>
```

### Mieux : moins de hard-coding

```
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>Cartes mémoires</title>
</head>
<body>
    <h1>Carte</h1>

    Question: {{carte.question}} <br>
    Réponse: {{carte.reponse}}

    <p>
        <a href="/">Bienvenue</a>
        <br>

        <button>
            <a href="{{url_for('vue_carte', index=i+1)}}">
                Carte suivante
            </a>
        </button>
    </p>
</body>
</html>
```

---

## Jinja : `if`

Syntaxe d'une condition Jinja :

```
{% if condition %}
    instructions
{% else %}
    instructions
{% endif %}
```

---

## Le problème de la dernière carte

Lorsqu'on arrive à la dernière carte, il faut éviter de créer un lien  
vers une carte inexistante.

### `carte.html`

```
<p>
    <a href="{{url_for('bienvenue')}}">Bienvenue</a>
    <br><br>

    <button>
        {% if i < max_index %} <!-- syntaxe jinja -->
            <a href="{{url_for('vue_carte', index=i+1)}}">Carte suivante</a>
        {% else %} <!-- syntaxe jinja -->
            <a href="{{url_for('vue_carte', index=0)}}">On recommence</a>
        {% endif %} <!-- ne pas oublier -->
    </button>
</p>
```

La vue doit également transmettre l'index maximal au template :

```
@app.route("/carte/<int:index>")
def vue_carte(index):
    try:
        uneCarte = db[index]
        return render_template(
            "carte.html",
            carte=uneCarte,
            i=index,
            max_index=len(db)-1
        )
    except IndexError:
        abort(404)
```

---

## Boucle Jinja `for`

Syntaxe générale :

```
<ul>
    {% for carte in cartes %}
        <li>
            <a href="{{ url_for(...) }}">
                {{ carte.question }}
            </a>
        </li>
    {% endfor %}
</ul>
```

---

## Une page d'accueil qui montre toutes les cartes

La vue `bienvenue` transmet toute la base de données au template :

```
@app.route("/")
def bienvenue():
    return render_template(
        "bienvenue.html",
        cartes=db
    )
```

Dans `bienvenue.html` :

```
<h2>Cartes mémoire</h2>

<ul>
    {% for carte in cartes %} <!-- cartes vient de cartes_memoire.py -->
        <li>
            <a href="{{url_for('vue_carte', index=loop.index0)}}">
                {{carte.question}}
            </a>
        </li>
    {% endfor %}
</ul>
```

`loop.index0` s'incrémente de 1 à chaque tour de boucle à partir de `0`.

Le résultat est une page d'accueil présentant les différentes cartes  
sous forme de liens, par exemple :

```
Cartes mémoire

• Bonjour
• Au revoir
• Chien
• Merci
```