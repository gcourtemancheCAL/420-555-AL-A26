# Exercices - Intro Python

## Exercice 1

Convertissez le programme java suivant en programme python : 

```java
import java.util.Scanner;
import java.lang.Math;

public class Racines {
    public static void main(String[] v) {
        Scanner clv = new Scanner(System.in);

        float a, b, c;
        double racine1, racine2, imaginaire;
        double discriminant;

        // Demander les entrées
        System.out.print("Entrez a : ");
        a = clv.nextFloat();

        System.out.print("Entrez b : ");
        b = clv.nextFloat();

        System.out.print("Entrez c : ");
        c = clv.nextFloat();

        // Calcul du discriminant
        discriminant = (b * b) - (4 * a * c);

        if (discriminant > 0) {
            racine1 = ((-b + Math.sqrt(discriminant)) / (2 * a));
            racine2 = (-b - Math.sqrt(discriminant)) / (2 * a);
            System.out.printf("Il existe deux racines réelles distinctes : %.3f et %.3f\n",
                              racine1, racine2);

        } else if (discriminant == 0) {
            racine1 = racine2 = -b / (2 * a);
            System.out.printf("Il existe deux racines réelles doubles : %.3f et %.3f\n",
                              racine1, racine2);

        } else if (discriminant < 0) {
            racine1 = racine2 = -b / (2 * a);
            imaginaire = Math.sqrt(-discriminant) / (2 * a);
            System.out.printf("Il existe deux racines complexes distinctes: %.3f + i(%.3f) et %.3f - i(%.3f)\n",
                              racine1, imaginaire, racine2, imaginaire);
        }

        // Fermeture de la ressource
        clv.close();
    }
}
```

## Exercice 2

### Exercice 2.1

Écrivez un script Python (moyenne.py) qui permet de calculer la moyenne de quatre notes entrées par l’utilisateur. Ne gérez pas les exceptions.

Utilisez la fonction input() pour demander les notes à l'utilisateur.

Ex: `note_1 = float(input("Entrez la note 1 (0 à 100) : "))`

**Exemple d’exécution :** 

<img src="img/Pasted image 20261007121331.png" width="400" />

### Exercice 2.2

Modifiez votre script afin de gérer l'exception lancée lorsque la valeur entrée par l'utilisateur n'est pas convertissable en float.

On va vouloir indiquez l'erreur à l'utilisateur et recommencer la lecture.

## Exercice 3

Écrivez un script python qui lit un fichier CSV au format suivant : `descriptif,quantite,prix unitaire`. Vous allez devoir : 
- Créez une classe représentant une entrée dans le fichier.
- Lire le fichier et transformer chaque ligne en nouvelle instance de votre classe.
- Ajouter chaque instance dans une liste.

Par la suite, imprimer à l'écran les informations suivantes : 
- Pour chaque entrée: `QUANTITExDESCRIPTIF@PRIX$  = TOTAL$` où
	- QUANTITE est la quantité
	- DESCRIPTIF est le descriptif
	- PRIX est le prix unitaire formaté à deux décimals suivant la virgule.
	- TOTAL est le produit de la quantite et du prix unitaire, formaté à deux décimals suivant la virgule.
- À la fin, séparée par une ligne de tirets, le prix total.

Le fichier CSV est passé en argument au programme.

Voici un exemple de fichier : 
```
Clavier mécanique,12,79.99
Souris sans fil,25,34.50
Écran 24 pouces,8,189.99
Câble HDMI,40,12.95
Disque SSD 1 To,15,94.99
Casque audio USB,18,49.95
Webcam HD,10,59.99
Clé USB 64 Go,35,14.50
Adaptateur USB-C,20,24.99
Tapis de souris,30,9.95
```
