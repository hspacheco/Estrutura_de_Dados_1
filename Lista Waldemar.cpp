#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
 	int n;
 	struct lista* prox;
};
	
typedef struct lista Lista;
	
Lista* inicializar (void){
	return NULL;
}	

Lista* inserir (Lista* l, int i){
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

Lista* procura(Lista* l, int i){
	Lista* ant = NULL;
	Lista* p = l;
	
	while(p!= NULL && p->n != i ){ /*busca elemento*/
		ant = p;
		p = p->prox;
	}
}

int main (){
	Lista* l;
	
	l = inicializar();
	l = inserir(l, 30);
	l = inserir(l,789);
	imprimir(l);
	
}
