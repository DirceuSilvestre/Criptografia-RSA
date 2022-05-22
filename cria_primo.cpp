#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <string>
#include <sstream>

/*

    Código criado para gerar 2 números primos e diferentes entre si

    os primos são importantes pois a partir deles conseguiremos criar a chave pública e a chave privada

*/

using namespace std;

// typedef unsigned short int usi;

int primo1, primo2, anterior = 0;

// Protótipos

void cria_primo(int *onde_guardar);

void guarda_primo(int primo);

int main()
{
    cria_primo(&primo1);
    cria_primo(&primo2);

    guarda_primo(primo1);
    guarda_primo(primo2);

    return 0;
}

void guarda_primo(int primo)
{
    char texto[sizeof(int)];
    ofstream fout("primos.txt", ios::app);
    sprintf(texto, "%d", primo);
    fout << texto << endl;
}

void cria_primo(int *onde_guardar)
{
    int gerador_de_numero;
    srand(time(NULL));
    gerador_de_numero = rand();
    while (gerador_de_numero < 10000)
    {
        gerador_de_numero = rand();
    }

    while (1)
    {
        int i;
        int divisores = 0;

        for (i = 2; i < gerador_de_numero / 2; i++)
        {
            if (gerador_de_numero % i == 0)
            {
                divisores++;
            }
            else if (divisores != 0)
            {
                break;
            }
        }
        if (divisores == 0 && gerador_de_numero != anterior)
        {
            *onde_guardar = gerador_de_numero;
            anterior = gerador_de_numero;
            break;
        }
        else
        {
            gerador_de_numero = rand();
        }
    }
}
