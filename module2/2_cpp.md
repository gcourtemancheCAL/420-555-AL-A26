# C++

## Syntaxe de base

### Types primitifs

- Virgule flottante : 
	- `float`
	- `double`
- Booléen
	- `bool`
	- `true` et `false`. 
- Les charactères
	- `char`
- Le bon vieux void
	- `void`

#### Les nombres entiers

Le type de base pour un nombre entier est le `int`.

Le `int` peut être modifié en taille : 
- `char` : 1 octet
- `short int` : 2 octets
- `int` : 4 octets
- `long int` : 4 octets
- `long long int` : 8 octets

Les `int` peuvent aussi êtres signés (par défaut) et non signés : 
- `signed`
- `unsigned`

Ce qui mène à des combinaisons du genre : 
- `unsigned int`
- `unsigned long long int`
- `signed char`
- `unsigned char`

##### Entiers de taille fixe

Avec `#include <cstdint>` :
- `std::int8_t`
- `std::int16_t`
- `std::int32_t`
- `std::int64_t`

Et les variantes non signés : 
- `std::uint8_t`
- `std::uint16_t`
- `std::uint32_t`
- `std::uint64_t`

### Les tableaux

```c++
	char array1[3] = {0}; // Tous les éléments sont init a 0
	int array2[16] = {}; // // Tous les éléments sont init a 0
	unsigned long long int array3[3] = {1,2,3}; // Le tableau contient 1,2,3
	array3[2]; // => 3	

	int* comme_un_pointeur = array2;
	array2[0] == comme_un_pointeur[0]; // Même affaire.
```

>[!warning] Important : Il n'y a pas de fonctions qui permettent de trouver la longueur d'un tableau. Il faut s'en souvenir. Get gud scrub. 

### Conditionnels et boucles

Sensiblement la même chose qu'en java : 

```c++

int i = 0;

if( true ) {
	// Yup. C'est ca qui est ca.
}
else if( i != 0 ) {
	// ...
}
else {
	// ...
}

for( int index = 0; i < 10; i++ ) {
	// On boucle de 0 a 9
} 

while( condition ) {
	//...
}
```


### Fonctions

```c++

// Sensiblement comme d'autres langages
int ma_fonction(int arg1, int arg2) {
	return arg1 + arg2;
}
```

>[!warning] Les fonctions doivent avoir été déclarées avant leur utilisation.

```c++

void a() {
}

void b() {
	a(); // tout est beau
	c(); // nu-uh! illegal
}

void c() {
	//...
}

// On peut declarer les fonctions d'avance : 
void d();

void e() {
	d();
}

void d() {
	// ...
}

```

### Objets et classes

```c++

void exemple()
{
	// La string suivante est instancie sur la stack.
	// Sa duree de vie est limite au block dans lequel elle est cree.
	// i.e. dans ce cas, str1 meurt a la sortie de la fonction
	//
	// Entre les { ... } nous avons les arguments pour le constructeurs de la 
	// string.
	std::string str1 { "le texte de ma string" };
	
	// On invoque les methodes sur la string comme on s'y attend.
	str1.size() == 21;
}
```

Attention à `new` : 

```c++
void exemple2()
{
	// new cree l'object sur le heap. la string va continuer a exister 
	// apres avoir quitter la fonction mais elle risque de ne plus etre 
	// accessible.
	std::string *str = new std::string {"le texte de ma string"};
	
	// On utilise la notation en fleche pour appeler une fonction via un 
	// pointeur.
	str->size() == 21;
	
	// On n'oublie pas de supprimer les pointeurs apres en avoir termine.
	delete str;
	str = nullptr;
}
```

## Pointeurs

[Plus d'info](https://web.maths.unsw.edu.au/~lafaye/CCM/cpp/cpppoint.htm)


## Heap et stack

Limite stack : environ 4Kio.
Limite DRAM : environ 50-80Kio.
Limite IRAM : environ 64Kio.
