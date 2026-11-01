#include <iostream>
#include <vector>
using namespace std;


int partition(vector <int> &arr, int st, int end)
{
    int index = st - 1;
    int pivot = arr[end];

    for(int i = st; i < end; i++)
    {
        if(arr[i] <= pivot)
        {
            index++;
            swap(arr[i], arr[index]);
        }
    }

    index++;
    swap(arr[index], arr[end]);

    return index;
}


void quickSort(vector <int> &arr, int st, int end)
{
    if(st < end)
    {
        int pivotIndex = partition(arr, st, end);

        quickSort(arr, st, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
    }
}


int main()
{
    vector <int> arr = {12, 31, 35, 8, 32, 17};

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array: \n" << endl;
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "  ";
    }

    return 0;
}