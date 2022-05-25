#include <bits/stdc++.h>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

// Protótipos

int encontrando_d();

void descriptografar(unsigned short int de);

// Variavel Global

int totiente;

int main()
{
    int d;

    d = encontrando_d();

    descriptografar(d);

    return 0;
}

int encontrando_d()
{
    int tamanho = 0, numero_euler, resto, divisor_anterior, divisor, v;
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
    v = 0;
    while (((v * numero_euler) % totiente) != 1)
    {
        v++;
    }

    return v;
}

void descriptografar(unsigned short int de)
{
    unsigned short int numero;
    char buffer[10], letra;
    stringstream aux;
    ifstream fun("criptografado.txt");
    ofstream fout("descriptografado.txt");
    while (fun)
    {
        fun.getline(buffer, 10);
        numero = atoi(buffer);
        numero = pow(numero, de);
        numero = numero % totiente;
        letra = numero;
        fout << letra;
    }
}