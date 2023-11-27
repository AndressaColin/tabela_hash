#include <srdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM 26

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

void quickSort(char vetor, int inicio, int fim){
    int esquerda, direita;
    char pivo;
    char aux;
    esquerda = inicio;
    direita = fim;

    /* PIV‘ ELEMENTO DO MEIO */
    //pivo = v[(inicio + fim) / 2];

    /* PIV‘ ELEMENTO DO INÕCIO */
    //pivo = v[inicio];

    /* PIV‘ ELEMENTO DO FIM */
    pivo = v[fim];

    while(esquerda <= direita){
        while(vetor[esquerda] > pivo && esquerda < fim){//caminha para esquerda
            esquerda++;
        }
        while(vetor[direita] < pivo && direita > inicio){//caminha para direita
            direita--;
        }
        if(esquerda <= direita){
            aux = vetor[esquerda];
            vetor[esquerda] = vetor[direita];
            vetor[direita] = aux;
            esquerda++;
            direita--;
        }
    }
    if(direita > inicio){ //particao
        quickSort(vetor, inicio, direita);
    }
    if(esquerda < fim){ //particao
        quickSort(vetor, esquerda, fim);
    }

int main(){
    char vetor[TAM];

    preencherVetor(vetor, TAM);
    puts("vetor original");
    imprimirVetor(vetor, TAM);

    quickSort(vetor, TAM);
    puts("vetor ordenado");
    imprimirVetor(vetor, TAM);

    return 0;
}