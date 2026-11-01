#include <iostream>
#include <vector>
using namespace std;


void merge(vector <int> &arr, int st, int mid, int end) //TIME COMPLEXITY OF MERGE FUNCTION: O(n)
{
    vector <int> temp;
    int i = st;
    int j = mid + 1;

    while(i <= mid && j <= end)
    {
        if(arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for(int index = 0; index < temp.size(); index++)
    {
        arr[st + index] = temp[index];
    }

}

void mergeSort(vector <int> &arr, int st, int end)
{
    if(st < end)
    {
        int mid = st + ((end - st) / 2);

        mergeSort(arr, st, mid);        // LEFT
        mergeSort(arr, mid + 1, end);   // RIGHT

        merge(arr, st, mid, end);
    }
}


int main()
{
    vector <int> arr = {12, 31, 35, 8, 32, 17};

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array: \n" << endl;
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "  ";
    }

    return 0;
}