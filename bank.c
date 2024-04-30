#include "bank.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



int contem_apenas_letras(const char *str) {
  if (*str == '\0') {
      return 0; 
  }
  while (*str) {
    if (!isalpha(*str) && *str != ' ') { // Verifica se o caractere não é uma letra ou espaço
      return 0;
    }
    str++;
  }
  return 1;
}


int criar_cliente(Cliente clientes[], int *posicao) {
  // Verificando se a posição não excedeu o total.
  if (*posicao >= total) {
    printf("Não é possível adicionar mais clientes, a lista de clientes está cheia.\n");
    return 0;
  }

  // Pedindo para o usuário os dados e salvando-os na struct
  clearBuffer();
  printf("Nome: ");
  fgets(clientes[*posicao].nome, max_nome, stdin);
  // Removendo o caractere de nova linha, se presente
  clientes[*posicao].nome[strcspn(clientes[*posicao].nome, "\n")] = '\0';
  // Verificando se o nome não está vazio e contém apenas letras
  if (!contem_apenas_letras(clientes[*posicao].nome)) {
    printf("O nome não pode estar vazio e só pode conter apenas letras.\n");
    return 0;
  }

  printf("CPF: ");
  scanf("%d", &clientes[*posicao].cpf);

int tipo_con;
  printf("Tipo de conta (1 - Comum, 2 - Plus): ");
  scanf("%d", &tipo_con);
  // Verificando se o tipo de conta é válido
  if (tipo_con != 1 && tipo_con != 2) {
    printf("Tipo de conta inválido.\n");
    return 0;
  } else if (tipo_con == 1) {
    strcpy(clientes[*posicao].tipo_conta, "Comum");
  } else if(tipo_con == 2) {
    strcpy(clientes[*posicao].tipo_conta, "Plus");
  }


  printf("Saldo inicial da conta: ");
  scanf("%f", &clientes[*posicao].saldo);

  printf("Senha do usuário: ");
  clearBuffer();
  fgets(clientes[*posicao].senha, max_senha, stdin);
  // Removendo o caractere de nova linha, se presente
  clientes[*posicao].senha[strcspn(clientes[*posicao].senha, "\n")] = '\0';

  (*posicao)++; // Incrementa a posição

  printf("Cliente adicionado com sucesso!\n");

  return 1; // Retorna 1 indicando que o cliente foi criado com sucesso
}

int apagar_cliente() {
  printf("função apagar\n");
  return 1;
}

int listar_clientes() {
  printf("Função listar\n");
  return 1;
}

int debitar() {
  printf("função debitar\n");
  return 1;
}

int depositar() {
  printf("função depositar\n");
  return 1;
}

int extrato() {
  printf("função extrato\n");
  return 1;
}

int tranferencia() {
  printf("função transferencia\n");
  return 1;
}

void clearBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}
