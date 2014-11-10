#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct{
 int origem;
 int destino;
}Aresta;

int main()
{
    int matriz[MAX][MAX];
    int encadeada[MAX];
    Aresta lista[MAX*MAX];
    int cont, cont2, opcao = 1, origem = 0, destino = 0, tamanho = -1, 	pos =0;

    while(tamanho < 0 || tamanho >= MAX){
     printf("Digite o tamaho da matriz. \n");
     scanf("%d", &tamanho);
    }

    for(cont = 0; cont < tamanho; cont++){
        encadeada[cont] = -1;
        for(cont2 = 0; cont2 < tamanho; cont2++){
          matriz[cont][cont2] = -1 ;
        }
    }


    do{
     system("cls")       ;
     Imprimir(matriz, tamanho);
     printf("\n");
     printf("Digite o vertice de origem\n");
     scanf("%d", &origem);
     printf("Digite o vertice de destino\n");
     scanf("%d", &destino);
     if(origem >= 0 && origem < tamanho  && destino >= 0 && destino < tamanho){
       matriz[origem][destino] = 1 ;
     }else{
       printf("Desejas continuar? (1 para continar)\n");
       scanf("%d", &opcao);
     }
    }while(opcao == 1);

  

   for(cont = 0; cont < tamanho-1; cont++){
   	if(Checar_Existir_Vetor(encadeada, cont, tamanho) == 0)
   	{
   	 printf("%d \n", cont)	;
   	 system("pause");
   	 system("cls");	
   	 Busca_Profundidade(matriz, encadeada, cont, tamanho, pos);
    }
   }
   system("cls");
   
   for(cont = 0; cont < tamanho; cont++){
     printf("%d ", encadeada[cont]);
   }
   return 0;
}











void Imprimir(int matriz[][MAX], int tamanho){
  int i,j;
  for(i = 0; i < tamanho; i++){
  printf("\n");
    for(j = 0; j <tamanho; j++){
        if(i == j || matriz[i][j] == -1){
          printf("-- ");
        }else{
         printf("0%d ", matriz[i][j]);
        }
    }

  }
}

void Busca_Profundidade(int matriz[][MAX],int encadeada[MAX], int origem,int tamanho, int pos){
 int cont, cont2, aux = 0, flag;
 
/*
for(cont = 0; cont < tamanho; cont++){
  	printf("\n");
   for(cont2 = 0; cont2 < tamanho; cont2++){
   	printf("%d ", matriz[cont][cont2]);
   }
  }
system("pause");
*/
 /*
 cont2 = Checar_Existir_Vetor(encadeada, cont, tamanho);
 printf("%d \n", cont2);*/
 for(cont = 0; cont < tamanho; cont++){ 	
  if(matriz[origem][cont] == 1 && Checar_Existir_Vetor(encadeada, cont, tamanho) == 0){
    //printf("%d - p \n", matriz[origem][cont]);
    pos++;
    Busca_Profundidade(matriz,encadeada, cont, tamanho,	pos);
    aux= cont;
  }
 }
    if(aux == 0){
     encadeada[0] = aux;	
    }else{
     encadeada[pos] = aux;	
    }
    flag++;
    
    /*p2  -> 0
	  p2  -> 2
	  
	*/
    //pos++;
    
 for(cont = 0; cont < tamanho; cont++){
  if(encadeada[cont] == -1 ){
    printf("-- ");
  }else{
   printf("%d  ", encadeada[cont]);
  }

 }
 system("pause");

}

int Checar_Existir_Vetor(int vetor[], int valor,int tamanho){
  int cont;
  for(cont = 0; cont < tamanho; cont++){
     if(vetor[cont] == valor){
       return 1;
     }else{
       return 0;
     }
  }
}
