#include <stdio.h>
#include <stdlib.h>
#include <time.h>


	// void printar(){
	// 	for(int x = 0; x < MAX; x++)
	// 		printf("%d", vetor[x])
	// }
	void bubbleSort(int max, int *vetor){
        int aux;
        printf("%d\n", max);
        for(int x = 0; x < max-1; x++){
        	printf("Teste 1\n");	
            for(int y = x+1; y < max; y++){
            	printf("Teste 2\n");
                if(vetor[x] > vetor[y]){
                	printf("Teste 3\n");
                    aux = vetor[x];
                    vetor[x] = vetor[y];
                    vetor[y] = aux;
                }
            }
        }
        printf("Teste\n");
        for(int x = 0; x < max; x++){
			printf(" %d ", vetor[x]);
		}
    }

	// void bubbleSort(int max, int *vetor){
	// 	for(int x = max; x > 0; x--){
	// 		for(int y = 0; y < x-1; y++){
	// 			if(vetor[y] > vetor[y+1]){
	// 				int aux = vetor[y+1];
	// 				vetor[y+1] = vetor[y];
	// 				vetor[y] = aux;
	// 			}
	// 		}
	// 	}

	// 	for(int x = 0; x < max; x++){
	// 		printf(" %d ", vetor[x]);
	// 	}

	// }

	void selectionSort(int max, int *vetor){
		for(int x = 0; x < max; x++){
			int menor = vetor[x];
			for(int y = x+1; y < max; y++){
				if(vetor[y] < menor){
					int aux = menor;
					menor = vetor[y];
					vetor[y] = aux;
				}
			}
			vetor[x] = menor;
		}
		for(int x = 0; x < max; x++){
			printf(" %d ", vetor[x]);
		}
	};

	// void shellSort(){
	// 	int k;
	// 	if(MAX%2 == 0)
	// 		k = MAX/2;
	// 	else
	// 		k = (MAX/2)+1;
	// 	for(; k > 0; k--){
	// 		for(int i = 0; i+k < MAX; i++){
	// 			if(vetor[i] > vetor[i+k]){
	// 				int aux = vetor[i];
	// 				vetor[i] = vetor[i+k];
	// 				vetor[i+k] = aux;
	// 			}
	// 		}
	// 	}
	// 	printar();
	// };

	// void insertionSort(){
	// 	for(int i = 1; i < MAX; i++){
	// 		if(vetor[i] < vetor[i-1]){
	// 			int aux = vetor[i];
	// 			int p;
	// 			for(p = i-1; p >= 0; p--){
	// 				if(aux > vetor[p])
	// 					break;
	// 			}
	// 			for(int j = i; j > (p+1); j--){
	// 				vetor[j] = vetor[j-1];
	// 			}
	// 			vetor[p+1] = aux;
	// 		}
	// 	}
	// 	printar();
	// };

	// void quickSort(int inicio, int fim){
	//     int i, j, pivo, metade, aux;
	//     i = inicio;
	//     j = fim;

	//     metade = (int)((i+j)/2);
	//     pivo =  vetor[metade];

	//     do{
	//     	while(vetor[i] < pivo)
	//         	i = i+1;
	//         while(vetor[j] > pivo)
	//             j = j-1;
	//         if(i <= j){
	//             aux = vetor[i];
	//             vetor[i] = vetor[j];
	//             vetor[j] = aux;
	//             i = i+1;
	//             j = j-1;
	//         }
	//     }while(j > i);

	//     if(inicio < j)
	//     	quickSort(inicio,j);
	// 	if(i < fim)
	//         quickSort(i,fim);
	// };

	// void MergeSort(int inicio, int fim) {
 //        int i, j, k, tam, *aux;
 //        if(inicio == fim)
 //            return;
 //        //ordena recursivamente as duas metades dos vetores
 //        tam = (inicio + fim)/2;
 //        MergeSort(inicio, tam);
 //        MergeSort(tam+1,fim);
 //        //Intercala no vetor auxiliar
 //        i = inicio;
 //        j = tam+1;
 //        k = 0;
 //        aux = new int[fim-inicio+1];
 //        while(i < tam+1 || j  < fim+1){
 //            if(i == tam+1) { // i passou do final da primeira metade, pega v[j]
 //             aux[k] = vetor[j];
 //             j++;
 //             k++;
 //            }else{
 //                if(j==fim+1){ // j passa do final da segunda metade, pega v[i]
 //                    aux[k] = vetor[i];
 //                    i++;
 //                    k++;
 //                }else{
 //                    if(vetor[i] < vetor[j]){
 //                       aux[k] = vetor[i];
 //                       i++;
 //                       k++;
 //                    }else{
 //                      aux[k] = vetor[j];
 //                      j++;
 //                      k++;
 //                    };
 //                };
 //            };

 //        };
 //        // copia o vetor intercalado para original
 //        for(i = inicio; i <= fim; i++) {
 //          vetor[i] = aux[i-inicio];
 //        };
 //        delete(aux);
 //    };

	// void radixSort(int tamanho) {
	//     int *b;
	//     int maior = vetor[0];
	//     int exp = 1;

	//     b = (int *)calloc(tamanho, sizeof(int));

	//     for(int x = 0; x < tamanho; x++) {
	//     	if(vetor[x] > maior)
	//         	maior = vetor[x];
	//     }

	//     while(maior/exp > 0) {
	//     	int bucket[10] = { 0 };
	//         for(i = 0; i < tamanho; i++)
	//         	bucket[(vetor[i]/exp) % 10]++;
	//         for(i = 1; i < 10; i++)
	//         	bucket[i] += bucket[i-1];
	//         for(i = tamanho - 1; i >= 0; i--)
	//         	b[--bucket[(vetor[i]/exp)%10]] = vetor[i];
	//         for(i = 0; i < tamanho; i++)
	//         	vetor[i] = b[i];
	//         exp *= 10;
	//     }
	//     free(b);
	// };


	void menuTipoOrdenacao(){
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
					//CHAMAR FUNÇÃO ORDENAÇÃO CRESCENTE
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

	void preencherRandom(int max, int *vetor){
		//srand(time(NULL));
		srand((unsigned)time(NULL));
		for(int x = 0; x < max; x++){
			int b = 1 + (rand() % max);
			vetor[x] = b;
		}
		for(int x = 0; x < max; x++){
			printf(" %d ", vetor[x]);
		}
	}

int main(int argc, char const *argv[]){
	int op, op3, max = 1, enviar;
	int vetor[max];
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
				vetor[max];
				break;
			case 2:
				max = 100;
				vetor[max];
				break;
			case 3:
				max = 1000;
				vetor[1000];
				break;
			case 4:
				max = 50000;
				vetor[max];
				break;
			case 5:
				max = 100000;
				vetor[max];
				break;
		}
		printf("TAMANHO 1: %d\n", max);
		enviar = max;
		preencherRandom(max, vetor);
		printf("\n");
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
					printf("TAMANHO: %d\n", enviar);
					bubbleSort(enviar, vetor);
					//menuTipoOrdenacao();
					printf("\n------------------------------------------------------\n");
					break;
				case 2:
					printf("------------------------------------------------------\n");
					printf("\tSELECT SORT\n");
					printf("------------------------------------------------------\n");
					selectionSort(enviar, vetor);
					printf("\n------------------------------------------------------\n");
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
	}while(op3 != 0);

	

	return 0;
}