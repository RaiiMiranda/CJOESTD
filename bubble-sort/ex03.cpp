//Implementação do algoritmo Bubble Sort - Contador de Operações
#include <iostream>
using namespace std;

/*
Bubble Sort - versão otimizada
    teste 1: comp = 9   trocas = 3
    teste 2: comp = 42  trocas = 23
    teste 3: comp = 45  trocas = 45  (pior caso)
    teste 4: comp = 9   trocas = 0   (melhor caso)

Bubble Sort - versão não otimizada
    teste 1: comp = 10  trocas = 3
    teste 2: comp = 45  trocas = 23
    teste 3: comp = 45  trocas = 45  (pior caso)
    teste 4: comp = 45  trocas = 0   (melhor caso)
*/

//Funcao bubbleSort - O(n²)
void bubbleSort(int arr[], int n)
{
    int qntComparacoes = 0;
    int qntTrocas = 0;

    for(int i = 0; i < n; i++)
    {
        bool swapped = false; //volta como false a cada passada

        for(int j = 0; j < n - i - 1; j++)
        {
            qntComparacoes++;

            if(arr[j] > arr[j + 1])
            {
                swapped = true; //houve troca
                qntTrocas++;

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

        //se nao houve troca, entao ja esta ordenado
        if(swapped == false)
        {
            cout << "Numero de comparacoes ...: " << qntComparacoes << endl;
            cout << "Numero de trocas ........: " << qntTrocas << endl;
            return;
        }
    }

    //cout << "Numero de comparacoes ...: " << qntComparacoes << endl;
    //cout << "Numero de trocas ........: " << qntTrocas << endl;
}

//Funcao pra imprimir o array
void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(void)
{
    // Teste 1: Array pequeno
    int arr1[] = {3, 1, 4, 1, 5};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    // Teste 2: Array médio
    int arr2[] = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // Teste 3: Pior caso (ordem inversa)
    int arr3[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);

    // Teste 4: Melhor caso (já ordenado)
    int arr4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);

    cout << ">> TESTE 1 - Array pequeno" << endl;
    cout << "Array original: ";
    printArray(arr1, n1);
    cout << endl;

    bubbleSort(arr1, n1);

    cout << endl;
    cout << "Array ordenado: ";
    printArray(arr1, n1);

    cout << endl;

    cout << ">> TESTE 2 - Array medio" << endl;
    cout << "Array original: ";
    printArray(arr2, n2);
    cout << endl;

    bubbleSort(arr2, n2);

    cout << endl;
    cout << "Array ordenado: ";
    printArray(arr2, n2);

    cout << endl;

    cout << ">> TESTE 3 - Pior caso (ordem inversa)" << endl;
    cout << "Array original: ";
    printArray(arr3, n3);
    cout << endl;

    bubbleSort(arr3, n3);

    cout << endl;
    cout << "Array ordenado: ";
    printArray(arr3, n3);

    cout << endl;

    cout << ">> TESTE 4 - Melhor caso (ja ordenado)" << endl;
    cout << "Array original: ";
    printArray(arr4, n4);
    cout << endl;

    bubbleSort(arr4, n4);

    cout << endl;
    cout << "Array ordenado: ";
    printArray(arr4, n4);

    return 0;
}
