///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///      Projeto SIG-Inventory: Um Sistema de Controle de Estoques          ///
///                Developed by @MacielSaints - Jan, 2021                   ///
///////////////////////////////////////////////////////////////////////////////

//
/// VALIDADOR CPF.
//

/*
Função encontrada no site:

http://pog-carlos.blogspot.com/2011/11/validacao-de-cpf-em-c-usando-vetor.html

Em 05/03/2021

E adaptada por @macielSaints
*/

#include <stdio.h>


  
int validaCpf (char n[])
{


  //char cpf[12]; 
  int icpf[12];
  int i,somador=0,digito1,result1,result2,digito2,valor; 

  //printf("Digite o cpf: ");  
  //scanf(" %s",cpf);  
  
  //Efetua a conversao de array de char para um array de int.  
  for(i=0;i<11;i++)
  {
    icpf[i]=n[i]-48;  
  }  
  
  //PRIMEIRO DIGITO.  
  
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
    printf("\nCPF VALIDADO.\n");
    getchar();
  }  
  else
  {
    printf("CPF INVÁLIDO.\n");
    getchar();
  
  }

  return 0;  
}