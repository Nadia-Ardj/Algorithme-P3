#include<iostream>
#include<cmath>
#include<array>

using namespace std ;
// QUESTION 01 :
struct point{
    int x ;
    int y ;
};
// QUESTION 02 :
bool confondus( point &p1 , point &p2){
    if(p1.x == p2.x && p1.y == p2.y){
        return true ;
    }else{
        return false ;
    }
}
// QUESTION 03 :
float distance( point &p1 , point &p2 ){
    float d ;
    d = ((p2.x - p1.x)*(p2.x - p1.x)) + ((p2.y - p1.y)*(p2.y - p1.y));
     return sqrt(d);
}
// QUESTION 04 :
point milieu( point p1 , point p2 ){
    point c ;
    c.x = (p1.x + p2.x )/2;
    c.y = (p1.y + p2.y )/2;

    return c;
}
// QUESTION 05 :
const int MAX = 100 ;
struct enspoints {
    int n ;
    array<point,MAX>tab;

};
// QUESTION 06 :
void saisie(enspoints &e){
    cout<<" saisie l'ensemble de point : ";
    cin>>e.n;

    for(int i=0 ; i < e.n ; i++){
        cout<<"Point "<<i+1<<" : " ;
        cin>>e.tab[i].x;
        cin>>e.tab[i].y;
    }
}
// QUESTION 07 :
void affichage(enspoints e){
    for(int i=0 ; i<e.n ; i++){
     cout<<"Point : ( "<<e.tab[i].x<<" , "<<e.tab[i].y<<")"<<endl;
    }
}
// QUESTION 08 :
point centre_gravite( enspoints e){
    point g ;
    float sx =0 , sy = 0 ;

   for(int i=0 ; i < e.n ; i++){
      sx += e.tab[i].x ;
      sy += e.tab[i].y ;
}
   g.x = sx / e.n ;
   g.y = sy / e.n ;

   return g ;
}
// QUESTION 09 :
point plus_proche( enspoints e ){
    point origine = {0,0} ;
    point p = e.tab[0];
    float dmin = distance (p , origine);

    for(int i=1 ; i< e.n ; i++){
        float d = distance(e.tab[i], origine );
        if(d < dmin ){
            dmin = d ;
            p = e.tab[i];
        }

    }
    return p ;
}
// QUESTION 10 :
float distmin( enspoints e ){
    float dmin = distance( e.tab[0] , e.tab[1]);
    for( int i=0 ; i < e.n ; i++){
       for(int j = i+1 ; j < e.n ; j++){
        float d = distance(e.tab[i] , e.tab[j]);
        if( d < dmin ){
            dmin = d ;
        }
        }
    }
    return dmin ;
}
// QUESTION 11 :
bool ordonne( enspoints e){
    for(int i=0 ; i < e.n ; i++){
        if( e.tab[i].x > e.tab[i+1].x){
            return false ;
        }
    }
    return true ;
}

int main (){
point p1 , p2 ;
enspoints e ;

cout<<"donner l'abssice et l'ordonne de chaque  point : ";
cin>>p1.x>>p1.y>>p2.x>>p2.y;

if(confondus(p1,p2)){
    cout<<"les points sont confondus ."<<endl;
}else{
    cout<<"les points ne sont pas confondus ."<<endl;
}

cout<<"la distance euclidienne entre ces deux point est : "<<distance(p1,p2)<<endl;
point m=milieu(p1 , p2);
cout<<"le milieu du segment entre ses deux points est : ("<<m.x<<" , "<<m.y<<")"<<endl;

saisie(e);
affichage(e);

point c = centre_gravite( e );
cout<<"le centre de gravité des points est : ("<<c.x <<" , "<<c.y<<" )"<<endl;

point P= plus_proche(e);
cout<<"le point le plus proche de l'origine est : ("<<P.x<<" , "<<P.y<<")"<<endl;

cout<<" la plus petite distance entre deux points de l'ensemble est : "<<distmin(e)<<endl;

if(ordonne(e)){
    cout<<"les points sont ordonnées selon leur abscisse . "<<endl;
}else{
    cout<<" les points ne sont pas ordonnées selon leur abscisse ."<<endl;
}
    return 0;
}
