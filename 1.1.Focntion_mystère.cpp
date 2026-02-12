 #include<iostream>

 Détailler l’exécution du sous-programme suivant, pour une valeur de paramètre n = 4. Que calcule-t-il ? Le
prouver.
int c (int n)
{
if (n == 1) return 1 ;
else return c(n - 1) + 2 * (n - 1) + 1;
}

solution :

 n=4

 c(4) = c(3) + 2 * (3) + 1  = c(3) + 7
 c(3)= c(2) + 2 *(2) + 1  = c(2) + 5
 c(2)= c(1) + 2* (1) + 1  = c(1) + 3
 c(1)= c(0) + 2* (0) + 1 = 1

et là on monte :
 c(2)= 1+3
 c(3)=4+5
 c(4)=9+7=16

--> donc c'est la fonction carré
