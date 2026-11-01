#include <iostream>
#include <vector>
using namespace std;


class Computer
{
    public:
    int mem;
    int num;

    Computer() : mem(0), num(0) {}
};


class manageComp
{
    private:
    int size;
    Computer *arr;
    int count;

    public:
    manageComp(int s) : size(s), count(0)
    {
        arr = new Computer[size];
    }

    void addComputer(int m, int n)
    {
        arr[count].mem = m;
        arr[count].num = n;
        count++;
    }

    void quickSort(int st, int end)
    {
        if(st < end)
        {
            int pivotIndex = partition(st, end);
            
            quickSort(st, pivotIndex - 1);
            quickSort(pivotIndex + 1, end);
        }
    }

    int partition(int st, int end)
    {
        int mid = st + ((end - st)/2);

        Computer t = arr[mid];
        arr[mid] = arr[end];
        arr[end] = t;

        int index = st - 1;
        int pivot = end;

        for(int i = st; i < pivot; i++)
        {
            if(arr[i].mem <= arr[pivot].mem)
            {
                index++;
                Computer temp;

                temp.mem = arr[i].mem;
                temp.num = arr[i].num;
                arr[i].mem = arr[index].mem;
                arr[i].num = arr[index].num;
                arr[index].mem = temp.mem;
                arr[index].num = temp.num;
            }
        }

        index++;
        Computer temp2;
        temp2.mem = arr[index].mem;
        temp2.num = arr[index].num;
        arr[index].mem = arr[pivot].mem;
        arr[index].num = arr[pivot].num;
        arr[pivot].mem = temp2.mem;
        arr[pivot].num = temp2.num;

        return index;
    }

    void display()
    {
        cout << "Sorted: \n" << endl;
        for(int i = 0; i < size; i++)
        {
            cout << arr[i].mem << " - " << arr[i].num << "  -->  ";
        }
    }
};


int main()
{
    manageComp obj(5);
    obj.addComputer(512, 1);
    obj.addComputer(256, 2);
    obj.addComputer(128, 3);
    obj.addComputer(1024, 4);
    obj.addComputer(64, 5);

    obj.quickSort(0, 4);
    obj.display();

    return 0;
}