//Implementação do algoritmo Bubble Sort
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//Funcao bubbleSort
void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int indiceCor(string cor)
{
    if(cor == 'preto')
        return 1;
    if(cor == 'marrom')
        return 2;
    if(cor == 'vermelho')
        return 3;
    if(cor == 'laranja')
        return 4;
    if(cor == 'amarelo')
        return 5;
    if(cor == 'verde')
        return 6;
    if(cor == 'azul')
        return 7;
    if(cor == 'anil')
        return 8;
    if(cor == 'violeta')
        return 9;
    if(cor == 'rosa')
        return 10;
    if(cor == 'cinza')
        return 11;
    if(cor == 'branco')
        return 12;
    if(cor == 'dourado')
        return 13;
    if(cor == 'prateado')
        return 14;
    if(cor == 'ciano')
        return 15;
    if(cor == 'magenta')
        return 16;
    if(cor == 'lilás')
        return 17;
    if(cor == 'vinho')
        return 18;
    if(cor == 'salmão')
        return 19;
    if(cor == 'turquesa')
        return 20;
}

//Funcao pra imprimir o array
void printArray(string arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 'preto')
            cout << "preto, ";

    }
    cout << endl;
}

int main(void)
{
    int n = 15;
    string cor;
    int indice[n];

        //entra as 15 cores
    for(int i = 0; i < n; i++)
    {
        getline(cin, cor);


        indice[i] = indiceCor(cor); //preto = 1
    }

    cout << "Lista original:" << endl;
    printArray(indice, n);

    bubbleSort(indice, n);

    cout << "Lista ordenada:" << endl;
    printArray(indice, n);

    return 0;
}

