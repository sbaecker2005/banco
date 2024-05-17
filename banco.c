#include "cliente_banco.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void arquivo_clientes(struct Cliente *clientesbanco, int numClientes) {
  FILE *arquivo = fopen("clientesbanco.bin", "wb");
  if (arquivo == NULL) {
    perror("Erro ao abrir o arquivo");
    return;
  }

  for (int i = 0; i < numClientes; i++) {
    fprintf(arquivo, "%s,%s,%d,%.2lf,%s\n", clientesbanco[i].nome,
            clientesbanco[i].cpf, clientesbanco[i].tipo, clientesbanco[i].saldo,
            clientesbanco[i].senha);
  }

  fclose(arquivo);
}

void arquivo_extrato(struct Extrato *lista_extrato, int numExtratos) {
  FILE *arquivo = fopen("extrato.txt", "w");
  if (arquivo == NULL) {
    perror("Erro ao abrir o arquivo");
    return;
  }

  for (int i = 0; i < numExtratos; i++) {
    fprintf(arquivo, "%s,%s,%.2lf,%.2lf,%.2lf\n", lista_extrato[i].cpf,
            lista_extrato[i].data, lista_extrato[i].valor,
            lista_extrato[i].tarifa, lista_extrato[i].saldo);
  }

  fclose(arquivo);
}
void ler_arquivo_clientes(struct Cliente *clientesbanco, int *numClientes) {
  FILE *arquivo = fopen("clientesbanco.bin", "rb");
  if (arquivo == NULL) {
    perror("Erro ao abrir o arquivo");
    return;
  }

  while (fscanf(arquivo, "%[^,],%[^,],%d,%lf,%s\n",
                clientesbanco[*numClientes].nome, clientesbanco[*numClientes].cpf,
                &clientesbanco[*numClientes].tipo,
                &clientesbanco[*numClientes].saldo,
                clientesbanco[*numClientes].senha) != EOF) {
    (*numClientes)++;
  }

  fclose(arquivo);
}

void ler_arquivo_extrato(struct Extrato *lista_extrato, int *numExtratos) {
  FILE *arquivo = fopen("extrato.txt", "r");
  if (arquivo == NULL) {
    perror("Erro ao abrir o arquivo");
    return;
  }

  while (fscanf(arquivo, "%[^,],%[^,],%lf,%lf,%lf\n",
                lista_extrato[*numExtratos].cpf, lista_extrato[*numExtratos].data,
                &lista_extrato[*numExtratos].valor,
                &lista_extrato[*numExtratos].tarifa,
                &lista_extrato[*numExtratos].saldo) != EOF) {
    (*numExtratos)++;
  }

  fclose(arquivo);
}
struct Cliente *buscar_cliente(const char *cpf, struct Cliente *clientesbanco, int numClientes) {
  for (int i = 0; i < numClientes; i++) {
    if (strcmp(cpf, clientesbanco[i].cpf) == 0) {
      return &clientesbanco[i];
    }
  }
  return NULL;
}

struct Cliente *buscar_senha(const char *senha, struct Cliente *clientesbanco, int numClientes) {
  for (int i = 0; i < numClientes; i++) {
    if (strcmp(senha, clientesbanco[i].senha) == 0) {
      return &clientesbanco[i];
    }
  }
  return NULL;
}

void cadastrar_cliente(struct Cliente *clientesbanco, int *numClientes, struct Extrato *lista_extrato, int *numExtratos) {
  struct Cliente cliente;
  printf("Digite os dados para criar sua conta:\n");
  printf("Digite seu nome: ");
  scanf("%s", cliente.nome);
  printf("Digite seu CPF: ");
  scanf("%s", cliente.cpf);
  printf("Digite 1 para a conta plus ou digite 2 para a conta comum: ");
  scanf("%d", &cliente.tipo);
  printf("Digite o valor da conta: ");
  scanf("%lf", &cliente.saldo);
  printf("Digite a senha do usuário: ");
  scanf("%s", cliente.senha);
