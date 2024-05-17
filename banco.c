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

