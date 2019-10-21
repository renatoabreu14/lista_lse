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

void insereFim(){

}

void removeIni(struct listaEnc *pList){
    struct no *pAux = pList->prim;
    pList->prim = pList->prim->prox;
    free(pAux);
}

void removeFim(struct listaEnc *pList){
    struct no *p;
    for(p = pList->prim; p != NULL; p = p->prox){
        if (p->prox.prox == NULL)
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
        printf( "2 - Inserir elemento em ordem (so se a lista estiver ordenada)\n" );
        printf( "3 - Remover elemento no inicio\n" );
        printf( "4 - Remover elemento\n" );
        printf( "5 - Mostrar lista\n" );
        printf( "6 - Sair\n" );
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
                break;
            }
            case 3:{
                removeIni(&minhaLista);
                break;
            }
            case 4:{
                break;
            }
            case 5:{
                if (listaVazia(minhaLista)){
                    printf("Lista vazia\n");
                }else{
                    mostrarLista(minhaLista);
                }
                break;
            }
        }
    }while(op != 6);
}