///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///      Projeto SIG-Inventory: Um Sistema de Controle de Estoques          ///
///                Developed by @MacielSaints - Jan, 2021                   ///
///////////////////////////////////////////////////////////////////////////////

// %[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]

//
/// BIBLIOTECAS
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "telas.h"
#include "valid.h"

//
/// FUÇÕES
//
char menuInicial (void);

char telaMenuInicial (void);

char telaLogin (void);

char novoUsuario (void);
char id[50];
char  cpf[12];


//char funcaoLogin (void);


//
/// Função Principal
//
int main(void) {

		menuInicial();

	return 0;
}

//
/// CRUD
//

char menuInicial(void) {
	char opcao;
	do {
		opcao = telaMenuInicial();
		switch (opcao) {
			case '1' : 	telaLogin();
						break;
			case '2' : 	novoUsuario();
						break;
      case '3' : 	telaSobre();
						break;
			case '0' : 	telaSair();
						break;
		}
	} while (opcao != '0');
  return 0;
}

char telaLogin (void) {
  printf("\033[2J\033[1;1H");
	printf("╔═════════════════════════════════╗\n");
  printf("║          SIG-Inventory          ║\n");
  printf("╚═════════════════════════════════╝\n");
	printf("╔═════════════════════════════════╗\n");
  printf("║              LOGIN              ║\n");
  printf("╚═════════════════════════════════╝\n");

  printf("Informe seu login:");
  scanf("%s", id);
  printf("Você digitou: '%s'\n",id);
  
  printf("Digite o cpf: ");  
  scanf(" %s",cpf);
  validaCpf(cpf);
  printf("Você digitou: '%s'\n", cpf);
  getchar();

  menuInicial();
  return 0;
}