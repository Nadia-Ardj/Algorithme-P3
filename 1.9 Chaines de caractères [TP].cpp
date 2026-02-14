#include<iostream>
#include<string>

using namespace std ;

// QUESTION 1 :
 string sous_chaine( string chaine , int d , int l){
     if(l==0){
         return " ";
    }
    return chaine[d]+sous_chaine( chaine , d+1 , l-1);
}

// QUESTION 2 :
bool est_palindrome(string chaine , int d , int l){
    if( d>=l){
        return true;
    }

    if( chaine[d]!=chaine[l]){
        return false ;
    }
    return est_palindrome( chaine , d+1 , l-1);
}

// QUESTION 3 :
int compter( string chaine ,char c , int n , int i ){
    int cmpt=0 ;
    if(n==i){
        return 0;
    }
    if(chaine[i]==c){
        cmpt+=1;
    }
    return cmpt+ compter(chaine , c , n, i+1);
}

int main(){
    cout<<sous_chaine("BONJOUR" , 0 , 3)<<endl;
    cout<<est_palindrome("radar" , 0 , 4)<<endl;
    cout<<compter("machinnn" , 'n' , 7 , 0)<<endl;
    return 0;
}
