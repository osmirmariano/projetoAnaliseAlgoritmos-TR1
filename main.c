#include <stdio.h>
#include <stdlib.h>
#include <time.h>

	/*--------------------FUNÇÃO PRINTAR O RESULTADO DOS MÉTODOS---------------------*/
	void printar(int max, int *vetor){
		for(int x = 0; x < max; x++)
			printf(" %d ", vetor[x]);
	}

	/*---------------------FUNÇÃO ORDENAÇÃO MÉTODO BUBBLE SORT-----------------------*/
	void bubbleSort(int max, int *vetor){
        int aux, cont = 0;
        float tempo;
        time_t inicio, fim;
        inicio = time(NULL);
        for(int x = 0; x < max-1; x++){
            for(int y = x+1; y < max; y++){
                if(vetor[x] > vetor[y]){
                	cont++;
                    aux = vetor[x];
                    vetor[x] = vetor[y];
                    vetor[y] = aux;
                }
            }
        }
        fim = time(NULL);
        tempo = difftime(fim, inicio);
        printar(max, vetor);
        printf("\n\n TEMPO DE EXECUÇÃO: %f", tempo);
        printf("\n\n NUMERO DE COMPARAÇÕES: %d", cont);
    }

    /*---------------------FUNÇÃO ORDENAÇÃO MÉTODO SELECTION SORT---------------------*/
	void selectionSort(int max, int *vetor){
		int cont = 0;
		float tempo;
        time_t inicio, fim;
        inicio = time(NULL);
		for(int x = 0; x < max; x++){
			int menor = vetor[x];
			for(int y = x+1; y < max; y++){
				if(vetor[y] < menor){
					cont++;
					int aux = menor;
					menor = vetor[y];
					vetor[y] = aux;
				}
			}
			vetor[x] = menor;
		}
		fim = time(NULL);
		tempo = difftime(fim, inicio);
		printar(max, vetor);
		printf("\n\n TEMPO DE EXECUÇÃO: %f", tempo);
		printf("\n\n NUMERO DE COMPARAÇÕES: %d", cont);
	};

	/*------------------------FUNÇÃO ORDENAÇÃO MÉTODO SHELL SORT-----------------------*/
	void shellSort(int max, int *vetor){
		int k, cont = 0;
		float tempo;
        time_t inicio, fim;
        inicio = time(NULL);
		if(max%2 == 0)
			k = max/2;
		else
			k = (max/2)+1;
		for(; k > 0; k--){
			for(int i = 0; i+k < max; i++){
				if(vetor[i] > vetor[i+k]){
					cont++;
					int aux = vetor[i];
					vetor[i] = vetor[i+k];
					vetor[i+k] = aux;
				}
			}
		}
		fim = time(NULL);
		tempo = difftime(fim, inicio);
		printar(max, vetor);
		printf("\n\n TEMPO DE EXECUÇÃO: %f", tempo);
		printf("\n\n NUMERO DE COMPARAÇÕES: %d", cont);
	};

	/*----------------------FUNÇÃO ORDENAÇÃO MÉTODO INSERTION SORT-----------------------*/
	void insertionSort(int max, int *vetor){
		int cont = 0;
		float tempo;
        time_t inicio, fim;
        inicio = time(NULL);
		for(int i = 1; i < max; i++){
			if(vetor[i] < vetor[i-1]){
				cont++;
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
		fim = time(NULL);
		tempo = difftime(fim, inicio);
		printar(max, vetor);
		printf("\n\n TEMPO DE EXECUÇÃO: %f", tempo);
		printf("\n\n NUMERO DE COMPARAÇÕES: %d", cont);
	};

	/*-----------------------FUNÇÃO ORDENAÇÃO MÉTODO RADIX SORT-----------------------*/
	void radixSort(int max, int *vetor) {
	    int *b;
	    int maior = vetor[0];
	    int exp = 1;

	    b = (int*)calloc(max, sizeof(int));
	    float tempo;
        time_t inicio, fim;
        inicio = time(NULL);
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
	    fim = time(NULL);
	    tempo = difftime(fim, inicio);
		printar(max, vetor);
		printf("\n\n TEMPO DE EXECUÇÃO: %f", tempo);
	};

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
		float tempo;
        time_t inicial, final;
        inicial = time(NULL);

		novoVetor = quickSort(inicio, fim, vetor);
		final = time(NULL);
	    tempo = difftime(final, inicial);
		printar(max, novoVetor);
		printf("\n\n TEMPO DE EXECUÇÃO: %f", tempo);
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
		float tempo;
        time_t inicial, final;
        inicial = time(NULL);

		novoVetor = mergeSort(inicio, fim, vetor);
		final = time(NULL);
	    tempo = difftime(final, inicial);
		printar(max, novoVetor);
		printf("\n\n TEMPO DE EXECUÇÃO: %f", tempo);
	}

	void preencherRandom2(int max, int *vetor){
		float tempo;
        time_t inicial, final;
        inicial = time(NULL);
		srand((unsigned)time(NULL));
		for(int x = 0; x < max; x++){
			int b = 1 + (rand() % max);
			vetor[x] = b;
		}
		final = time(NULL);
	    tempo = difftime(final, inicial);
		printar(max, vetor);
		printf("\n\n TEMPO DE EXECUÇÃO: %f", tempo);
	}

	void preencherRandom(int max, int *vetor){
		srand((unsigned)time(NULL));
		for(int x = 0; x < max; x++){
			int b = 1 + (rand() % max);
			vetor[x] = b;
		}
	}

	void menuTipoOrdenacao(int max, int *vetor){
		int op2;
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
					
					break;
				case 2:
					printf("------------------------------------------------------\n");
					printf("\tORDENAÇÃO DECRESCENTE\n");
					printf("------------------------------------------------------\n");
					//CHAMAR FUNÇÃO ORDENAÇÃO DECRESCENTE
					break;
				case 3:
					printf("------------------------------------------------------\n");
					printf("\tDESORDENADO");
					printf("------------------------------------------------------\n");
					//CHAMAR FUNÇÃO DESORDENADO
					break;
				default:
					printf("OPÇÃO INVÁLIDA\n");
			}

		}while(op2 != 0);
	}

