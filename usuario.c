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
#include "estoque.h"



//----------------------------------------------------
//
/// DEFINIÇÕES
//
//----------------------------------------------------

#define clear "\033[2J\033[1;1H" // PARÂMETRO PARA LIMPAR TELA
#define True 1
#define False 0

typedef struct user User;


//----------------------------------------------------
//
/// STRUCT
//
//----------------------------------------------------

struct user {
  long int cpf;
  long int senha;

  char status;
};


//----------------------------------------------------
//
/// FUNÇÕES DE ACESSO AO SISTEMA
//
//----------------------------------------------------

User* preencheUser(void) {
  User* aln;
  aln = (User*) malloc(sizeof(User));
  telaNovoUsuario();

  printf("\nInforme seu CPF: ");
  scanf("%ld", &aln->cpf);
  getchar();
  printf("Senha: ");
  scanf("%ld", &aln->senha);
  getchar();
  aln->status = 'm';
  return aln;
}


void loginUser(User* al) {
  char situacao[20];
  if ((al == NULL) || (al->status == 'x')) {
    printf("\n= = = Usuário Inexistente = = =\n");
  } else {
    telaBemVindo();
    getchar();
    telaEstoque();
  }
}

void gravaUser(User* aln) {
  FILE* fp;
  fp = fopen("User.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
  }
  fwrite(aln, sizeof(User), 1, fp);
  fclose(fp);
}


User* buscaUser(void) {
  FILE* fp;
  User* aln;
  int id;
  int pwd;

  telaSigLogin(); 
  printf("Informe seu CPF: "); 
  scanf("%d", &id);
  getchar();

  printf("Informe sua senha: "); 
  scanf("%d", &pwd);
  getchar();

  aln = (User*) malloc(sizeof(User));
  fp = fopen("User.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
  }
  while(!feof(fp)) {
    fread(aln, sizeof(User), 1, fp);
    if ((aln->cpf == id) && (aln->senha == id) && (aln->status != 'x')) {
      fclose(fp);
      return aln;
    }else{
      printf("\n\n ~> Entrada Invalida <~,\n");
      getchar();
      return 0;
    }
  }
  fclose(fp);
  return NULL;
}
