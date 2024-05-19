#ifndef BANCO_H
#define BANCO_H

struct Cliente {
    char nome[100];
    char cpf[12];
    int tipo;
    double saldo;
    char senha[20];
};
struct Extrato {
    char cpf[12];
    char data[20];
    double valor;
    double tarifa;
    double saldo;
};

void arquivo_clientes(struct Cliente *clientesbanco, int numClientes);
void arquivo_extrato(struct Extrato *lista_extrato, int numExtratos);
void ler_arquivo_clientes(struct Cliente *clientesbanco, int *numClientes);
void ler_arquivo_extrato(struct Extrato *lista_extrato, int *numExtratos);
struct Cliente *buscar_cliente(const char *cpf, struct Cliente *clientesbanco, int numClientes);
struct Cliente *buscar_senha(const char *senha, struct Cliente *clientesbanco, int numClientes);
void cadastrar_cliente(struct Cliente *clientesbanco, int *numClientes, struct Extrato *lista_extrato, int *numExtratos);
void deletar_cliente(struct Cliente *clientesbanco, int *numClientes);
void listar_clientes(struct Cliente *clientesbanco, int numClientes);
void deposito(struct Cliente *clientesbanco, int numClientes, struct Extrato *lista_extrato, int *numExtratos);
void debito(struct Cliente *clientesbanco, int numClientes, struct Extrato *lista_extrato, int *numExtratos);
void extrato(struct Cliente *clientesbanco, int numClientes, struct Extrato *lista_extrato, int numExtratos);
void transferencia(struct Cliente *clientesbanco, int numClientes, struct Extrato *lista_extrato, int *numExtratos);

#endif
