#include<iostream>

using namespace std;
bool estImpair(int n) ;
bool estPair(int n);

//  pour n>=0
bool estPair(int n ){

        if(n==0){
            return true ;
        }
        else{
            return estImpair(n-1);
}
}
bool estImpair(int n){

    if(n==0){
        return false ;
    }

    return estPair(n-1);
}

int main(){
    int n ;
    cout<<"entrer une valeur n :  ";
    cin>> n ;

        cout<<estPair(n)<<endl;
        cout<<estImpair(n)<<endl;


  return 0;
}


// pour n<0 :

bool estPair(int n ){
    if(n==0){
        return true ;
    }
    if(n<0){
        return estImpair(n+1);
}
return estImpair(n-1);
}

bool estImpair(int n){
    if(n==0){
        return false ;
    }
    if(n<0){
        return estPair(n+1);
    }
    return estPair(n-1);
}
int main(){
    int n ;
    cout<<" entrer une valeur : ";
    cin>> n ;

    if(estPair){
        cout<< "pair "<<endl ;
    }
    else{
        cout<<" impair "<<endl;
    }
    return 0;
}
