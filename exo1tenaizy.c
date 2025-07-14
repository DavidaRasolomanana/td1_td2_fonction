#include <stdio.h>

void lireTaille(int *n);
void remplirTableau(int *T, int n);
void afficherTableau(int *T, int n);
int sommeTableau(int *T, int n);
void afficherSomme(int somme);

int main() 
{
    int T[50];      
    int N,somme;          

    lireTaille(&N);           
    remplirTableau(T, N);     
    afficherTableau(T, N);    
    somme=sommeTableau(T, N); 
    afficherSomme(somme);         

    return (0);
}

void lireTaille(int *n) 
{
    do 
    {
        printf("Entrez la taille du tableau (1 à 50) : ");
        scanf("%d",n);
    }
    while (*n<1 || *n>50);
}

void remplirTableau(int *T, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("T[%d] = ", i);
        scanf("%d", &T[i]);
    }
}

void afficherTableau(int *T, int n) 
{
    int i;
    printf("Contenu du tableau : ");
    for (i=0;i<n;i++) 
    {
        printf("%d ", T[i]);
    }
    printf("\n");
}

int sommeTableau(int *T, int n) 
{
    int i;
    int somme=0;
    for (i=0;i<n;i++) 
    {
        somme=somme+T[i];
    }
    return (somme);
}

void afficherSomme(int somme) 
{
    printf("La somme des éléments est : %d\n",somme);
}
