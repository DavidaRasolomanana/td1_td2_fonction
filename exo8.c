#include <stdio.h>

void lireTaille(int *n);
void remplirTableau(int *T, int n);
void afficherTableau(int *T, int n);
void trouverMinMax(int *T, int n, int *min, int *posMin, int *max, int *posMax);
void afficherResultatMinMax(int min, int posMin, int max, int posMax);

int main() 
{
    int A[50];
    int N;
    int min, posMin, max, posMax;

    lireTaille(&N);
    remplirTableau(A, N);
    afficherTableau(A, N);

    trouverMinMax(A, N, &min, &posMin, &max, &posMax);
    afficherResultatMinMax(min, posMin, max, posMax);

    return (0);
}

void lireTaille(int *n) 
{
    do 
    {
        printf("Entrez la taille du tableau (1 a 50) : ");
        scanf("%d", n);
    } 
    while (*n<1 || *n>50);
}

void remplirTableau(int *T, int n) 
{
    int i;
    for (i=0;i<n;i++) 
    {
        printf("A[%d] = ", i);
        scanf("%d", &T[i]);
    }
}

void afficherTableau(int *T, int n) 
{
    int i;
    printf("\nContenu du tableau A : ");
    for (i=0;i<n;i++) 
    {
        printf("%d ", T[i]);
    }
    printf("\n");
}

void trouverMinMax(int *T, int n, int *min, int *posMin, int *max, int *posMax) 
{
    int i;
    *min = T[0];
    *max = T[0];
    *posMin = 0;
    *posMax = 0;
    
    for(i=1;i<n;i++) 
    {
        if (T[i]<*min) 
        {
            *min=T[i];
            *posMin=i;
        }
        if (T[i]>*max) 
        {
            *max=T[i];
            *posMax=i;
        }
    }
}

void afficherResultatMinMax(int min, int posMin, int max, int posMax) 
{
    printf("\nPlus petite valeur : %d a la position %d\n", min, posMin);
    printf("Plus grande valeur : %d a la position %d\n", max, posMax);
}
