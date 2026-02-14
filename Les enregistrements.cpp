#include<iostream>
#include<array>
#include<string>

using namespace std ;



Un enregistrement permet de regrouper plusieurs variables différentes dans une seule structure.

 Exemple :
Un étudiant a :

un nom
un âge
une moyenne

On peut regrouper tout ça dans une seule variable.

 // 1- Syntaxe de base:
struct Etudiant {
    string nom ;
    int age ;
    float moyenne ;
};
// déclarer une variable :

  Etudiant e1;

  //Acceder aux champs :  on utilise le point .

  e1.nom="ange";
  e1.age= 20 ;
  e1.moyenne=17 ;

  // affichage :

  cout<<e1.nom <<e1.age <<e1.moyenne <<endl;

  // un exemple très simple :

  struct Etudiant{
  string nom ;
  int age ;
  float moyenne ;
  };

  int main(){

  Etudiant e1 ;

  cout<<"le nom du l etidiant : ";
  cin>>e1.nom ;

  cout<<"son age : ";
  cin>> e1.age ;

  cout<<"sa moyenne ";
  cin>>e1.moyenne ;

  cout<<"\n------INFOS------\n";
  cout<<e1.nom <<" "<<e1.age << " "<<e1.moyenne<<endl;


     return 0 ;
  }


  // Tableau d'enregistements :
  Etudiant tab[3];

  tab[0].nom= "Sara";
  tab[1].age=22 ;

  // padder un struct à une fonction :
  //Exemple avec fonction :
  void afficher(Etudiant &e){
    cout<< e.nom << " " << e.age << " "<< e.moyenne <<endl ;
   }

   struct Rectange{
    float longeur ;
    float largeur ;


    float surface(){
    retun longeur * largeur  ;
    }
     };
    int main(){

    r.largeur = 4 ;
    r.longeur =5  ;
    cout<<r.surface();

    retun 0 ;
    }


    //des simples exercices :

    //Exercice 1 :
  Créer un struct Livre avec :
titre
auteur
prix
 Lire un livre et l’afficher.

 struct Livre{
 string titre ;
 string auteur;
 int prix ;
 };
 int main(){
 Livre L ;
  cin>>L.titre>>L.auteur>>L.prix
 cout<<L.titre<<L.auteur<<L.prix <<endl ;
 return 0 ;
 }

 //Exercice 2 :
 Créer un tableau de 5 étudiants.
Afficher celui qui a la meilleure moyenne.

struct Tableau{
string nom
float moyenne;
};
void affichage( Tableau &t){
cout<<t.nom ;
 }

 int main(){
 Tableau T[5] ;
 for( int i=0 ; i<5 ; i++){
 cin>> T[i].nom >>T[i].moyenne ;
 }
 for( int i=0 ; i<5 ; i++){
 int index_max = 0 ;
 if(T[i].moyenne>t[index_max].moyenne){
index_max=i;

 }
 }
 cout<<"l Etudiant : "<<tab[index_max].nom<<" a la meilleure moyenne "<<tab[index_max].moyenne <<endl;

 return 0 ;
 }

//  exercice 3 :

Créer un struct Date (jour, mois, année).
Écrire une fonction qui compare deux dates
et retourne la plus récente.


struct Date{
    int jour , mois;
    int annee ;
};
Date Date_la_plus_recente( Date d , Date d1){
    if( d1.annee>d.annee){
        return d1;
    }
    if(d1.annee<d.annee){
        return d ;
    }
    if(d1.annee == d.annee && d1.mois>d.mois ){
        return d1 ;

    }
    if(d1.annee == d.annee && d1.mois<d.mois ){
        return d;
    }
    if(d1.annee == d.annee && d1.mois == d.mois && d1.jour>d.jour){
        return d1 ;
    }
    return d ;
}
int main(){
    Date d = { 30 , 9 , 2006};
    Date d1 = { 14 , 2 , 2026};

    Date resultat = Date_la_plus_recente(d , d1);

    cout<<" la date la plus recente est : "<<resultat.jour <<"/ "<<resultat.mois<<"/ "<<resultat.annee<<endl;
    return 0 ;
}

// Exercice 4 :
Créer un struct CompteBancaire :
numero
solde
Écrire une fonction deposer et retirer.

struct CompteBancaire{
    int numero ;
    float solde ;
};

void deposer(CompteBancaire &cb , float montant){
 cb.solde += montant;
 cout <<cb.solde;
}
void retirer(CompteBancaire &cb , float montant){
    if(montant <= cb.solde){
       cb.solde-= montant ;
       cout<<cb.solde;
    }
    else{
        cout<<"solde insuffisant "<<endl;
    }
}

int main(){
    CompteBancaire cb ;
    cin>>cb.numero>>cb.solde;

    cout<<"le nouveau solde aprés le depot : ";
    deposer(cb , 500);
    cout<<"\nle nouveau solde apres le retrait :" ;
   retirer(cb, 200);

    cout<<"\nle solde final : "<<cb.solde <<endl ;
    return 0 ;
}
