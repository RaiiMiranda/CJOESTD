//Implementação do algoritmo Bubble Sort - Versão Otimizada
#include <iostream>
using namespace std;

//Funcao bubbleSort - O(n²) pior e caso medio - O(n) melhor caso
void bubbleSort(int arr[], int n)
{
    int qntPassadas = 0;

    for(int i = 0; i < n; i++)
    {
        bool swapped = false; //volta como false a cada passada
        qntPassadas++;

        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swapped = true; //houve troca

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

        //se nao houve troca, entao ja esta ordenado
        if(swapped == false)
        {
            cout << "Nao ha mais trocas." << endl;
            cout << "Quantidade de passadas: " << qntPassadas << endl; //ordenado = 1 passada ... desordenado = 5 passadas
            return;
        }
    }
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
    //melhor caso: O(n)
    int arrOrdenado[] = {1, 2, 3, 4, 5};
    int n1 = sizeof(arrOrdenado) / sizeof(arrOrdenado[0]);

    //pior caso: O(n²)
    int arrDesordenado[] = {5, 4, 3, 2, 1};
    int n2 = sizeof(arrDesordenado) / sizeof(arrDesordenado[0]);

    cout << ">> Array original - Ordenado: ";
    printArray(arrOrdenado, n1);
    cout << endl;

    bubbleSort(arrOrdenado, n1);

    cout << endl;
    cout << "Array ordenado: ";
    printArray(arrOrdenado, n1);

    cout << endl;

    cout << ">> Array original - Desordenado: ";
    printArray(arrDesordenado, n2);
    cout << endl;

    bubbleSort(arrDesordenado, n2);

    cout << endl;
    cout << "Array ordenado: ";
    printArray(arrDesordenado, n2);

    return 0;
}
