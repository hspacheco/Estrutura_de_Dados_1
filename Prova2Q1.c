#include <stdio.h>
#include <stdlib.h>

/*INSERE FIM*/

struct lista{
 	int n;
 	struct lista* prox;
};

typedef struct lista Lista;

Lista* inicializar (void){
	return NULL;
}

Lista* cria_no(int i){
    Lista* novo = (Lista*) malloc (sizeof(Lista)); /*NOVO � A NOVA STRUCT ELEMENTO DA LISTA */

    novo->n = i;
    novo->prox = NULL;

    return novo;
}

Lista* inserir (Lista* l, int i){ /*insere fim*/
	Lista* p = l;
    Lista* inicio;

    if(p == NULL){  /*lista vazia*/
        return cria_no(i);

    }

    inicio = p; /*Guarda inicio da lista antes de correr*/

    while(p->prox != NULL){
        p=p->prox;
    }


    p->prox = cria_no(i);

    return inicio;
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

Lista* verificar(Lista* l){
  Lista **p;
  Lista *l1 = l, *l2;

  p = l1->prox->prox;

  for(l2=l;l2!=NULL;l2=l2->prox){
    if(p==l2){
        printf("PtrPtr aponta para a sublista: ");
        return l2;
    }
  }

  return 0;
}

int main (){
	Lista* l;
  Lista* tem;

  printf("Primeira lista\n");
  l = inicializar();
  l = inserir(l, 30);
  l = inserir(l, 5);
  l = inserir(l, 789);
  l = inserir(l, 30);
  imprimir(l);
  printf("\n");

  tem = verificar(l);
  imprimir(tem);

  return 0;
}
