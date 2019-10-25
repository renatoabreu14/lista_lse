#include <stdio.h>
#include <stdlib.h>

struct no{
    int valor;
    int *prox;
};

struct listaEnc{
    struct no *prim;
};

void criarLista(struct listaEnc *pList){
    pList->prim = NULL;
}

void mostrarLista(struct listaEnc pList){
    struct no *p;

    for(p = pList.prim; p != NULL; p = p->prox){
        printf("%d\t", p->valor);
    }
    printf("\n");
}

void insereIni(struct listaEnc *pList, int valor){
    struct no *novo;
    novo = (struct no*)malloc(sizeof(struct no));
    novo->valor = valor;
    novo->prox = pList->prim;
    pList->prim = novo;
}

void insereFim(struct listaEnc *pList, int valor){
    struct no *p;
    for(p = pList->prim; p->prox != NULL; p = p->prox);
    struct no *novo;
    novo = (struct no*)malloc(sizeof(struct no));
    novo->valor = valor;
    novo->prox = p->prox;
    p->prox = novo;
}

void removeIni(struct listaEnc *pList){
    struct no *pAux = pList->prim;
    pList->prim = pList->prim->prox;
    free(pAux);
}

void removeFim(struct listaEnc *pList){
    struct no *p;
    struct no *pAux;
    for(p = pList->prim; p != NULL; p = p->prox){
        pAux = p->prox;
        if (pAux->prox == NULL){
            p->prox = NULL;
            free(pAux);
        }
    }
}

int listaVazia(struct listaEnc pList){
    return (pList.prim == NULL);
}

int main() {
    struct listaEnc minhaLista;
    int valor, op;
    criarLista(&minhaLista);
    do{
        printf( "1 - Inserir elemento no inicio\n" );
        printf( "2 - Inserir elemento no fim\n" );
        printf( "3 - Inserir elemento em ordem (so se a lista estiver ordenada)\n" );
        printf( "4 - Remover elemento no inicio\n" );
        printf( "5 - Remover elemento no fim\n" );
        printf( "6 - Remover elemento\n" );
        printf( "7 - Mostrar lista\n" );
        printf( "8 - Numero de elementos na lista\n" );
        printf( "9 - Qual a posicao do elemento\n" );
        printf( "10 - Inserir apos o valor\n" );
        printf( "11 - Inserir antes do valor\n" );
        printf( "12 - Inverter lista\n" );
        printf( "13 - Sair\n" );
        printf( "Opcao? " );
        scanf( "%d", &op );
        switch (op){
            case 1:{
                printf("Informe o valor:");
                scanf("%d", &valor);
                insereIni(&minhaLista, valor);
                break;
            }
            case 2:{
                printf("Informe o valor:");
                scanf("%d", &valor);
                insereFim(&minhaLista, valor);
                break;
            }
            case 3:{
                break;
            }
            case 4:{
                removeIni(&minhaLista);
                break;
            }
            case 5:{
                removeFim(&minhaLista);
                break;
            }
            case 6:{
                break;
            }
            case 7:{
                if (listaVazia(minhaLista)){
                    printf("Lista vazia\n");
                }else{
                    mostrarLista(minhaLista);
                }
                break;
            }
            case 8:{
                printf("A lista contem $d elemento(s)", numerodeelementos(minhaLista));
                break;
            }
        }
    }while(op != 13);
}

//numero de elementos
//em qual posição o elemento se encontra sabendo que a primeira posição eh 0
//inserir após valor
//inserir antes valor
//inverter lista