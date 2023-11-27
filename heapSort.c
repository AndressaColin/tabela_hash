#include <stdio.h>
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

void cria_heap(char v[], int pai, int fim) {
    int filho;
    char aux;
    filho = 2 * pai + 1;
    aux = v[pai];
    while (filho <= fim) {
        if (filho < fim) { // Se tem irm„o
            if (v[filho] > v[filho + 1]) { // Qual o menor dos irm„os (decrescente)
                filho = filho + 1;
            }
        }
        if (aux > v[filho]) { // Pai tem que ser menor que os filhos (descrescente)
            v[pai] = v[filho];
            pai = filho;
            filho = 2 * pai + 1;
        }
        else {
            filho = fim + 1;
        }
    }
    v[pai] = aux; // Coloca no ˙ltimo filho o valor do pai "original"
}


void heap_sort(char v[], int tamanho) {
    char aux;
    for (int i = (tamanho - 1) / 2; i >= 0; i--) {
        cria_heap(v, i, tamanho - 1);
    }
    for (int i = tamanho - 1; i > 0; i--) {
        // Pega a raiz da Heap, coloca na ˙ltima posiÁ„o e esquece l·
        aux = v[0];
        v[0] = v[i];
        v[i] = aux;
        cria_heap(v, 0, i - 1); // Cria o MAX_HEAP (ou MIN, se decrescente)
    }
}

int main(){

    return 0;
}

