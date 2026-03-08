#include<iostream>
#include<cmath>
#include<string>
#include<array>

using namespace std ;

// QUESTION 01 :
struct lecteur{
    string nom ;
    string prenom ;
    int numero;
};
// QUESTION 02 :
void saisie( lecteur &l){
    cin>>l.nom;
    cin>>l.prenom;
    cin>>l.numero;
}
// QUESTION 03 :
void affiche(lecteur l){
    cout<<"Nom : "<<l.nom<<"\nPrenom : "<<l.prenom<<"\nNuméro : "<<l.numero<<endl;
}
// QUESTION 04 :
const int MAX=100;
struct enslecteurs{
    int n ;
    array<lecteur,MAX>tab;
};
// QUESTION 05 :
void initialise( enslecteurs &e){
   e.n=0;
}
// QUESTION 06 :
void ajoute(enslecteurs &e , lecteur &l){
    if(e.n < MAX){
        e.tab[e.n]=l;
        e.n++;
    }
}
// QUESTION 07 :
void saisie_tous( enslecteurs &e ){
    cout<<"saisie le nombre de lecteurs : ";
    cin>>e.n;
    if(e.n > MAX){
        e.n = MAX ;
    }
    for(int i=0 ; i<e.n ; i++){
        cout<<"Lecteur "<<i+1<<endl;
        saisie(e.tab[i]);
    }
}
// QUESTION 08 :
void affiche_tous(enslecteurs &e){
    for(int i=0 ; i<e.n ; i++){
        cout<<"Lecteur "<<i+1<<": "<<endl;
        affiche(e.tab[i]);
        cout<<endl;
    }
}
// QUESTION 10 :
string recherche_Nom(enslecteurs e , int num){
    for(int i=0 ; i<e.n ; i++){
      if( e.tab[i].numero == num){
          return e.tab[i].nom ;
    }
    }
    return "Lecteur Non-Trouve ";
}
// QUESTION 11 :
struct livre{
   string ISBN ;
   string titre ;
   string auteur;
   bool emprunte ;
   int numlecteur ;
};
struct enslivres{
    array<livre,MAX>tab;
    int n ;
};
struct biblio{
  enslivres LIVRES;
  enslecteurs LECTEURS;
};
// QUESTION 12 /
void affiche_emprunts( biblio &b ){
    for(int i=0 ; i<b.LIVRES.n ; i++){
        if(b.LIVRES.tab[i].emprunte ){
            cout<<"Livre : "<<b.LIVRES.tab[i].titre<<endl;
            int num = b.LIVRES.tab[i].numlecteur;
            cout<<"Emprunté par : "<<recherche_Nom(b.LECTEURS,num)<<endl;
        }
    }

}
int main(){
 lecteur l;
 enslecteurs e ;
 biblio b;

 cout<<"saisie les informations du lecteur : ";
 saisie(l);
 cout<<"--INFOS LECTEUR--"<<endl;
 affiche(l);
 saisie_tous(e);
 cout<<"--L'ENSEMBLE DES LECTEURS-- "<<endl;
 affiche_tous(e);
 cout<<"Le lecteur avec le numero demandé est :"<< recherche_Nom(e,27)<<endl;
//  mettre les lecteurs dans bibliothèque :
 b.LECTEURS = e;
//  initialiser les livres :
 b.LIVRES.n = 0;
//  afficher les emprunts :
 cout<<"--EMRUNTS EN COURS--"<<endl;
 affiche_emprunts(b);

    return 0;
}
