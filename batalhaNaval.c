#include <stdio.h>
#include <stdlib.h>  // Para usar abs()

#define TAM 5  // Tamanho fixo do tabuleiro

// ----------------------------
// Função para exibir a matriz
// ----------------------------
void exibirMatriz(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// -----------------------------------------------------------
// Preenche a matriz com o padrão de CONE (triângulo invertido)
// -----------------------------------------------------------
void habilidadeCone(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            // A partir da linha 2, expande para os lados formando o cone
            if (i >= 2 && j >= 2 - (i - 2) && j <= 2 + (i - 2)) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// ------------------------------------
// Preenche a matriz com o padrão CRUZ
// ------------------------------------
void habilidadeCruz(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            // Marca linha e coluna centrais
            matriz[i][j] = (i == 2 || j == 2) ? 1 : 0;
        }
    }
}

// ----------------------------------------
// Preenche a matriz com o padrão OCTAEDRO
// ----------------------------------------
void habilidadeOctaedro(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            // Forma de losango com centro em (2,2) e raio 1
            matriz[i][j] = (abs(i - 2) + abs(j - 2) <= 1) ? 1 : 0;
        }
    }
}

// --------------------------
// Função principal do jogo
// --------------------------
int main() {
    int matriz[TAM][TAM];

    printf("🔺 Habilidade: CONE\n");
    habilidadeCone(matriz);
    exibirMatriz(matriz);

    printf("\n➕ Habilidade: CRUZ\n");
    habilidadeCruz(matriz);
    exibirMatriz(matriz);

    printf("\n♦️ Habilidade: OCTAEDRO\n");
    habilidadeOctaedro(matriz);
    exibirMatriz(matriz);

    return 0;
}
