#ifndef COMMON_H 
#define COMMON_H
#include <time.h>

void mostrarItens(int * array, int tam); 

void mostrarRange(int * array, int inicio, int fim); 

void swap(int * array, int p1, int p2); 

int getMaior(int * array, int tam);

int * gerarArrayAleatorio(int tam);

void printaTempoOrdenacao(clock_t inicio, clock_t fim);

#endif
