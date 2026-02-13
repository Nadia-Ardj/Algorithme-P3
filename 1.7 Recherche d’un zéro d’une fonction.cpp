#include<iostream>

using namespace std ;


float f(float x ){
    return 4*x*(4*x*(3*x-1)-8)-1 ;
}

float dichotomie( float a , float b , float eps  ){

    float m = (a+b)/2;
    if(abs(b-a) <= 2*eps){
        return m ;
    }
    if(f(m) * f(eps)<0){
        return dichotomie( a , eps , m);
    }
    else{
        return dichotomie( m , b , eps);
    }


}
int main(){

    cout<<dichotomie(6 , 8 , 2 )<<endl;
    return 0 ;
}
