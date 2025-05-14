#include <stdio.h>

// Função para limpar o tabuleiro
void limpar_tabuleiro(char tab[8][8]) {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            tab[i][j] = '.';
}

// Função para mostrar o tabuleiro
void mostrar_tabuleiro(char tab[8][8]) {
    printf("\nTabuleiro:\n\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", i);
        for (int j = 0; j < 8; j++)
            printf("%c ", tab[i][j]);
        printf("\n");
    }
    printf("  0 1 2 3 4 5 6 7\n");
}

// Movimentos das peças
void movimentos_peao(char tab[8][8], int l, int c) {
    if (l > 0)
        tab[l - 1][c] = '*';
}

void movimentos_torre(char tab[8][8], int l, int c) {
    for (int i = 0; i < 8; i++) {
        if (i != l) tab[i][c] = '*';
        if (i != c) tab[l][i] = '*';
    }
}

void movimentos_bispo(char tab[8][8], int l, int c) {
    int i, j;
    i = l - 1; j = c - 1;
    while (i >= 0 && j >= 0) tab[i--][j--] = '*';
    i = l - 1; j = c + 1;
    while (i >= 0 && j < 8) tab[i--][j++] = '*';
    i = l + 1; j = c - 1;
    while (i < 8 && j >= 0) tab[i++][j--] = '*';
    i = l + 1; j = c + 1;
    while (i < 8 && j < 8) tab[i++][j++] = '*';
}

void movimentos_cavalo(char tab[8][8], int l, int c) {
    int movs[8][2] = {
        {-2, -1}, {-2, +1}, {-1, -2}, {-1, +2},
        {+1, -2}, {+1, +2}, {+2, -1}, {+2, +1}
    };
    for (int k = 0; k < 8; k++) {
        int nl = l + movs[k][0];
        int nc = c + movs[k][1];
        if (nl >= 0 && nl < 8 && nc >= 0 && nc < 8)
            tab[nl][nc] = '*';
    }
}

void movimentos_rainha(char tab[8][8], int l, int c) {
    movimentos_torre(tab, l, c);
    movimentos_bispo(tab, l, c);
}

void movimentos_rei(char tab[8][8], int l, int c) {
    for (int i = l - 1; i <= l + 1; i++) {
        for (int j = c - 1; j <= c + 1; j++) {
            if (i >= 0 && i < 8 && j >= 0 && j < 8 && !(i == l && j == c))
                tab[i][j] = '*';
        }
    }
}

int main() {
    char tabuleiro[8][8];
    int linha, opcao;
    char coluna_char;
    int coluna;

    // Apresentação
    printf("JOGO DE XADREZ\n\n");
    
    printf("8|t|c|b|r|k|b|c|t|\n");
    printf("7|p|p|p|p|p|p|p|p|\n");
    printf("6| |#| |#| |#| |#|\n");
    printf("5|#| |#| |#| |#| |\n");
    printf("4| |#| |#| |#| |#|\n");
    printf("3|#| |#| |#| |#| |\n");
    printf("2|P|P|P|P|P|P|P|P|\n");
    printf("1|T|C|B|R|K|B|C|T|\n");
    printf("  a b c d e f g h\n\n");
    printf("=== Movimentos de Peças de Xadrez ===\n");

    // Entrada de dados
    printf("Digite a linha (0-7): ");
    scanf("%d", &linha);
    printf("Digite a coluna (a-h): ");
    scanf(" %c", &coluna_char);

    // Conversão da letra para número de coluna
    if (coluna_char >= 'a' && coluna_char <= 'h') {
        coluna = coluna_char - 'a';
    } else if (coluna_char >= 'A' && coluna_char <= 'H') {
        coluna = coluna_char - 'A';
    } else {
        printf("Coluna inválida!\n");
        return 1;
    }

    if (linha < 0 || linha > 7) {
        printf("Linha inválida!\n");
        return 1;
    }

    // Menu de peça
    printf("\nEscolha a peça:\n");
    printf("1 - Peão\n");
    printf("2 - Torre\n");
    printf("3 - Bispo\n");
    printf("4 - Cavalo\n");
    printf("5 - Rainha\n");
    printf("6 - Rei\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    limpar_tabuleiro(tabuleiro);
    tabuleiro[linha][coluna] = 'P'; // Marca a peça (apenas representativo)

    // Chama a função de acordo com a peça
    switch (opcao) {
        case 1:
            movimentos_peao(tabuleiro, linha, coluna);
            break;
        case 2:
            movimentos_torre(tabuleiro, linha, coluna);
            break;
        case 3:
            movimentos_bispo(tabuleiro, linha, coluna);
            break;
        case 4:
            movimentos_cavalo(tabuleiro, linha, coluna);
            break;
        case 5:
            movimentos_rainha(tabuleiro, linha, coluna);
            break;
        case 6:
            movimentos_rei(tabuleiro, linha, coluna);
            break;
        default:
            printf("Opção inválida!\n");
            return 1;
    }

    mostrar_tabuleiro(tabuleiro); // Mostra o resultado
    return 0;
}
