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
