# Formulaires avec Flask

## Déploiement en réseau local

---

## Rappel : formulaire HTML

```
<form method="post">
    Question: <input type="text" name="question">
    Réponse: <input type="text" name="reponse">
    <button type="submit">Soumettre</button>
</form>
```

---

## Permettons à l'usager d'ajouter une carte

### Vue Flask

```
@app.route("/ajoute_carte")
def ajoute_carte():
    return render_template("ajoute_carte.html")
```

### `ajoute_carte.html`

```
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>Ajoute une carte</title>
</head>
<body>
    <h1>Ajoute une nouvelle carte</h1>

    <form method="post">
        <p>
            Question:
            <input type="text" name="question">
        </p>
        <p>
            Réponse:
            <input type="text" name="reponse">
        </p>
        <button type="submit">Soumettre</button>
    </form>
</body>
</html>
```

Il faut coder un peu plus : **Flask gère GET par défaut, pas POST.**

> Rappel : GET est utilisé pour récupérer des données, tandis que POST  
> est utilisé pour envoyer des données au serveur.

---

## Traiter les requêtes POST

Pour permettre à une route de traiter les requêtes GET et POST :

```
@app.route("/ajoute_carte", methods=["GET", "POST"])
def ajoute_carte():
    if request.method == "POST":
        # Traiter la requête
        pass
    else:
        return render_template("ajoute_carte.html")
```

---

## Le code complet de `ajoute_carte`

```
@app.route("/ajoute_carte", methods=["GET", "POST"])
def ajoute_carte():
    if request.method == "POST":  # quand on envoi les données au serveur
        # request.form contient les données envoyées par le formulaire
        carte = {
            "question": request.form["question"],
            "reponse": request.form["reponse"]
        }

        db.append(carte)

        # ne change pas l'URL dans le Browser
        # return render_template(
        #     "carte.html",
        #     carte=carte,
        #     i=len(db)-1,
        #     max_index=len(db)-1
        # )

        # OU change l'URL dans le browser
        return redirect(url_for("vue_carte", index=len(db) - 1))

    elif request.method == "GET":  # quand on accède à la page
        return render_template("ajoute_carte.html")
```

### Déroulement illustré

1. L'utilisateur accède à `/ajoute_carte`.
2. Il entre, par exemple :
    - Question : `Chat`
    - Réponse : `Katze`
3. Il clique sur **Soumettre**.
4. La nouvelle carte est ajoutée à `db`.
5. L'application redirige vers la vue de la carte.
6. La page affiche :

```
Carte

Question: Chat
Réponse: Katze
```

7. En cliquant sur **Bienvenue**, l'utilisateur retourne à la page  principale, où la nouvelle carte apparaît dans la liste.

---
