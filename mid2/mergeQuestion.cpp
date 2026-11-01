#include <iostream>
#include <vector>
using namespace std;


class Guest
{
    public:
    string name;
    int regID;
    int pScore;
    int seat;

    Guest() : name(""), regID(0), pScore(0), seat(0) {}  

    Guest(string na, int r, int p) : name(na), regID(r), pScore(p), seat(0) { }
};


class guestManager
{
    private:
    int size;
    Guest *arr;
    int curr;

    public:
    guestManager(int n) : size(n), curr(0)
    {
        arr = new Guest[size];
    }

    void enterGuest(string n, int r, int p)
    {
        arr[curr].name = n;
        arr[curr].pScore = p;
        arr[curr].regID = r;
        arr[curr].seat = curr;

        curr++;
    }

    void mergeSort(int st, int end)
    {
        if(st < end)
        {
            int mid = st + ((end - st)/2);

            mergeSort(st, mid);
            mergeSort(mid + 1, end);

            merge(st, mid, end);
        }
    }

    void merge(int st, int mid, int end)
    {
        int i = st;
        int j = mid + 1;
        Guest *temp = new Guest[size];
        int count = 0;

        while(i <= mid && j <= end)
        {
            if(arr[i].pScore >= arr[j].pScore)
            {
                temp[count] = arr[i];
                i++;
                count++;
            }
            else
            {
                temp[count] = arr[j];
                j++;
                count++;
            }
        }

        while(i <= mid)
        {
            temp[count] = arr[i];
            i++;
            count++;
        }
        while(j <= end)
        {
            temp[count] = arr[j];
            j++;
            count++;
        }

        for(int index = 0; index < count; index++)
        {
            arr[index + st] = temp[index];
        }
    }

    void display()
    {
        cout << "Sorted List: \n" << endl;
        for(int k = 0; k < size; k++)
        {
            cout << arr[k].pScore << " | " << arr[k].regID << " ---> ";
        }
    }

};



int main()
{
    guestManager obj(5);
    obj.enterGuest("Ammar", 101, 10);
    obj.enterGuest("Mateen", 102, 69);
    obj.enterGuest("Maniha", 103, 17);
    obj.enterGuest("Omar", 104, 11);
    obj.enterGuest("Khizer", 105, 56);

    obj.mergeSort(0, 4);
    obj.display();

    return 0;
}

