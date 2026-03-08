#include<iostream>
#include<cmath>

using namespace std ;

// 1- Comprendre la mémoire :
 quand tu fais int a=5 :
 L’ordinateur :
  réserve une case mémoire
  met 5 dedans
  appelle cette case a

  On peut l imaginer comme des boites :
  Chaque boîte possède aussi une adresse (comme une adresse de maison):
  nom: a
  valeur: 5
  adresse 0x61FF08 ( àa depend de l oridinateur)

  on peut voir l adresse d une variable avec &
 // 2- exemple :

int main(){
   int a=5 ;
   cout<<"valeur de a : "<<a<<endl;
   cout<<"l'adresse de a :"<<&a<<endl;
    return 0;
}
// Qu'est ce qu'un pointeur :
Un pointeur est une variable qui stocke une adresse mémoire
variable normal -->stocke une valeur
pointeur -->stocke une adresse
// Déclarer un pointeur :
type *nom_pointeur;
exemple:
int *p;
Cela signifie --> p est un pointeur vers un entier
// Accéder à la valeur avec un pointeur :
L’opérateur * permet de lire la valeur pointée
int main(){

    int a = 10;
    int *p;

    p = &a;

    cout<<"a = "<<a<<endl;
    cout<<"*p = "<<*p<<endl;
    
//     Modifier une variable avec un pointeur :
    int main(){
        int *p ;
        int a=10 ;
       p = &a ;
        *p = 20;
        cout<<a<<endl;
        return 0;
    
    }
//   Exercice simple :
Écris un programme qui :

déclare une variable int x = 7
déclare un pointeur p
fait pointer p vers x
affiche :

valeur de x
adresse de x
valeur de p
valeur pointée par p

int main(){
    int x=7 ;
    int *p ;
    p = &x;

    cout<<"valeur de x : "<<x<<endl;
    cout<<"adresse de x : "<<&x<<endl;
    cout<<"valeur de p :"<<p<<endl;
    cout<<"valeur pointé par p "<<*p<<endl;
    return 0;

}
// Exercice 2 :
créer int a = 5
créer int *p = &a
changer la valeur de a avec le pointeur
afficher a

int main(){
    int a=5;
    int *p = &a;
    *p = 22;
    cout<<"a = "<<a<<endl;
    return 0;

}
// Pointeur dans les fonction :
void change(int *x){
    *x=100;
}
int main(){
    int a=2;
    change(&a);
    cout<<"a= "<<a<<endl;
    return 0;
}
// Exercice classique pour échanger deux variables :
void change( int *a , int *b){
    int temp = *a;
    *a = *b ;
    *b = temp ;
}
int main(){
    int x=2;
    int y=3;
    change(&x,&y);
    cout<<"x= "<<x<<endl<<"y= "<<y<<endl;
}
// // Exercice :
Écrire une fonction :

void doubleValeur(int *x)
qui multiplie une variable par 2.

void doubleValeur(int *x){
    *x *=2;
}
int main(){
    int a=2;
    doubleValeur(&a);
    cout<<"a = "<<a<<endl;
  return 0;
}
// Exercice :
Écrire une fonction :

void addition(int *a, int *b)
qui ajoute b à a.

void addition(int *a , int *b , int *c){
     *c = *a + *b ;
}
int main(){
    int x=2;
    int y=3;
    int c=0;
    addition(&x,&y,&c);
    cout<<" a+b = "<<c<<endl;

    return 0;

}

// L'allocation dynamique :
int a=5 ;
ci, la mémoire est créée automatiquement par le programme.
Mais parfois on veut créer de la mémoire pendant l’exécution.
Pour cela on utilise : new

int main(){

    int *p;
    p = new int;
    *p = 10;
    cout<<*p<<endl;
    delete p ;
    return 0;
}

Quand on utilise new, il faut libérer la mémoire
On utilise : delete

new --> delete ; sinon on vas créer une fuite mémoire(memory leak)

// Exercice 1 :
Écrire un programme qui :

crée un entier dynamique
met la valeur 50
affiche la valeur
libère la mémoire

int main(){
    int *p = new int ;
    *p = 50 ;
    cout<<*p<<endl;
    delete p;
    return 0;

}
// Exercice 2 :
Créer un tableau dynamique de 4 entiers

int main(){
    int *tab = new int[4];
    tab[0] = 2;
    tab[1] = 4;
    tab[2] = 6;
    tab[3] = 8;

    for(int i=0;i<4;i++){
        cout<<tab[i]<<endl;
    }
    delete [] tab;
    return 0;
}

// // Tableau et pointeur :
int *p = tab;
*p → valeur de tab[0]
*(p+1) → valeur de tab[1]
On peut créer un pointeur vers un tableau
int tab[3] = {10,20,30};
int *p = tab;
tab[0] = *p;
tab[1] = *p+1;
tab[2] = *p+2;
int main(){

    int tab[3] = {10,20,30};
    int *p = tab;

    cout<<*p<<endl;
    cout<<*(p+1)<<endl;
    cout<<*(p+2)<<endl;
    return 0;
}

 // Parcourir un tableau avec un pointeur :
int main(){

    int tab[4] = {2,4,6,8};
    int *p = tab;
    for(int i=0;i<4;i++){
      cout<<*(p+i)<<endl;
    }

}

// Passage d’un tableau à une fonction :
void afficher(int *tab,int n){

    for(int i=0;i<n;i++)
        cout<<tab[i]<<endl;

}
int main(){
    int tab[3] = {1,2,3};
    afficher(tab,3);
}
// exemple:
int tab[3] = {2,4,6};
int *p = tab;
p = p + 2;
cout<<*p<<endl;
// explication
resultat => 6
p = tab → pointe sur tab[0]
p = p + 2 → pointe sur tab[2]
*p → valeur de tab[2]

// Tableau dynamique + fonction :
void saisir( int *tab n , int n){
    for(int i=0 ; i < n ; i++){
        cin>>tab[i];
    }
}
void affiche(int *tab , int n){
    for(int i=0 ; i<n ; i++){
        cout<<tab[i]<<endl;
    }
}
int main(){
    int n=4;
   int *tab = new int[n];
   cout<<"saisir "<<n<<" valeurs "<<endl;
   saisir(tab,n);
   cout<<"Tableau : "<<endl;
   affiche(tab,n);

   delete []tab;
   return 0;
}

// Pointeurs et structures :
struct etudiant{
    string nom ;
    int age;
};
etudiant *p = new etudiant;
p->nom ="Alex";
p->age =20;

cout<<p->nom<<" "<<p->age<<endl;

p->nom  : équivalent à : (*p).nom;
p->age : équivalent à : (*p).age;

// Tableau de structures dynamique:
int n=3 ;
etudiant *tab = new etudiant[n];
tab[0].nom = "Ange"; tab[0].age = 20;
tab[1].nom = "Rose"; tab[1].age = 22;
tab[2].nom = "Alex"; tab[2].age = 21;

for(int i=0;i<n;i++)
    cout << tab[i].nom << " " << tab[i].age << endl;

delete[] tab;

// Exercice:
Créer un tableau dynamique de 5 entiers, stocker 2,4,6,8,10 et l’afficher.

int *tab = new tab[5];
for(int i=0 ; i<5 ; i++){
    tab[i]= (i+1)*2;
    for(int i=0 ; i<5 ; i++){
        cout<<tab[i]<<" ";
    }
    cout<<endl;
    delete [] tab;
}
// Exercice:
Créer un tableau dynamique de 3 étudiants, saisir leur nom et âge puis afficher.

Correction :
struct etudiant{
    string nom ;
    int age ;
};
etudiant *tab = new etudiant[3];
for(int i=0 ; i<3 ; i++){
    cout<<" nom : ";
    cin>>tab[i].nom;
    cout<<"age : ";
    cin>>tab[i].age;
}
for (int i=0 ; i<3 ; i++){
    cout<<tab[i].nom<<" "<<tab[i].age;
}

// Fonction avec tableau dynamique :
Créer une fonction qui calcule la somme d’un tableau dynamique d’entiers.

int somme(int *tab , int n){
    int s=0;
    for(int i=0 ; i< n ; i++){
        s += tab[i]
    }
    return s;
}
int main(){
    int n=4;
    int *tab = new [n]{2,4,5,6}.
    cout<<"somme = "<<somme(tab,n)<<endl;
    delete []tab;
    return 0;
}

// Fichiers avec pointeurs :
int main(){

    int *tab = new int[5];
    ofstream fichier("data.txt");
    for(int i=0;i<5;i++)
    {
        cin >> tab[i];
    }
    for(int i=0;i<5;i++)
    {
        fichier << tab[i] << endl;
    }
    fichier.close();
    delete[] tab;

}
// Lecture avec un fichier :
int main(){

    int *tab = new int[5];

    ifstream fichier("data.txt");

    for(int i=0;i<5;i++)
    {
        fichier >> tab[i];
    }

    for(int i=0;i<5;i++)
    {
        cout << tab[i] << " ";
    }

    fichier.close();

    delete[] tab;

}
// Exemple complet :
int main(){

    int *tab = new int[5];
    ofstream fichier("data.txt");
    for(int i=0;i<5;i++)
    {
        cin >> tab[i];
        fichier << tab[i] << endl;
    }
    fichier.close();
    ifstream fichier2("data.txt");
    for(int i=0;i<5;i++)
    {
        fichier2 >> tab[i];
    }
    for(int i=0;i<5;i++)
    {
        cout << tab[i] << " ";
    }
    fichier2.close();
    delete[] tab;

}

// Lire la structure depuis un fichier :
struct Etudiant
{
    string nom;
    int age;
};

int main(){
    Etudiant *e = new Etudiant;

    ifstream fichier("etudiant.txt");
    fichier >> e->nom;
    fichier >> e->age;

    cout << "Nom : " << e->nom << endl;
    cout << "Age : " << e->age << endl;
    fichier.close();
    delete e;

}

