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

int numeroDeElementos(struct listaEnc pList){
    int cont = 0;
    struct no *p;
    for(p = pList.prim; p != NULL; p = p->prox){
        cont++;
    }
    return cont;
}

int posicaoDoElemento(struct listaEnc pList, int valor){
    int cont = 0;
    struct no *p;
    for(p = pList.prim; p != NULL; p = p->prox){
        if (p->valor == valor){
            return cont;
        }
        cont++;
    }
    return -1;
}

void insereAposValor(struct listaEnc *pList, int valor, int inserir){
    struct no *p;
    for(p = pList->prim; p != NULL; p = p->prox){
        if (p->valor == inserir){
            struct no *novo;
            novo = (struct no*)malloc(sizeof(struct no));
            novo->valor = valor;
            novo->prox = p->prox;
            p->prox = novo;
        }
    }
}

void insereAntesValor(struct listaEnc *pList, int valor, int inserir){
    struct no *p;
    struct no *pAux;
    for(p = pList->prim; p->prox != NULL; p = p->prox){
        pAux = p->prox;
        if (pAux->valor == inserir){
            struct no *novo;
            novo = (struct no*)malloc(sizeof(struct no));
            novo->valor = valor;
            novo->prox = pAux;
            p->prox = novo;
            p = p->prox;
        }
    }
}

void inverterLista(struct listaEnc *pList){
    struct no *p, *q, *r;
    if (pList->prim != NULL){
        if ((pList->prim)->prox != NULL){
            r = NULL;
            q=pList->prim;
            for (p=(pList->prim)->prox; p!= NULL; p=p->prox){
                q->prox = r;
                r=q;
                q=p;
            }
            q->prox = r;
            pList->prim = q;
        }
    }
}

int listaVazia(struct listaEnc pList){
    return (pList.prim == NULL);
}

void insereOrd(struct listaEnc *pList, int valor){
    struct no *novo, *p, *q;
    novo = (struct no*)malloc(sizeof(struct no));
    novo->valor = valor;
    novo->prox = NULL;

    if (pList->prim == NULL){
        pList->prim = novo;
    }
    else{	//Posicionando o ponteiro "p" na frente e o ponteiro "q" no elemento anterior (o novo elemento será inserido entre p e q)
        q = NULL;
        for (p=pList->prim; p!=NULL; p=p->prox){
            if (p->valor > valor)
                break;
            q = p;
        }
        if (q == NULL){
            // O novo elemento deve ser inserido no início da lista
            novo->prox = pList->prim;
            pList->prim = novo;
            return;
        }
        if (p == NULL){
            // O novo elemento deve ser inserido no fim da lista (após o ponteiro "q")
            q->prox = novo;
            return;
        }
        // Se o fluxo de execução chegou até aqui... então o elemento deve ser inserido entre p e q
        novo->prox = p;
        q->prox = novo;
    }

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
                printf("Informe o valor:");
                scanf("%d", &valor);
                insereOrd(&minhaLista, valor);
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
                printf("A lista contem %d elemento(s)\n", numeroDeElementos(minhaLista));
                break;
            }
            case 9:{
                printf("Informe o valor:");
                scanf("%d", &valor);
                int posicao = posicaoDoElemento(minhaLista, valor);
                if (posicao == -1){
                    printf("Valor não encontrado");
                }else{
                    printf("O elemento de valor %d esta na posicao %d\n", valor, posicao);
                }
                break;
            }
            case 10:{
                int inserir;
                printf("Informe o valor a ser inserido:");
                scanf("%d", &valor);
                printf("Deseja inserir apos o valor:");
                scanf("%d", &inserir);
                insereAposValor(&minhaLista, valor, inserir);
                break;
            }
            case 11:{
                int inserir;
                printf("Informe o valor a ser inserido:");
                scanf("%d", &valor);
                printf("Deseja inserir antes o valor:");
                scanf("%d", &inserir);
                insereAntesValor(&minhaLista, valor, inserir);
                break;
            }
            case 12:{
                inverterLista(&minhaLista);
                printf("A lista foi invertida\n");
                mostrarLista(minhaLista);
                break;
            }
        }

    }while(op != 13);
}

//numero de elementos
//em qual posição o elemento se encontra sabendo que a primeira posição eh 0
//inserir após um determinado valor
//inserir antes um determinado valor
//inverter lista