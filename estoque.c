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
#include "relatorios.h"

//----------------------------------------------------
//
/// DEFINIÇÕES
//
//----------------------------------------------------

#define clear "\033[2J\033[1;1H" // PARÂMETRO PARA LIMPAR TELA
#define True 1
#define False 0

typedef struct produtos Produtos;

//----------------------------------------------------
//
/// STRUCT
//
//----------------------------------------------------

struct produtos {

  long long codBarras;
  char nome[80];
  char marca[32];
  int quantidade;
  float valor;
  int dia;
  int mes;
  int ano;

  char status;
};

//----------------------------------------------------
//
/// FUNÇÕES CONTROLE DE ESTOQUE
//
//----------------------------------------------------

Produtos* preencheProduto(void) {
  Produtos* prod;
  prod = (Produtos*) malloc(sizeof(Produtos));
  sig();

  printf("\nInforme a Código de Barras: ");
  scanf("%lld", &prod->codBarras);

  printf("Informe o Nome do Produto: ");
  scanf(" %80[^\n]", prod->nome);

  printf("Informe a Marca do Produto: ");
  scanf(" %32[^\n]", prod->marca);

  printf("Informe a Quantidade: ");
  scanf("%i", &prod->quantidade);

  printf("Informe o Valor Unitário: ");
  scanf("%f", &prod->valor);


  printf("\nInforme a data de entrada do produto (dd/mm/aaaa): ");
  scanf("%d/%d/%d",&prod->dia, &prod->mes, &prod->ano);
  getchar();
  while(!dataValida(prod->dia, prod->mes, prod->ano)){
    printf("\nData invalida! Digite novamente (dd/mm/aaaa): ");
    scanf("%d/%d/%d",&prod->dia, &prod->mes, &prod->ano);
    getchar();
  }

  prod->status = 'd';

  return prod;
}


void exibeProduto(Produtos* pd) {
  char situacao[20];

  if ((pd == NULL) || (pd->status == 'x')) {
    printf("\n ═══════ Produto Inexistente ═══════\n");
    estoque();
  } else {
    sig();
    printf("╔═══════════════════════════════════════════════════════════════════╗\n");
    printf("    Código de Barras: %lld\n", pd->codBarras);
    printf("    Produto: %s\n", pd->nome);
    printf("    Produto: %s\n", pd->marca);
    printf("    Quantidade: %d\n", pd->quantidade); 
    printf("    Valor Unitário: R$:%.2f\n", pd->valor);
    printf("    Data de registro: %d/%d/%d\n", pd->dia, pd->mes, pd->ano);
    printf("╚═══════════════════════════════════════════════════════════════════╝\n");
    printf("\n\n");

    if (pd->status == 'd') {
      strcpy(situacao, "Disponível");
    } else if (pd->status == 'i') {
      strcpy(situacao, "Indisponível");
    } else {
      strcpy(situacao, "Não informada");
    }
    printf("Situação do Produto: %s\n", situacao);
    getchar();
  }
}

void gravaProduto(Produtos* prod) {
  FILE* fp;
  fp = fopen("Produtos.dat", "ab");

  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
  }
  fwrite(prod, sizeof(Produtos), 1, fp);
  fclose(fp);
}



Produtos* buscaProduto(void) {
  FILE* fp;
  Produtos* prod;
  int aux;

  sig();
  printf("Códiogo de Barras: "); 
  scanf("%d", &aux);
  getchar();

  prod = (Produtos*) malloc(sizeof(Produtos));
  fp = fopen("Produtos.dat", "rb");

  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
  }

  while(!feof(fp)) {
    fread(prod, sizeof(Produtos), 1, fp);
    if ((prod->codBarras == aux) && (prod->status != 'x')) {
      fclose(fp);
      return prod;
    }
  }
  fclose(fp);
  return NULL;
}

void listaProdutos(void) {
  FILE* fp;
  Produtos* prod;
  sig();

  printf("\n = Lista de Produtos = \n"); 
  prod = (Produtos*) malloc(sizeof(Produtos));
  fp = fopen("Produtos.dat", "rb");

  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
  }
  while(fread(prod, sizeof(Produtos), 1, fp)) {
    if (prod->status != 'x') {
      exibeProduto(prod);
    }
  }
  fclose(fp);
}

void listaProdutosPorMarca(void) {
  FILE* fp;
  char aux[32];
  Produtos* prod;
  sig();

  printf("\n = Lista Produtos por Marca= \n"); 
  printf("\n = Busca Produto = \n"); 
  printf("Informe Marca: "); 
  scanf(" %s", aux);
  prod = (Produtos*) malloc(sizeof(Produtos));
  fp = fopen("Produtos.dat", "rb");

  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
  }
  while(fread(prod, sizeof(Produtos), 1, fp)) {
    if (strcmp(prod->marca, aux) == 0 && (prod->status != 'x')) {
      exibeProduto(prod);
    }
  }
  fclose(fp);
}

