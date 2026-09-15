
## Exercice 1

Pour cet exercice, nous allons nous faire une classe utilitaire permettant de facilement gérer le debouncing pour nos futures projets.

Dans votre sketch, commencez par inclure le fichier `FunctionalInterrupt` - il vient surcharger la méthode attachInterrupt de sorte à ce qu'on puisse lui passer une lambda en paramètre (et non juste un pointeur de fonction).

```arduino
#include <FunctionalInterrupt.h>
```

Écrivez une classe "DebouncedInput" qui respecte l'interface suivante : 

```
class DebouncedInput {
public:
	DebouncedInput(int pin, bool pullup = false, int debouncingTimerMs = 10);
	~DebouncedInput();
	
	// Retourne la valeur debouncé du GPIO. 
	bool read();
	// Retourne la valeur sans debouncing du GPIO. 
	bool readRaw();
	
	// Appelé par l'ISR pour mettre à jour l'état de la broche.
	void IRAM_ATTR tick();
	
	// Ces fonctions sont supprimées - elles ne sont donc pas à implémenter
	DebouncedInput(const DebouncedInput&) = delete;
	DebouncedInput(DebouncedInput&&) = delete;
	DebouncedInput& operator=(const DebouncedInput&) = delete;
	DebouncedInput& operator=(DebouncedInput&&) = delete;
	
private:
	// À vous de déterminez les variables à utiliser!
}
```

Dans le constructeur de votre classe, vous allez vouloir attaché un interrupt sur votre GPIO à l'aide d'une lambda : 

```arduino
attachInterrupt(digitalPinToInterrupt(pin), [this]() IRAM_ATTR { 
	this->tick();
}, mode);
```

À vous de compléter le reste :
- Choisissez le bon mode pour l'interrupt
- Assurez-vous de détacher l'interrupt dans le destructeur.
- Déterminez la logique et les variables requises pour faire fonctionner la classe.
- Testez!
	- Testez avec un bouton. 
		- Validez dans une boucle la valeur débouncé vs la valeur telle quelle.
	- Testez avec deux boutons. Vous devriez pouvoir créer plusieurs instances de votre classe sans problème.

## Exercice 2

Reprenez l'exercice <a href="2_ex_io.md#exercice-2">2_ex_io::exercice 2</a>. Cette fois-ci, utilisez votre classe de DebouncedInput. 

## Exercice 

L'image suivante présente une tentative de circuit de debouncing : 

<img src="img/Pasted image 20260915112547.png" width="500" />

Outre le manque d'hystérésis, ce circuit n'accompli pas entièrement sa fonction. Identifions pourquoi à l'aide des mathématiques.

<img src="img/Pasted image 20260915115250.png" width="500" />

**En présumant une tension à la source de 3.3V :**
- Calculez la tension en A avant que l'on appuie sur le bouton.
- Calculez la tension en A lorsque nous appuyons sur le bouton et que le capaciteur est entièrement déchargé.
- Calculez la tension en A lorsque nous appuyons sur le bouton et que le capaciteur est entièrement chargé.
- Calculez la tension en A lorsque nous relâchons le bouton. Prenons pour acquis que le capaciteur va fournir 3.3V de tension. 

**Suivant les calculs réalisés :**
- Est-ce que le capaciteur aura un impact sur le bounce lorsque nous appuyons sur le bouton?
- Est-ce que le capaciteur aura un impact sur le bounce lorsque nous relâchons le bouton?





