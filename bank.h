#define total 1000
#define max_nome 70
#define max_tipo_conta 6
#define max_senha 50
#define max_tipo 20
#define max_transacoes 100




typedef struct {
    char tipo[max_tipo];
    float valor;
    float tarifa;
} Transacao;

typedef struct {
    char nome[max_nome];
    int cpf;
    char tipo_conta[max_tipo_conta];
    float saldo;
    char senha[max_senha];
    Transacao extrato[max_transacoes]; 
    int num_transacoes; 
} Cliente;

// Funções
int criar_cliente(Cliente clientes[], int *posicao);
int listar_clientes(Cliente clientes[], int *posicao);
int apagar_cliente();
int debitar(Cliente clientes[], int *posicao);
int depositar(Cliente clientes[], int *posicao);
int extrato(Cliente clientes[], int *posicao);
int tranferencia(Cliente clientes[], int *posicao);
int salvar_em_binario(Cliente clientes[], int *posicao);
int carregar_de_binario(Cliente clientes[], int *posicao);
void clearBuffer();