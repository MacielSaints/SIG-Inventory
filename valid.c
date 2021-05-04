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
/// DEFINIÇÕES ESTRUTURAS
//
//----------------------------------------------------

#define clear "\033[2J\033[1;1H" // PARÂMETRO PARA LIMPAR TELA
#define True 1
#define False 0

//----------------------------------------------------
//
/// BIBLIOTECAS
//
//----------------------------------------------------

#include <stdio.h>
#include <string.h>

#include "telas.h"
#include "cruds.h"
#include "estoque.h"
#include "usuario.h"

//----------------------------------------------------
//
/// VALIDADOR CPF.
//
//----------------------------------------------------

/*
Função encontrada no site:

http://pog-carlos.blogspot.com/2011/11/validacao-de-cpf-em-c-usando-vetor.html

Em 05/03/2021

E adaptada por @macielSaints
*/

int validaCpf (char n[])
{
  //char cpf[12]; 
  int icpf[12];
  int i,somador=0,digito1,result1,result2,digito2,valor;

  //printf("Digite o cpf: ");  
  //scanf(" %s",cpf);

  ///Efetua a conversao de array de char para um array de int.
  for(i=0;i<11;i++)
  {
    icpf[i]=n[i]-48;
  }  
  
  ///PRIMEIRO DIGITO.  
    for(i=0;i<9;i++)
  {
    somador+=icpf[i]*(10-i);
  }
  
  result1=somador%11;
  
  if( (result1==0) || (result1==1) )
  {  
    digito1=0;
  }
  
    else  
    {  
      digito1 = 11-result1;
    }
  
  //SEGUNDO DIGITO.
  somador=0;

  for(i=0;i<10;i++)
  {  
    somador+=icpf[i]*(11-i);
  }

  valor=(somador/11)*11;
  result2=somador-valor;

  if( (result2==0) || (result2==1) )
  {
    digito2=0;
  }

    else
    {
      digito2=11-result2;
    }
    
  //RESULTADOS DA VALIDACAO.
  if((digito1==icpf[9]) && (digito2==icpf[10]))
  {
    printf("CPF VALIDADADO!\n\n");
  }
    else
    {
      printf("CPF INVÁLIDO.\n");
      getchar();
      menuInicial();
    }

  return icpf[i];  
}
//----------------------------------------------------
//
/// VALIDADOR DATA.
//
//----------------------------------------------------

// Função adaptada do material visto na diciplina - DCT1106 - Programação.


int dataValida(int dd, int mm, int aa) {
  int maiorDia;
  int bissexto(int);
  if (aa < 0 || mm < 1 || mm > 12 || dd < 1) {
    return 0;
  }
  if (mm == 2) {
    if (bissexto(aa)) {
      maiorDia = 29;
    } else {
      maiorDia = 28;
    }
  } else if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
    maiorDia = 30;
  } else {
    maiorDia = 31;
  }
  if (dd > maiorDia) {
    return 0;
  }
 return 1;
}

//----------------------------------------------------
//
/// valida ANO.
//
//----------------------------------------------------

int bissexto(int aa) {
  if ((aa % 4 == 0) && (aa % 100 != 0)) {
    return 1;
  } else if (aa % 400 == 0) {
    return 1;
  } else {
    return 0;
  }
}

//----------------------------------------------------
//
/// VALIDADOR NUMEROS.
//
//----------------------------------------------------

int ehDigito(char c) {
  return (c>='0' && c<='9');
}

//----------------------------------------------------
//
/// VALIDADOR LETRAS.
//
//----------------------------------------------------

int ehLetra(char *c){
    int tam = strlen(c);
    char letra;
    for (int i = 0; i < tam; i++) {
        letra = c[i];
        if (letra >='A' && letra <='Z') {
            return 1;
        } else if (letra >='a' && letra <='z') {
            return 1;
        }else {
            return 0;
        }
     }
  return 0;
}