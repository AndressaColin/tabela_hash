#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//definir tipo de dado
struct hash
{
    int quantidade, tamanho;
    int **itens; //cria ponteiro para um ponteiro
};

typedef struct hash Hash;

Hash* criaHash(int tamanho); //definindo funcao, retorna o ponteiro Hash*
void liberaHash(Hash* h); //definindo funcao, nao retorna nada
int insereHash_semColisao(Hash* h, int elemento);
int buscaHash_semColisao(Hash* h, int mat, int *elemento);

Hash* criaHash(int tamanho){
    Hash* h = (Hash*) malloc(sizeof(Hash)); //alocacao de memoria
    if(h != NULL){
        int i;
        h -> tamanho = tamanho; //tamanho que vou alocar no array
        h -> itens = (int**) malloc(tamanho * sizeof(int*)); //aloca memoria para array de ponteiros
        if(h -> itens == NULL){ //verificar se a alocacao de memoria foi bem sucedida
            free(h)
            return NULL;
        }
        h -> quantidade = 0;
        for(i = 0; i < h -> tamanho; i++)
        h->itens[i] = NULL;
    }
    return h;
}

void liberaHash(Hash* h){
    if(h != NULL){
        int i;
        for(i = 0; i < h -> tamanho; i++){
            if(h -> itens[i] != NULL)
            free(h -> itens[i]);
        }
        free(h -> itens);
        free(h);
    }
}
//hash divisao
//pos = chaveDivisao(chave, tamanho)
int chaveDivisao(int chave, int tamanho){ // encontrar posição na tabela calculada usando a chave
    return (chave & 0x7FFFFFFF) % tamanho;
}

//inseri e busca sem tratamento de colisao
int insereHash_semcColisao(Hash* h, int elemento){
    if(h == NULL || h -> quantidade == h -> tamanho)
    return 0;

    int chave = elemento;

    int pos = chaveDivisao(chave, h->tamanho); //cria variavel para chamar a funcao
    int* novo; //ponteiro inteiro
    novo = (int*) malloc(sizeof(int)); //aloca memoria
    if(novo == NULL)
        return 0;
    *novo = elemento;
    h -> itens[pos] = novo; 
    h -> quantidade;
    return 1;
}

int buscaHashe_semColisao(Hash* h, int mat, int *elemento){
    if(h == NULL)
        return 0;

    int pos = chaveDivisao(mat, h -> tamanho);
    if(h -> itens[pos] == NULL)
        return 0;
    *elemento = *(h -> itens[pos]);
    return 1;
}

int main(){
    int tamanho = 1024;
    Hash* tabela = criaHash(tamanho);

    int elementoBusca, elementos[4] = {12352, 7894, 3451, 5293};
    int i;
    printf("Inserindo Elementos\n");
    for(i = 0; i < 4; i++){
        printf("%d\n", elementos[i]);
        insereHash_semcColisao(tabela, elementos[i]);
    }
     printf("Elementos Buscados\n");

     buscaHash_semColisao(tabela, 12352, &elementoBusca);
     printf("%d\n", elementoBusca);

     buscaHash_semColisao(tabela, 3451, &elementoBusca);
     printf("%d\n", elementoBusca);

      buscaHash_semColisao(tabela, 5293, &elementoBusca);
     printf("%d\n", elementoBusca);
    
    liberaHash(tabela);

    return 0;
}