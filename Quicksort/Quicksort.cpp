// Quicksort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int arr[20];
int cmp_count = 0;
int mov_count = 0;
int n;


void input() {
    while (true)
    {
        cout << "Masukkan panjang element array : ";              
        cin >> n;

        if (n <= 20)
            break;
        else
            cout << "\nMaksimum panjang array adalah 20" << endl;
    }

    cout << "\n-------------------" << endl;
    cout << "\nEnter Array Element" << endl;
    cout << "\n-------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "<" << (i + 1) << ">";
        cin >> arr[i];
    }
}


void swap(int x, int y)
{
    int temp;

    temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void q_sort(int low, int high)
{
    int pivot, i, j;
    if (low > high)                                         //Langkah Algoritma No. 1
        return;
    pivot = arr[low];                                       //Langkah Algoritma No. 2

    i = low + 1;                                            //Langkah Algoritma No. 3
    j = high;                                               //Langkah Algoritma No. 4

    while (i <= j)                                          //Langkah Algoritma No. 10
    {
        while ((arr[i] <= pivot) && (j <= high))            //Langkah Algoritma No. 5
        {
            i++;                                            //Langkah Algoritma No. 6
            cmp_count++;
        }
        cmp_count++;
        while ((arr[j] > pivot) && (j >= low))              //Langkah Algoritma No. 7
        {
            j--;                                            //Langkah Algoritma No. 8
            cmp_count++;
        }
        cmp_count++;
        //if the greter element is on the left of the element
        if (i < j)                                          //Langkah Algoritma No. 9
        {
            swap(i, j);
            mov_count++;
        }
    }
    if (low < j)
    {
        swap(low, j);
        mov_count++;
    }

    q_sort(low, j - 1);
    q_sort(j + 1, high);

}

void display() {
    cout << "\n----------" << endl;
    cout << "Sorted Array" << endl;
    cout << "------------" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "n\nNumber of comparasions: " << cmp_count << endl;
    cout << "Number of data movements" << mov_count << endl;
}
int main() {
    input();
    q_sort(0, n - 1);
    display();
    system("pause");
    
    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
