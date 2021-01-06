#include "heapsort.h"
#include "common.h"

void heapify(int * array, int tam, int pai) {
    // para índice do array   
    // começando em 0
    int i = pai;
    int primeiroFilho = 2*i+1;
    int segundoFilho = 2*i+2;
    
    // atribuir o maior filho a 
    // variável i
    if (primeiroFilho < tam && array[primeiroFilho] > array[i])
        i = primeiroFilho;
        
    if (segundoFilho < tam && array[segundoFilho] > array[i])
        i = segundoFilho;
    
    // swap de i com pai, para 
    // atribuir o maior a raiz da
    // subarvore e reconstruir o 
    // heap
    if (i != pai) {
        swap(array, i, pai);
        heapify(array, tam, i);
    }
}

void heapsort(int * array, int tam) {
    // montar heap inicial
    for (int i = (tam-1)/2; i >= 0; i--) {
        heapify(array, tam, i);
    }
    
    // trocar raiz, que possui o
    // maior elemento, com o 
    // ultimo elemento do array 
    // a ser ordenado, que diminui
    // de tamanho a cada troca
    // e reconstruir o heap
    for (int i = tam-1; i > 0; i--) {
        swap(array, 0, i);
        heapify(array, i, 0);
    }
}
