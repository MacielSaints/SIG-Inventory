  
///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///      Projeto SIG-Inventory: Um Sistema de Controle de Estoques          ///
///                Developed by @MacielSaints - Oct, 2020                   ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

char menuInicial(void);
char telaMenuInicial(void);
void telaSobre(void);
char menuPrincipal(void);
char login (void);
char novoUsuario (void);
char sair (void);


int main(void) {

		menuInicial();
  
	return 0;
}

char menuInicial(void) {
	char opcao;
	do {
		opcao = telaMenuInicial();
		switch (opcao) {
			case '1' : 	login();
						break;
			case '2' : 	novoUsuario();
						break;
      case '3' : 	telaSobre();
						break;            
			case '0' : 	sair();
						break;
		}
	} while (opcao != '0');
  return 0;
}

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


char login (void) {
  printf("\033[2J\033[1;1H");
	printf("\n\n\nLogin.\n\n\n");
	printf("\n");
	printf("\n\n\t\t\t\t<<< Em Desenvolvimento >>>\n\n");
	printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
	getchar();
  return 0;
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

char sair (void) {
  printf("\033[2J\033[1;1H");
	printf("\n\n\nAté Logo  õ/.\n\n\n");
	printf("\n");
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