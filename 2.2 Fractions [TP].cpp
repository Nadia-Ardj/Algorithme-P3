#include<iostream>
#include<cmath>

using namespace std ;
// QUESTION 01:
struct fraction{
    int den;
    int num;
};
// QUESTION 02:
void saisie( fraction &f){
    cin>>f.num>>f.den;
}
// QUESTION 03:
void affichage( fraction f){
    cout<<" fraction : "<<f.num<<" / "<<f.den<<endl;
}
// QUESTION 04:
fraction mult(fraction &f1 , fraction &f2){
    fraction c ;
    c.num = f1.num * f2.num ;
    c.den = f1.den * f2.den ;
    return c ;
}
// QUESTION 05 :
fraction add(fraction &f1 , fraction &f2 ){
    fraction d ;
    d.num = f1.num*f2.den + f2.num*f1.den ;
    d.den = f1.den*f2.den ;
    return d ;
}
// QUESTION 06 :
fraction opp( fraction &f1 ){
    fraction p ;
    p.num = -(f1.num);
    p.den = f1.den ;
    return p ;
}
fraction inv( fraction &f1){
    fraction in ;
    in.num = f1.den ;
    in.den = f1.num ;
    return in ;
}
// QUESTION 07 :
fraction soustr( fraction &f1 , fraction &f2 ){
    fraction s ;
    s.num =  f1.num*f2.den - f2.num*f1.den ;
    s.den = f1.num * f2.den ;
    return s ;
}
fraction div( fraction &f1 , fraction &f2 ){
    fraction d ;
    d.num = f1.num * f2.den ;
    d.den = f2.den * f2.num ;
    return d;
}
// QUESTION 08 :
int pgcd( int a , int b ){
    if(a<0){
        return (-a,b);
    }else if(b<0) return (a,-b);
    else if(a % b == 0) return b ;
    else return (b,a%b);

}
// QUESTION 09 :
fraction simpl(fraction &f  ){
    int p = pgcd(f.num , f.den);
    f.num = f.num / p ;
    f.den = f.den / p ;
    if(f.den < 0){
        f.num = -f.num ;
        f.den = -f.den ;
    }
    return f ;
}
int main(){
    fraction f , f1 , f2 ;

    cout<<"saisie la fraction : "<<endl;
    saisie(f1);
    saisie(f2);

    affichage(f1);
    affichage(f2);
fraction m = mult( f1 , f2);
    cout<<"la multiplication de deux fractions est : "<<m.num<<" / "<<m.den<<endl;
fraction a = add( f1 , f2);
    cout<<"l'addition des deux fractions est : "<<a.num<<" / "<<a.den<<endl;
fraction op = opp(f1);
    cout<<"l'opposeur de la fraction : "<<op.num <<" / "<< op.den <<endl ;
fraction in = inv(f1);
    cout<<"l'inverse de la fraction : "<<in.num << " / "<<in.den << endl;
fraction sous = soustr(f1, f2);
    cout<<"la soustraction des deux fractions :"<<sous.num<<" / "<<sous.den<<endl;
fraction divi = div(f1 , f2);
    cout<<"la division entre les deux fraction :"<<divi.num<<" / "<<divi.den<<endl;
cout<<"le pgcd est : "<<pgcd(5,10)<<endl;
    return 0 ;
}
