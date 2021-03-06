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

#include "telas.h"
#include "valid.h"
#include "estoque.h"
#include "usuario.h"
#include "relatorios.h"


//----------------------------------------------------
//
/// CRUDs
//
//----------------------------------------------------

char menuInicial(void) {
	char op;
  User* aux;

  do {
    op = telaMenuInicial();

    switch (op) {
    case '1': aux = buscaUser();
              loginUser(aux);
              break;
    case '2': aux = preencheUser();
              gravaUser(aux);
              break;
    case '3': telaSobre();
              break;
    case '0': telaSair();
               break;
    }
  } while (op != '0');
  free(aux);
return 0;
}

char estoque(void) {
	char op;
  Produtos* aux;

  do {
    op = telaEstoque();

    switch (op) {
    case '1': aux = preencheProduto();
              gravaProduto(aux);
              break;
    case  '2' :aux = buscaProduto();
              entradaProduto(aux);
              break;
    case  '3' :aux = buscaProduto();
              saidaProduto(aux);
              break;
    case '4': aux = buscaProduto();
              exibeProduto(aux);
              break;
    case  '5' :aux = buscaProduto();
              atualizaProduto(aux);
              break;
    case '6': aux = buscaProduto();
              excluiProduto(aux);
              break;
    case '7': listaProdutos();
              break;
    case '8': listaProdutosPorMarca();
              break;
    case '9': relatorio();
			        break;
    case '0': menuInicial();
				break;
    }
  } while (op != '0');
  free(aux);
return 0;
}