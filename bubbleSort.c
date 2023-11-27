#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 50

//ordenacao descrecente 

void preencherVetor(char vetor[], int tamanho){
    srand(time(NULL));
    int i;
    for(i = 0; i < tamanho; i++){
        vetor[i] = (char) (33 + rand() % 94); //tabela ASCII
    }
}

void imprimirVetor(char vetor[], int tamanho){
    int i, j;
    char aux;
    for(i = 0; i < tamanho; i++){
        printf("%c\t", vetor[i]);
    }
}

void bubbleSort(char vetor[], int tamanho){
    int i, j;
    char aux;
    for(i = 0; i < tamanho - 1; i++){
        for(j = 0; j < tamanho - i - 1; j++){
            if(vetor[j] < vetor[j + 1]){
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

int main(){
    char vetor[TAM];

    preencherVetor(vetor, TAM);

    puts("Vetor Original:");
    imprimirVetor(vetor, TAM);

    bubbleSort(vetor, TAM);

    return 0;
}