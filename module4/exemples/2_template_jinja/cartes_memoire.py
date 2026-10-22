# cartes_memoire.py
from flask import Flask, render_template
import json

def charge_db():
	with open("cartes_db.json") as f:
		return json.load(f)
		
db = charge_db() 

app = Flask(__name__) # name est le nom du programme

@app.route("/") # ces 3 lignes sont une "view function"
def bienvenue():
	return render_template("bienvenue.html", message = "Voici un message de la vue.")
	
@app.route("/carte") # ces 3 lignes sont une "view function"
def vue_carte():
	uneCarte = db[0]
	return render_template("carte.html", carte = uneCarte)



