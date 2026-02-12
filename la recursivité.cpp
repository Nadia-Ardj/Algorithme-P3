#include<iostream>

using namespace std ; 
using tab=array<int,n>;

// la recursivité : 
c est une fonction qui s appelle elle-meme pour se resoudre ;
mais à un moment il faut qu elle s arrete  , donc elle a deux cas : 
1- un appel d arret 
2- un appel recursif 
// exemple :
 int fact(){
    int n ; 
    if (n==0)
    {
      return 1;// appel d arret
    }
    return n * fact(n-1);  // appel recursif 
    
 } 
 // expl --> fact(4) :
 = 4 * fact(3)
 = 4 * (3 * fact(2))
 = 4 * (3 * (2 * fact(1)))
= 4 *( 3 * 2 * (1 * fact(0)))    // on est arrive au cas d arret donc , la fonction vas arreter 
= 4*3*2*1 = 24 ;
 
//  Quand utiliser la récursivité ?

Quand :
le problème se décompose naturellement
la solution est plus simple à comprendre
// Exemples :
factorielle
puissance
somme d un tableau
minimum d un tableau
recherche dichotomique
//  eviter la recursivite 
quand il y a bcp d appel 

//  recursif et interatif
// interatif                             // recusif 
int n=0 ;                               int somme(tab t , int n ){
for (int i = 0; i < n; i++)             if (n==1)
{                                          {
    s += tab[i] ;                            return tab[0];
}                                          }
cout<< s ;                               return somme(t, n-1) + tab[n-1]; 
                                        }
            

//   Exemple :  min tableau 
int minimum(tab t , int n ){
    if (n==1)
    {
        return t[0];
    }
    int m =minimum(t,n-1);
    if (m<t[n-1])
    {
        return m ;
    }
    else{
        return t[n-1] ; 
    }
    
}
// exemple 

bool recherche(int v , int d, tab t , int f ){
    if (v==0)
    {
        return 1;
    }
    else
    {
        int m = (d + f) / 2 ;
        if (t[m] == v)
        {
           return true ; 
        }
        else if (t[m] < v )
        {
            return recherche( v , t ,d , m-1 );
        }
        return recherche( v ,t, m+1 , f )
       
        
    }
        
}
// fonction recursive qui calcule la somme 1+2+3+.....+n 

int somme(int n){
    if (n==1)
    {
        return 1;
    }
    else
    {
        return n + somme(n-1); 
    }
    
}
// Calculer xⁿ récursivement (n ≥ 0) : 
int puissance(int n , int x){
    if (n=0)
    {
        return 1;
    }
    else
    {
        return x * puissance(n-1,x);
    }
    
}
// Écrire une fonction récursive qui retourne le nombre d’éléments d’un tableau :
int taille( tab t , int n ){
    if (n=0)
    {
        return 0;
    }
    else
    {
        return 1 + taille(n-1);
    }
    
}
// Écrire une fonction récursive qui retourne le maximum d’un tableau d’entiers :
int maximum(tab t , int n ){
    if (n=1)
    {
        return t[0];
    } 
    else
    {
        int m = maximum(t,n-1);
      if (m < t[n-1])
      {
       return t[n-1];
      }
      return m ;
    }
    
}
// Écrire une fonction récursive qui détermine si n est pair :
bool estPair(int n){
    if (n==0)
    {
        return true;
    }
    if (n==1)
    {
      return false
    }
    else
    {
        return estPair(n-2);
    }  
}
// Afficher les éléments d’un tableau à l’envers sans boucle : 
void affiche_envers(tab t , int n ){
    if (n==1)
    {
        return;
    }
    else
    {   
        cout<<t[n-1];
        affiche_envers(t,n-1);
    }
    
    
}
// Écrire une fonction récursive qui vérifie si une valeur est présente dans un tableau trié : une recherche dichotomique : 
bool verifier(tab t , int v , int d , int f){
    if (d<f)
    {
       return true ;
    }
    int m = (d+f)/2 ;   
    if (t[m]> v )
    {
      return verifier( t, v, m+1, f); 
    }
    else
    {
        return verifier(t,v , d , m-1) ;
    }
    
}
// pour pouvoir utiliser la dichotomie il faut repondre à ces questions par oui :
Je cherche UNE valeur précise 
 Le tableau est trié ?
 Est-ce que je peux éliminer la moitié du tableau ?


