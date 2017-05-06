#include <stdio.h>
#include <stdlib.h>

/*INSERE INICIO*/

struct lista{
 	int n;
 	struct lista* prox;
};

typedef struct lista Lista;

Lista* inicializar (void){
	return NULL;
}

Lista* inserir (Lista* l, int i){ /*insere no inicio*/
	Lista* novo = (Lista*) malloc (sizeof(Lista)); /*NOVO É A NOVA STRUCT ELEMENTO DA LISTA */
	novo->n = i;
	novo->prox = l;
	return novo;
}

void imprimir(Lista* l){
	Lista* p; /*manipular a copia da lista*/
	for(p=l;p!=NULL;p=p->prox){
		printf("%d\n", p->n);
	}
}

Lista* remover(Lista* l, int i){
    Lista* p=l;
    Lista* ant = NULL;
    Lista* inicio = p;

    while(p != NULL && p->n != i){
        ant = p;
        p = p->prox;
    }

    if(ant == NULL){ /*remover se for o primeiro*/
        inicio = p->prox;
        return inicio;
    }

    if(p->n == i){ /*remover se for o do meio*/
        ant->prox = p->prox;
    }

    free(p);
    p = inicio;
    return p;
}

void liberar(Lista* l){
    Lista* p = l;
    Lista* t;

    while(p != NULL){
        t = p->prox;
        free(p);
        p = t;
    }
}

int main (){
	Lista* l;

    printf("Primeira lista\n");
	l = inicializar();
	l = inserir(l, 30);
	l = inserir(l,789);
	l = inserir(l,7);
	l = inserir(l,77);
	l = inserir(l,18);
	l = inserir(l,2);
	imprimir(l);

	printf("\nRemocao\n");
    l = remover(l,2);
    l = remover(l,18);
    imprimir(l);

    printf("\nNova lista\n");
    liberar(l); /*liberar a memória alocada*/
    l = inicializar();
    l = inserir(l,500);
    imprimir(l);
}
