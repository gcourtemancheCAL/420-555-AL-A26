## Question 1

### Question 1.1

Reproduisez le circuit suivant. Utilisez une résistance de 220Ω afin de limiter le courant qui passe à travers la DEL.

1. Fermer le circuit à l'aide de vos doigts. La DEL devrait s'allumer.
2. Si vous touchez les fils directement ensemble (la base du transistor et la connexion 5 volt), la DEL ne devrait pas s'allumer. Formulez une hypothèse expliquant ce comportement. **IMPORTANT** Ne gardez pas la base connecter trop longtemps directement à l'alimentation - cela pourrait briser le transistor.


<img src="img/Pasted image 20260820112029.png" width="500" />

### Question 1.2

Modifiez le circuit ainsi : 

<img src="img/Pasted image 20260901113437.png" width="500" />

La deuxième DEL devrait s'allumer lorsque vous appuyez sur le bouton. Votre hypothèse explique-t-elle aussi ce phénomène? 

### Question 1.3

Nous allons normalement vouloir utiliser une résistance pour le courant et la tension en B. Autrement, il devient très difficile de prévoir le comportement de notre transistor et nous pouvons tomber dans des situations dangereuses (qui pourraient endommager notre matériel).

Le circuit en 1.1 est correct parce que nous utilisons la résistance de notre corps pour limiter le courant en B.

<img src="img/Pasted image 20260902085144.png" width="600" />

Modifiez le circuit ainsi : 

<img src="img/Pasted image 20260902085937.png" width="500" />

Les deux DELs devraient maintenant s'allumer lorsque vous appuyez sur le bouton.

Sans résoudre le circuit dans son ensemble calculez : 
- Le courant maximal qui pourrait passer en R1
- Le courant maximal qui pourrait passer en R2

## Question 2

Le circuit suivant utilise un transistor NPN et une photorésistance afin de contrôler le volume et la fréquence d'un buzzer. 

<img src="img/Pasted image 20260820171329.png" width="500" />


En passant vos mains devant la photorésistance - et en créant ainsi de l'ombre - vous allez pouvoir contrôler la valeur de la résistance.

1. La valeur de la photorésistance monte elle ou descend elle avec la luminosité? Comment le valider?
2. Quel est le rôle du transistor dans ce circuit?
3. Si l'interrupteur est en position ouverte, est-ce que du courant passe par votre circuit?
4. Produisez sur KiCad un plan de circuit modifié qui pourrait garder sa charger "infiniment" lorsque l'interrupteur est ouvert. 