# Les lois de Kirchhoff

La résistance rencontré par le courant dans un circuit va causer une baisse de tension à chaque résistance. 
## La loi du voltage de Kirchhoff

La somme de toutes les augmentations et chutes de tension dans un circuit (une boucle fermée) est égale à zéro.

<img src="img/Pasted image 20260817133317.png" width="300" />

## La loi du courant de Kirchhoff

La quantité de courant qui entre dans une jonction est équivalente à la quantité de courant qui quitte la jonction 

<img src="img/Pasted image 20260817134149.png" width="300" />

La chute de tension à chaque résistance peut être calculée en combinant les principes des lois de Kirchhoff à la loi d'Ohm.

<img src="img/Pasted image 20260817133925.png" width="300" />

```
R_t = 10Ω + 5Ω = 15Ω
I = V/R = 5 / 15 = 0.33333
V_r1 = R1 * I = 10Ω x 0.33333 = 3.33333V
V_r2 = R2 * I = 5Ω * 0.33333 = 1.66667V
```

<img src="img/Pasted image 20260817142029.png" width="300" />

```
1/R = 1/R1 + 1/R2 = 1/10Ω + 1/5Ω = 1/10Ω + 2/10Ω = 3/10Ω
R = 3.33333Ω
I_1 = V/R = 5V / 3.33333Ω = 1.5A

I_r1 = V/R1 = 5V/10Ω = 0.5A
I_r2 = V/R2 = 5V/5Ω = 1A
I_2 = I_r1 + I_r2 = 1A + 0.5A = 1.5A
```

