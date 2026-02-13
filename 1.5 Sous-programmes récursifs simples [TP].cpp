#include<iostream>

using namespace std ;

// QUESTION 1 :

void affiche(int n){
    if(n==0){
        return ;
    }
    else{
        cout<<"bonjour "<<endl ;
        affiche(n-1);
    }
}

// QUESTION 2 :
int somme(int n ){
    if(n==0){
        return 0;
    }
    return n*n + somme(n-1);
}
int main(){
    affiche(2);
    cout<<somme(3)<<endl;
    return 0 ;
}
