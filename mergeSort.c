#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAM 26
//ordenacao por mistura

void preencherVetor(char vetor[], int tamanho){
    int i;
    for(i = 0; i < tamanho; i++){
        vetor[i] = 65 + (rand() % 26);
    }
}

void imprimirVetor(char vetor[], int tamanho){
    int i;
    for(i = 0; i < tamanho; i++){
        printf("%c ", vetor[i]);
    }
}

void criaMerge(char vetor[], int inicio, int meio, int fim){
    char *temp;
    int tamanho;
    int Lado_Esquerdo, Lado_Direito;
    int fim1, fim2;
    int i, j;

    fim1 = 0;
    fim2 = 0;

    tamanho = fim - inicio + 1;
    Lado_Esquerdo = inicio;
    Lado_Direito = meio + 1;
    temp = (char*) calloc(tamanho, sizeof(char));
    if(temp == NULL){
        puts("Impossivel alocar a memoria!");
        return;
    }
    for(i = 0; i < tamanho; i++){
        if(!fim1 && !fim2){ // operador not 
            if(vetor[Lado_Esquerdo] > vetor[Lado_Direito]){
                Lado_Esquerdo++;
            }
            else{
                temp[i] = vetor[Lado_Direito];
                Lado_Direito++;
            }
            if(Lado_Esquerdo > meio){
                fim1 = 1; //final esquerdo
            }
            if(Lado_Direito > fim){
                fim2 = 1; //final direito
            }
        }
        else {
            if(!fim1){
                temp[i] = vetor[Lado_Esquerdo];
                Lado_Esquerdo++;
            }
            else{
                temp[i] = vetor[Lado_Direito];
                Lado_Direito++;
            }
        }
    }
    for(j = 0, i = inicio; j < tamanho; j++, i++){
        vetor[i] = temp[j];
    }
    free(temp);
}

void mergeSort(char vetor[], int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = floor((inicio + fim)/2);
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        criaMerge(vetor, inicio, meio, fim);
    }
}



int main(){
    int vetor[TAM];

    preencherVetor(vetor, TAM);
    puts("Vetor original:");
    imprimirVetor(vetor, TAM);

    mergeSort(vetor, TAM);
    puts("vetor ordenado:");
    imprimirVetor(vetor, TAM);

    return 0;
}