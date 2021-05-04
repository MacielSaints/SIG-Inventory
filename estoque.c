///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///      Projeto SIG-Inventory: Um Sistema de Controle de Estoques          ///
///                Developed by @MacielSaints - Jan, 2021                   ///
///////////////////////////////////////////////////////////////////////////////

//----------------------------------------------------
//
/// BIBLIOTECAS
//
//----------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "valid.h"
#include "telas.h"
#include "cruds.h"
#include "usuario.h"

//----------------------------------------------------
//
/// DEFINIÇÕES
//
//----------------------------------------------------

#define clear "\033[2J\033[1;1H" // PARÂMETRO PARA LIMPAR TELA
#define True 1
#define False 0

typedef struct produtos Produtos;
typedef struct Produtos prod;

//----------------------------------------------------
//
/// STRUCT
//
//----------------------------------------------------

struct produtos {
  
  char nome[80];
  int quantidade;
  float valor;
  int dia;
  int mes;
  int ano;

  char status;

};


//----------------------------------------------------
//
/// FUNÇÃO CADASTRO DE PRODUTOS
//
//----------------------------------------------------

char cadastraProduto (void) {

  Produtos* prod;
  prod = (Produtos*) malloc(sizeof(Produtos));
  FILE *fp;
  fp = fopen("Produtos.txt", "at");

	if (fp == NULL){
		printf("Erro na criacao do arquivo\n!");
		exit(1);
  }

  printf("\nDigite o nome do produto: ");
  scanf(" %80[^\n]", prod->nome);

  printf("\nDigite a quantidade: ");
  scanf("%i", &prod->quantidade);

  printf("\nDigite o valor: ");
  scanf("%f", &prod->valor);

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

  printf("\nNovo Produto Cadastrado com Sucesso!\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
  telaEstoque();
  return 0;
}

//----------------------------------------------------
//
/// FUNÇÃO LISTA DE PRODUTOS
//
//----------------------------------------------------

char listaProdutos (void) {

  printf(clear);
  FILE* fp;
  Produtos* prod;
  fp = fopen("Produtos.txt", "rt");
  if (fp == NULL){
    printf("\nErro na abertura do arquivo\n!");
  }
  prod = (Produtos*) malloc(sizeof(Produtos));

  sig();
  
  while (fread(prod, sizeof(Produtos), 1, fp)) {

    printf("╔═══════════════════════════════════════════════════════════════════╗\n");
    printf("    Produto: %s\n", prod->nome);                                         
    printf("    Data de registro: %d/%d/%d\n", prod->dia, prod->mes, prod->ano);  
    printf("    Quantidade: %d\n", prod->quantidade);
    printf("    Valor: R$:%.2f\n", prod->valor);
    printf("╚═══════════════════════════════════════════════════════════════════╝\n");
    printf("\n\n");
  }

  fclose(fp);
  free(prod);
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
  telaEstoque();
  return 0;
}
