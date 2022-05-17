/*
*José Miguel Santos, nº45968, PL3
*Rúben Alves, nº46244, PL3
*/
#include <stdio.h>
#define N 3
char grid[N][N];

void inicializaGrelha(char grid[N][N])
{
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            grid[i][j] = ' ';
        }
    }
}

void imprimeGrelha(char grid[N][N])
{
    printf(" %c | %c | %c \n", grid[0][0], grid[0][1], grid[0][2]);
    printf("--- --- --- \n");
    printf(" %c | %c | %c \n", grid[1][0], grid[1][1], grid[1][2]);
    printf("--- --- --- \n");
    printf(" %c | %c | %c \n", grid[2][0], grid[2][1], grid[2][2]);
}

int jogada(char grid[N][N], int x, int y, int jogador)
{
    if (x >= 0 && x <= 2 && y >= 0 && y <= 2)
    {
        if (jogador % 2 == 0 && grid[x][y] == ' ')
        {
            grid[x][y] = 'X';
            return 0;
        }
        else if (jogador % 2 != 0 && grid[x][y] == ' ')
        {
            grid[x][y] = 'O';
            return 0;
        }
        else
        {
            return 2;
        }
    }
    else
    {
        return 1;
    }
}

int tresEmLinha(char grid[N][N], int x, int y)
{
    //Diagonal principal:
    if ((grid[0][0] == 'X' && grid[1][1] == 'X' && grid[2][2] == 'X') || (grid[0][0] == 'O' && grid[1][1] == 'O' && grid[2][2] == 'O'))
    {
        return 1;
    }

    //Diagonal Secundária:
    else if ((grid[0][2] == 'X' && grid[1][1] == 'X' && grid[2][0] == 'X') || (grid[0][2] == 'O' && grid[1][1] == 'O' && grid[2][0] == 'O'))
    {
        return 1;
    }

    //Colunas X e O:
    for (int i = 0; i < 3; i++)
    {
        if ((grid[0][0 + i] != ' ' && grid[1][0 + i] != ' ' && grid[2][0 + i] != ' ') && ((grid[0][0 + i] == 'X' && grid[1][0 + i] == 'X' && grid[2][0 + i] == 'X') || (grid[0][0 + i] == 'O' && grid[1][0 + i] == 'O' && grid[2][0 + i] == 'O')))
        {
            return 1; //se todos os elementos de uma determinada coluna são diferentes de espaço vazio e iguais entre assim, então o jogador X ou O ganha o jogo
        }
    }

    //Linhas X e O:
    for (int i = 0; i < 3; i++)
    {
        if ((grid[0 + i][0] != ' ' && grid[0 + i][1] != ' ' && grid[0 + i][2] != ' ') && ((grid[0 + i][0] == 'X' && grid[0 + i][1] == 'X' && grid[0 + i][2] == 'X') || (grid[0 + i][0] == 'O' && grid[0 + i][1] == 'O' && grid[0 + i][2] == 'O')))
        {
            return 1; //se todos os elementos de uma determinada linha são diferentes de espaço vazio e iguais entre assim, então o jogador X ou O ganha o jogo
        }
    }

    //Empate:
    if (grid[0][0] != ' ' && grid[0][1] != ' ' && grid[0][2] != ' ' && grid[1][0] != ' ' && grid[1][1] != ' ' && grid[1][2] != ' ' && grid[2][0] != ' ' && grid[2][1] != ' ' && grid[2][2] != ' ')
    {
        return -1;
    }
    return 0;
}

int main(void)
{
    char galo[N][N] = {};
    int jogador = 0, x = 0, y = 0;
    double vencedor = 0, jg = 0;
    inicializaGrelha(galo);
    imprimeGrelha(galo);

    while (vencedor != 1 && vencedor != -1)
    {
        if (jogador % 2 == 0)
        {
            printf("É a vez do jogador 'X' jogar.\nIndique as coordenadas\nx = ");
            scanf("%i", &x);
            printf("y = ");
            scanf("%i", &y);
        }
        else
        {
            printf("É a vez do jogador 'O' jogar.\nIndique as coordenadas\nx = ");
            scanf("%i", &x);
            printf("y = ");
            scanf("%i", &y);
        }
        jg = jogada(galo, x, y, jogador);
        jogada(galo, x, y, jogador);
        vencedor = tresEmLinha(galo, x, y);
        imprimeGrelha(galo);
        if (vencedor == 1 && jogador % 2 == 0)
        {
            printf("O jogador X ganhou!!!\n");
        }
        else if (vencedor == 1 && jogador % 2 != 0)
        {
            printf("O jogador O ganhou!!!\n");
        }
        else if (vencedor == -1)
        {
            printf("O jogo empatou\n");
        }
        if (jg == 0) //Mudar de jogador só quando a jogada é valida.
        {
            jogador = jogador + 1;
        }
    }
    return 0;
}