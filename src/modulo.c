#include <stdio.h>
#include "modulo.h"

int carregarCarteira(Ativo carteira[]) {
    FILE *arquivo;
    int total = 0;

    arquivo = fopen("data/carteira.txt", "r");
    if (arquivo == NULL) {
        return 0;
    }

    while (total < MAX_ATIVOS &&
           fscanf(arquivo, " %79[^|]|%49[^|]|%d|%f|%f",
                  carteira[total].nome,
                  carteira[total].categoria,
                  &carteira[total].quantidade,
                  &carteira[total].precoCompra,
                  &carteira[total].precoAtual) == 5) {
        total++;
    }

    fclose(arquivo);
    return total;
}

void salvarCarteira(Ativo carteira[], int total) {
    FILE *arquivo;
    int i;

    arquivo = fopen("data/carteira.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao salvar arquivo!\n");
        return;
    }

    for (i = 0; i < total; i++) {
        fprintf(arquivo, "%s|%s|%d|%.2f|%.2f\n",
                carteira[i].nome, carteira[i].categoria,
                carteira[i].quantidade, carteira[i].precoCompra,
                carteira[i].precoAtual);
    }

    fclose(arquivo);
}
