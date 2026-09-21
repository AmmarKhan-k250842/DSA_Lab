#include <iostream>
#include <string>
using namespace std;


int linearSearch(int Arr[], int n, int find)
{
    for(int i = 0; i < n; i++)
    {
        if(Arr[i] == find)
        {
            return i;
        }
    }

    return -1;
}

int binarySearch(int Arr[], int n, int find)
{
    int high = n - 1;
    int low = 0;

    while(low <= high)
    {
        int mid = low + ((high - low) / 2);
        if(Arr[mid] == find)
        {
            return mid;
        }
        else if(Arr[mid] > find)
        {
            high = mid - 1;
        }
        else if(Arr[mid] < find)
        {
            low = mid + 1;
        }
    }

    return -1;
}

int interpolationSearch(int Arr[], int n, int find)
{
    int low = 0;
    int high = n - 1;

    while(find <= Arr[high] && find >= Arr[low] && low <= high)
    { 
        int pos = low + (((find - Arr[low]) * (high - low)) / (Arr[high] - Arr[low]));

        if(Arr[pos] == find)
        {
            return pos;
        }
        else if(Arr[pos] > find)
        {
            high = pos - 1;
        }
        else
        {
            low = pos + 1;
        }
    }

    return -1;
}

int main() 
{
	int numArr[6] = {1, 3, 5, 7, 9, 11};
    int index, index2;
	
	cout << "Array:  " ;
	for(int i = 0; i < 6; i++)
	{
		cout << numArr[i] << "  ";
	}

    index = linearSearch(numArr, 6, 7);
    cout << "\n\nNumber found with linear search on index: " << index << endl;
	
    index = binarySearch(numArr, 6, 7);
    cout << "Number found with binary search on index: " << index << endl;

    index = interpolationSearch(numArr, 6, 7);
    cout << "Number found with Interpolation search on index: " << index << endl;

    return 0;
}
