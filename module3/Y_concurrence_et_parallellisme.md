# Concurrence, parallélisme et synchronization

## Concurrence

Un système dit _concurrent_ est un système dans lequel différentes tâches peuvent progresser au sein d'un même bloc temporel. 

Dans un système concurrent : 
- Un tâche A qui est bloqué ne va pas empêcher une tâche B indépendante de progresser.
- Sur une échelle de temps suffisament grande, les tâches A et B vont démontrer une progression.
- Sur une échelle de temps suffisament grande, la tâche B va progresser même si la tâche A n'est pas complétée
- Sur une échelle de temps suffisament grande, la tâche A va progresser même si la tâche B n'est pas complétée

Un système dit concurrent n'est pas forcémment parallèle : rien ne stipule que A et B doivent s'exécuter en même temps. Une forme de concurrence typique consiste à diviser le temps d'exécution des tâches en blocs temporels (timeslots). Les tâches se font assigner des timeslots en alternance. Ainsi, les tâches progressent en alternance sans progresser en même temps.

## Parallèlisme

Un système dit parallèle est en un système dans lequel les tâches s'exécutent en même temps. Les différents coeurs du processeur vont travailler sur des tâches en même temps. Un système parallèle est implicitement concurrent.

## Exemples

Le ESP8266 peut exécuter des tâches en **concurrence** à l'aide des interrupts. Par contre, n'ayant qu'un seul coeur de disponible, il n'est pas capable de **parallèlisme**.

Le ESP32 est capable d'exécuter des tâches en même temps sur ses deux coeurs. Le ESP32 est donc capable de **parallèlisme**. Par définition, il est donc aussi capable de **concurrence**.

Les [green threads](https://en.wikipedia.org/wiki/Green_thread) sont une alternatives _user spaces_ aux [threads](https://en.wikipedia.org/wiki/Thread_(computing)) utilisant un seul thread pour exécuter plusieurs tâche en concurrence. De par leur structure, les green threads ne sont pas capable de parallèlisme. _N.B. des exceptions existent._

## Synchronization

Lorsque plusieurs tâches concurrente peuvent modifier les mêmes données, des incohérences peuvent commencer à apparaitres. Ces situations sont appelées des race conditions.

L'exemple typiquement donné consiste au retrait d'argent d'un compte en banque.

```c++
// Retire de l'argent d'un compte et retourne si le solde etait suffisant.
bool withdraw( accnt_t *accnt, int amnt ) {
	if( accnt->total >= amnt ) 
	{
		int new_total = accnt->total - amnt;
		accnt->total = new_total;
		return true;
	}
	
	return false;
}

```

Si on prend pour acquis que plusieurs tâches peuvent effectuer des retraits concurrents, nous pourrions observer la situation suivante se produire : 

|Étape|Tâche A: retire $30|Tâche B: retire $20|
|---|---|---|
|1|total == **$100**||
|2||total == **$100**|
|3|new_total = $100 − $30 = **$70**||
|4||new_total = $100 − $20 = **$80**|
|5|total = **$70**||
|6||total = **$80**|

Dans cette situation, la tâche B n'a pas tenu compte du retrait en A pour calculer le total.

Les opérations de type Read-Write-Modify (RWM) sont des terreaux fertiles pour les race conditions. L'exemple précédent a éclaté les operations pour qu'on voit la totalité des étapes. Cependant, une opération simple peut en cacher plusieurs. Par exemple : `accnt->total -= amnt` produirait exactement les mêmes instructions que l'exemple précédent.

Plusieurs outils existent permettant de gérer ces cas de figure. Le plus commun est le mutex. Un mutex un cadenas mutuellement exclusif. C'est à dire qu'une seule tâche à la fois peut le barrer et que les autres tâches doivent attendre qu'il soit libre avant de l'utiliser.

```c++
// Retire de l'argent d'un compte et retourne si le solde etait suffisant.
bool withdraw( accnt_t *accnt, int amnt ) {
	bool success = false;
	
	// Le même mutex doit être utilisé pas les différentes tâches. 
	// Ici, chaque compte est synchronizé indépendemment des autres.
	// Si une autre tâche à déjà _lock_ le mutex, notre tâche va devoir attendre
	// qu'elle termine avant de continuer
	accnt->mutex.lock();
	
	// Arrivée ici, nous avons _lock_ le mutex.
	// Une seule tâche peut donc opérer sur le même compte à la fois.
	if( accnt->total >= amnt ) 
	{
		accnt->total -= amnt; // RWM
		success = true;
	}
	
	accnt->mutex.unlock();
	
	return success;
}

```

Utiliser directement les méthodes lock et unlock sur un mutex est fortement déconseillé puisque celà peut causer des problèmes innatendus.

```c++
// Retire de l'argent d'un compte et retourne si le solde etait suffisant.
bool withdraw( accnt_t *accnt, int amnt ) {

	accnt->mutex.lock();
	
	if( accnt->total >= amnt ) 
	{
		int new_total = accnt->total - amnt;
		accnt->total = new_total;
		return true;
		
		// On a return. On ne va donc jamais unlock le mutex.
		// Les autres tâche vont attendre pour toujours.
		// c'est un deadlock.
	}
	
	accnt->mutex.unlock();
	
	return false;
}

```

Nous allons donc préconiser l'utilisation de classes qui gère le mutex automatiquement pour nous.

```c++
// Retire de l'argent d'un compte et retourne si le solde etait suffisant.
bool withdraw( accnt_t *accnt, int amnt ) {
	// std::lock_guard est une classe.
	// lock est une variable de type lock_guard qui existe sur la stack de notre fonction
	// le constructeur de lock_guard appel lock sur le mutex automatiquement.
	std::lock_guard<std::mutex> lock {accnt->mutex}; 

	// Nous avons _lock_ le mutex à partir de ce point
	if( accnt->total >= amnt ) 
	{
		int new_total = accnt->total - amnt;
		accnt->total = new_total;
		return true;
	}
	
	return false;
}

// En quittant la fonction, peu importe où et comment, la variable lock est détruite.
// Le destructeur de lock_guard est invoqué 
```

