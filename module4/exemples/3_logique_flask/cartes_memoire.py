from flask import Flask, request, redirect, url_for, render_template, abort
import json

def charge_db():
    with open("cartes_db.json") as f:
        return json.load(f)
    
db = charge_db()

app = Flask(__name__)

@app.route("/")
def bienvenue():
    return render_template("bienvenue.html", cartes = db)

@app.route("/carte/<int:index>")
def vue_carte(index):
    try:
        uneCarte = db[index]
        return render_template("carte.html", carte = uneCarte, i = index, max_index = len(db)-1)
    except IndexError:
        abort(404)



