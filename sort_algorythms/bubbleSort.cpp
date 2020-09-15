// C++ program for implementation of Bubble sort
#include <iostream>
using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void bubbleSortDesc(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] < arr[j + 1]) //Change it to desc, only here, so easy!!!!
                swap(&arr[j], &arr[j + 1]);
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver code
int main()
{
    int a;
    cout<<"BUBBLE SORT\n";
    cout<<"Ingrese cantidad de numeros a ingresar: ";
    cin>>a;
    int arr[a];
    for (int i = 0; i < a; i++)
    {
        int b;
        cout<<"Ingrese numero: ";
        cin>>b;
        arr[i] = b;
    }

    cout<<"Entered matrix: ";
    for (int i = 0; i<a; i++)
    {
        cout<<arr[i]<<" ";
    }
    

    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    cout << "\nSorted array asc: \n";
    printArray(arr, n);
    cout <<"\nSorted array desc: \n";
    bubbleSortDesc(arr, n);
    printArray(arr, n);
    return 0;
}

