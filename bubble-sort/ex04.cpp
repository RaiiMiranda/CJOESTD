//Implementação do algoritmo Bubble Sort - Ordenação Decrescente
#include <iostream>
using namespace std;

//Funcao bubbleSort - O(n²)
void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] < arr[j + 1]) //única linha que precisa mudar para ficar em ordem decrescente
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
    int arr[] = {1, 5, 3, 9, 2, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array original ..............: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "Array ordenado decrescente ..: ";
    printArray(arr, n);

    return 0;
}
