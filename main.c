#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
	
	/*--------------------FUNÇÃO PRINTAR O RESULTADO DOS MÉTODOS---------------------*/
	void printar(int max, int *vetor){
		for(int x = 0; x < max; x++)
			printf(" %d ", vetor[x]);
	}
	void ordenacao(int max, int *vetor){
		for(int x = max; x > 0; x--){
			printf(" %d ", vetor[x]);
		}
	}
	/*---------------------FUNÇÃO ORDENAÇÃO MÉTODO BUBBLE SORT-----------------------*/
	void bubbleSort(int max, int *vetor){
        int aux;
        long int numTroca = 0, numComparacao = 0;
        for(int x = 0; x < max-1; x++){
            for(int y = x+1; y < max; y++){
            	numComparacao++;
                if(vetor[x] > vetor[y]){
                	numTroca++;
                    aux = vetor[x];
                    vetor[x] = vetor[y];
                    vetor[y] = aux;
                }
            }
        }
        
        printar(max, vetor);
        printf("\n\n NUMERO DE TROCA: %ld", numTroca);
        printf("\n\n NUMERO DE COMPARAÇÕES: %ld", numComparacao);
    }

    void bubbleSortDecrescente(int max, int *vetor){
        int aux;
        long int numTroca = 0, numComparacao = 0;
        for(int x = 0; x < max-1; x++){
            for(int y = x+1; y < max; y++){
                numComparacao++;
                if(vetor[x] < vetor[y]){
            		numTroca++;
                    aux = vetor[x];
                    vetor[x] = vetor[y];
                    vetor[y] = aux;
                }
            }
        }
        printar(max, vetor);
        printf("\n\n NUMERO DE TROCA: %ld", numTroca);
        printf("\n\n NUMERO DE COMPARAÇÕES: %ld", numComparacao);
    }
    /*---------------------FUNÇÃO ORDENAÇÃO MÉTODO SELECTION SORT---------------------*/
	void selectionSort(int max, int *vetor){
		long int numTroca = 0, numComparacao = 0;
		for(int x = 0; x < max; x++){
			int menor = vetor[x];
			for(int y = x+1; y < max; y++){
				numComparacao++;
				if(vetor[y] < menor){
					numTroca++;
					int aux = menor;
					menor = vetor[y];
					vetor[y] = aux;
				}
			}
			vetor[x] = menor;
		}
		printar(max, vetor);
		printf("\n\n NUMERO DE TROCA: %ld", numTroca);
        printf("\n\n NUMERO DE COMPARAÇÕES: %ld", numComparacao);
	};

	void selectionSortDecrescente(int max, int *vetor){
		long int numTroca = 0, numComparacao = 0;
		for(int x = 0; x < max; x++){
			int menor = vetor[x];
			for(int y = x+1; y < max; y++){
				numComparacao++;
				if(vetor[y] > menor){
					numTroca++;
					int aux = menor;
					menor = vetor[y];
					vetor[y] = aux;
				}
			}
			vetor[x] = menor;
		}
		printar(max, vetor);
		printf("\n\n NUMERO DE TROCA: %ld", numTroca);
        printf("\n\n NUMERO DE COMPARAÇÕES: %ld", numComparacao);
	};
	/*------------------------FUNÇÃO ORDENAÇÃO MÉTODO SHELL SORT-----------------------*/
	void shellSort(int max, int *vetor){
		long int numTroca = 0, numComparacao = 0;
		int k;
		if(max%2 == 0)
			k = max/2;
		else
			k = (max/2)+1;
		for(; k > 0; k--){
			for(int i = 0; i+k < max; i++){
				numComparacao++;
				if(vetor[i] > vetor[i+k]){
					numTroca++;
					int aux = vetor[i];
					vetor[i] = vetor[i+k];
					vetor[i+k] = aux;
				}
			}
		}
		printar(max, vetor);
		printf("\n\n NUMERO DE TROCA: %ld", numTroca);
        printf("\n\n NUMERO DE COMPARAÇÕES: %ld", numComparacao);
	};

	void shellSortDecrescente(int max, int *vetor){
		long int numTroca = 0, numComparacao = 0;
		int k;
		if(max%2 == 0)
			k = max/2;
		else
			k = (max/2)+1;
		for(; k > 0; k--){
			for(int i = 0; i+k < max; i++){
				numComparacao++;
				if(vetor[i] < vetor[i+k]){
					numTroca++;
					int aux = vetor[i];
					vetor[i] = vetor[i+k];
					vetor[i+k] = aux;
				}
			}
		}
		printar(max, vetor);
		printf("\n\n NUMERO DE TROCA: %ld", numTroca);
        printf("\n\n NUMERO DE COMPARAÇÕES: %ld", numComparacao);
	};

	/*----------------------FUNÇÃO ORDENAÇÃO MÉTODO INSERTION SORT-----------------------*/
	void insertionSort(int max, int *vetor){
		long int numTroca = 0, numComparacao = 0;
		for(int i = 1; i < max; i++){
			if(vetor[i] < vetor[i-1]){
				int aux = vetor[i];
				int p;
				for(p = i-1; p >= 0; p--){
					if(aux > vetor[p])
						break;
				}
				for(int j = i; j > (p+1); j--){
					numTroca++;
					numComparacao++;
					vetor[j] = vetor[j-1];
				}
				vetor[p+1] = aux;
			}
		}
		printar(max, vetor);
		printf("\n\n NUMERO DE TROCA: %ld", numTroca);
        printf("\n\n NUMERO DE COMPARAÇÕES: %ld", numComparacao);
	};


	void insertionSortDecrescente(int max, int *vetor){
		long int numTroca = 0, numComparacao = 0;
		for(int i = 1; i < max; i++){
			if(vetor[i] > vetor[i-1]){
				int aux = vetor[i];
				int p;
				for(p = i-1; p >= 0; p--){
					if(aux < vetor[p])
						break;
				}
				for(int j = i; j > (p+1); j--){
					numTroca++;
					numComparacao++;
					vetor[j] = vetor[j-1];
				}
				vetor[p+1] = aux;
			}
		}
		printar(max, vetor);
		printf("\n\n NUMERO DE TROCA: %ld", numTroca);
        printf("\n\n NUMERO DE COMPARAÇÕES: %ld", numComparacao);
	};
	/*-----------------------FUNÇÃO ORDENAÇÃO MÉTODO RADIX SORT-----------------------*/
	void radixSort(int max, int *vetor) {
	    int *b;
	    int maior = vetor[0];
	    int exp = 1;

	    b = (int*)calloc(max, sizeof(int));
	    for(int x = 0; x < max; x++) {
	    	if(vetor[x] > maior)
	        	maior = vetor[x];
	    }
	    while(maior/exp > 0) {
	    	int bucket[10] = { 0 };
	        for(int i = 0; i < max; i++)
	        	bucket[(vetor[i]/exp) % 10]++;
	        for(int i = 1; i < 10; i++)
	        	bucket[i] += bucket[i-1];
	        for(int i = max - 1; i >= 0; i--)
	        	b[--bucket[(vetor[i]/exp)%10]] = vetor[i];
	        for(int i = 0; i < max; i++)
	        	vetor[i] = b[i];
	        exp *= 10;
	    }
	    free(b);
		printar(max, vetor);
	};

	/*-----------------------FUNÇÃO ORDENAÇÃO MÉTODO QUICK SORT-----------------------*/
	int *quickSort(int inicio, int fim, int *vetor){
	    int i, j, pivo, metade, aux;
	    i = inicio;
	    j = fim;
	    int max = fim+1;
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
	    	quickSort(inicio, j, vetor);
		if(i < fim)
	        quickSort(i, fim, vetor);
	    return vetor;
	};

	void printarQuickSort(int inicio, int fim, int *vetor){
		int *novoVetor;
		int max = fim+1;

		novoVetor = quickSort(inicio, fim, vetor);
		printar(max, novoVetor);
	}

	int *mergeSort(int inicio, int fim, int *vetor){
        int i, j, k, tam, *aux;  
        if(inicio == fim)
            return 0;
        //ordena recursivamente as duas metades dos vetores
        tam = (inicio + fim)/2;
        int max = fim+1;
        mergeSort(inicio, tam, vetor);
        mergeSort(tam+1,fim, vetor);
        //Intercala no vetor auxiliar
        i = inicio;
        j = tam+1;
        k = 0;
        aux = (int *)calloc((fim-inicio+1), sizeof(int));
        
         while(i < tam+1 || j  < fim+1){
            if(i == tam+1) { // i passou do final da primeira metade, pega v[j]
             	aux[k] = vetor[j];
            	j++;
             	k++;
            }
            else{
                if(j==fim+1){ // j passa do final da segunda metade, pega v[i]
                    aux[k] = vetor[i];
                    i++;
                    k++;
                }
                else{
                    if(vetor[i] < vetor[j]){
                       	aux[k] = vetor[i];
                       	i++;
                      	k++;
                    }
                    else{
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
        free(aux);
        return vetor;
    };

    void printarMergeSort(int inicio, int fim, int *vetor){
		int *novoVetor;
		int max = fim+1;

		novoVetor = mergeSort(inicio, fim, vetor);
		printar(max, novoVetor);
	}

	void preencherRandom2(int max, int *vetor){
		srand((unsigned)time(NULL));
		for(int x = 0; x < max; x++){
			int b = 1 + (rand() % max);
			vetor[x] = b;
		}
		printar(max, vetor);
	}

	void preencherRandom(int max, int *vetor){
		srand((unsigned)time(NULL));
		for(int x = 0; x < max; x++){
			int b = 1 + (rand() % max);
			vetor[x] = b;
		}
	}

int main(int argc, char const *argv[]){
	int op, op3;
	int max, *vetor;
	float tempo;
    time_t inicio, fim;
    
	do{
		printf("\n\n------------------------------------------------------\n");
		printf("\tMENU - ESCOLHA O TAMANHO DO VETOR\n");
		printf("------------------------------------------------------\n");
		printf(" 1 --  10\n");
		printf(" 2 --  100\n");
		printf(" 3 --  1000\n");
		printf(" 4 --  50000\n");
		printf(" 5 --  100000\n");
		printf(" 0 --  SAIR\n");
		printf("------------------------------------------------------\n");
		printf("OPÇÃO: ");
		scanf("%d", &op3);
		printf("------------------------------------------------------\n");
		switch(op3){
			case 1:
				max = 10;
				vetor = (int*) malloc(max*sizeof(int));
				break;
			case 2:
				max = 100;
				vetor = (int*) malloc(max*sizeof(int));
				break;
			case 3:
				max = 1000;
				vetor = (int*) malloc(max*sizeof(int));
				break;
			case 4:
				max = 50000;
				vetor = (int*) malloc(max*sizeof(int));
				break;
			case 5:
				max = 100000;
				vetor = (int*) malloc(max*sizeof(int));				
				break;
			case 0:
				printf("\n \tPROGRAMA ENCERRADO COM SUCESSO!\n\n");
				exit(0);
				break;
			default:
				printf("OPÇÃO INVÁLIDA, POR FAVOR ESCOLHA UMA VÁLIDA\n");
		}
		printf("\e[H\e[2J");
		preencherRandom(max, vetor);

		do{
			printf("\n\n------------------------------------------------------\n");
			printf("\tMENU - ESCOLHA O MÉTODO DE ORDENAÇÃO\n");
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
			printf("OPÇÃO: ");
			scanf("%d", &op);
			printf("------------------------------------------------------\n");
			printf("\e[H\e[2J");
			switch(op){
				case 1:
					printf("\n\n------------------------------------------------------\n");
					printf("\tBUBBLE SORT\n");
					printf("------------------------------------------------------\n");
					int op2;
					do{
						printf("------------------------------------------------------\n");
						printf("\tMENU - ESCOLHA A ORDEM\n");
						printf("------------------------------------------------------\n");
						printf(" 1 --  ORDENAÇÃO CRESCENTE\n");
						printf(" 2 --  ORDENAÇÃO DECRESCENTE\n");
						printf(" 3 --  DESORDENADO\n");
						printf(" 0 --  VOLTAR MENU PRINCIPAL\n");
						printf("------------------------------------------------------\n");
						printf("OPÇÃO: ");
						scanf("%d", &op2);
						
						switch(op2){
							case 1:
								printf("------------------------------------------------------\n");
								printf("\tORDENAÇÃO CRESCENTE\n");
								printf("------------------------------------------------------\n");
								inicio = time(NULL);
								bubbleSort(max, vetor);
								fim = time(NULL);
        						tempo = difftime(fim, inicio);
        						printf("\n\n TEMPO DE EXECUÇÃO: %0.1f s", tempo);
								printf("\n------------------------------------------------------\n");
								break;
							case 2:
								printf("------------------------------------------------------\n");
								printf("\tORDENAÇÃO DECRESCENTE\n");
								printf("------------------------------------------------------\n");
								inicio = time(NULL);
								bubbleSortDecrescente(max, vetor);
								fim = time(NULL);
        						tempo = difftime(fim, inicio);
        						printf("\n\n TEMPO DE EXECUÇÃO: %0.1f s", tempo);
								printf("\n------------------------------------------------------\n");
								break;
							case 3:
								printf("------------------------------------------------------\n");
								printf("\tDESORDENADO\n");
								printf("------------------------------------------------------\n");
								inicio = time(NULL);
								preencherRandom2(max, vetor);
								fim = time(NULL);
        						tempo = difftime(fim, inicio);
        						printf("\n\n TEMPO DE EXECUÇÃO: %0.1f s", tempo);
								printf("\n------------------------------------------------------\n");
								break;
							case 0:
								printf("\tVOLTANDO PARA O MENU PRINCIPAL\n");
								printf("\e[H\e[2J");
								break;
							default:
								printf("OPÇÃO INVÁLIDA\n");
						}

					}while(op2 != 0);
					break;
				case 2:
					printf("\n\n------------------------------------------------------\n");
					printf("\tSELECT SORT\n");
					printf("------------------------------------------------------\n");
					do{
						printf("------------------------------------------------------\n");
						printf("\tMENU DE OPÇÕES - ESCOLHA DO TIPO DE ORDENAÇÃO\n");
						printf("------------------------------------------------------\n");
						printf(" 1 --  ORDENAÇÃO CRESCENTE\n");
						printf(" 2 --  ORDENAÇÃO DECRESCENTE\n");
						printf(" 3 --  DESORDENADO\n");
						printf(" 0 --  VOLTAR MENU PRINCIPAL\n");
						printf("------------------------------------------------------\n");
						printf("OPÇÃO: ");
						scanf("%d", &op2);
						
						switch(op2){
							case 1:
								printf("------------------------------------------------------\n");
								printf("\tORDENAÇÃO CRESCENTE\n");
								printf("------------------------------------------------------\n");
								inicio = time(NULL);
								selectionSort(max, vetor);
								fim = time(NULL);
        						tempo = difftime(fim, inicio);
        						printf("\n\n TEMPO DE EXECUÇÃO: %0.1f s", tempo);
								printf("\n------------------------------------------------------\n");
								break;
							case 2:
								printf("------------------------------------------------------\n");
								printf("\tORDENAÇÃO DECRESCENTE\n");
								printf("------------------------------------------------------\n");
								inicio = time(NULL);
								selectionSortDecrescente(max, vetor);
								fim = time(NULL);
        						tempo = difftime(fim, inicio);
        						printf("\n\n TEMPO DE EXECUÇÃO: %0.1f s", tempo);
								printf("\n------------------------------------------------------\n");
								break;
							case 3:
								printf("------------------------------------------------------\n");
								printf("\tDESORDENADO\n");
								printf("------------------------------------------------------\n");
								inicio = time(NULL);
								preencherRandom2(max, vetor);
								fim = time(NULL);
        						tempo = difftime(fim, inicio);
        						printf("\n\n TEMPO DE EXECUÇÃO: %0.1f s", tempo);
								printf("\n------------------------------------------------------\n");
								break;
							case 0:
								printf("\tVOLTANDO PARA O MENU PRINCIPAL\n");
								printf("\e[H\e[2J");
								break;
							default:
								printf("OPÇÃO INVÁLIDA\n");
						}

					}while(op2 != 0);
					break;
				case 3:
					printf("\n\n------------------------------------------------------\n");
					printf("\tSHELL SORT\n");
					printf("------------------------------------------------------\n");
					do{
						printf("------------------------------------------------------\n");
						printf("\tMENU DE OPÇÕES - ESCOLHA DO TIPO DE ORDENAÇÃO\n");
						printf("------------------------------------------------------\n");
						printf(" 1 --  ORDENAÇÃO CRESCENTE\n");
						printf(" 2 --  ORDENAÇÃO DECRESCENTE\n");
						printf(" 3 --  DESORDENADO\n");
						printf(" 0 --  VOLTAR MENU PRINCIPAL\n");
						printf("------------------------------------------------------\n");
						printf("OPÇÃO: ");
						scanf("%d", &op2);
						
						switch(op2){
							case 1:
								printf("------------------------------------------------------\n");
								printf("\tORDENAÇÃO CRESCENTE\n");
								printf("------------------------------------------------------\n");
								inicio = time(NULL);
								shellSort(max, vetor);
								fim = time(NULL);
        						tempo = difftime(fim, inicio);
        						printf("\n\n TEMPO DE EXECUÇÃO: %0.1f s", tempo);
								printf("\n------------------------------------------------------\n");
								break;
							case 2:
								printf("------------------------------------------------------\n");
								printf("\tORDENAÇÃO DECRESCENTE\n");
								printf("------------------------------------------------------\n");
								inicio = time(NULL);
								shellSortDecrescente(max, vetor);
								fim = time(NULL);
        						tempo = difftime(fim, inicio);
        						printf("\n\n TEMPO DE EXECUÇÃO: %0.1f s", tempo);
								printf("\n------------------------------------------------------\n");
								break;
							case 3:
								printf("------------------------------------------------------\n");
								printf("\tDESORDENADO\n");
								printf("------------------------------------------------------\n");
								inicio = time(NULL);
								preencherRandom2(max, vetor);
								fim = time(NULL);
        						tempo = difftime(fim, inicio);
        						printf("\n\n TEMPO DE EXECUÇÃO: %0.1f s", tempo);
								printf("\n------------------------------------------------------\n");
								break;
							case 0:
								printf("\tVOLTANDO PARA O MENU PRINCIPAL\n");
								printf("\e[H\e[2J");
								break;
							default:
								printf("OPÇÃO INVÁLIDA\n");
						}

					}while(op2 != 0);
					break;
				case 4:
					printf("\n\n------------------------------------------------------\n");
					printf("\tINSERTION SORT\n");
					printf("------------------------------------------------------\n");
					do{
						printf("------------------------------------------------------\n");
						printf("\tMENU DE OPÇÕES - ESCOLHA DO TIPO DE ORDENAÇÃO\n");
						printf("------------------------------------------------------\n");
						printf(" 1 --  ORDENAÇÃO CRESCENTE\n");
						printf(" 2 --  ORDENAÇÃO DECRESCENTE\n");
						printf(" 3 --  DESORDENADO\n");
						printf(" 0 --  VOLTAR MENU PRINCIPAL\n");
						printf("------------------------------------------------------\n");
						printf("OPÇÃO: ");
						scanf("%d", &op2);
						
						switch(op2){
							case 1:
								printf("------------------------------------------------------\n");
								printf("\tORDENAÇÃO CRESCENTE\n");
								printf("------------------------------------------------------\n");
								inicio = time(NULL);
								insertionSort(max, vetor);
								fim = time(NULL);
        						tempo = difftime(fim, inicio);
        						printf("\n\n TEMPO DE EXECUÇÃO: %0.1f s", tempo);
								printf("\n------------------------------------------------------\n");
								break;
							case 2:
								printf("------------------------------------------------------\n");
								printf("\tORDENAÇÃO DECRESCENTE\n");
								printf("------------------------------------------------------\n");
								inicio = time(NULL);
								insertionSortDecrescente(max, vetor);
								fim = time(NULL);
        						tempo = difftime(fim, inicio);
        						printf("\n\n TEMPO DE EXECUÇÃO: %0.1f s", tempo);
								printf("\n------------------------------------------------------\n");
								break;
							case 3:
								printf("------------------------------------------------------\n");
								printf("\tDESORDENADO\n");
								printf("------------------------------------------------------\n");
								inicio = time(NULL);
								preencherRandom2(max, vetor);
								fim = time(NULL);
        						tempo = difftime(fim, inicio);
        						printf("\n\n TEMPO DE EXECUÇÃO: %0.1f s", tempo);
								printf("\n------------------------------------------------------\n");
								break;
							case 0:
								printf("\tVOLTANDO PARA O MENU PRINCIPAL\n");
								printf("\e[H\e[2J");
								break;
							default:
								printf("OPÇÃO INVÁLIDA\n");
						}

					}while(op2 != 0);
					break;
				case 5:
					printf("\n\n------------------------------------------------------\n");
					printf("\tQUICK SORT\n");
					printf("\n------------------------------------------------------\n");
					do{
						printf("------------------------------------------------------\n");
						printf("\tMENU DE OPÇÕES - ESCOLHA DO TIPO DE ORDENAÇÃO\n");
						printf("------------------------------------------------------\n");
						printf(" 1 --  ORDENAÇÃO CRESCENTE\n");
						printf(" 2 --  ORDENAÇÃO DECRESCENTE\n");
						printf(" 3 --  DESORDENADO\n");
						printf(" 0 --  VOLTAR MENU PRINCIPAL\n");
						printf("------------------------------------------------------\n");
						printf("OPÇÃO: ");
						scanf("%d", &op2);
						
						switch(op2){
							case 1:
								printf("------------------------------------------------------\n");
								printf("\tORDENAÇÃO CRESCENTE\n");
								printf("------------------------------------------------------\n");
								inicio = time(NULL);
								printarQuickSort(0, max-1, vetor);
								fim = time(NULL);
        						tempo = difftime(fim, inicio);
        						printf("\n\n TEMPO DE EXECUÇÃO: %0.1f s", tempo);
								printf("\n------------------------------------------------------\n");
								break;
							case 2:
								printf("------------------------------------------------------\n");
								printf("\tORDENAÇÃO DECRESCENTE\n");
								printf("------------------------------------------------------\n");
								
								printf("\n------------------------------------------------------\n");
								break;
							case 3:
								printf("------------------------------------------------------\n");
								printf("\tDESORDENADO\n");
								printf("------------------------------------------------------\n");
								inicio = time(NULL);
								preencherRandom2(max, vetor);
								fim = time(NULL);
        						tempo = difftime(fim, inicio);
        						printf("\n\n TEMPO DE EXECUÇÃO: %0.1f s", tempo);
								printf("\n------------------------------------------------------\n");
								break;
							case 0:
								printf("\tVOLTANDO PARA O MENU PRINCIPAL\n");
								printf("\e[H\e[2J");
								break;
							default:
								printf("OPÇÃO INVÁLIDA\n");
						}

					}while(op2 != 0);
					break;
				case 6:
					printf("\n\n------------------------------------------------------\n");
					printf("\tMERGE SORT\n");
					printf("\n------------------------------------------------------\n");
					do{
						printf("------------------------------------------------------\n");
						printf("\tMENU DE OPÇÕES - ESCOLHA DO TIPO DE ORDENAÇÃO\n");
						printf("------------------------------------------------------\n");
						printf(" 1 --  ORDENAÇÃO CRESCENTE\n");
						printf(" 2 --  ORDENAÇÃO DECRESCENTE\n");
						printf(" 3 --  DESORDENADO\n");
						printf(" 0 --  VOLTAR MENU PRINCIPAL\n");
						printf("------------------------------------------------------\n");
						printf("OPÇÃO: ");
						scanf("%d", &op2);
						
						switch(op2){
							case 1:
								printf("------------------------------------------------------\n");
								printf("\tORDENAÇÃO CRESCENTE\n");
								printf("------------------------------------------------------\n");
								inicio = time(NULL);
								printarMergeSort(0, max-1, vetor);
								fim = time(NULL);
        						tempo = difftime(fim, inicio);
        						printf("\n\n TEMPO DE EXECUÇÃO: %0.1f s", tempo);
								printf("\n------------------------------------------------------\n");
								break;
							case 2:
								printf("------------------------------------------------------\n");
								printf("\tORDENAÇÃO DECRESCENTE\n");
								printf("------------------------------------------------------\n");
								
								printf("\n------------------------------------------------------\n");
								break;
							case 3:
								printf("------------------------------------------------------\n");
								printf("\tDESORDENADO\n");
								printf("------------------------------------------------------\n");
								inicio = time(NULL);
								preencherRandom2(max, vetor);
								fim = time(NULL);
        						tempo = difftime(fim, inicio);
        						printf("\n\n TEMPO DE EXECUÇÃO: %0.1f s", tempo);
								printf("\n------------------------------------------------------\n");
								break;
							case 0:
								printf("\tVOLTANDO PARA O MENU PRINCIPAL\n");
								printf("\e[H\e[2J");
								break;
							default:
								printf("OPÇÃO INVÁLIDA\n");
						}

					}while(op2 != 0);
					break;
				case 7:
					printf("\n\n------------------------------------------------------\n");
					printf("\tRADIX SORT\n");
					printf("------------------------------------------------------\n");
					do{
						printf("------------------------------------------------------\n");
						printf("\tMENU DE OPÇÕES - ESCOLHA DO TIPO DE ORDENAÇÃO\n");
						printf("------------------------------------------------------\n");
						printf(" 1 --  ORDENAÇÃO CRESCENTE\n");
						printf(" 2 --  ORDENAÇÃO DECRESCENTE\n");
						printf(" 3 --  DESORDENADO\n");
						printf(" 0 --  VOLTAR MENU PRINCIPAL\n");
						printf("------------------------------------------------------\n");
						printf("OPÇÃO: ");
						scanf("%d", &op2);
						
						switch(op2){
							case 1:
								printf("------------------------------------------------------\n");
								printf("\tORDENAÇÃO CRESCENTE\n");
								printf("------------------------------------------------------\n");
								inicio = time(NULL);
								radixSort(max, vetor);
								fim = time(NULL);
        						tempo = difftime(fim, inicio);
        						printf("\n\n TEMPO DE EXECUÇÃO: %0.1f s", tempo);
								printf("\n------------------------------------------------------\n");
								break;
							case 2:
								printf("------------------------------------------------------\n");
								printf("\tORDENAÇÃO DECRESCENTE\n");
								printf("------------------------------------------------------\n");
								
								printf("\n------------------------------------------------------\n");
								break;
							case 3:
								printf("------------------------------------------------------\n");
								printf("\tDESORDENADO\n");
								printf("------------------------------------------------------\n");
								inicio = time(NULL);
								preencherRandom2(max, vetor);
								fim = time(NULL);
        						tempo = difftime(fim, inicio);
        						printf("\n\n TEMPO DE EXECUÇÃO: %0.1f s", tempo);
								printf("\n------------------------------------------------------\n");
								break;
							case 0:
								printf("\tVOLTANDO PARA O MENU PRINCIPAL\n");
								printf("\e[H\e[2J");
								break;
							default:
								printf("OPÇÃO INVÁLIDA\n");
						}
					}while(op2 != 0);
					break;
				case 0:
					
					break;
				default:
					printf("OPÇÃO INVÁLIDA, POR FAVOR ESCOLHA UMA VÁLIDA\n");
			}

		}while(op != 0);
	}while(op3 != 0);

	return 0;
}