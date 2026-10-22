from flask import Flask, request, redirect, url_for, render_template
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

@app.route("/ajoute_carte", methods = ["GET","POST"])
def ajoute_carte():
    if request.method == "POST": # quand on envoi les données au serveur
		# request.form contient les données envoyées par le formulaire
        carte = {"question":request.form['question'], 
                 "reponse":request.form['reponse']}
        db.append(carte)
		# ne change pas l'URL dans le Browser
        #return render_template("carte.html", carte = carte, i = len(db)-1, max_index = len(db)-1)
        # OU change l'URL dans le browser
        return redirect(url_for('vue_carte', index = len(db) - 1))
    elif request.method == "GET" : # quand on accède à la page
        return render_template("ajoute_carte.html")
if __name__ == '__main__':
    app.run(host = '127.0.0.1', port = 5000, debug = True)
