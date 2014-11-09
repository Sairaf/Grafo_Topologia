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
    int cont, cont2, opcao = 1, origem = 0, destino = 0, tamanho = -1, pos =0;

    while(tamanho < 0 || tamanho >= MAX){
     printf("Digite o tamaho da matriz. \n");
     scanf("%d", &tamanho);
    }

    for(cont = 0; cont < tamanho; cont++){
        encadeada[cont] = 0;
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
   for(cont = 0; cont < tamanho; cont++){

    printf("%d ", encadeada[cont]);
   }


   for(cont = 0; cont < tamanho; cont++){
      Busca_Profundidade(matriz, encadeada, cont, tamanho, pos);
   }

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
 int cont, aux = 0, cont2, flag;

 for(cont = 0; cont < tamanho; cont++){
  if(matriz[origem][cont] == 1 ){

  //  printf("Foi %d\n", cont+1);
    //system("pause");
    Busca_Profundidade(matriz,encadeada, cont, tamanho,pos);
    aux = cont;
    //system("pause");
    //printf("Teste\n");
  }
 }

 for(cont2 = 0; cont2 < tamanho; cont2++)
 {
  if(aux != encadeada[cont2])
  {
   flag = 1;
  }else{
   flag = 0;
  }

  if(flag == 1){
   encadeada[pos] = aux;
   pos++;
  }
 }

 // printf("Iteracao %d: ", cont+1);
 // printf("%d + %d - ",aux, cont );

}
