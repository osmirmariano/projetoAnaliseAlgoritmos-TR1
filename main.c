#include <stdio.h>
#include <stdli.b>
#define MAX 10

void printar(){
	for(int x = 0; x < MAX; x++)
		printf("%d", vetor[x])
}

void bubbleSort(){
	for(int x = MAX; x > 0; x--){
		for(int y = 0; y < x-1; y++){
			if(vetor[y]>vetor[y+1]){
				int aux = vetor[y+1];
				vetor[y+1]=vetor[y];
				vetor[y]=aux;
			}
		}
	}
	printar();
}

void selectionSort(){
	for(int x = 0; x < MAX; x++){
		int menor = vetor[x];
		for(int y = x+1; y < MAX; y++){
			if(vetor[y] < menor){
				int aux = menor;
				menor = vetor[y];
				vetor[y] = aux;
			}
		}
		vetor[x] = menor;
	}
	printar();
};

void QuickSort(int inicio, int fim){
       int i, j, pivo, metade, aux;
       i = inicio;
       j = fim;

       metade = (int)((i+j)/2);
       pivo =  vetor[metade];
       do{
          while(vetor[i] < pivo)
            i = i+1;
          while(vetor[j] > pivo)
            j = j-1;
          if(i <= j){
             aux = vetor[i];
             vetor[i] = vetor[j];
             vetor[j] = aux;
             i = i+1;
             j = j-1;
          };
       }while(j > i);

       if(inicio < j)
        QuickSort(inicio,j);
       if(i < fim)
        QuickSort(i,fim);
    };


void radixSort(int tamanho) {
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *)calloc(tamanho, sizeof(int));

    for(int x = 0; x < tamanho; x++) {
    	if(vetor[x] > maior)
        	maior = vetor[x];
    }

    while(maior/exp > 0) {
    	int bucket[10] = { 0 };
        for(i = 0; i < tamanho; i++)
        	bucket[(vetor[i] / exp) % 10]++;
        for(i = 1; i < 10; i++)
        	bucket[i] += bucket[i - 1];
        for(i = tamanho - 1; i >= 0; i--)
        	b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
        for(i = 0; i < tamanho; i++)
        	vetor[i] = b[i];
        exp *= 10;
    }
    free(b);
};


int main(int argc, char const *argv[]){
	return 0;
}