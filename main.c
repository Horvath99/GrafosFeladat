#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct SzListaa{
    int fokszam;
    int *pSzomszedok;
}Lista;
//int IranyitatlanSzMatrix(const char *, int ***, int *, int *);
//
//int IranyitottSzMatrix(const char *, int ***, int *, int *);
//
//void KiirMatrix(int **, int);
void KiirSzLista(Lista *,int);
Lista SzomLista(const char* ,Lista **,int *,int* );

int main() {
//    int **SzMatrix;
//    int cspont, elek;
//    FILE *bemenet1 = fopen("bemenet", "rt");
//    char vizsgalat[10];
//    fscanf(bemenet1, "%s", &vizsgalat);
//    if (strcmp(vizsgalat, "Iranyitatlan") == 0) {
//        IranyitatlanSzMatrix("bemenet", &SzMatrix, &cspont, &elek);
//    } else {
//        IranyitottSzMatrix("bemenet", &SzMatrix, &cspont, &elek);
//    }
//    KiirMatrix(SzMatrix, cspont);

    Lista *SzLista;
    int cspont,elek;
    SzomLista("bemenet",&SzLista,&cspont,&elek);
    KiirSzLista(SzLista,cspont);
}
Lista SzomLista(const char* fnev,Lista **ptomb,int *pCspont,int* pElek){
    FILE *bemenet = fopen(fnev, "rt");
    int x, y;
//    char vizsgalat[10];
//    fscanf(bemenet, "%s", &vizsgalat);
    fscanf(bemenet, "%d", &(*pElek));
    fscanf(bemenet, "%d", &(*pCspont));
    *ptomb = (Lista *) malloc((*pCspont) * sizeof(Lista));
    for(int i=0;i<(*pCspont);i++){
        (*ptomb)[i].pSzomszedok=(Lista*)malloc((*pElek)*sizeof(Lista));
        (*ptomb)[i].fokszam=0;
        for (int j = 0; j < (*pElek); j++) {
            (*ptomb)[i].pSzomszedok[j]=0;
        }
    }
    for (int i = 0; i < (*pElek); i++) {
        fscanf(bemenet, "%d%d", &x, &y);
        (*ptomb)[x-1].pSzomszedok[(*ptomb)[x-1].fokszam]=y;
        (*ptomb)[y-1].pSzomszedok[(*ptomb)[y-1].fokszam]=x;
        (*ptomb)[x-1].fokszam++;
        (*ptomb)[y-1].fokszam++;

    }

}
void KiirSzLista(Lista* tomb,int Cspont){
    for(int i=0;i<Cspont;i++){
        for(int j=0;j<tomb[i].fokszam;j++){
            printf("%d ",tomb[i].pSzomszedok[j]);
        }
        printf("\n");
    }
}
int IranyitatlanSzMatrix(const char *fnev, int ***ptomb, int *pCspont, int *pElek) {
    FILE *bemenet = fopen(fnev, "rt");
    int x, y;
    char vizsgalat[10];
    fscanf(bemenet, "%s", &vizsgalat);
    fscanf(bemenet, "%d", &(*pElek));
    fscanf(bemenet, "%d", &(*pCspont));
    *ptomb = (int **) malloc((*pCspont) * sizeof(int *));
    for (int i = 0; i < (*pCspont); i++) {
        (*ptomb)[i] = (int *) malloc((*pCspont) * sizeof(int));
        for (int j = 0; j < (*pCspont); j++) {
            (*ptomb)[i][j] = 0;
        }
    }
    for (int i = 0; i < (*pElek); i++) {
        fscanf(bemenet, "%d%d", &x, &y);
        (*ptomb)[x - 1][y - 1] = 1;
        (*ptomb)[y - 1][x - 1] = 1;

    }
}

int IranyitottSzMatrix(const char *fnev, int ***ptomb, int *pCspont, int *pElek) {
    FILE *bemenet = fopen(fnev, "rt");
    int x, y;
    char vizsgalat[10];
    fscanf(bemenet, "%s", &vizsgalat);
    fscanf(bemenet, "%d", &(*pElek));
    fscanf(bemenet, "%d", &(*pCspont));
    *ptomb = (int **) malloc((*pCspont) * sizeof(int *));
    for (int i = 0; i < (*pCspont); i++) {
        (*ptomb)[i] = (int *) malloc((*pCspont) * sizeof(int));
        for (int j = 0; j < (*pCspont); j++) {
            (*ptomb)[i][j] = 0;
        }
    }
    for (int i = 0; i < (*pElek); i++) {
        fscanf(bemenet, "%d%d", &x, &y);
        (*ptomb)[x - 1][y - 1] = 1;

    }

}

void KiirMatrix(int **tomb, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", tomb[i][j]);
        }
        printf("\n");
    }
}
