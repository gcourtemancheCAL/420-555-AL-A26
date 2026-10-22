# Python 

Python est un langage interprété de haut niveau. 

## Syntaxe

```python
# Remarque : il n'y a pas de ; après les statements.
# On peut en mettre mais ce n'est pas pythonique.

# Variables
course_name = "Objets Connectés"
passing_grade = 60

# Listes
students = ["Éric Électrique", "Bob Morane", "Max Power", "Solomon Kane", "Conan le Bibliothécaire"]
grades = [82, 54, 91, 77, 95]

# Dictionaire - même principe qu'en javascript
course = {
    "name": course_name,
    "teacher": "John",
    "passing_grade": passing_grade
}

# Fonction
# Les tabulations sont importantes : elles indiquent les blocs
def get_result(grade):
    if grade >= passing_grade:
        return "Il passe, le champion"
    else:
        return "Il coule, le plouc"


def calculate_average(values):
    total = 0

	# Boucle sur les valeur contenu dans une liste.
    for value in values:
        total += value

	# Len : retourne la longueur d'une liste
    return total / len(values)

print("Course:", course["name"])
print("Teacher:", course["teacher"])
# imprime rien - donc juste une ligne vide.
print()

# boucle sur range : range(n) retourne un itérateur allant de 0 à (n - 1)
# i va donc prendre les valeurs 0, 1, 2, 3, 4
for i in range(len(students)):
    name = students[i]
    grade = grades[i]

    result = get_result(grade)

    print(name, "-", grade, "-", result)

average = calculate_average(grades)

print()
print("Moyenne:", average)
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

