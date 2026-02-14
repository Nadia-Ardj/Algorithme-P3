#include<iostream>
#include<string>
#include<array>


using namespace std ;
using tab=array<int,100>;


//  QUESTION 1 :

  void saisie_tableau( tab &t , int n ){
      if(n==0){
          return  ;
    }
    cout<<"entrer l element "<<n-1<<" : ";
    cin>>t[n-1];

    saisie_tableau(t,n-1);
}

//  QUESTION 2 :
 void affiche_tableau( tab &t , int n , int i ){
     if(i==n){
         return ;
    }
       cout<<t[i]<<" ";

    affiche_tableau(t, n , i+1);
}

// QUESTION 3 :
bool appartient(tab &t , int i ,int n , int val){
    if(i==n){
        return false ;
    }
    if(t[i]==val){
        return true ;
    }
    return appartient(t ,i+1 ,n,  val);
}

// QUESTION 4 :
 int recherche(tab &t , int n , int i , int val){
     if(i==n){
         return -1 ;
    }
    if(t[i]==val){
        return i ;
    }
    return recherche(t,n, i+1, val);
}

// QUESTION 5 :
bool contient_lettre( string mot , char c , int i ){
    if(i==mot.length()){
        return false ;
    }
    if( mot[i]==c){
        return true ;
    }
    return contient_lettre( mot , c , i+1);
}

int main(){
    tab t ;
    int n=5 ;

    saisie_tableau(t,5);
    cout<<" le tableau :  ";
    affiche_tableau(t,n,0);
    cout<<endl;
    cout<<appartient(t , 0 , n , 3)<<endl;
    cout<<"la position de cette valeur dans le tableau est : ";
    cout<<recherche(t , n , 0 , 3)<<endl;
    cout<<"mot et lettre : ";
    cout<<contient_lettre("bonjour" , 'n' , 2)<<endl;



    return 0 ;
}
