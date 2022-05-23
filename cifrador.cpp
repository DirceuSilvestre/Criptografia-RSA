#include <bits/stdc++.h>
#include <fstream>
#include <algorithm>

using namespace std;

typedef unsigned short int usi;

void encriptografador();

int main()
{
    encriptografador();

    return 0;
}

void encriptografador()
{
    int tamanho = 0, totiente, numero_euler;
    usi numero;
    char buffer[10], letra[1000], pedaco[1000];

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

    ifstream fun("texto.txt");

    ofstream fout("criptografado.txt");

    for (size_t i = 0; fun.get(letra[i]); i++)
    {
        if (letra[i] >= 'A' && letra[i] <= 'Z')
        {
            numero = letra[i] - 'A';
        }
        else if (letra[i] >= 'a' && letra[i] <= 'z')
        {
            numero = letra[i] - 'a';
        }
        else
        {
            numero = letra[i] - 1;
        }

        numero = pow(numero, numero_euler);

        numero = numero % totiente;

        sprintf(pedaco, "%d", numero);

        fout << pedaco << endl;
    }
}