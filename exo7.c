#include <stdio.h>

// Prototypes
void lireTaille(int *n);
void remplirVecteur(int *T, int n,char *nom);
void afficherVecteur(int *T, int n,char *nom);
int produitScalaire(int *U,int *V, int n);
void afficherVecteursEtProduit(int *U,int *V, int n, int ps);

int main() 
{
    int U[50], V[50];
    int N;
    int ps;

    lireTaille(&N);
    remplirVecteur(U, N, "U");
    remplirVecteur(V, N, "V");

    ps=produitScalaire(U, V, N);
    afficherVecteursEtProduit(U, V, N, ps);  

    return (0);
}

void lireTaille(int *n) 
{
    do 
    {
        printf("Entrez la dimension des vecteurs (1 à 50) : ");
        scanf("%d", n);
    } 
    while (*n < 1 || *n > 50);
}

void remplirVecteur(int *T, int n,char *nom) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("%s[%d] = ", nom, i);
        scanf("%d", &T[i]);
    }
}

void afficherVecteur(int *T, int n,char *nom) 
{
    int i;
    printf("Contenu du vecteur %s : ", nom);
    for (i=0;i<n;i++) 
    {
        printf("%d ", T[i]);
    }
    printf("\n");
}

int produitScalaire(int *U,int *V, int n) 
{
    int i;
    int ps = 0;
    for (i=0;i<n;i++) 
    {
        ps+=U[i]*V[i];
    }
    return (ps);
}

void afficherVecteursEtProduit(int *U,int *V, int n, int ps) 
{
    printf("\nVecteur U :\n");
    afficherVecteur(U, n, "U");

    printf("Vecteur V :\n");
    afficherVecteur(V, n, "V");

    printf("\nLe produit scalaire des deux vecteurs est : %d\n", ps);
}