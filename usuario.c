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
#include "valid.h"

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
  long long cpf;
  long long senha;

  char status;
};


//----------------------------------------------------
//
/// FUNÇÕES DE ACESSO AO SISTEMA
//
//----------------------------------------------------

User* preencheUser(void) {
  char aux[12];
  User* id;
  id = (User*) malloc(sizeof(User));
  telaNovoUsuario();

  printf("\nInforme seu CPF (Sómente N°s.): ");
  scanf("%s", aux);
  id->cpf = validaCpf(aux);
  getchar();
  printf("Senha: ");
  scanf("%llu", &id->senha);
  getchar();
  id->status = 'm';
  return id;
}


void loginUser(User* id) {
  char situacao[20];
  if ((id == NULL) || (id->status == 'x')) {
    printf("\n= = = Usuário Inexistente = = =\n");
  } else {
    telaBemVindo();
    getchar();
    estoque();
  }
}

void gravaUser(User* id) {
  FILE* fp;
  fp = fopen("User.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
  }
  fwrite(id, sizeof(User), 1, fp);
  fclose(fp);
}

User* buscaUser(void) {
  FILE* fp;
  User* id;
  long long usr;
  long long pwd;

  telaSigLogin(); 
  printf("Informe seu CPF: "); 
  scanf("%llu", &usr);
  getchar();

  printf("Informe sua senha: "); 
  scanf("%llu", &pwd);
  getchar();

  id = (User*) malloc(sizeof(User));
  fp = fopen("User.dat", "rb");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
  }
  while(!feof(fp)) {
    fread(id, sizeof(User), 1, fp);
    if ((id->cpf == usr) && (id->senha == pwd) && (id->status != 'x')) {
      fclose(fp);
      return id;
    }else{
      printf("\n\n ~> Entrada Invalida <~,\n");
      getchar();
      return 0;
    }
  }
  fclose(fp);
  return NULL;
}