#include <stdio.h>
#define TMAX 5
/*Suponha que, diferentemente da convenção adotada no texto, a parte do vetor ocupada pela pilha é pilha[1..t]. Escreva o código das funções empilha, desempilha, pilhavazia e pilhacheia*/

int fim=0,inicio=0,x,y,p[TMAX];

int vazia(){
    if(inicio == fim) return 1;
    else return 0;
}

int cheia(){
    if(fim == TMAX) return 1;
    else return 0;
}

int pop(){
     int x;
     if( !vazia() ){
       x = p[fim-1]; /*POR QUE ? - neste caso deveria usar o --fim*/
       fim--;        /*POR QUE ? - se não ele vai atribuir o ultimo valor do vetor, que tem valor 0*/
       return x;
     }
     else printf("pilha vazia\n");
}

void push(int y){

    if( !cheia() ){
        p[fim] = y; /*Aqui permite usar no índice fim++, pq a primeira atribuição será feita com 0 e dps será incrementado*/
        fim++;
    }
    else printf("pilha cheia\n");
}


int main(){

    push(3);
    push(6);

    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
}
