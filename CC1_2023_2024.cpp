#include<iostream>
#include<fstream>
#include<string>

using namespace std ;

// QUESTION 01 :
struct ingredient{
    string nom;
    float quantite;
};
struct stock{
    int nbi;
    ingredient* tab;
};
struct recette{
    string intitule;
    int portions;
    int nbi;
    ingredient* tab;
};
// QUESTION 02 :
bool initialise_stock(stock &s ,string filename ){
    ifstream fichier(filename);

    if(!fichier){
        return false ;
    }
    fichier>>s.nbi;

    s.tab = new ingredient[s.nbi];
    for(int i=0 ; i<s.nbi ; i++){
        fichier>>s.tab[i].quantite>>s.tab[i].nom ;
        }
    return true ;
}
// QUESTION 03 :
void affiche_etat_stock( stock s ){
    for(int i=0 ; i< s.nbi ; i++){
        cout<<s.tab[i].quantite<<" "<<s.tab[i].nom<<endl;
    }
}
// QUESTION 04 :
bool charger_recette(recette &r, string filename1){
    ifstream fichier(filename1);
    if(!fichier){
        return false;
    }
    getline(fichier,r.intitule);
    fichier>>r.portions>>r.nbi;
    r.tab = new ingredient[r.nbi];
    for(int i=0 ; i<r.nbi ; i++){
        fichier>>r.tab[i].quantite>>r.tab[i].nom;
    }
    return true ;

}
// QUESTION 05 :
bool ingredient_disponible( stock s , ingredient i){
    for(int j=0 ; j<s.nbi ; j++){
        if(s.tab[j].nom == i.nom){
            if(s.tab[j].quantite >= i.quantite){
                return true ;
            }else{
                    return false ;
                }
        }
    }
    return false;
}
// QUESTION 06 :
bool recette_disponible(stock s , recette r , int nbPortions){
    for(int i=0 ; i<r.nbi ; i++){
       ingredient besoin ;
       besoin.nom = r.tab[i].nom ;
       besoin.quantite = r.tab[i].quantite * nbPortions / r.portions ;

       if(!ingredient_disponible(s,besoin)){
           return false ;
    }
    }return true ;
}
// QUESTION 07 :
void mettre_a_jour_stock( stock &s , recette r , int nbPortions){
    for(int i=0 ; i<r.nbi ; i++){
        for(int j=0 ; j<s.nbi ; j++){
            if(s.tab[j].nom == r.tab[i].nom){
                float q = r.tab[i].quantite * nbPortions / r.portions ;
                s.tab[j].quantite -= q ;
            }
        }
    }
    cout<<"Stock aprés préparation : "<<endl;
    affiche_etat_stock(s);
}
int main(){
    string filename = "Stock.txt";
    string filename1 = "Donuts.txt";
    stock s;
    recette r ;
    recette Donuts;
    recette crepes ;

if(initialise_stock(s,filename)){
     cout<<"Stock disponible "<<endl;
  affiche_etat_stock(s);
}
cout<<"======================="<<endl;


if(charger_recette(r,filename1)){
    cout<<"Recette chargé "<<endl;
}
cout<<"======================"<<endl;
cout<<"Est-il possible de cuisiner 6 donuts ? ";
 bool test1 = recette_disponible(s,Donuts,6);
 cout<<test1<<endl;

 cout<<"====================="<<endl;
cout<<"Est-il possible de cuisiner 15 crépes ?";
bool test2 = recette_disponible(s,crepes,15);
cout<<test2<<endl;

cout<<"======================"<<endl;
if(test2){
mettre_a_jour_stock(s,crepes,15);
}

delete [] s.tab;
delete [] r.tab;
delete [] Donuts.tab;
delete [] crepes.tab;
    return 0;
}
