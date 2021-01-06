#include "countingsort.h"
#include "common.h"

void countingsort(int * array, int tam) {
	int ordenado[tam]; // array com valores ordenados
	int maior = getMaior(array, tam);
	int contagem[maior + 1]; // array de contagem

	// inicializar valores do array contagem com 0
	for (int i = 0; i <= maior; i++)
		contagem[i] = 0;

	// contar a quantidade de cada um dos numeros do array
	// a ser ordenado
	for (int i = 0; i < tam; i++) 
		contagem[array[i]]++;

	// contagem passar a ter valores menores ou iguais
	// ao numero em determinada posicao
	for (int i = 1; i <= maior;  i++) 
		contagem[i] += contagem[i - 1];

	// montar array ordenado
	for (int i = tam - 1; i >= 0; i--) {
		ordenado[contagem[array[i]] - 1] = array[i];
		contagem[array[i]]--;
	}

	// copiar valores ordenados para array original
	for (int i = 0; i < tam;  i++)
		array[i] = ordenado[i];
}
