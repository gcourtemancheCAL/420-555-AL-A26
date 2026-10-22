# cartes_memoire.py

from flask import Flask

app = Flask(__name__) # name est le nom du programme

@app.route("/") # ces 3 lignes sont une "view function"
def bienvenue():
	return "<h2>Bienvenue dans mon application!</h2>"

@app.route("/bonjour") # ces 3 lignes sont une "view function"
def bonjour():
	return "<h2>Bonjour!</h2>"

# Si vous voulez tout contrôler à partir de votre Python
# Il faut le démarrer en ligne de commande: $ python cartes_memoire.py
#if __name__ == '__main__':
    #app.run(debug = True, host = '127.0.0.1', port = 5000)



