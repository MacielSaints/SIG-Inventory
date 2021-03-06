///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///      Projeto SIG-Inventory: Um Sistema de Controle de Estoques          ///
///                Developed by @MacielSaints - Jan, 2021                   ///
///////////////////////////////////////////////////////////////////////////////

#include<stdio.h>

char telaMenuInicial(void) {
	char op;
  printf("\033[2J\033[1;1H");
	printf("╔═════════════════════════════════╗\n");
  printf("║          SIG-Inventory          ║\n");
  printf("╚═════════════════════════════════╝\n");

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

char novoUsuario (void) {
  printf("\033[2J\033[1;1H");
	printf("\n\n\nNovo Usuário.\n\n\n");
	printf("\n");
	printf("\n\n\t\t\t\t<<< Em Desenvolvimento >>>\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
  return 0;
}


void telaSobre(void) {
  printf("\033[2J\033[1;1H");
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

char telaSair (void) {
  printf("\033[2J\033[1;1H");
	printf("\n\n\nAté Logo  õ/.\n\n\n");

  return 0;
}