#define X "\\"
#define TEXTO_VERMELHO "\x1b[31;1m"
#define COLOR_RESET "\033[0m"
#define ANSI_COLOR_GREEN "\e[0;32m"
#define ANSI_COLOR_GRAY "\e[0;37m"

int main()
{

    int linhas, lim_inf_lin1, lim_inf_col1, lim_inf_lin2, lim_inf_col2, largura, altura;
    int lim_sup_col1, lim_sup_lin1, lim_sup_col2, lim_sup_lin2, aux, cont; /*cards[20] = {1, 2, 2, 1}*/
    char tela[36][119] = {"\tXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXI",
                          "\tI      xxxxxxxxx       xxxxxxxxx       xxxxxxxxx       xxxxxxxxx       xxxxxxxxx       xxxxxxxxx      xxxxxxxxx    X",
                          "\tX  01.i         i  02.i         i  03.i         i  04.i         i  05.i         i  06.i         i 07.i         i   I",
                          "\tI     i         i     i         i     i         i     i         i     i         i     i         i    i         i   X",
                          "\tX     i         i     i         i     i         i     i         i     i         i     i         i    i         i   I",
                          "\tI     i         i     i         i     i         i     i         i     i         i     i         i    i         i   X",
                          "\tX     i         i     i         i     i         i     i         i     i         i     i         i    i         i   I",
                          "\tI     i         i     i         i     i         i     i         i     i         i     i         i    i         i   X",
                          "\tX     i         i     i         i     i         i     i         i     i         i     i         i    i         i   I",
                          "\tI     i         i     i         i     i         i     i         i     i         i     i         i    i         i   X",
                          "\tX      xxxxxxxxx       xxxxxxxxx       xxxxxxxxx       xxxxxxxxx       xxxxxxxxx       xxxxxxxxx      xxxxxxxxx    I",
                          "\tX                                                                                                                  X",
                          "\tI      xxxxxxxxx       xxxxxxxxx       xxxxxxxxx       xxxxxxxxx       xxxxxxxxx       xxxxxxxxx      xxxxxxxxx    I",
                          "\tX  08.i         i  09.i         i  10.i         i  11.i         i  12.i         i  13.i         i 14.i         i   X",
                          "\tI     i         i     i         i     i         i     i         i     i         i     i         i    i         i   A",
                          "\tI     i         i     i         i     i         i     i         i     i         i     i         i    i         i   B",
                          "\tI     i         i     i         i     i         i     i         i     i         i     i         i    i         i   I",
                          "\tX     i         i     i         i     i         i     i         i     i         i     i         i    i         i   X",
                          "\tI     i         i     i         i     i         i     i         i     i         i     i         i    i         i   I",
                          "\tX     i         i     i         i     i         i     i         i     i         i     i         i    i         i   X",
                          "\tI     i         i     i         i     i         i     i         i     i         i     i         i    i         i   I",
                          "\tX      xxxxxxxxx       xxxxxxxxx       xxxxxxxxx       xxxxxxxxx       xxxxxxxxx       xxxxxxxxx      xxxxxxxxx    X",
                          "\tI                                                                                                  XXXXXXXXXXXXXXXXX",
                          "\tI      xxxxxxxxx       xxxxxxxxx       xxxxxxxxx       xxxxxxxxx       xxxxxxxxx       xxxxxxxxx   X",
                          "\tX  15.i         i  16.i         i  17.i         i  18.i         i  19.i         i  20.i         i  I",
                          "\tI     i         i     i         i     i         i     i         i     i         i     i         i  X",
                          "\tX     i         i     i         i     i         i     i         i     i         i     i         i  I",
                          "\tI     i         i     i         i     i         i     i         i     i         i     i         i  X",
                          "\tX     i         i     i         i     i         i     i         i     i         i     i         i  X",
                          "\tI     i         i     i         i     i         i     i         i     i         i     i         i  I",
                          "\tX     i         i     i         i     i         i     i         i     i         i     i         i  X",
                          "\tI     i         i     i         i     i         i     i         i     i         i     i         i  I",
                          "\tX      xxxxxxxxx       xxxxxxxxx       xxxxxxxxx       xxxxxxxxx       xxxxxxxxx       xxxxxxxxx   X",
                          "\tI                                                                                                  X",
                          "\tIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIXIX"};

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
        "[__   __]",
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
                        "  \\|    ",
                        "  \\|/   ",
                        " \\\\|// ",
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
        "   /\\)( ",
        "  /  \\ |",
        " / || \\|",
        "/______\\",
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
        " _______ ",
        "|calbin_|", // calculadora binaria par 4 bits
        "|| 0001||",
        "|[+]|[X]|",
        "|*sosoma|",
        "|[/]|[-]|",
        "|*sosoma|",
        "|[0]|[1]|",
    };
    char estatua[8][10] = {
        "(((^^))) ",
        " >>><<<  ",
        " ||||||  ",
        " (o)(o)  ",
        " | /\\ | ",
        " (====)  ",
        " |_/\\_| ",
        " (_/\\_) ",
    };
    
    system("clear||cls");
    for (linhas = 0; linhas < 36; linhas++)
    {
        printf("%s\n", tela[linhas]);
    }
    /*int jogadores;
    printf("Vamos jogar? Insira o numero de jogadores"); //REVISAR PARA PEDIR O NOME DO JOGADOR
    scanf("%d", &jogadores); */

    lim_inf_lin1 = 2;
    lim_sup_lin1 = 9;
    lim_inf_col1 = 8;
    lim_sup_col1 = 17;
    for (altura = 0, cont = lim_inf_lin1; cont < lim_sup_lin1; cont++, altura++)
    { //
        for (aux = lim_inf_col1, largura = 0; aux < lim_sup_col1; aux++, largura++)
        {
            tela[cont][aux] = nota[altura][largura];
        }
    }
    lim_inf_lin1 = 2;
    lim_sup_lin1 = 9;
    lim_inf_col1 = 24;
    lim_sup_col1 = 33;
    for (altura = 0, cont = lim_inf_lin1; cont < lim_sup_lin1; cont++, altura++)
    {
        for (aux = lim_inf_col1, largura = 0; aux < lim_sup_col1; aux++, largura++)
        {
            tela[cont][aux] = cruz[altura][largura];
        }
    }
    lim_inf_lin1 = 2;
    lim_sup_lin1 = 9;
    lim_inf_col1 = 40;
    lim_sup_col1 = 49;
    for (altura = 0, cont = lim_inf_lin1; cont < lim_sup_lin1; cont++, altura++)
    {
        for (aux = lim_inf_col1, largura = 0; aux < lim_sup_col1; aux++, largura++)
        {
            tela[cont][aux] = cruz[altura][largura];
        }
    }
    lim_inf_lin1 = 2;
    lim_sup_lin1 = 9;
    lim_inf_col1 = 56;
    lim_sup_col1 = 65;
    for (altura = 0, cont = lim_inf_lin1; cont < lim_sup_lin1; cont++, altura++)
    {
        for (aux = lim_inf_col1, largura = 0; aux < lim_sup_col1; aux++, largura++)
        {
            tela[cont][aux] = nota[altura][largura];
        }
    }

    lim_inf_lin1 = 2;
    lim_sup_lin1 = 10;
    lim_inf_col1 = 73;
    lim_sup_col1 = 81;
    for (altura = 0, cont = lim_inf_lin1; cont < lim_sup_lin1; cont++, altura++)
    {
        for (aux = lim_inf_col1, largura = 0; aux < lim_sup_col1; aux++, largura++)
        {
            tela[cont][aux] = coffe[altura][largura];
        }
    }
    lim_inf_lin1 = 2;
    lim_sup_lin1 = 10;
    lim_inf_col1 = 88;
    lim_sup_col1 = 97;
    for (altura = 0, cont = lim_inf_lin1; cont < lim_sup_lin1; cont++, altura++)
    {
        for (aux = lim_inf_col1, largura = 0; aux < lim_sup_col1; aux++, largura++)
        {
            tela[cont][aux] = cactus[altura][largura];
        }
    }
    lim_inf_lin1 = 2;
    lim_sup_lin1 = 10;
    lim_inf_col1 = 103;
    lim_sup_col1 = 112;
    for (altura = 0, cont = lim_inf_lin1; cont < lim_sup_lin1; cont++, altura++)
    {
        for (aux = lim_inf_col1, largura = 0; aux < lim_sup_col1; aux++, largura++)
        {
            tela[cont][aux] = cactus[altura][largura];
        }
    }
    lim_inf_lin1 = 13;
    lim_sup_lin1 = 21;
    lim_inf_col1 = 9;
    lim_sup_col1 = 17;
    for (altura = 0, cont = lim_inf_lin1; cont < lim_sup_lin1; cont++, altura++)
    {
        for (aux = lim_inf_col1, largura = 0; aux < lim_sup_col1; aux++, largura++)
        {
            tela[cont][aux] = coffe[altura][largura];
        }
    }
    lim_inf_lin1 = 13;
    lim_sup_lin1 = 21;
    lim_inf_col1 = 24;
    lim_sup_col1 = 33;
    for (altura = 0, cont = lim_inf_lin1; cont < lim_sup_lin1; cont++, altura++)
    {
        for (aux = lim_inf_col1, largura = 0; aux < lim_sup_col1; aux++, largura++)
        {
            tela[cont][aux] = books[altura][largura];
        }
    }
    lim_inf_lin1 = 13;
    lim_sup_lin1 = 21;
    lim_inf_col1 = 40;
    lim_sup_col1 = 48;
    for (altura = 0, cont = lim_inf_lin1; cont < lim_sup_lin1; cont++, altura++)
    {
        for (aux = lim_inf_col1, largura = 0; aux < lim_sup_col1; aux++, largura++)
        {
            tela[cont][aux] = Cazinha[altura][largura];
        }
    }
    lim_inf_lin1 = 13;
    lim_sup_lin1 = 21;
    lim_inf_col1 = 56;
    lim_sup_col1 = 65;
    for (altura = 0, cont = lim_inf_lin1; cont < lim_sup_lin1; cont++, altura++)
    {
        for (aux = lim_inf_col1, largura = 0; aux < lim_sup_col1; aux++, largura++)
        {
            tela[cont][aux] = books[altura][largura];
        }
    }
    lim_inf_lin1 = 13;
    lim_sup_lin1 = 21;
    lim_inf_col1 = 72;
    lim_sup_col1 = 80;
    for (altura = 0, cont = lim_inf_lin1; cont < lim_sup_lin1; cont++, altura++)
    {
        for (aux = lim_inf_col1, largura = 0; aux < lim_sup_col1; aux++, largura++)
        {
            tela[cont][aux] = Cazinha[altura][largura];
        }
    }
    lim_inf_lin1 = 13;
    lim_sup_lin1 = 21;
    lim_inf_col1 = 88;
    lim_sup_col1 = 96;
    for (altura = 0, cont = lim_inf_lin1; cont < lim_sup_lin1; cont++, altura++)
    {
        for (aux = lim_inf_col1, largura = 0; aux < lim_sup_col1; aux++, largura++)
        {
            tela[cont][aux] = estatua[altura][largura];
        }
    }
    lim_inf_lin1 = 13;
    lim_sup_lin1 = 21;
    lim_inf_col1 = 103;
    lim_sup_col1 = 112;
    for (altura = 0, cont = lim_inf_lin1; cont < lim_sup_lin1; cont++, altura++)
    {
        for (aux = lim_inf_col1, largura = 0; aux < lim_sup_col1; aux++, largura++)
        {
            tela[cont][aux] = chapeuchefe[altura][largura];
        }
    }
    lim_inf_lin1 = 24;
    lim_sup_lin1 = 32;
    lim_inf_col1 = 88;
    lim_sup_col1 = 95;
    for (altura = 0, cont = lim_inf_lin1; cont < lim_sup_lin1; cont++, altura++)
    {
        for (aux = lim_inf_col1, largura = 0; aux < lim_sup_col1; aux++, largura++)
        {
            tela[cont][aux] = rosa[altura][largura];
        }
    }
    lim_inf_lin1 = 24;
    lim_sup_lin1 = 32;
    lim_inf_col1 = 8;
    lim_sup_col1 = 14;
    for (altura = 0, cont = lim_inf_lin1; cont < lim_sup_lin1; cont++, altura++)
    {
        for (aux = lim_inf_col1, largura = 0; aux < lim_sup_col1; aux++, largura++)
        {
            tela[cont][aux] = rosa[altura][largura];
        }
    }
    lim_inf_lin1 = 24;
    lim_sup_lin1 = 32;
    lim_inf_col1 = 24;
    lim_sup_col1 = 33;
    for (altura = 0, cont = lim_inf_lin1; cont < lim_sup_lin1; cont++, altura++)
    {
        for (aux = lim_inf_col1, largura = 0; aux < lim_sup_col1; aux++, largura++)
        {
            tela[cont][aux] = calculadora[altura][largura];
        }
    }
    lim_inf_lin1 = 24;
    lim_sup_lin1 = 32;
    lim_inf_col1 = 40;
    lim_sup_col1 = 48;
    for (altura = 0, cont = lim_inf_lin1; cont < lim_sup_lin1; cont++, altura++)
    {
        for (aux = lim_inf_col1, largura = 0; aux < lim_sup_col1; aux++, largura++)
        {
            tela[cont][aux] = estatua[altura][largura];
        }
    }
    lim_inf_lin1 = 24;
    lim_sup_lin1 = 32;
    lim_inf_col1 = 56;
    lim_sup_col1 = 65;
    for (altura = 0, cont = lim_inf_lin1; cont < lim_sup_lin1; cont++, altura++)
    {
        for (aux = lim_inf_col1, largura = 0; aux < lim_sup_col1; aux++, largura++)
        {
            tela[cont][aux] = chapeuchefe[altura][largura];
        }
    }
    lim_inf_lin1 = 24;
    lim_sup_lin1 = 32;
    lim_inf_col1 = 72;
    lim_sup_col1 = 81;
    for (altura = 0, cont = lim_inf_lin1; cont < lim_sup_lin1; cont++, altura++)
    {
        for (aux = lim_inf_col1, largura = 0; aux < lim_sup_col1; aux++, largura++)
        {
            tela[cont][aux] = calculadora[altura][largura];
        }
    }

    printf(TEXTO_VERMELHO "Pressione <ENTER> pra continuar...\n" COLOR_RESET);
    scanf("%*c");
    system("clear||cls");
    for (linhas = 0; linhas < 36; linhas++)
    {
        printf("%s\n", tela[linhas]);
    }
    printf(ANSI_COLOR_GREEN "Obrigado por jogar nosso joguinho "COLOR_RESET".\n");
    printf(ANSI_COLOR_GRAY"\nVenha jogar mais vezes\n");
}
