#include <stdio.h>

void lireTaille(int *n,char *nom);
void remplirTableau(int *T, int n,char *nom);
void afficherTableau(int *T, int n,char *nom);
void concatenerTableaux(int *A, int *nA,int *B, int nB);

int main() {
    int A[100];  // Tableau A, peut contenir jusqu'a 100 elements
    int B[50];   // Tableau B, limite a 50 pour garder marge
    int N, M;    // Tailles des tableaux

    lireTaille(&N, "A");
    remplirTableau(A, N, "A");

    lireTaille(&M, "B");
    remplirTableau(B, M, "B");

    printf("\nTableau A initial :\n");
    afficherTableau(A, N, "A");

    printf("Tableau B :\n");
    afficherTableau(B, M, "B");

    // Ajout des elements de B a la fin de A
    concatenerTableaux(A, &N, B, M);

    printf("\nResultat apres concatenation\n");
    afficherTableau(A, N, "A (mis a jour)");

    return (0);
}

// Lire la taille d'un tableau (avec nom A ou B)
void lireTaille(int *n,char *nom) {
    do {
        printf("Entrez la taille du tableau %s (1 a 50) : ", nom);
        scanf("%d", n);
    } while (*n < 1 || *n > 50);
}

// Remplir un tableau avec saisie utilisateur
void remplirTableau(int *T, int n,char *nom) {
    for (int i = 0; i < n; i++) {
        printf("%s[%d] = ", nom, i);
        scanf("%d", &T[i]);
    }
}

// Afficher un tableau
void afficherTableau(int *T, int n,char *nom) 
{
    printf("Contenu du tableau %s : ", nom);
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", T[i]);
    }
    printf("\n");
}

// Concatener B a la fin de A (en modifiant la taille de A)
void concatenerTableaux(int *A, int *nA,int *B,int nB) 
{
    for (int i=0;i<nB;i++) 
    {
        A[*nA+i]=B[i];  
    }
    *nA=*nA+nB;  
}