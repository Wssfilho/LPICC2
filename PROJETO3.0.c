#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define X "\\"
#define TEXTO_VERMELHO "\x1b[31;1m"
#define COLOR_RESET "\033[0m"
#define ANSI_COLOR_GREEN "\e[0;32m"
#define ANSI_COLOR_GRAY "\e[0;37m"

int main()
{
    //A TELA DE INCIO SERA ADCIONADA PARA A JOGABILIDADE DE DOIS JOGADORES, ASSIM COMO OS SEUS RESPECTIVO NICKS E IDENTIFICAÇAO. O DESIGN DO JOGO IRA MUDAR ATE A PARTE 4. A JOGABILIDADE BASE PARA 1 JOGADOR ESTÁ PRONTA, CONTUDO, ADAPTAÇOES DOS CARDS SERÃO FEITAS QUANDO A JOGABILIDADE EM DOIS FOR INTRODUZIDA
    int linhas, lim_inf_lin1, lim_inf_col1, lim_inf_lin2, lim_inf_col2, largura, altura;
    int lim_sup_col1, lim_sup_lin1, lim_sup_col2, lim_sup_lin2, aux, pares, cont, cards[20] = {0};
    //char incio[36][120];
    char tela[37][139] = {"\tXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIX",
                          "\tI      ____________       ____________       ____________       ____________       ____________       ____________      ____________    X",
                          "\tX  01.i            i  02.i            i  03.i            i  04.i            i  05.i            i  06.i            i 07.i            i   I",
                          "\tI     i            i     i            i     i            i     i            i     i            i     i            i    i            i   X",
                          "\tX     i            i     i            i     i            i     i            i     i            i     i            i    i            i   I",
                          "\tI     i            i     i            i     i            i     i            i     i            i     i            i    i            i   X",
                          "\tX     i            i     i            i     i            i     i            i     i            i     i            i    i            i   I",
                          "\tI     i            i     i            i     i            i     i            i     i            i     i            i    i            i   X",
                          "\tX     i            i     i            i     i            i     i            i     i            i     i            i    i            i   I",
                          "\tI     i            i     i            i     i            i     i            i     i            i     i            i    i            i   X",
                          "\tX     i            i     i            i     i            i     i            i     i            i     i            i    i            i   I",
                          "\tX      xxxxxxxxxxxx       xxxxxxxxxxxx       xxxxxxxxxxxx       xxxxxxxxxxxx       xxxxxxxxxxxx       xxxxxxxxxxxx      xxxxxxxxxxxx    X",
                          "\tI      ____________       ____________       ____________       ____________       ____________       ____________      ____________    I",
                          "\tX  08.i            i  09.i            i  10.i            i  11.i            i  12.i            i  13.i            i 14.i            i   X",
                          "\tI     i            i     i            i     i            i     i            i     i            i     i            i    i            i   I",
                          "\tI     i            i     i            i     i            i     i            i     i            i     i            i    i            i   X",
                          "\tI     i            i     i            i     i            i     i            i     i            i     i            i    i            i   I",
                          "\tX     i            i     i            i     i            i     i            i     i            i     i            i    i            i   X",
                          "\tI     i            i     i            i     i            i     i            i     i            i     i            i    i            i   I",
                          "\tX     i            i     i            i     i            i     i            i     i            i     i            i    i            i   X",
                          "\tI     i            i     i            i     i            i     i            i     i            i     i            i    i            i   I",
                          "\tX     i            i     i            i     i            i     i            i     i            i     i            i    i            i   X",
                          "\tI      xxxxxxxxxxxx       xxxxxxxxxxxx       xxxxxxxxxxxx       xxxxxxxxxxxx       xxxxxxxxxxxx       xxxxxxxxxxxx      xxxxxxxxxxxx    X",
                          "\tI      ____________       ____________       ____________       ____________       ____________       ____________                      X",
                          "\tX  15.i            i  16.i            i  17.i            i  18.i            i  19.i            i  20.i            i                     I",
                          "\tI     i            i     i            i     i            i     i            i     i            i     i            i                     X",
                          "\tX     i            i     i            i     i            i     i            i     i            i     i            i                     I",
                          "\tI     i            i     i            i     i            i     i            i     i            i     i            i                     X",
                          "\tX     i            i     i            i     i            i     i            i     i            i     i            i                     X",
                          "\tI     i            i     i            i     i            i     i            i     i            i     i            i                     I",
                          "\tX     i            i     i            i     i            i     i            i     i            i     i            i                     X",
                          "\tI     i            i     i            i     i            i     i            i     i            i     i            i                     I",
                          "\tX     i            i     i            i     i            i     i            i     i            i     i            i                     X",
                          "\tI      xxxxxxxxxxxx       xxxxxxxxxxxx       xxxxxxxxxxxx       xxxxxxxxxxxx       xxxxxxxxxxxx       xxxxxxxxxxxx                      X",
                          "\tIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIX"};

    char nota[8][10] = {"         ",
                        " |~~~~|  ",
                        " |    |  ",
                        " |    |  ", // nota de musica!!
                        " |    |  ",
                        " |    |  ",
                        " (_)  (_)",
                        "         "};

    char cruz[8][10] = {
        "   .-.   ",
        " __| |__ ",
        " __   __ ",
        "   | |   ",
        "   | |   ",
        "   | |   ",
        "   '-'   ",
    };
    char coffe[8][10] = {
        "   )(    ",
        "   )(    ",
        "   )(    ",
        " :----:  ",
        "C|====|  ",
        " |    |  ",
        " |    |  ",
        " `----'  ",
    };
    char cactus[8][10] = {
        " _  _    ",
        "| || | _ ",
        "| || || |",
        "| || || |",
        "|__| || |",
        "   | |_/ ",
        "   | |   ",
        "   |_|-  ",
    };
    char rosa[8][10] = {" wWWWw   ",
                        " (___)   ",
                        "  ~Y~    ",
                        "   |     ",
                        "   |     ",
                        "   |     ",
                        " ^^^^^   ",
                        "         "};
    char books[8][10] = {
        "     ___ ",
        " ___| _ |",
        "|   |   |",
        "|===|   |",
        "|===| - |",
        "|   |   |",
        "|===| - |",
        "|___|___|",
    };
    char Cazinha[8][10] = {
        " ______  ",
        "|      | ",
        "|      | ",
        "|______| ",
        "|   _  | ",
        "|  | | | ",
        "|  | | | ",
        "|__|_|_| ",
    };
    char chapeuchefe[8][10] = {
        "  ,- -.  ",
        ",'  .--',",
        "`.     ,'",
        " |`-.-'| ",
        " |     | ",
        " |     | ",
        " |     | ",
        "  `---'  ",
    };
    char calculadora[8][10] = {
        " _______ ", // calculadora binaria par 4 bits
        "|| 0001||",
        "| + | x |",
        "| soma  |",
        "| / | - |",
        "| soma  |",
        "| 0 | 1 |",
        "|_______|"
    };
    char estatua[8][10] = {
        " (((^^)))",
        "  >>><<< ",
        "  |||||| ",
        "  (o)(o) ",
        "  |    | ",
        "  (====) ",
        "  |_/ _| ",
        "  (_/ _) ",
    };
    int escolha1, escolha2, i, j, x;
    srand(time(NULL));       // pseudo-random
    for (i = 0; i < 10; i++) // gera as primeiras 10 cartas
    {
        cards[i] = 1 + (rand() % 10);
    }
    for (i = 0; i < 10; i++) // for aninhado pra numeros repetidos
    {
        for (j = 0; j < 10; j++)
        {
            if (i != j)
            {

                while (cards[i] == cards[j])
                {
                    cards[i] = 1 + (rand() % 10);
                }
                for (x = 0; x < 10; x++)
                {
                    if (i != x)
                    {
                        while (cards[i] == cards[x])
                        {
                            cards[i] = 1 + (rand() % 10);
                        }
                    }
                }
            }
        }
    }
    for (i = 10; i < 20; i++) // gera as outras 10 cartas para formar par
    {
        cards[i] = 1 + (rand() % 10);
    }
    for (i = 10; i < 20; i++) // for aninhado pra numeros repetidos
    {
        for (j = 10; j < 20; j++)
        {
            if (i != j)
            {
                while (cards[i] == cards[j])
                {
                    cards[i] = 1 + (rand() % 10);
                }
                for (x = 10; x < 20; x++)
                {
                    if (i != x)
                    {
                        while (cards[i] == cards[x])
                        {
                            cards[i] = 1 + (rand() % 10);
                        }
                    }
                }
            }
        }
    }
    do
    {
        system("clear||cls");
        for (linhas = 0; linhas < 36; linhas++) //COMECO DA ESCOLHA DE CARD 1
        {
            printf("%s\n", tela[linhas]);
        }
        printf("\n\n");

        printf("ESCOLHA UM CARD OU 0 PRA SAIR");
        scanf("%d%*c", &escolha1);
        while (escolha1 < 0 || escolha1 > 20)
        {
            printf("DIGITE UM NUMERO CORRETO DE CARDS");
            scanf("%d%*c", &escolha1);
        }
        if (escolha1 == 0)
            break;

        switch (escolha1) //COORDENADAS DOS CARDS DA ESCOLHA 1
        {

        // 1
        case 1:
            lim_inf_lin1 = 2; //Onde comecao card
            lim_sup_lin1 = 10; //Onde termina de cima pra baixo
            lim_inf_col1 = 9; //onde comeca a coluna
            lim_sup_col1 = 18; //Onde termina
            break;

        // 2
        case 2:
            lim_inf_lin1 = 3;
            lim_sup_lin1 = 11;
            lim_inf_col1 = 24;
            lim_sup_col1 = 33;
            break;
        // 3
        case 3:
            lim_inf_lin1 = 2;
            lim_sup_lin1 = 10;
            lim_inf_col1 = 40;
            lim_sup_col1 = 48;
            break;
        // 4
        case 4:
            lim_inf_lin1 = 2;
            lim_sup_lin1 = 10;
            lim_inf_col1 = 56;
            lim_sup_col1 = 64;
            break;
        // 5
        case 5:
            lim_inf_lin1 = 2;
            lim_sup_lin1 = 10;
            lim_inf_col1 = 72;
            lim_sup_col1 = 81;
            break;
        // 6
        case 6:
            lim_inf_lin1 = 2;
            lim_sup_lin1 = 10;
            lim_inf_col1 = 88;
            lim_sup_col1 = 97;
            break;
        // 7
        case 7:
            lim_inf_lin1 = 2;
            lim_sup_lin1 = 10;
            lim_inf_col1 = 103;
            lim_sup_col1 = 111;
            break;
        // 8
        case 8:
            lim_inf_lin1 = 13;
            lim_sup_lin1 = 21;
            lim_inf_col1 = 8;
            lim_sup_col1 = 15;
            break;
        // 9
        case 9:
            lim_inf_lin1 = 13;
            lim_sup_lin1 = 21;
            lim_inf_col1 = 24;
            lim_sup_col1 = 30;
            break;
        // 10
        case 10:
            lim_inf_lin1 = 13;
            lim_sup_lin1 = 21;
            lim_inf_col1 = 40;
            lim_sup_col1 = 49;
            break;
        // 11
        case 11:
            lim_inf_lin1 = 13;
            lim_sup_lin1 = 21;
            lim_inf_col1 = 56;
            lim_sup_col1 = 65;
            break;
        // 12
        case 12:
            lim_inf_lin1 = 13;
            lim_sup_lin1 = 21;
            lim_inf_col1 = 72;
            lim_sup_col1 = 79;
            break;
        // 13
        case 13:
            lim_inf_lin1 = 13;
            lim_sup_lin1 = 21;
            lim_inf_col1 = 88;
            lim_sup_col1 = 96;
            break;
        // 14
        case 14:
            lim_inf_lin1 = 13;
            lim_sup_lin1 = 21;
            lim_inf_col1 = 103;
            lim_sup_col1 = 111;
            break;

        // 15
        case 15:
            lim_inf_lin1 = 24;
            lim_sup_lin1 = 32;
            lim_inf_col1 = 8;
            lim_sup_col1 = 16;
            break;

        // 16
        case 16:
            lim_inf_lin1 = 24;
            lim_sup_lin1 = 32;
            lim_inf_col1 = 24;
            lim_sup_col1 = 31;
            break;
        // 17
        case 17:
            lim_inf_lin1 = 24;
            lim_sup_lin1 = 32;
            lim_inf_col1 = 40;
            lim_sup_col1 = 49;
            break;
        // 18
        case 18:
            lim_inf_lin1 = 24;
            lim_sup_lin1 = 32;
            lim_inf_col1 = 56;
            lim_sup_col1 = 64;
            break;
        // 19
        case 19:
            lim_inf_lin1 = 24;
            lim_sup_lin1 = 32;
            lim_inf_col1 = 72;
            lim_sup_col1 = 79;
            break;
        // 20
        case 20:
            lim_inf_lin1 = 24;
            lim_sup_lin1 = 32;
            lim_inf_col1 = 88;
            lim_sup_col1 = 96;
            break;
        }
        for (altura = 0, cont = lim_inf_lin1; cont < lim_sup_lin1; cont++, altura++)
        {
            for (aux = lim_inf_col1, largura = 0; aux < lim_sup_col1; aux++, largura++) //FOR DAS FIGURAS
            {
                switch (cards[escolha1 - 1])
                {
                case 1:
                    tela[cont][aux] = nota[altura][largura];
                    break;
                case 2:
                    tela[cont][aux] = cruz[altura][largura];
                    break;
                case 3:
                    tela[cont][aux] = coffe[altura][largura];
                    break;
                case 4:
                    tela[cont][aux] = cactus[altura][largura];
                    break;
                case 5:
                    tela[cont][aux] = rosa[altura][largura];
                    break;
                case 6:
                    tela[cont][aux] = books[altura][largura];
                    break;
                case 7:
                    tela[cont][aux] = Cazinha[altura][largura];
                    break;
                case 8:
                    tela[cont][aux] = chapeuchefe[altura][largura];
                    break;
                case 9:
                    tela[cont][aux] = calculadora[altura][largura];
                    break;
                case 10:
                    tela[cont][aux] = estatua[altura][largura];
                    break;
                }
            }
        }
        system("clear||cls"); //COMECO DA ESCOLHA 2
        for (linhas = 0; linhas < 36; linhas++)
        {
            printf("%s\n", tela[linhas]);
        }
        printf("\n\n");
        printf("ESCOLHA UM CARD, OU ZERO (0) PRA SAIR"); //VALIDACAO DE ENTRADA
        scanf("%d%*c", &escolha2);
        while (escolha2 < 0 || escolha2 > 20)
        {
            printf("ESCOLHA UM CARD CORRETO");
            scanf("%d%*c", &escolha2);
        }

        if (escolha2 == 0)
            break;
        switch (escolha2)
        {
        // 1
       case 1:
            lim_inf_lin2 = 2;
            lim_sup_lin2 = 10;
            lim_inf_col2 = 8;
            lim_sup_col2 = 16;
            break;

        // 2
        case 2:
            lim_inf_lin2 = 2;
            lim_sup_lin2 = 10;
            lim_inf_col2 = 24;
            lim_sup_col2 = 33;
            break;
        // 3
        case 3:
            lim_inf_lin2 = 2;
            lim_sup_lin2 = 10;
            lim_inf_col2 = 40;
            lim_sup_col2 = 48;
            break;
        // 4
        case 4:
            lim_inf_lin2 = 2;
            lim_sup_lin2 = 10;
            lim_inf_col2 = 56;
            lim_sup_col2 = 64;
            break;
        // 5
        case 5:
            lim_inf_lin2 = 2;
            lim_sup_lin2 = 10;
            lim_inf_col2 = 72;
            lim_sup_col2 = 81;
            break;
        // 6
        case 6:
            lim_inf_lin2 = 2;
            lim_sup_lin2 = 10;
            lim_inf_col2 = 88;
            lim_sup_col2 = 97;
            break;
        // 7
        case 7:
            lim_inf_lin2 = 2;
            lim_sup_lin2 = 10;
            lim_inf_col2 = 103;
            lim_sup_col2 = 111;
            break;
        // 8
        case 8:
            lim_inf_lin2 = 13;
            lim_sup_lin2 = 21;
            lim_inf_col2 = 8;
            lim_sup_col2 = 15;
            break;
        // 9
        case 9:
            lim_inf_lin2 = 13;
            lim_sup_lin2 = 21;
            lim_inf_col2 = 24;
            lim_sup_col2 = 30;
            break;
        // 10
        case 10:
            lim_inf_lin2 = 13;
            lim_sup_lin2 = 21;
            lim_inf_col2 = 40;
            lim_sup_col2 = 48;
            break;
        // 11
        case 11:
            lim_inf_lin2 = 13;
            lim_sup_lin2 = 21;
            lim_inf_col2 = 56;
            lim_sup_col2 = 65;
            break;
        // 12
        case 12:
            lim_inf_lin2 = 13;
            lim_sup_lin2 = 21;
            lim_inf_col2 = 72;
            lim_sup_col2 = 79;
            break;
        // 13
        case 13:
            lim_inf_lin2 = 13;
            lim_sup_lin2 = 21;
            lim_inf_col2 = 88;
            lim_sup_col2 = 95;
            break;
        // 14
        case 14:
            lim_inf_lin2 = 13;
            lim_sup_lin2 = 21;
            lim_inf_col2 = 103;
            lim_sup_col2 = 111;
            break;

        // 15
        case 15:
            lim_inf_lin2 = 24;
            lim_sup_lin2 = 32; 
            lim_inf_col2 = 8;
            lim_sup_col2 = 16;
            break;

        // 16
        case 16:
            lim_inf_lin2 = 24;
            lim_sup_lin2 = 32;
            lim_inf_col2 = 24;
            lim_sup_col2 = 31;
            break;
        // 17
        case 17:
            lim_inf_lin2 = 24;
            lim_sup_lin2 = 32;
            lim_inf_col2 = 40;
            lim_sup_col2 = 49;
            break;
        // 18
        case 18:
            lim_inf_lin2 = 24;
            lim_sup_lin2 = 32;
            lim_inf_col2 = 56;
            lim_sup_col2 = 64;
            break;
        // 19
        case 19:
            lim_inf_lin2 = 24;
            lim_sup_lin2 = 32;
            lim_inf_col2 = 72;
            lim_sup_col2 = 79;
            break;
        // 20
        case 20:
            lim_inf_lin2 = 24;
            lim_sup_lin2 = 32;
            lim_inf_col2 = 88;
            lim_sup_col2 = 96;
            break;
        }
        for (altura = 0, cont = lim_inf_lin2; cont < lim_sup_lin2; cont++, altura++)
        {
            for (aux = lim_inf_col2, largura = 0; aux < lim_sup_col2; aux++, largura++) //SWITCH CASES DAS FIGURAS
            {
                switch (cards[escolha2 - 1])
                {
                case 1:
                    tela[cont][aux] = nota[altura][largura];
                    break;
                case 2:
                    tela[cont][aux] = cruz[altura][largura];
                    break;
                case 3:
                    tela[cont][aux] = coffe[altura][largura];
                    break;
                case 4:
                    tela[cont][aux] = cactus[altura][largura];
                    break;
                case 5:
                    tela[cont][aux] = rosa[altura][largura];
                    break;
                case 6:
                    tela[cont][aux] = books[altura][largura];
                    break;
                case 7:
                    tela[cont][aux] = Cazinha[altura][largura];
                    break;
                case 8:
                    tela[cont][aux] = chapeuchefe[altura][largura];
                    break;
                case 9:
                    tela[cont][aux] = calculadora[altura][largura];
                    break;
                case 10:
                    tela[cont][aux] = estatua[altura][largura];
                    break;
                }
            }
        }
        system("clear||cls");
        for (linhas = 0; linhas < 36; linhas++) //limpar a tela
        {
            printf("%s\n", tela[linhas]);
        }

        if (cards[escolha1 - 1] == cards[escolha2 - 1]) //CONDIÇAO DE ACHOU UM PAR
        {
            printf("Parabéns, voce achou um par...\n");
            pares++;
        }
        else
        {
            printf("Não deu match, mas continue tentando...\n");
            for (altura = 0; lim_inf_lin1 < lim_sup_lin1; lim_inf_lin1++, altura++) //ESSE FOR ANINHADO SERVE PRA LIMPAR A TELA PÓS O JOGADOR N TER ACERTADO O PAR
        {
            for (aux = lim_inf_col1, largura = 0; aux < lim_sup_col1; aux++, largura++)
            {
                switch (cards[escolha1])
                {
                case 1:
                    tela[lim_inf_lin1][aux] = ' ';
                    break;
                case 2:
                    tela[lim_inf_lin1][aux] = ' ';
                    break;
                case 3:
                    tela[lim_inf_lin1][aux] = ' ';
                    break;
                case 4:
                    tela[lim_inf_lin1][aux] = ' ';
                    break;
                case 5:
                    tela[lim_inf_lin1][aux] = ' ';
                    break;
                case 6:
                    tela[lim_inf_lin1][aux] = ' ';
                    break;
                case 7:
                    tela[lim_inf_lin1][aux] = ' ';
                    break;
                case 8:
                    tela[lim_inf_lin1][aux] = ' ';
                    break;
                case 9:
                    tela[lim_inf_lin1][aux] = ' ';
                    break;
                case 10:
                    tela[lim_inf_lin1][aux] = ' ';
                    break;
                case 11:
                    tela[lim_inf_lin1][aux] = ' ';
                    break;
                case 12:
                    tela[lim_inf_lin1][aux] = ' ';
                    break;
                case 13:
                    tela[lim_inf_lin1][aux] = ' ';
                    break;
                case 14:
                    tela[lim_inf_lin1][aux] = ' ';
                    break;
                case 15:
                    tela[lim_inf_lin1][aux] = ' ';
                    break;
                case 16:
                    tela[lim_inf_lin1][aux] = ' ';
                    break;
                case 17:
                    tela[lim_inf_lin1][aux] = ' ';
                    break;
                case 18:
                    tela[lim_inf_lin1][aux] = ' ';
                    break;
                case 19:
                    tela[lim_inf_lin1][aux] = ' ';
                    break;
                case 20:
                    tela[lim_inf_lin1][aux] = ' ';
                    break;
                }
            }
        }
        for (altura = 0; lim_inf_lin2 < lim_sup_lin2; lim_inf_lin2++, altura++) //ESSE FOR ANINHADO SERVE PRA LIMPAR A TELA PÓS O JOGADOR N TER ACERTADO O PAR
        {
            for (aux = lim_inf_col2, largura = 0; aux < lim_sup_col2; aux++, largura++)
            { 
                switch (cards[escolha2])
                {
                case 1:
                    tela[lim_inf_lin2][aux] = ' ';
                    break;
                case 2:
                    tela[lim_inf_lin2][aux] = ' ';
                    break;
                case 3:
                    tela[lim_inf_lin2][aux] = ' ';
                    break;
                case 4:
                    tela[lim_inf_lin2][aux] = ' ';
                    break;
                case 5:
                    tela[lim_inf_lin2][aux] = ' ';
                    break;
                case 6:
                    tela[lim_inf_lin2][aux] = ' ';
                    break;
                case 7:
                    tela[lim_inf_lin2][aux] = ' ';
                    break;
                case 8:
                    tela[lim_inf_lin2][aux] = ' ';
                    break;
                case 9:
                    tela[lim_inf_lin2][aux] = ' ';
                    break;
                case 10:
                    tela[lim_inf_lin2][aux] = ' ';
                    break;
                case 11:
                    tela[lim_inf_lin2][aux] = ' ';
                    break;
                case 12:
                    tela[lim_inf_lin2][aux] = ' ';
                    break;
                case 13:
                    tela[lim_inf_lin2][aux] = ' ';
                    break;
                case 14:
                    tela[lim_inf_lin2][aux] = ' ';
                    break;
                case 15:
                    tela[lim_inf_lin2][aux] = ' ';
                    break;
                case 16:
                    tela[lim_inf_lin2][aux] = ' ';
                    break;
                case 17:
                    tela[lim_inf_lin2][aux] = ' ';
                    break;
                case 18:
                    tela[lim_inf_lin2][aux] = ' ';
                    break;
                case 19:
                    tela[lim_inf_lin2][aux] = ' ';
                    break;
                case 20:
                    tela[lim_inf_lin2][aux] = ' ';
                    break;
                }
            }
        }
        }
        if (pares == 10)
        {
            printf("\nParabéns, voce achou todos os pares!!!!\n");
            printf("\nDesejas jogar novamente? 0-Sair, qualquer coisa pra continuar\n");
            scanf("%d", &escolha1);
            system("clear||cls");
        for (linhas = 0; linhas < 36; linhas++)
        {
            printf("%s\n", tela[linhas]);
        }
        }

        

        printf(TEXTO_VERMELHO "Pressione <ENTER> pra continuar...\n" COLOR_RESET);
        scanf("%*c");
        // printf(ANSI_COLOR_GREEN "Obrigado por jogar nosso joguinho " COLOR_RESET ".\n");
        // printf(ANSI_COLOR_GRAY "\nVenha jogar mais vezes, estamos em desenvolvimento\n");
        printf("OBRIGADO POR JOGAR, VOLTE SEMPRE :)\n");
    } while (escolha1);
}