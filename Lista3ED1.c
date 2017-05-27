
/*Escreva uma função que realiza a inserção ordenada de uma nova chave na lista P. */

No* insere_ordenado(No *lista, int n){

    No* p = lista;
    No* inicio = p;

    if(p == NULL){
        p = cria_no(n);
        printf("Inserido %d no inicio da lista\n", n);
        return p;
    }


    while(p->prox != NULL){
        p = p->prox;
    }

    p->prox = cria_no(n);
    printf("Inserido %d no fim da lista\n", n);
    return inicio;

}

###############################################################

/*Escreva uma função que remove o k-ésimo nó da lista encadeada P.*/

No* insere_ordenado(No *lista, int n){

    No* p = lista;
    No* inicio = p;

    if(p == NULL){
        p = cria_no(n);
        p->posi = x;
        printf("Inserido %d no inicio da lista na posi %d\n", n, p->posi);
        return p;
    }

    while(p->prox != NULL){
        p = p->prox;
    }


    x++;
    p->prox = cria_no(n);
    p->posi  = x;
    printf("Inserido %d no fim da lista na posi %d\n", n, x);
    return inicio;

}

###############################################################

No* remover(No* lista, int y){
    No* p = lista;
    No* ant;

    if(p->posi == y){
        p = p->prox;
        printf("Primeiro elemento da lista removido\n");
        return p;
    }
    printf("Não e o 1 da lista\n");

    No* inicio = p;

    while(p->posi != y){
        printf("Nao e o %d elemento\n",p->posi);
        ant = p;
        p = p->prox;
    }

    ant->prox = p->prox;
    printf("Removido %d elemento\n",p->posi);
    return inicio;

}


###############################################################

/*Escreva uma função que remove um elemento com chave K da lista ordenada.
Caso K não pertença à lista, uma mensagem de erro deve ser exibida*/

No* remover(No* lista, int y){
    No* p = lista;
    No* ant;

    if(p->chave == y){
        p = p->prox;
        printf("Primeiro elemento da lista removido\n");
        return p;
    }

    No* inicio = p;

    while(p->chave != y){
        ant = p;
        p = p->prox;
    }

    ant->prox = p->prox;
    printf("Y REMOVIDO\n");
    return inicio;
}

###############################################################
/*Escreva uma função que recebe duas listas ligadas ordenadas
x = (x1 , ..., xn) e y = (y1, . . . ,ym) como parâmetros e retorna
uma lista ordenada formada pelos elementos de x e y intercalados.
Seu algoritmo deve ter complexidade de tempo O(n).*/


###############################################################
Lista* concatena(Lista* p, Lista* q){
    Lista* inicio = p;

    while(p->prox != NULL){
        p = p->prox;
    }

    p->prox = q;

    return inicio;

###############################################################

Lista* comparar(Lista* p, Lista* q){

    while(p->prox != NULL && q->prox != NULL){
        if(p->n != q->n){
            return 0;
        }
        p = p->prox;
        q = q->prox;
    }
    return 1;
}

###############################################################

Lista* inverter(Lista* p){
    Lista* r = p;
    Lista* novo=NULL;

    while(r != NULL){
        novo = cria_no2(novo,r->n);
        r = r->prox;
    }
    return novo;

}

###############################################################

Lista* interse(Lista* p, Lista* q){
    Lista* x;
    Lista* y;
    Lista* novo = NULL;

    for(x=p;x!=NULL;x=x->prox){
        for(y=q;y!=NULL;y=y->prox){
            if(x->n == y->n){
                novo = cria_no2(novo,x->n);
            }
        }
    }

    return novo;
}

###############################################################

int crescente(Lista* l){
    Lista* p=l;
    Lista* r=p->prox;

    while(r != NULL){ /* R CHEGARA PRIMEIRO A NULL POIS É UM ELEMENTO A FRENTE*/
          if((p->n) > (r->n)){
             return 0;
          }
          p=p->prox;
          r=r->prox;
    }
    return 1;

}

###############################################################
