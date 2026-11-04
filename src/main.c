#include <stdio.h>
#include "funcoes.h"

int main() {
    Ativo carteira[MAX_ATIVOS];
    int total, opcao;

    total = carregarCarteira(carteira);

    do {
        printf("\n=== CARTEIRA DE INVESTIMENTOS ===\n\n");
        printf("1 - Cadastrar ativo\n2 - Listar ativos\n3 - Valor total da carteira\n4 - Rentabilidade geral\n5 - Ordenar por rentabilidade\n6 - Simulador educativo\n7 - Relatorio final\n0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarAtivo(carteira, &total);
                salvarCarteira(carteira, total);
                break;
            case 2:
                listarAtivos(carteira, total);
                break;
            case 3:
                printf("Valor total: R$ %.2f\n", calcularValorTotal(carteira, total));
                break;
            case 4:
                printf("Rentabilidade geral: %.2f%%\n", calcularRentabilidadeGeral(carteira, total));
                break;
            case 5:
                ordenarPorRentabilidade(carteira, total);
                listarAtivos(carteira, total);
                salvarCarteira(carteira, total);
                break;
            case 6:
                simuladorEducativo(carteira, total);
                break;
            case 7:
                gerarRelatorioFinal(carteira, total);
                break;
            case 0:
                salvarCarteira(carteira, total);
                printf("Carteira salva. Ate mais!\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
    return 0;
}