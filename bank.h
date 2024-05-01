#define total 1000
#define max_nome 70
#define max_tipo_conta 6
#define max_senha 50

typedef struct{
    char nome[max_nome];
    int cpf;
    char tipo_conta[max_tipo_conta];
    float saldo;
    char senha[max_senha];
} Cliente;

//Funções

int criar_cliente(Cliente clientes[], int *posicao);

int listar_clientes(Cliente clientes[], int *posicao);

int apagar_cliente();

int debitar(Cliente clientes[], int *posicao);

int depositar(Cliente clientes[], int *posicao);

int extrato();

int tranferencia();

void clearBuffer();
