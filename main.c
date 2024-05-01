#include "bank.h"
#include <stdio.h>

int main() {
  Cliente clientes[total];
  int posicao = 0;
  while (1) {
    int opcao;
    printf("\n");
    printf("1 - Criar cliente\n");
    printf("2 - Apagar cliente\n");
    printf("3 - Listar clientes\n");
    printf("4 - Débito\n");
    printf("5 - Depósito\n");
    printf("6 - Extrato\n");
    printf("7 - Transferências\n");
    printf("0 - Sair\n");
    printf("\nDigite a opção desejada:");
    scanf("%d", &opcao);

    if (opcao == 1) {
      criar_cliente(clientes, &posicao);
    } else if (opcao == 2) {
      apagar_cliente();
    } else if (opcao == 3) {
      listar_clientes(clientes, &posicao);
    } else if (opcao == 4) {
      debitar();
    } else if (opcao == 5) {
      depositar();
    } else if (opcao == 6) {
      extrato();
    } else if (opcao == 7) {
      tranferencia();
    } else if (opcao == 0) {
      printf("Saindo...");
      break;
    } else {
      printf("Opção inválida!\n");
    }
  }
  return 1;
}
