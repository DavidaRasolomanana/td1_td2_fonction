#include <stdio.h>

void lireTaille(int *n);
void remplirTableau(int *T, int n);
void afficherTableau(int *T, int n);
int sommeTableau(int *T, int n);
void afficherSomme(int somme);
int trouverMax(int *T,int n);
int positionMax(int *T,int n);
void afficherMaxEtPosition(int max,int position);
void supprimerZeros(int *T, int *n);
void afficherTableauFinal(int *T, int n);
void extrairePosNeg(int *T, int n, int *TPOS, int *nPos, int *TNEG, int *nNeg);
void afficherTableauNegPos(int *T, int n,char *nom);
void inverserTableau(int *T, int n);
void afficherTableauinverse(int *T, int n);


int main() 
{
    int T[50];      
    int N,somme,max,pos;
    int TPOS[50];
    int TNEG[50];
    int nPos,nNeg;          

    lireTaille(&N);           
    remplirTableau(T, N);     
    afficherTableau(T, N);    
    somme=sommeTableau(T, N); 
    afficherSomme(somme);
    max=trouverMax(T, N);
    pos=positionMax(T, N);
    afficherMaxEtPosition(max, pos);
    supprimerZeros(T, &N);
    afficherTableauFinal(T, N);
    extrairePosNeg(T, N, TPOS, &nPos, TNEG, &nNeg);
    afficherTableauNegPos(TPOS, nPos, "TPOS");
    afficherTableauNegPos(TNEG, nNeg, "TNEG");
    inverserTableau(T, N);
    afficherTableauinverse(T,N);
         
    return (0);
}

void lireTaille(int *n) 
{
    do 
    {
        printf("Entrez la taille du tableau (1 a 50) : ");
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

int sommeTableau(int *T,int n) 
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
    printf("La somme des elements est : %d\n",somme);
}

int trouverMax(int *T,int n) 
{
    int max = T[0];
    int i;
    for (i=1;i<n;i++) 
    {
        if (T[i]>max) 
        {
            max=T[i];
        }
    }
    return (max);
}

int positionMax(int *T, int n) 
{
    int pos = 0;
    int i;
    for (i=1;i<n;i++) 
    {
        if (T[i]>T[pos]) 
        {
            pos=i;
        }
    }
    return (pos);
}

void afficherMaxEtPosition(int max, int position) 
{
    printf("La valeur maximale est : %d\n", max);
    printf("Elle se trouve a la position : %d\n", position);
}

void supprimerZeros(int *T, int *n) 
{
    int i;
    int j = 0;  
    for (i=0;i<*n;i++) 
    {
        if (T[i]!=0) 
        {
            T[j]=T[i];
            j++;
        }
    }
    *n = j;
}

void afficherTableauFinal(int *T, int n) 
{
    int i;
    printf("Tableau apres suppression des zeros : ");
    for (i=0;i<n;i++) 
    {
        printf("%d ", T[i]);
    }
    printf("\n");
}

void extrairePosNeg(int *T, int n, int *TPOS, int *nPos, int *TNEG, int *nNeg) 
{
    int i;
    *nPos = 0;
    *nNeg = 0;
    for (i=0;i<n;i++) 
    {
        if (T[i]>0) 
        {
            TPOS[*nPos]=T[i];
            (*nPos)++;
        } 
        else if (T[i]<0) 
        {
            TNEG[*nNeg]=T[i];
            (*nNeg)++;
        }
    }
}

void afficherTableauNegPos(int *T, int n,char *nom) 
{
    int i;
    printf("tableau %s : ",nom);
    for (i=0;i<n;i++) 
    {
        printf("%d ",T[i]);
    }
    printf("\n");
}

void inverserTableau(int *T, int n) 
{
    int i;
    int temp;
    for (i=0;i<n/2;i++) 
    {
        temp = T[i];
        T[i] = T[n - 1 - i];
        T[n - 1 - i]=temp;
    }
}

void afficherTableauinverse(int *T, int n) 
{
    int i;
    printf("tableau inverse : ");
    for (i=0;i<n;i++) 
    {
        printf("%d ",T[i]);
    }
    printf("\n");
}