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
        numero = int(letra[i]);

        numero = pow(numero, numero_euler);

        numero = numero % totiente;

        sprintf(pedaco, "%d", numero);

        fout << pedaco << endl;
    }
}