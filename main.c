#include <stdio.h>
#include <stdlib.h>
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

	void shellSort(){
		int k;
		if(MAX%2 == 0)
			k = MAX/2;
		else
			k = (MAX/2)+1;
		for(; k > 0; k--){
			for(int i = 0; i+k < MAX; i++){
				if(vetor[i] > vetor[i+k]){
					int aux = vetor[i];
					vetor[i] = vetor[i+k];
					vetor[i+k] = aux;
				}
			}
		}
		printar();
	};

	void insertionSort(){
		for(int i = 1; i < MAX; i++){
			if(vetor[i] < vetor[i-1]){
				int aux = vetor[i];
				int p;
				for(p = i-1; p >= 0; p--){
					if(aux > vetor[p])
						break;
				}
				for(int j = i; j > (p+1); j--){
					vetor[j] = vetor[j-1];
				}
				vetor[p+1] = aux;
			}
		}
		printar();
	};

	void quickSort(int inicio, int fim){
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
	        }
	    }while(j > i);

	    if(inicio < j)
	    	quickSort(inicio,j);
		if(i < fim)
	        quickSort(i,fim);
	};

	void MergeSort(int inicio, int fim) {
        int i, j, k, tam, *aux;
        if(inicio == fim)
            return;
        //ordena recursivamente as duas metades dos vetores
        tam = (inicio + fim)/2;
        MergeSort(inicio, tam);
        MergeSort(tam+1,fim);
        //Intercala no vetor auxiliar
        i = inicio;
        j = tam+1;
        k = 0;
        aux = new int[fim-inicio+1];
        while(i < tam+1 || j  < fim+1){
            if(i == tam+1) { // i passou do final da primeira metade, pega v[j]
             aux[k] = vetor[j];
             j++;
             k++;
            }else{
                if(j==fim+1){ // j passa do final da segunda metade, pega v[i]
                    aux[k] = vetor[i];
                    i++;
                    k++;
                }else{
                    if(vetor[i] < vetor[j]){
                       aux[k] = vetor[i];
                       i++;
                       k++;
                    }else{
                      aux[k] = vetor[j];
                      j++;
                      k++;
                    };
                };
            };

        };
        // copia o vetor intercalado para original
        for(i = inicio; i <= fim; i++) {
          vetor[i] = aux[i-inicio];
        };
        delete(aux);
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
	        	bucket[(vetor[i]/exp) % 10]++;
	        for(i = 1; i < 10; i++)
	        	bucket[i] += bucket[i-1];
	        for(i = tamanho - 1; i >= 0; i--)
	        	b[--bucket[(vetor[i]/exp)%10]] = vetor[i];
	        for(i = 0; i < tamanho; i++)
	        	vetor[i] = b[i];
	        exp *= 10;
	    }
	    free(b);
	};


int main(int argc, char const *argv[]){
	int op;
	do{
		printf("------------------------------------------------------\n");
		printf("\tMENU DE OPÇÕES\n");
		printf("------------------------------------------------------\n");
		printf(" 1 --  BUBBLE SORT\n");
		printf(" 2 --  SELECT SORT\n");
		printf(" 3 --  SHELL SORT\n");
		printf(" 4 --  INSERTION SORT\n");
		printf(" 5 --  QUICK SORT\n");
		printf(" 6 --  MERGE SORT\n");
		printf(" 7 --  RADIX SORT\n");
		printf(" 0 --  SAIR\n");
		printf("------------------------------------------------------\n");
		scanf("%d", &op);
		printf("------------------------------------------------------\n");

		switch(op){
			case 1:
				printf("------------------------------------------------------\n");
				printf("\tBUBBLE SORT\n");
				printf("------------------------------------------------------\n");
				bubbleSort();
				printf("------------------------------------------------------\n");
				break;
			case 2:
				printf("------------------------------------------------------\n");
				printf("\tSELECT SORT\n");
				printf("------------------------------------------------------\n");
				break;
			case 3:
				printf("------------------------------------------------------\n");
				printf("\tSHELL SORT\n");
				printf("------------------------------------------------------\n");
				break;
			case 4:
				printf("------------------------------------------------------\n");
				printf("\tINSERTION SORT\n");
				printf("------------------------------------------------------\n");
				break;
			case 5:
				printf("------------------------------------------------------\n");
				printf("\tQUICK SORT\n");
				printf("------------------------------------------------------\n");
				break;
			case 6:
				printf("------------------------------------------------------\n");
				printf("\tMERGE SORT\n");
				printf("------------------------------------------------------\n");
				break;
			case 7:
				printf("------------------------------------------------------\n");
				printf("\tRADIX SORT\n");
				printf("------------------------------------------------------\n");
				break;
			case 0:
				printf("PROGRAMA ENCERRADO COM SUCESSO\n");
				break;
			default:
				printf("OPÇÃO INVÁLIDA, POR FAVOR ESCOLHA UMA VÁLIDA\n");
		}

	}while(op != 0);

	return 0;
}