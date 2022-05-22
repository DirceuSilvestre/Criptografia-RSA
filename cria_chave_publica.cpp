#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>

using namespace std;

// Protótipos

int funcao_totiente(int primoX, int primoY);

int chave_publica(int fi_de_x_totiente);

int main()
{
    int primo1, primo2, tamanho = 0, totiente, numero_euler;
    char buffer[10], texto[sizeof(int)];
    ifstream fin("primos.txt");

    while (fin)
    {
        fin.getline(buffer, 6);
        if (tamanho == 0)
        {
            primo1 = atoi(buffer);
        }
        else if (tamanho == 1)
        {
            primo2 = atoi(buffer);
        }
        tamanho++;
    }

    totiente = funcao_totiente(primo1, primo2);
    cout << totiente << endl;

    numero_euler = chave_publica(totiente);
    cout << numero_euler << endl;

    ofstream fout("chave_publica.txt", ios::app);
    sprintf(texto, "%d", numero_euler);
    fout << texto << endl;
}

int funcao_totiente(int primoX, int primoY)
{
    return (primoX - 1) * (primoY - 1);
}

int chave_publica(int fi_de_x_totiente)
{
    for (int i = fi_de_x_totiente - 2; i > 1; i--)
    {
        if (__gcd(fi_de_x_totiente, i) == 1)
        {
            return i;
        }
    }
}