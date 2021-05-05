/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "telas.h"
#include "cruds.h"
#include "usuario.h"
#include "valid.h"
#include "usuario.h"

#define clear "\033[2J\033[1;1H" // PARÂMETRO PARA LIMPAR TELA


char telaRelatorio(void);
char crudRelatorio(void);



char crudRelatorio(void) {
	char op;
  do {
    op = telaRelatorio();

    switch (op) {
    case '1': buscaUser();
              loginUser();
              break;
    }
  } while (op != '0');
return 0;
}


char telaRelatorio(void) {
	char op;
  printf(clear);
  sig();

  printf("╔══════════════════════════════════╗\n");
  printf("║ ████  RELATORIO DE ESTOQUE  ████ ║\n");
  printf("║══════════════════════════════════║\n");
  printf("║       1 - Listar por Nome        ║\n");
  printf("║       2 - Listar por Marca       ║\n");
  printf("║       3 - Listar por  Qunatidade ║\n");
  printf("║       4 - Menu Estoque           ║\n");
  printf("║       5 - Menu Inicial           ║\n");
  printf("║       0 - Exit                   ║\n");
  printf("╚══════════════════════════════════╝\n");
  printf("~>: ");
  scanf("%c", &op);
	getchar();
  return op;
}

char* telaTurmasPorHorario(void) {
	char* nome;

    nome = (char*) malloc(11*sizeof(char));

  printf(clear);
	printf("\n");
	printf("╔═══════════════════════════════════════════════════════════════════════════╗\n");
	printf("║                                                                           ║\n");
	printf("║          ===================================================              ║\n");
	printf("║          = = = = = = = = = = = = = = = = = = = = = = = = = =              ║\n");
	printf("║          = = = = = =   Projeto SIG-Inventory     = = = = = =              ║\n");
	printf("║          = = = = = = = = = = = = = = = = = = = = = = = = = =              ║\n");
	printf("║          ===================================================              ║\n");
	printf("║                Developed by  @macielsaints - Jan, 2021                    ║\n");
	printf("║                                                                           ║\n");
	printf("║═══════════════════════════════════════════════════════════════════════════║\n");
	printf("║                                                                           ║\n");
	printf("║           = = = = = = = = = = = = = = = = = = = = = = = =                 ║\n");
	printf("║           = = = =    lISTA POR DO PRODUTO NOME    = = = =                 ║\n");
	printf("║           = = = = = = = = = = = = = = = = = = = = = = = =                 ║\n");
	printf("║                                                                           ║\n");
	printf("║           Informe o horário desejado (Ex. Maciel): ");
	scanf("%s", nome);
	getchar();
	printf("║                                                                           ║\n");
	printf("║                                                                           ║\n");
	printf("╚═══════════════════════════════════════════════════════════════════════════╝\n");
	printf("\n");
  return nome;
}*/