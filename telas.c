///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///      Projeto SIG-Inventory: Um Sistema de Controle de Estoques          ///
///                Developed by @MacielSaints - Jan, 2021                   ///
///////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include "estoque.h"

#define clear "\033[2J\033[1;1H" // PARÂMETRO PARA LIMPAR TELA

void sig(void) {
	printf("╔═════════════════════════════════╗\n");
  printf("║          SIG-Inventory          ║\n");
  printf("╚═════════════════════════════════╝\n");
}

char telaMenuInicial(void) {
	char op = {0};
  printf(clear);
  sig();

  printf("╔══════════════════════════════════╗\n");
  printf("║ ████████     MENU      █████████ ║\n");
  printf("║══════════════════════════════════║\n");
  printf("║          1 - Login               ║\n");
  printf("║          2 - Novo Usuário        ║\n");
  printf("║          3 - Sober               ║\n");
  printf("║          0 - Exit                ║\n");
  printf("╚══════════════════════════════════╝\n");
  printf("~>: ");
  scanf("%c", &op);
	printf("\n");
	getchar();
	return op;
}

char telaEstoque(void) {
	char op = {0};
  printf(clear);
  sig();

  printf("╔══════════════════════════════════╗\n");
  printf("║ ████  CONTROLE DE ESTOQUE  █████ ║\n");
  printf("║══════════════════════════════════║\n");
  printf("║       1 - Listar                 ║\n");
  printf("║       2 - Cadastrar              ║\n");
  printf("║       3 - Computar Entrada       ║\n");
  printf("║       4 - Computar Saída         ║\n");
  printf("║       5 - Excluir                ║\n");
  printf("║       6 - Atualizar              ║\n");
  printf("║       7 - Voltar                 ║\n");
  printf("╚══════════════════════════════════╝\n");
  printf("~>: ");
  scanf("%c", &op);
	printf("\n");
	getchar();
	return op;
}

char novoUsuario (void) {
  printf(clear);
  sig();
	printf("\n\n\t\t\t\t<<< Em Desenvolvimento >>>\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
  return 0;
}


char telaSair (void) {
  printf(clear);
	printf("\n\n\nAté Logo  õ/.\n\n\n");

  return 0;
}

void lista(void) {
  printf(clear);
  listaProdutos();
	getchar();
}
void cadastrar(void) {
  printf(clear);
  cadastraProduto();
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