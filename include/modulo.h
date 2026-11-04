#ifndef MODULO_H
#define MODULO_H

#define MAX_ATIVOS 100
#define TAXA_POUPANCA 0.005
#define TAXA_TESOURO 0.008
#define TAXA_CDB 0.009

typedef struct {
    char nome[80];
    char categoria[50];
    int quantidade;
    float precoCompra;
    float precoAtual;
} Ativo;

int carregarCarteira(Ativo carteira[]);
void salvarCarteira(Ativo carteira[], int total);

#endif
