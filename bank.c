#include "bank.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool validarEscolhaConta(const char *tipo) {
  const char *contas[] = {"Conta corrente", "Conta poupança", "Conta salário"};

  for (int i = 0; i < 3; i++) {
    if (strcmp(contas[i], tipo) == 0) {
      return true;
    }
  }
  return false;
}

int criar_cliente(Cliente clientes[], int *pos) {
  if (*pos >= total) {
    printf("Você chegou ao maximo de clientes no seu banco!!");
    return 0;
  }
  printf("Digite o nome do cliente: ");
  fgets(clientes[*pos].nome, max_nome, stdin);

  printf("Digite o CPF:");
  scanf("%d", &clientes[*pos].cpf);

  printf("Digite o tipo de conta do cliente: \n Conta corrente \n Conta "
         "poupança \n Conta salário ");

  fgets(clientes[*pos].tipo_conta, max_tipo_conta, stdin);
  if (validarEscolhaConta(clientes[*pos].tipo_conta) == false) {
    printf("Tipo de conta nao existe no nossos registros");
    return 0;
  }

  printf("Deposito inicial: ");
  scanf("%f", &clientes[*pos].saldo);
  if (clientes[*pos].saldo < 0) {
    printf("O saldo precisa ser positivo!! ");
    return 0;
  }

  printf("Digite uma senha: ");
  fgets(clientes[*pos].senha, max_senha, stdin);

  (*pos)++;
  return 1;
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
