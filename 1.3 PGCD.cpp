#include<iostream>

using namespace std ;

int pgcd(int x, int y ){
    int x=abs(x);
    int y=abs(y);

    if(y==0){
        return x ;
    }
    if( x<y){
        return pgcd(y,x);
    }
    else{
        return pgcd(y,x%y);
    }
}
int main(){
    // cout<<pgcd(8,2)<<endl;
   int x , y ;
   cin>>x >>y ;
   cout<<"pgcd("<<x <<","<<y <<")"<<" est : "<<pgcd(x,y)<<endl;
    return 0;
}
