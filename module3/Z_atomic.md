# Types atomics

>[!warning] Optionel

[Référence](https://en.cppreference.com/cpp/atomic/atomic/exchange)

Les `atomic` sont des primitives de synchronization. Dans la plupart des cas (et probablement l'entièreté des cas qui vont vous intéresser), vous pouvez vous en sortir en utilisant des mtuex.

Les types atomiques vont garantir que les opérations sont effectuées de façon atomiques : 
- Les opérations vont être visibles dans tous les thread (gestion de cache CPU, prefetch de cache, branch prediction).
- Certaines optimisations du compilateur sont désactivées
- Fournit des opérations permettant de faire des combinaisons de READ et de WRITE atomiquement.

En C++, le type `atomic` est un wrapper `template`. Un peu comme les génériques en Java, il faut préciser le type sous jacent.

```
std::atomic<uint16_t> atomic_uint16;
std::atomic<uint32_t> atomic_uint32;
std::atomic<bool> atomic_bool;
std::atomic<char*> atomic_ptr; // Uniquement le pointeur, pas les donnéees
```

## Les opérations intéressantes

### exchange

Même si le type sous jacent est atomique, le code suivant n'est pas atomique : 

```c++
std::atomic<uint32_t> atom {...};

void fn() {
	int next = compute();
	
	int prev = atom.load();
	// un autre thread peut changer la valeur de atom ici
	atom.store(next);
	
	// ...
}
```

`exchange` permet de lire et d'écrire la valeur d'un seul coup : 

```c++
std::atomic<uint32_t> atom {...};

void fn() {
	int prev atom.exchange(compute());
	
	// ...
}

```


### compare_exchange_weak / compare_exchange_strong

Permet de changer une valeur si et seulement si elle est égale à valeur prédéterminée.

Si la valeur est égale à ce que l'on veut : 
- Change la valeur.
- Retourne true.

Sinon : 
- La valeur réelle est passée au caller via la référence à la valeur attendue.
- Retourne false.

Utilisée de façon imaginative, c'est un outil extrêmement puissant bien qui est à la base de plusieurs structures de données dites `lock-free`.

Exemple : ajouter un noeud à la fin d'une liste chaînée : 

```c++

void append_node( node* first, node* newnode )
{
	node* last_node = first;
	while( last_node->next.load(std::memory_order::relaxed) != nullptr )
	{
		last_node = last_node->next.load(std::memory_order::acquire);
	}
	
	node* expected {nullptr};
	while( !last_node->next.compare_exchange_strong(expected, newnode, std::memory_order::memory_order_rel) )
	{
		last_node = expected;
		expected = nullptr;
	}
}

```