#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 50

preencherVetor(char vetor[], int tamanho){
    srand(time(NULL));
    int i;
    for(i = 0; i < tamanho; i++){
        vetor[i] = (33 + rand() % 94);
    }
}

imprimirVetor(char vetor[], int tamanho){
    int i;
    for(i = 0; i < tamanho; i++){
        printf("%c\t", vetor[i]);
    }
}

selectionSort(vetor[], int tamanho){
    int i, j;
    char aux;
    int menor;
    for(i = 0; i < tamanho - 1; i++){
        menor = i;
        for(j = i + 1; j <= tamanho - 1; j++){
            if(vetor[j] > vetor[menor]){
                menor = j;
            }
        }
        if(i != menor){
            aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }
    }
}

int main(){
    char vetor[TAM];

    preencherVetor(vetor, TAM);
    puts("Vetor otiginal:");
    imprimirVetor(vetor, TAM);

    selectionSort(vetor, TAM);
    imprimirVetor(vetor, TAM);
    return 0;
}down
//# tabela_hash
//Estudos, tipos