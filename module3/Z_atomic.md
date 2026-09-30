std::atomic ftw.

-> optimisation compilateur
-> cpu prefetch and branch prediction

std::atomic 
	-> atomic
	-> sync


-> cas, exchange
-> store, load
	std::memory_order::acquire -> sur load, garanti "arrive après"
	std::memory_order::release -> sur store, garanti "arrive avant"
	std::memory_order::acq_rel -> combine acquire et relase. sur ops rw (e.g. CAS et exchange)


quelques exemples simple de synchro - aucune attente de compréhension ici.

le but c'est surtout de pouvoir modifier un flag ou qqch dans un isr et bien agir sur sa valeur apres.


scanner.exploding_head.gif

riky_oh.hilarious_exploding_head.gif.