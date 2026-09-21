#include <iostream>
#include <string>
using namespace std;


void bubbleSort(int Arr[])
{
	int temp = 0;
	int swapCount = 0;
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			if(Arr[j] >  Arr[j + 1])
			{
				temp = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = temp;
				swapCount++;
			}
		} 	
	} 
	
	cout << "\nBubble Sorted Array:  ";
	for(int x = 0; x < 6; x++)
	{
		cout << Arr[x] << "  ";
	}
	cout << "\nSwap Count: " << swapCount << endl;
}


void insertionSort(int Arr[])
{
	for(int i = 1; i < 6; i++)
	{
		int key = Arr[i];
		int j = i - 1;
		
		while(j >= 0 && key > Arr[j + 1])
		{
			Arr[j + 1] = Arr[j];
			j--;
		}
		
		Arr[j + 1] = key;
	}
	
	cout << "\nInsertion Sorted Array:  ";
	for(int i = 0; i < 6; i++)
	{
		cout << Arr[i] << "  ";
	}
}


void selectionSort(int Arr[])
{	
	for(int i = 0; i < 6; i++)
	{
		int min = i;
		
		for(int j = i + 1; j < 6; j++)
		{
			if(Arr[j] < Arr[min])
			{
				min = j;
			}
		}
		
		int temp = Arr[i];
		Arr[i] = Arr[min];
		Arr[min] = temp;
	}
	
	cout << "\n\nSelection Sorted Array:  ";
	for(int x = 0; x < 6; x++)
	{
		cout << Arr[x] << "  ";
	}
}	

void shellSort(int myArr[], int n)
{
    for(int gap = n / 2; gap > 0; gap /= 2)
    {
        for(int j = gap; j < n; j++)
        {
            int temp = myArr[j];
            int res = j;

            while((res >= j) && (myArr[res - j] > temp))
            {
                myArr[res] = myArr[res - j];
                res -= j;
            }
            myArr[res] = temp;
        }
    }

    cout << "\n\nShell Sorted Array:  ";
	for(int x = 0; x < 6; x++)
	{
		cout << myArr[x] << "  ";
	}
}

void combSort(int Arr[], int n)
{
    int gap = n;
    bool swapped = true;
    int temp;

    while(gap != 1 || swapped == true)
    {
        gap = (gap * 10) / 13;
        if(gap < 1)
        {
            gap = 1;
        }
        swapped = false;

        for(int i = 0; i < n - gap; i++)
        {
            if(Arr[i] > Arr[i + gap])
            {
                temp = Arr[i];
                Arr[i] = Arr[i + gap];
                Arr[i + gap] = temp;
                swapped = true;
            }
        }
    }

    cout << "\n\nComb Sorted Array:  ";
	for(int x = 0; x < 6; x++)
	{
		cout << Arr[x] << "  ";
	}
}


int main() 
{
	int numArr[6] = {5, 2, 9, 1, 10, 3};
	
	cout << "Unsorted Array:  " ;
	for(int i = 0; i < 6; i++)
	{
		cout << numArr[i] << "  ";
	}

	cout << "\n";
	bubbleSort(numArr);
	insertionSort(numArr);
	selectionSort(numArr);
    shellSort(numArr, 6);
    combSort(numArr, 6);

    return 0;
}













