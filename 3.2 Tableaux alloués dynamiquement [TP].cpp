#include<iostream>
#include<cmath>
#include<fstream>
#include<array>
#include<string>

using namespace std ;

// QUESTION 01 :
struct film{
  string titre ;
 string langue;
 string realisateur ;
 int duree;
 int annee;
};
struct ensemble{
    film* tab ;
    int n;
};
struct selection{
    film**f ;
    int n;
};
// QUESTION 02 :
void importer( ensemble &e, string filename ){
    ifstream fichier(filename);
    if(fichier){
        fichier>>e.n;
        fichier.ignore();
           e.tab = new film[e.n];    //allocation dynamique ;

        for(int i=0 ; i<e.n ; i++){

            getline(fichier,e.tab[i].titre);

            fichier>>e.tab[i].annee;
            fichier.ignore();

            getline(fichier,e.tab[i].realisateur);

            fichier>>e.tab[i].duree;
            fichier.ignore();

            getline(fichier,e.tab[i].langue);
        }

    }else{
        cout<<"fichier non-trouvé ! "<<endl;
    }
}
// QUESTION 03 :
void affiche( ensemble e, string filename){
    for(int i=0 ; i<e.n ; i++){
        cout<<e.tab[i].titre<<"( "<<e.tab[i].annee<<" , "<<e.tab[i].realisateur<<" , "<<e.tab[i].duree<<" min, "<<e.tab[i].langue<<" )"<<endl;
    }
}
// QUESTION 04 :
selection construit(ensemble e , string filename){
  selection s;
  s.n=e.n;
  s.f = new film*[s.n];
  for(int i=0 ; i<s.n ; i++){
      s.f[i] = &e.tab[i];
}
return s;
}
// QUESTION 05 :
selection filtrer(ensemble &e){
    selection s;
    string real;
    int amin , amax, dmin , dmax ;

    cout<<"realisateur( X pour tout):";
    cin>>real;

    cout<<"Anneé minimale et maximale :";
    cin>>amin>>amax;

    cout<<"Dureé minimale et maximale :";
    cin>>dmin>>dmax;

    s.f = new film*[e.n];
    s.n = 0;

    for(int i=0 ; i<e.n ; i++){

     bool condR = (real == "X" || e.tab[i].realisateur == real) ;
     bool condA = (e.tab[i].annee > amin && e.tab[i].annee < amax );
     bool condD = (e.tab[i].duree > dmin && e.tab[i].duree < dmax );
     if( condR && condA && condD ){
         s.f[s.n] = &e.tab[i];
         s.n++;
    }
    }
    return s;
}
// QUESTION 06 :
void affiche_selection(selection s){
    for(int i=0 ; i<s.n ; i++){
        cout<<s.f[i]->titre<<"( "<<s.f[i]->realisateur<<" , "<<s.f[i]->annee<<" )"<<endl;
    }
}
// QUESTION 07 :
void enregistrer( selection s, string filename){
    ofstream fichier(filename);
    fichier<<s.n<<endl;

    for(int i=0 ;  i<s.n ; i++){
        fichier<<s.f[i]->titre<<endl;
        fichier<<s.f[i]->annee<<endl;
        fichier<<s.f[i]->realisateur<<endl;
        fichier<<s.f[i]->duree<<endl;
        fichier<<s.f[i]->langue<<endl;

    }
}
// QUESTION 08 :
int communs(selection s1 , selection s2){
    int c=0;
    for(int i=0 ; i<s1.n ; i++){
        for(int j=0 ; j<s2.n ; j++){
            if(s1.f[i] == s2.f[i]){
              c++;
            }
        }
    }
    return c ;
}
// QUESTION 09 :
void trier(selection s){
    for(int i=0 ; i<s.n ; i++){
        for(int j=i+1 ; j<s.n ; j++){
          if(s.f[i]->annee > s.f[j]->annee){
              film* temp = 0;
              temp = s.f[i];
              s.f[i] = s.f[j];
              s.f[j] = temp ;
        }
        }
    }
}
int main(){
    string filename ="films.txt";
    ensemble e;
    selection s ,s1,s2;
    film f;

    importer(e,filename);
    affiche(e,filename);
    affiche_selection(s);
    enregistrer(s,filename);
    communs(s1,s2);
    trier(s);
    return 0;
}
