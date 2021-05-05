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

#include<stdio.h>
#include <stdlib.h>

#include "estoque.h"
#include "cruds.h"
#include "valid.h"
#include "usuario.h"


//----------------------------------------------------
//
/// DEFINIÇÕES
//
//----------------------------------------------------

#define clear "\033[2J\033[1;1H" // PARÂMETRO PARA LIMPAR TELA

//----------------------------------------------------
//
/// TELAS
//
//----------------------------------------------------

char sig(void) {
  printf(clear);
	printf("╔═════════════════════════════════╗\n");
  printf("║          SIG-Inventory          ║\n");
  printf("╚═════════════════════════════════╝\n");
  return 0;
}

char telaLogin (void) {
  printf(clear);
	sig();

	printf("╔═════════════════════════════════╗\n");
  printf("║              LOGIN              ║\n");
  printf("╚═════════════════════════════════╝\n");
  
  return 0;
}

char telaBemVindo(void) {
  printf(clear);
	printf("╔═════════════════════════════════╗\n");
  printf("║           BEM VINDO             ║\n");
  printf("║               AO                ║\n");
  printf("║          SIG-Inventory          ║\n");
  printf("╚═════════════════════════════════╝\n");
  printf("\n\n\n\n\n\t>>> Tecle <ENTER> para continuar...\n");
  return 0;
}

char telaSigLogin(void) {
  printf(clear);
	printf("╔═════════════════════════════════╗\n");
  printf("║          SIG-Inventory          ║\n");
  printf("║             LOGIN               ║\n");
  printf("╚═════════════════════════════════╝\n");
  return 0;
}

char telaMenuInicial(void) {
	char op;
  sig();

  printf("╔══════════════════════════════════╗\n");
  printf("║ ████████     MENU      █████████ ║\n");
  printf("║══════════════════════════════════║\n");
  printf("║          1 - Login               ║\n");
  printf("║          2 - Novo Usuário        ║\n");
  printf("║          3 - Sobre               ║\n");
  printf("║          0 - Exit                ║\n");
  printf("╚══════════════════════════════════╝\n");
  printf("~>: ");
  scanf("%c", &op);
	printf("\n");
	getchar();
	return op;
}

char telaEstoque(void) {
	char op;
  printf(clear);
  sig();

  printf("╔══════════════════════════════════╗\n");
  printf("║ ████  CONTROLE DE ESTOQUE  █████ ║\n");
  printf("║══════════════════════════════════║\n");
  printf("║       1 - Cadastrar              ║\n");
  printf("║       2 - Computar Entrada       ║\n");
  printf("║       3 - Computar Saída         ║\n");
  printf("║       4 - Excluir                ║\n");
  printf("║       5 - Atualizar              ║\n");
  printf("║       6 - Produto Especifico     ║\n");
  printf("║       7 - Relatório              ║\n");
  printf("║       8 - Volta                  ║\n");
  printf("║       0 - Exit                   ║\n");
  printf("╚══════════════════════════════════╝\n");
  printf("~>: ");
  scanf("%c", &op);
	getchar();
  return op;
}
char telaNovoUsuario (void) {
  printf(clear);
  sig();
  printf("╔═════════════════════════════════╗\n");
  printf("║        CADASTRO DE USUÁRIO      ║\n");
  printf("╚═════════════════════════════════╝\n");

  return 0;
}


char telaSair (void) {
  sig();
	printf("\n\n\n            Até Logo  õ/.\n\n\n");

  exit(1);
}

char lista(void) {
  printf(clear);
  listaProdutos();
  return 0;
}
char cadastrar(void) {
  printf(clear);
  //cadastraProduto();
  return 0;
}

void Indisponivel(void) {
    printf("OPÇÃO INDISPONÍVEL!!!\n");
}
void listaEspecifc(void) {
  printf(clear);
	printf("\n\n\nMódulo Produto Especifico\n\n\n");
	printf("\n");
	printf("\n\n\t\t\t\t<<< Em Desenvolvimento >>>\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}
void relatorio(void) {
  printf(clear);
	printf("\n\n\nMódulo Relatório\n\n\n");
	printf("\n");
	printf("\n\n\t\t\t\t<<< Em Desenvolvimento >>>\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}
void entrada(void) {
  printf(clear);
	printf("\n\n\nMódulo Computar Entrada\n\n\n");
	printf("\n");
	printf("\n\n\t\t\t\t<<< Em Desenvolvimento >>>\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}
void saida(void) {
  printf(clear);
	printf("\n\n\nMódulo Computar Saída\n\n\n");
	printf("\n");
	printf("\n\n\t\t\t\t<<< Em Desenvolvimento >>>\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void excluir(void) {
  printf(clear);
	printf("\n\n\nMódulo Excluir\n\n\n");
	printf("\n");
	printf("\n\n\t\t\t\t<<< Em Desenvolvimento >>>\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}
void atualizar(void) {
  printf(clear);
	printf("\n\n\nMódulo Atualizar \n\n\n");
	printf("\n");
	printf("\n\n\t\t\t\t<<< Em Desenvolvimento >>>\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
}

void telaSobre(void) {
  printf(clear);
	printf("\n");
	printf("█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n");
	printf("█                             █ █ █▀▀ █▀▀█ █▄ █                               █\n");
	printf("█                             █ █ █▀▀ █ █  █ ▀                                █\n");
	printf("█                             ▀▀▀ ▀   ▀  ▀ ▀                                  █\n");
	printf("█               Universidade Federal do Rio Grande do Norte                   █\n");
	printf("█                   Centro de Ensino Superior do Seridó                       █\n");
	printf("█                 Departamento de Computação e Tecnologia                     █\n");
	printf("█         Projeto SIG-Inventory: Um Sistema de Controle de Estoques           █\n");
	printf("█                   Developed by @MacielSaints - Jan, 2021                    █\n");
	printf("█                                                                             █\n");
	printf("▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n");

  printf("\n");

  printf("█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█\n");
  printf("█                   ╔═════════════════════════════════╗                       █\n");
  printf("█                   ║ Sistema de Controle de Estoques ║                       █\n");
  printf("█                   ╚═════════════════════════════════╝                       █\n");
  printf("█    Projeto desenvolvido na disciplina DCT1106 - As empresas da              █\n");
  printf("█    atualidade utilizam complexos sistemas gerenciais para, entre            █\n");
  printf("█    várias outras funções, gerenciar seu estoque de produtos.                █\n");
  printf("█    Gerenciar estoques de maneira eficiente, sem a ajuda de um sistema       █\n");
  printf("█    automatizado, é algo difícil para as pequenas empresas e impossível      █\n");
  printf("█    para as grandes. O presente projeto tem como objetivo propor um          █\n");
  printf("█    software que ofereça funcionalidades básicas relacionadas ao             █\n");
  printf("█    controle de inventário de uma empresa, visando facilitar a               █\n");
  printf("█    administração de estoques de produtos dos mais diversos tipos.           █\n");
  printf("█                                                                             █\n");
  printf("▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀\n");
  printf("\n");
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
}