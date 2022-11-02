#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Encontrar o maior valor, menor valor e média  dos valores de um vetor de 20 posições

    int vetor[20], i, maior, menor, soma = 0;
    float media;

    for (i = 0; i < 20; i++)
    {
        printf("Digite o valor de vetor[%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    maior = vetor[0];
    menor = vetor[0];

    for (i = 0; i < 20; i++)
    {
        if (vetor[i] > maior)
        {
            maior = vetor[i];
        }
        if (vetor[i] < menor)
        {
            menor = vetor[i];
        }
        soma = soma + vetor[i];
    }

    media = soma / 20;

printf("O maior valor e: %d", maior);
printf("O menor valor e: %d", menor);
printf("A media e: %.2f", media);

return 0;
}
