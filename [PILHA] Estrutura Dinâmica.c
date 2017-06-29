#include <stdio.h>
#include <stdlib.h>

/*LIFO - Last In, First Out || FILO - First In, Last Out*/

typedef struct elem {
    int n;
    struct elem* prox;
}Elem;

typedef struct pilha{   /*GUARDA O APONTADOR DO TOPO DA PILHA*/
    Elem* prim;
}Pilha;

Pilha* criar(void){     /*INICIALIZA A PILHA COM O PONTEIRO PARA O TOPO APONTANDO NULL*/
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}

int vazia(Pilha* l){
    return (l->prim == NULL);   /*OPERACAO LOGICA, RETORNA 1 SE A PILHA ESTIVER VAZIA*/
}

Elem* inser_ini(Elem* l, int x){    /*INSERE ELEMENTO NO TOPO DA PILHA, A*/
    Elem* p = (Elem*) malloc(sizeof(Elem));
    p->n = x;
    p->prox = l;
    return p;
}

Elem* remov_ini(Elem* l){ /*CRIA COPIA QUE ASSUME A POSICAO "ABAIXO" DO TOPO*/
    Elem* p = l->prox;
    free(l);
    return p;
}

void push(Pilha* l, int x){ /*INSER_INI DEVOLVE UM APONTADOR PARA O ELEMENTO QUE AGORA É O TOPO DA PILHA*/
    l->prim = inser_ini(l->prim,x);
}

void pop (Pilha* l){
    if(!vazia(l)){
       printf("Removido o %d\n", l->prim->n);
       l->prim = remov_ini(l->prim);/*FUNCAO REMOV_INI JA DEVOLVE PONTEIRO DA PILHA SEM O PRIMEIRO ELEMENTO*/
    }
    else{
        printf("A pilha esta vazia\n");
        exit(1);
    }
}

void imprime(Pilha* l){
    Elem* p;
    for(p=l->prim;p!=NULL;p=p->prox){
        printf("%d\n", p->n);
    }
}

int main(){
    Pilha* p;

    p = criar();
    push(p,6);
    push(p,9);
    push(p,7);

    imprime(p);

    pop(p);
    pop(p);

    imprime(p);

}
