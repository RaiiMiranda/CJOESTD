//Implementação do algoritmo Bubble Sort
#include <iostream>
using namespace std;

//Funcao bubbleSort - O(n²) todos os casos
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

//Funcao pra imprimir o array
void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(void)
{
    int arr[] = {7, 3, 9, 1, 5, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]); //n = 7 * 4 bytes / 4 bytes = 7 elementos

    cout << "Array original: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "Array ordenado: ";
    printArray(arr, n);

    return 0;
}
