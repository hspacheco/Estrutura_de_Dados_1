#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int n;
    struct no* no_esq;
    struct no* no_dir;
}No;

No* inicializa(void){
    return NULL;
}

No* create_tree(int numero){
    No* arv = (No*)malloc(sizeof(No));
    arv->n = numero;
    arv->no_esq = NULL;
    arv->no_dir = NULL;
    return arv;
}

No* insert_tree(No* Arvore, int n){
    No* tree = Arvore;

    if(tree == NULL){
        tree = create_tree(n);
    }

    if(n > tree->n){
       tree->no_dir = insert_tree(tree->no_dir,n);
    }

    if(n < tree->n){
       tree->no_esq = insert_tree(tree->no_esq,n);
    }

    return tree;

}

void print_pre(No* arvore){
     if(arvore != NULL){
        printf("%d ",arvore->n);
        print_pre(arvore->no_esq);
        print_pre(arvore->no_dir);
     }
}

void print_pos(No* arvore){
     if(arvore != NULL){
        print_pos(arvore->no_esq);
        print_pos(arvore->no_dir);
        printf("%d ",arvore->n);
     }
}

void print_in(No* arvore){
     if(arvore != NULL){
        print_in(arvore->no_esq);
        printf("%d ",arvore->n);
        print_in(arvore->no_dir);
     }
}

int main(){
    No* arv;

    arv = inicializa();
    arv = insert_tree(arv,9);
    arv = insert_tree(arv,3);
    arv = insert_tree(arv,11);
    arv = insert_tree(arv,2);
    arv = insert_tree(arv,5);
    arv = insert_tree(arv,10);
    arv = insert_tree(arv,15);
    print_pre(arv);
    printf("\n");
    print_pos(arv);
    printf("\n");
    print_in(arv);
    printf("\n");
}
