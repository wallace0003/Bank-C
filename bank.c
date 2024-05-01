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

int listar_clientes(Cliente clientes[], int *posicao) {
  // Verificação de há contatos
  if (*posicao == 0) {
    printf("Não há contatos, impossível listá-los.");
    return 0;
  }

  // Looping para printar os contatos
  for (int i = 0; i < *posicao; i++) {
    printf("Posição: %d\t", i + 1);
    printf("Nome: %s\t", clientes[i].nome);
    printf("CPF: %d\t", clientes[i].cpf);
    printf("Tipo de conta: %s\t", clientes[i].tipo_conta);
    printf("Saldo atual: %.2f\n", clientes[i].saldo);
  }
  return 1;
}

// Função para debitar valor da conta de um cliente
int debitar(Cliente clientes[], int *posicao) {
    int cpf;
    char senha[max_senha];
    float valor;

    // Solicitando dados do usuário
    printf("CPF: ");
    scanf("%d", &cpf);
    printf("Senha: ");
    clearBuffer();
    fgets(senha, max_senha, stdin);
    // Removendo o caractere de nova linha, se presente
    senha[strcspn(senha, "\n")] = '\0';
    printf("Valor: ");
    scanf("%f", &valor);

    // Verificando os dados do cliente
    for (int i = 0; i < *posicao; i++) {
        if (cpf == clientes[i].cpf && strcmp(senha, clientes[i].senha) == 0) {
            // Verificando limite de saldo negativo
            float verificando_limite_saldo = clientes[i].saldo - valor;
            float tarifa_saque;

            if (verificando_limite_saldo < -1000 && strcmp(clientes[i].tipo_conta, "Comum") == 0) {
                printf("\nSeu limite de saldo negativo é -1000\n");
                printf("Impossível realizar o débito, seu saldo ficaria %.2f\n", verificando_limite_saldo);
                return 0;
            } else if (verificando_limite_saldo < -5000 && strcmp(clientes[i].tipo_conta, "Plus") == 0) {
                printf("\nSeu limite de saldo negativo é -5000\n");
                printf("Impossível realizar o débito, seu saldo ficaria: R$%.2f\n", verificando_limite_saldo);
                return 0;
            }

            // Calculando tarifa de saque
            if (strcmp(clientes[i].tipo_conta, "Comum") == 0) {
                tarifa_saque = 0.05 * valor;
            } else if (strcmp(clientes[i].tipo_conta, "Plus") == 0) {
                tarifa_saque = 0.03 * valor;
            }

            // Descontando tarifa do saldo
            clientes[i].saldo -= tarifa_saque;
            printf("\nFoi descontado do valor de seu saque: R$%.2f\n", tarifa_saque);

            // Realizando o saque
            clientes[i].saldo -= valor;
            printf("Valor sacado: R$%.2f\n", valor);

            // Registrando transação
            printf("Transação registrada com sucesso!\n");

            return 1;
        }
    }

    // Caso não encontre o cliente
    printf("\nCPF ou senha não encontrados.\n");
    return 0;
}




int depositar(Cliente clientes[], int *posicao) {
    int cpf;
    char senha[max_senha];
    float valor_deposito;

    // Solicitar CPF e senha do usuário para autenticação
    printf("CPF: ");
    scanf("%d", &cpf);
    clearBuffer(); // Limpar o buffer após a leitura do inteiro
    printf("Senha: ");
    fgets(senha, max_senha, stdin);
    senha[strcspn(senha, "\n")] = '\0'; // Remover o caractere de nova linha

    // Verifica se o CPF e a senha correspondem a algum cliente
    int i;
    for (i = 0; i < *posicao; i++) {
        if (clientes[i].cpf == cpf && strcmp(clientes[i].senha, senha) == 0) {
            // CPF e senha correspondem, solicitar valor do depósito
            printf("Valor do depósito: ");
            scanf("%f", &valor_deposito);
            // Verificar se o valor do depósito é válido
            if (valor_deposito <= 0) {
                printf("Valor de depósito inválido.\n");
                return 0;
            }
            // Realizar o depósito adicionando o valor ao saldo do cliente
            clientes[i].saldo += valor_deposito;
            printf("Depósito realizado com sucesso. Novo saldo: %.2f\n", clientes[i].saldo);
            return 1;
        }
    }

    // Se o loop terminar, significa que o cliente não foi encontrado
    printf("CPF ou senha incorretos. Não foi possível realizar o depósito.\n");
    return 0;
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
