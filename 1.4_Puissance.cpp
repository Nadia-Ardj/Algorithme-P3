#include<iostream>

using namespace std ;

// QUESTION 1 :
float puissance( float x , int n){

    if(n==0){
        return 1 ;
    }
    if(n<0){
        return 1/puissance(x,n-1);              //x^-n = 1/x^n
    }
    else {return x * puissance(x , n-1);}
}
// QUESTION 2 :
float puissance( float x , int n){

    if(n==0){
        return 1 ;
    }
    if(n%2==0){
        return puissance(x*x , (n/2));
    }
    else {
        return x *puissance(x*x , (n/2));
    }
}

int main(){
    int x,n ;
    cin >>x >>n ;
    cout<<puissance(x,n)<<endl;

    return 0;
}
