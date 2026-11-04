#ifndef FUNCOES_H
#define FUNCOES_H

#include "modulo.h"

void cadastrarAtivo(Ativo carteira[], int *total);
void listarAtivos(Ativo carteira[], int total);
float calcularValorTotal(Ativo carteira[], int total);
float calcularTotalInvestido(Ativo carteira[], int total);
float calcularRentabilidadeGeral(Ativo carteira[], int total);
float calcularRentabilidadeAtivo(Ativo ativo);
void ordenarPorRentabilidade(Ativo carteira[], int total);
void simuladorEducativo(Ativo carteira[], int total);
void gerarRelatorioFinal(Ativo carteira[], int total);

#endif
