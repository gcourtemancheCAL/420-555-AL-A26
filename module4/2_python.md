# Python 

Python est un langage interprété de haut niveau. 

## Syntaxe

```python
# Remarque : il n'y a pas de ; après les statements.
# On peut en mettre mais ce n'est pas pythonique.

# Listes
etudiants = ["Éric Électrique", "Diesel Jay", "Max Power", "Solomon Kane", "Conan le Bibliothécaire"]
notes = [82, 54, 91, 77, 44]

# Dictionaire - même principe qu'en javascript
cours = {
    "nom": "Objets Connectés",
    "prof": "Pepe Silva",
    "note_passage": 60
}

# Fonction
# Les tabulations sont importantes : elles indiquent les blocs
def resultat(note, cours):
    if note >= cours['note_passage']:
        return "CEO mindset"
    else:
        return "Automate de chair"


def moyenne(vs):
    total = 0

	# Boucle sur les valeur contenu dans une liste.
    for v in vs:
        total += v

	# Len : retourne la longueur d'une liste
    return total / len(vs)

print("Cours:", cours["nom"])
print("Prof:", cours["prof"])
# imprime rien - donc juste une ligne vide.
print()

# boucle sur range : range(n) retourne un itérateur allant de 0 à (n - 1)
# i va donc prendre les valeurs 0, 1, 2, 3, 4
for i in range(len(etudiants)):
    nom = etudiants[i]
    note = notes[i]

    print(nom, "-", note, "-", resultat(note, cours))

print()
print("Moyenne:", moyenne(notes))

```

## Environnement virtuel

Pour éviter les conflits de librairies, python utilise les environements virtuels afin d'isoler les dépendance d'un projet  des autres.

- Virtual Env
	- Création : `python -m venv <répertoire>`
	- Activate : `source <répertoire>/scripts/activate`
	- deactivate: `deactivate`

- PIP
	- Utilisation
	- `pip install`
	- `pip list`
	- `pip freeze`
	- `pip install -r requirements.txt`

