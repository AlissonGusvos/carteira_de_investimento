#include <stdio.h>
#include "funcoes.h"

void cadastrarAtivo(Ativo carteira[], int *total) {
    if (*total >= MAX_ATIVOS) {
        printf("Limite de ativos atingido!\n");
        return;
    }

    printf("Nome do ativo: ");
    scanf(" %79[^\n]", carteira[*total].nome);
    printf("Categoria: ");
    scanf(" %49[^\n]", carteira[*total].categoria);
    printf("Quantidade: ");
    scanf("%d", &carteira[*total].quantidade);
    printf("Preco de compra por unidade: ");
    scanf("%f", &carteira[*total].precoCompra);
    printf("Preco atual por unidade: ");
    scanf("%f", &carteira[*total].precoAtual);

    *total = *total + 1;
    printf("Ativo cadastrado!\n");
}

void listarAtivos(Ativo carteira[], int total) {
    int i;

    if (total == 0) {
        printf("Nenhum ativo cadastrado.\n");
    }

    for (i = 0; i < total; i++) {
        printf("%d - %s | %s | Quantidade: %d | Compra: R$ %.2f | Atual: R$ %.2f | Rentabilidade: %.2f%%\n",
               i + 1, carteira[i].nome, carteira[i].categoria,
               carteira[i].quantidade, carteira[i].precoCompra,
               carteira[i].precoAtual, calcularRentabilidadeAtivo(carteira[i]));
    }
}

float calcularValorTotal(Ativo carteira[], int total) {
    int i;
    float totalCarteira = 0;

    for (i = 0; i < total; i++) {
        totalCarteira = totalCarteira + carteira[i].precoAtual * carteira[i].quantidade;
    }
    return totalCarteira;
}

float calcularTotalInvestido(Ativo carteira[], int total) {
    int i;
    float totalInvestido = 0;

    for (i = 0; i < total; i++) {
        totalInvestido = totalInvestido + carteira[i].precoCompra * carteira[i].quantidade;
    }
    return totalInvestido;
}

float calcularRentabilidadeGeral(Ativo carteira[], int total) {
    float investido = calcularTotalInvestido(carteira, total);
    float atual = calcularValorTotal(carteira, total);

    if (investido == 0) {
        return 0;
    }
    return ((atual - investido) / investido) * 100;
}

float calcularRentabilidadeAtivo(Ativo ativo) {
    if (ativo.precoCompra == 0) {
        return 0;
    }
    return ((ativo.precoAtual - ativo.precoCompra) / ativo.precoCompra) * 100;
}

void ordenarPorRentabilidade(Ativo carteira[], int total) {
    int i, j;
    Ativo aux;

    for (i = 0; i < total - 1; i++) {
        for (j = 0; j < total - 1 - i; j++) {
            if (calcularRentabilidadeAtivo(carteira[j]) < calcularRentabilidadeAtivo(carteira[j + 1])) {
                aux = carteira[j];
                carteira[j] = carteira[j + 1];
                carteira[j + 1] = aux;
            }
        }
    }
    printf("Carteira ordenada!\n");
}

void simuladorEducativo(Ativo carteira[], int total) {
    int mes;
    float inicial, poupanca, tesouro, cdb;

    inicial = calcularValorTotal(carteira, total);
    poupanca = inicial;
    tesouro = inicial;
    cdb = inicial;

    if (inicial <= 0) {
        printf("Cadastre ativos antes de usar o simulador.\n");
        return;
    }

    for (mes = 1; mes <= 12; mes++) {
        poupanca = poupanca * (1 + TAXA_POUPANCA);
        tesouro = tesouro * (1 + TAXA_TESOURO);
        cdb = cdb * (1 + TAXA_CDB);
    }

    printf("\n=== SIMULADOR DE 12 MESES ===\n");
    printf("Valor inicial: R$ %.2f\n", inicial);
    printf("Poupanca (0,50%% ao mes): R$ %.2f | Rendimento: R$ %.2f\n", poupanca, poupanca - inicial);
    printf("Tesouro Selic (0,80%% ao mes): R$ %.2f | Rendimento: R$ %.2f\n", tesouro, tesouro - inicial);
    printf("CDB (0,90%% ao mes): R$ %.2f | Rendimento: R$ %.2f\n", cdb, cdb - inicial);
    printf("\nPoupanca: simples e conhecida, mas pode render menos.\n");
    printf("Tesouro Selic: titulo publico, considerado de baixo risco.\n");
    printf("CDB: investimento de banco; alguns possuem protecao do FGC, seguindo limites e regras.\n");
    printf("As taxas sao ilustrativas e nao garantem rendimento.\n");
}

void gerarRelatorioFinal(Ativo carteira[], int total) {
    FILE *arquivo;
    Ativo copia[MAX_ATIVOS];
    int i;
    float investido, atual, lucro;

    for (i = 0; i < total; i++) {
        copia[i] = carteira[i];
    }
    ordenarPorRentabilidade(copia, total);

    investido = calcularTotalInvestido(carteira, total);
    atual = calcularValorTotal(carteira, total);
    lucro = atual - investido;

    arquivo = fopen("relatorio_final.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar relatorio!\n");
        return;
    }

    fprintf(arquivo, "=== RELATORIO FINAL ===\n\n");
    fprintf(arquivo, "ATIVOS ORDENADOS POR RENTABILIDADE:\n");
    for (i = 0; i < total; i++) {
        fprintf(arquivo, "%d - %s | Rentabilidade: %.2f%%\n", i + 1,
                copia[i].nome, calcularRentabilidadeAtivo(copia[i]));
    }
    fprintf(arquivo, "\nValor total da carteira: R$ %.2f\n", atual);
    fprintf(arquivo, "Rentabilidade geral: %.2f%%\n", calcularRentabilidadeGeral(carteira, total));
    fprintf(arquivo, "Lucro/prejuizo total: R$ %.2f\n", lucro);
    fprintf(arquivo, "\nIMPACTO SOCIAL - ODS 8.10:\n");
    fprintf(arquivo, "O simulador ajuda na inclusao financeira porque apresenta investimentos de forma simples e compara seus rendimentos. Assim, mais pessoas podem aprender sobre planejamento, riscos e possibilidades de guardar dinheiro, contribuindo para o acesso a servicos financeiros, como propoe a ODS 8.10 da ONU.\n");

    fclose(arquivo);
    printf("Relatorio criado no arquivo relatorio_final.txt\n");
}