int main(int argc, char const *argv[]){
	int op, op3;
	int max, *vetor;

	do{
		printf("------------------------------------------------------\n");
		printf("\tESCOLHA O TAMANHO DO VETOR\n");
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
				printf("PROGRAMA ENCERRADO COM SUCESSO\n");
				exit(0);
				break;
			default:
				printf("OPÇÃO INVÁLIDA, POR FAVOR ESCOLHA UMA VÁLIDA\n");
		}
		preencherRandom(max, vetor);

		do{
			printf("------------------------------------------------------\n");
			printf("\tMENU DE OPÇÕES - ESCOLHA DO MÉTODO DE ORDENAÇÃO\n");
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

			switch(op){
				case 1:
					printf("------------------------------------------------------\n");
					printf("\tBUBBLE SORT\n");
					printf("------------------------------------------------------\n");
					int op2;
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
								bubbleSort(max, vetor);
								printf("\n------------------------------------------------------\n");
								break;
							case 2:
								printf("------------------------------------------------------\n");
								printf("\tORDENAÇÃO DECRESCENTE\n");
								printf("------------------------------------------------------\n");
								//CHAMAR FUNÇÃO ORDENAÇÃO DECRESCENTE
								break;
							case 3:
								printf("------------------------------------------------------\n");
								printf("\tDESORDENADO\n");
								printf("------------------------------------------------------\n");
								preencherRandom2(max, vetor);
								printf("\n------------------------------------------------------\n");
								break;
							case 0:
								printf("\tVOLTANDO PARA O MENU PRINCIPAL\n");
							default:
								printf("OPÇÃO INVÁLIDA\n");
						}

					}while(op2 != 0);
					break;
				case 2:
					printf("------------------------------------------------------\n");
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
								selectionSort(max, vetor);
								printf("\n------------------------------------------------------\n");
								break;
							case 2:
								printf("------------------------------------------------------\n");
								printf("\tORDENAÇÃO DECRESCENTE\n");
								printf("------------------------------------------------------\n");
								//CHAMAR FUNÇÃO ORDENAÇÃO DECRESCENTE
								break;
							case 3:
								printf("------------------------------------------------------\n");
								printf("\tDESORDENADO\n");
								printf("------------------------------------------------------\n");
								preencherRandom2(max, vetor);
								printf("\n------------------------------------------------------\n");
								break;
							case 0:
								printf("\tVOLTANDO PARA O MENU PRINCIPAL\n");
							default:
								printf("OPÇÃO INVÁLIDA\n");
						}

					}while(op2 != 0);
					break;
				case 3:
					printf("------------------------------------------------------\n");
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
								shellSort(max, vetor);
								printf("\n------------------------------------------------------\n");
								break;
							case 2:
								printf("------------------------------------------------------\n");
								printf("\tORDENAÇÃO DECRESCENTE\n");
								printf("------------------------------------------------------\n");
								//CHAMAR FUNÇÃO ORDENAÇÃO DECRESCENTE
								break;
							case 3:
								printf("------------------------------------------------------\n");
								printf("\tDESORDENADO\n");
								printf("------------------------------------------------------\n");
								preencherRandom2(max, vetor);
								printf("\n------------------------------------------------------\n");
								break;
							case 0:
								printf("\tVOLTANDO PARA O MENU PRINCIPAL\n");
							default:
								printf("OPÇÃO INVÁLIDA\n");
						}

					}while(op2 != 0);
					break;
				case 4:
					printf("------------------------------------------------------\n");
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
								insertionSort(max, vetor);
								printf("\n------------------------------------------------------\n");
								break;
							case 2:
								printf("------------------------------------------------------\n");
								printf("\tORDENAÇÃO DECRESCENTE\n");
								printf("------------------------------------------------------\n");
								//CHAMAR FUNÇÃO ORDENAÇÃO DECRESCENTE
								break;
							case 3:
								printf("------------------------------------------------------\n");
								printf("\tDESORDENADO\n");
								printf("------------------------------------------------------\n");
								preencherRandom2(max, vetor);
								printf("\n------------------------------------------------------\n");
								break;
							case 0:
								printf("\tVOLTANDO PARA O MENU PRINCIPAL\n");
							default:
								printf("OPÇÃO INVÁLIDA\n");
						}

					}while(op2 != 0);
					break;
				case 5:
					printf("------------------------------------------------------\n");
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
								printarQuickSort(0, max-1, vetor);
								printf("\n------------------------------------------------------\n");
								break;
							case 2:
								printf("------------------------------------------------------\n");
								printf("\tORDENAÇÃO DECRESCENTE\n");
								printf("------------------------------------------------------\n");
								//CHAMAR FUNÇÃO ORDENAÇÃO DECRESCENTE
								break;
							case 3:
								printf("------------------------------------------------------\n");
								printf("\tDESORDENADO\n");
								printf("------------------------------------------------------\n");
								preencherRandom2(max, vetor);
								printf("\n------------------------------------------------------\n");
								break;
							case 0:
								printf("\tVOLTANDO PARA O MENU PRINCIPAL\n");
							default:
								printf("OPÇÃO INVÁLIDA\n");
						}

					}while(op2 != 0);
					break;
				case 6:
					printf("------------------------------------------------------\n");
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
								printarMergeSort(0, max-1, vetor);
								printf("\n------------------------------------------------------\n");
								break;
							case 2:
								printf("------------------------------------------------------\n");
								printf("\tORDENAÇÃO DECRESCENTE\n");
								printf("------------------------------------------------------\n");
								//CHAMAR FUNÇÃO ORDENAÇÃO DECRESCENTE
								break;
							case 3:
								printf("------------------------------------------------------\n");
								printf("\tDESORDENADO\n");
								printf("------------------------------------------------------\n");
								preencherRandom2(max, vetor);
								printf("\n------------------------------------------------------\n");
								break;
							case 0:
								printf("\tVOLTANDO PARA O MENU PRINCIPAL\n");
							default:
								printf("OPÇÃO INVÁLIDA\n");
						}

					}while(op2 != 0);
					break;
				case 7:
					printf("------------------------------------------------------\n");
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
								radixSort(max, vetor);
								printf("\n------------------------------------------------------\n");
								break;
							case 2:
								printf("------------------------------------------------------\n");
								printf("\tORDENAÇÃO DECRESCENTE\n");
								printf("------------------------------------------------------\n");
								//CHAMAR FUNÇÃO ORDENAÇÃO DECRESCENTE
								break;
							case 3:
								printf("------------------------------------------------------\n");
								printf("\tDESORDENADO\n");
								printf("------------------------------------------------------\n");
								preencherRandom2(max, vetor);
								printf("\n------------------------------------------------------\n");
								break;
							case 0:
								printf("\tVOLTANDO PARA O MENU PRINCIPAL\n");
							default:
								printf("OPÇÃO INVÁLIDA\n");
						}

					}while(op2 != 0);
					break;
				case 0:
					printf("\tVOLTANDO PARA O MENU PRINCIPAL\n");
					break;
				default:
					printf("OPÇÃO INVÁLIDA, POR FAVOR ESCOLHA UMA VÁLIDA\n");
			}

		}while(op != 0);
	}while(op3 != 0);

	return 0;
}





