# Carteira de Investimentos - CP3

Projeto academico em linguagem C para cadastrar ativos, calcular valores e rentabilidade, ordenar a carteira, simular investimentos e gerar relatorio.

## Público-alvo
Pessoas interessadas em educação financeira e usuários
que desejam aprender sobre organização e acompanhamento de
investimentos de forma simples e educativa.

## Funcionalidades
- Cadastro e listagem de ativos.
- Calculo do valor total, total investido e rentabilidade.
- Salvamento e leitura dos dados em `data/carteira.txt`.
- Ordenacao por rentabilidade usando Bubble Sort.
- Simulador de 12 meses para poupanca, Tesouro Selic e CDB.
- Relatorio final com resumo e texto sobre a ODS 8.10.

## Tecnologias utilizadas
- Linguagem C.
- Compilador GCC.
- Biblioteca padrão da linguagem C.
- Manipulação de arquivos TXT para armazenamento de dados.

## Requisitos mínimos para execução
- Sistema operacional Windows, Linux ou macOS.
- Compilador GCC instalado.
- Terminal ou prompt de comando.
- Espaço em disco suficiente para armazenar o programa e os dados.

## Compilacao
Na pasta principal do projeto, execute:

```bash
gcc -Wall -Wextra -Iinclude src/main.c src/funcoes.c src/modulo.c -o programa
```

No Windows, execute `programa.exe` (ou `programa`, conforme o terminal).

## Arquivos
- `src/`: codigos principais.
- `include/`: bibliotecas e definicao da struct.
- `data/carteira.txt`: dados salvos da carteira.

## Simulador
As taxas sao exemplos educativos: poupanca 0,50% ao mes, Tesouro Selic 0,80% ao mes e CDB 0,90% ao mes. Os valores nao sao promessa de rendimento. O simulador usa juros compostos por 12 meses.

## Video
Link do video nao listado: https://youtu.be/MjM3X9D-RI8

## Integrantes

Daniel Gonçalves Araújo
Renan André Gomes da Silva
José Gustavo Rodrigues Simoncini
Alisson Gustavo Fernandes Goncalves 
Guilherme de Oliveira Silva
