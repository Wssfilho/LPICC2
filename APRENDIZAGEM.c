#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    int matriz[3][3], i, j;

    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            printf("insira a linha e a coluna");
            scanf("%d%*c", &matriz[i][j]);
        }

    }
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            printf("[%d] [%d] = %d\n", i, j, matriz[i][j]);

        }

    }
    */
   
    char frase[20], inteiros[20];
    int i, cont = 0;
    printf("Digite uma frase: ");
    scanf("%[^\n]s", frase);

    for (i = 0; frase[i] != '\0'; i++)
    {
        inteiros[i] = frase[i];
        inteiros[i] = '\0';
    }
    for (cont = 0; cont < i; cont++)
    {
        printf("%c", frase[2]);

    }
    /*

        int matriz[3][3], linha1, coluna1, soma = 0, maior = 0, menor; // variaveis
        for (linha1 = 0; linha1 < 3; linha1++)                         // conta as linhas e quantas vezes ela foi rodada.
        {
            for (coluna1 = 0; coluna1 < 3; coluna1++) // Conta as colunas
            {                                       //Dois fors para varrer a matriz
                printf("Insira numeros");
                scanf("%d", &matriz[linha1][coluna1]);
            }
        }
        printf("\n\n");
        for (linha1 = 0; linha1 < 3; linha1++) // Construir outro for para imprimir as colunas
        {
            for (coluna1 = 0; coluna1 < 3; coluna1++)
            {
                printf("[%d][%d] = [%d]\n", linha1, coluna1, matriz[linha1][coluna1]);
            }

        }
        for (linha1 = 0; linha1 < 3; linha1++)
        {
            for (coluna1 = 0; coluna1 < 3; coluna1++) // Paara descobrir o traço,
            {
                if (linha1 == coluna1)
                {
                    soma += matriz[linha1][coluna1]; // Para fazer a media
                }
            }
        }
        printf("%d", soma); // Imprimir a soma
        for (linha1 = 0; linha1 < 3; linha1++)
        {
            for (coluna1 = 0; coluna1 < 3; coluna1++) // For usado para calcular o maior, se tiver valor na matriz sendo maior que a variavel maior
                                                      // recebe
            {
                if (maior < matriz[linha1][coluna1])
                {
                    maior = matriz[linha1][coluna1];
                }
            }
        }
        menor = maior;
        for (linha1 = 0; linha1 < 3; linha1++)
        {
            for (coluna1 = 0; coluna1 < 3; coluna1++) // For usado para calcular o menor, se tiver valor na matriz sendo menor que a variavel menor
                                                      // recebe
            {
                if (menor > matriz[linha1][coluna1])
                {
                    menor = matriz[linha1][coluna1];
                }
            }
        }
        printf("\nMaior e: %d,\n Menor e: %d", maior, menor);

        //COMPLETAR */
}