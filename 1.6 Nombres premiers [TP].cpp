#include<iostream>

using namespace std;

// QUESTION 1 /

int diviseur( int n , int d){
    if(n%(d+1)==0){
        return (d+1) ;                         // si d+1 divise n on affiche d+1 sinon on continue de chercher d+1
    }
    else{
         return diviseur(n, d+1);
    }


}

// QUESTION 2 :

bool est_premier(int n ){
    if(n <= 1){                       // si tous les nombre inferieur où égale à 1 ne sont pas premier ( il a dit  nombres strictement positifs)
        return false ;
    }
    return diviseur( n ,1) == n ;
}

// QUESTION 3 :
void affiche_premier( int n ){
    if(n<= 2){                   // 2 c'est le premier nombre premier
        return ;
    }
    affiche_premier(n-1);

    if (est_premier (n-1)){
        cout<<n-1 <<" ";
    }
}
int main(){
  cout<<diviseur(10,3)<<endl;
  cout<<est_premier(8)<<endl;
  affiche_premier(8);
  cout<<endl;
    return 0 ;
}
