#include <stdio.h>
#include <stdlib.h>

struct no{
    int n;
    struct no *no_dir;
    struct no *no_esq;
}no;

typedef struct no No;

No* cria_arvore(void){
    return NULL;
}

No* cria_no(No *Arvore){
    Arvore = (No*)malloc(sizeof(No));
    return Arvore;
}

void insere_arvore(No *Arvore, int numero){

    if(Arvore == NULL){
        Arvore = cria_no(Arvore);
        Arvore->n = numero;
        Arvore->no_dir = NULL;
        Arvore->no_esq = NULL;
        printf("INSERIDO %d.\n", numero);
    }

    if(numero > Arvore->n){
        insere_arvore(Arvore->no_dir,numero);
    }

    if(numero < Arvore->n){
        insere_arvore(Arvore->no_esq,numero);
    }

}


int main(){
    No* Arv;

    Arv = cria_arvore();
    insere_arvore(Arv,9);
    insere_arvore(Arv,11);
    insere_arvore(Arv,15);
    insere_arvore(Arv,5);
    insere_arvore(Arv,3);

}
