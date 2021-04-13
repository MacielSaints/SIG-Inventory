#include <stdio.h>
#include <stdlib.h>

#include "valid.h"

//----------------------------------------------------
//
/// DEFINIÇÕES ESTRUTURAS
//
//----------------------------------------------------

typedef struct produtos Produtos;
typedef struct Produtos prod;


//----------------------------------------------------
//
/// STRUCT
//
//----------------------------------------------------

struct produtos {

    char nome[80];
    int quntudade;
    float valor;
    int dia;
    int mes;
    int ano;

};


//----------------------------------------------------
//
/// FUNÇÃO CADASTRO DE PRODUTOS
//
//----------------------------------------------------

void cadastraProduto (void) {

  Produtos* prod;
  prod = (Produtos*) malloc(sizeof(Produtos));
  FILE *fp;
  fp = fopen("Produtos.txt", "a+t");

	if (fp == NULL){
		printf("Erro na criacao do arquivo\n!");
		exit(1);
  }

  printf("\nDigite o nomedo produto: ");
  scanf(" %80[^\n]", prod->nome);

  printf("\nInforme a data de entrada do produto (dd/mm/aaaa): ");
  scanf("%d/%d/%d",&prod->dia, &prod->mes, &prod->ano);
  getchar();

  while(!dataValida(prod->dia, prod->mes, prod->ano)){
  printf("\nData invalida! Digite novamente (dd/mm/aaaa): ");
      scanf("%d/%d/%d",&prod->dia, &prod->mes, &prod->ano);
      getchar();
  }
  fwrite(prod, sizeof(Produtos), 1, fp);
  fclose(fp);
  free(prod);
}