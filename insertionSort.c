#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 50

void preencheVetor(char vetor[], int tamanho){
    srand(time(NULL));
    int i;
    for(i = 0; i < tamanho; i++){
        vetor[i] = (char) (33 + rand() % 94);
    }
}

void imprimirVetor(char vetor[], int tamanho){
    int i;
    char aux;
    for(i = 0; i < tamanho; i++){
        printf("%c\t", vetor[i]);
    }
}

void insertionSort(char vetor[], int tamanho){
    int i, j;
    char aux;
    for(i = 1; i < tamanho; i++){
        aux = vetor[i];
        for(j = i; (j > 0) && (aux < vetor[j -1]); j++){
            vetor[j] = vetor[j - 1];
            vetor[j] = aux;
        }
    }
}

int main(){
    char vetor[TAM];
    int i;

    preencheVetor(vetor, TAM);
    puts("Vetor Original: ");
    imprimirVetor(vetor, TAM);

    insertionSort(vetor, TAM);
    imprimirVetor(vetor, TAM);

    return 0;
}