Produtos* entradaProduto(Produtos* pd) {
  char situacao[20];
  int aux;
  FILE *fp;
  fp = fopen("Produtos.dat", "r+b");

  if ((pd == NULL) || (pd->status == 'x')) {
    printf("\n= = = Produto Inexistente = = =\n");
  } else {
    sig();
    Produtos* prod;
    pd = (Produtos*) malloc(sizeof(Produtos));
    sig();

    printf("    Código de Barras: %lld\n", pd->codBarras);

    printf("\n═══════ %s ═══════\n", pd->nome);
    printf("    %s \n", pd->marca);
    printf("       R$:%.2f \n", pd->valor);
    printf("\n═══ Quantidade Atual: %i ═══\n", pd->quantidade);

    printf("Informe a Quantidade: ");
    scanf("%i", &aux);
    pd->quantidade += aux;
    getchar();

    printf("\n═══ Quantidade Atualizada: %i ═══\n", pd->quantidade);


    pd->status = 'd';
    fseek(fp, -1*sizeof(Produtos), SEEK_CUR);
    fwrite(pd, sizeof(Produtos), 1, fp);
    printf("\n═══════ Entrada Computada! ═══════\n");
    getchar();
  }
  fclose(fp);
  free(pd);
  return 0;
}

Produtos* saidaProduto(Produtos* pd) {
  char situacao[20];
  int aux;
  FILE *fp;
  fp = fopen("Produtos.dat", "r+b");

  if ((pd == NULL) || (pd->status == 'x')) {
    printf("\n= = = Produto Inexistente = = =\n");
  } else {
    sig();
    Produtos* prod;
    pd = (Produtos*) malloc(sizeof(Produtos));
    sig();

    printf("    Código de Barras: %lld\n", pd->codBarras);

    printf("\n═══════ %s ═══════\n", pd->nome);
    printf("    %s \n", pd->marca);
    printf("       R$:%.2f \n", pd->valor);
    printf("\n═══ Quantidade Atual: %i ═══\n", pd->quantidade);

    printf("Informe a Quantidade: ");
    scanf("%i", &aux);
    if (pd->quantidade < 0){
      printf("O Não há Unidades Suficientes Em Estoque.");
      getchar();
      estoque();
    }
    pd->quantidade -= aux;
    getchar();

    printf("\n═══ Quantidade Atualizada: %i ═══\n", pd->quantidade);


    pd->status = 'd';
    fseek(fp, -1*sizeof(Produtos), SEEK_CUR);
    fwrite(pd, sizeof(Produtos), 1, fp);
    printf("\n═══════ Saída Computada! ═══════\n");
    getchar();
  }
  fclose(fp);
  free(pd);
  return 0;
}

Produtos* atualizaProduto(Produtos* pd) {
  char situacao[20];
  FILE *fp;
  fp = fopen("Produtos.dat", "r+b");

  if ((pd == NULL) || (pd->status == 'x')) {
    printf("\n= = = Produto Inexistente = = =\n");
  } else {
    sig();
    Produtos* prod;
    pd = (Produtos*) malloc(sizeof(Produtos));
    sig();

    printf("    Código de Barras: %lld\n", pd->codBarras);

    printf("Informe o Nome do Produto: ");
    scanf(" %80[^\n]", pd->nome);

    printf("Informe a Marca do Produto: ");
    scanf(" %32[^\n]", pd->marca);

    printf("Informe a Quantidade: ");
    scanf("%i", &pd->quantidade);

    printf("Informe o Valor Unitário: ");
    scanf("%f", &pd->valor);

    printf("\nInforme a data de entrada do produto (dd/mm/aaaa): ");
    scanf("%d/%d/%d",&pd->dia, &pd->mes, &pd->ano);
    getchar();
    while(!dataValida(pd->dia, pd->mes, pd->ano)){
      printf("\nData invalida! Digite novamente (dd/mm/aaaa): ");
      scanf("%d/%d/%d",&pd->dia, &pd->mes, &pd->ano);
      getchar();
    }

    pd->status = 'd';
    fseek(fp, -1*sizeof(Produtos), SEEK_CUR);
    fwrite(pd, sizeof(Produtos), 1, fp);
    printf("\n═══════ Produto Alterado ═══════\n");
    getchar();
  }
  fclose(fp);
  free(pd);
  return 0;
}

void excluiProduto(Produtos* p) {
  FILE* fp;
  Produtos* prodArq;
  int aux;
  int achou = 0;
  if (p == NULL) {
    printf("Ops! O Produto Informado Não Existe!\n");
    getchar();
  }
  else {
    prodArq = (Produtos*) malloc(sizeof(Produtos));
    fp = fopen("Produtos.dat", "r+b");
    if (fp == NULL) {
      printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
      printf("Não é possível continuar este programa...\n");
      exit(1);
    }
    while(!feof(fp)) {
      fread(prodArq, sizeof(Produtos), 1, fp);
      if ((prodArq->codBarras == p->codBarras) && (prodArq->status != 'x')) {
        achou = 1;
        prodArq->status = 'x';
        fseek(fp, -1*sizeof(Produtos), SEEK_CUR);
        fwrite(prodArq, sizeof(Produtos), 1, fp);
        printf("\nProduto excluído com sucesso!!!\n");
        getchar();
      }
    }
    if (!achou) {
      printf("\nProduto não encontrado!\n");
      getchar();
    }
    fclose(fp);
  }
}
