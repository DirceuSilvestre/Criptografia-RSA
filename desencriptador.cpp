#include <bits/stdc++.h>
#include <fstream>
#include <algorithm>

using namespace std;

// Protótipos

int encontrando_d()
{
    int tamanho = 0, totiente, numero_euler, resto, divisor_anterior, divisor;
    char buffer[10];
    ifstream fin("chave_publica.txt");
    while (fin)
    {
        fin.getline(buffer, 10);
        if (tamanho == 0)
        {
            totiente = atoi(buffer);
        }
        else if (tamanho == 1)
        {
            numero_euler = atoi(buffer);
        }
        tamanho++;
    }

    resto = numero_euler % totiente;
    divisor_anterior = totiente;

    while (resto != 1)
    {
        divisor = divisor_anterior;
        divisor_anterior = resto;
        resto = divisor % divisor_anterior;
    }

    return 0;
}

int main()
{
    encontrando_d();

    return 0;
}