#include <iostream>
#include <string>
using namespace std;


# define MAX 10

class student
{
    public:
    int studentID;
    string name;
    string department;
    double cgpa;

    student(int id, string n, string d, double c)
    {
        studentID = id;
        name = n;
        department = d;
        cgpa = c;
    }

    student()
    {
        studentID = 0;
        name = "";
        department = "";
        cgpa = 0.0;
    }
};


class studentManagement
{
    private:
    student sArray[MAX];
    int count;

    public:
    studentManagement()
    {
        count = 0;
    }

    void insert(int id, string n, string d, double c)
    {
        sArray[count].studentID = id;
        sArray[count].name = n;
        sArray[count].department = d;
        sArray[count].cgpa = c;
        count++;
    }

    void mergeSort(int st, int end)
    {
        if(st < end)
        {
            int mid = st + ((end - st) / 2);

            mergeSort(st, mid);
            mergeSort(mid + 1, end);

            merge(st, mid, end);
        }
    }

    void merge(int st, int mid, int end)
    {
        int i = st;
        int j = mid + 1;
        student temp[MAX];
        int ind = 0;

        while(i <= mid && j <= end)
        {
            if(sArray[i].cgpa >= sArray[j].cgpa)
            {
                temp[ind] = sArray[i];
                i++;
                ind++;
            }
            else if(sArray[j].cgpa >= sArray[i].cgpa)
            {
                temp[ind] = sArray[j];
                j++;
                ind++;
            }
        }

        while(i <= mid)
        {
            temp[ind] = sArray[i];
            ind++;
            i++;
        }
        while(j <= end)
        {
            temp[ind] = sArray[j];
            ind++;
            j++;
        }

        for(int index = 0; index < ind; index++)
        {
            sArray[st + index] = temp[index];
        }
    }

    void display()
    {
        for(int k = 0; k < count; k++)
        {
            cout << sArray[k].cgpa << "  ";
        }
    }
};


int main()
{
    studentManagement s1;

    s1.insert(001, "Ammar", "CS", 3.2);
    s1.insert(002, "Khizer", "CS", 3.4);
    s1.insert(003, "Askari", "CS", 3.7);
    s1.insert(004, "Mateen", "CS", 3.9);
    s1.insert(005, "Qusai", "CS", 3.2);
    s1.insert(006, "Ebaad", "CS", 3.1);
    s1.insert(007, "Sunil", "CS", 2.2);
    s1.insert(230, "Hasan", "CS", 2.8);
    s1.insert(012, "Omar", "CS", 2.5);
    s1.insert(010, "Haseeb", "CS", 2.1);

    cout << "Before Sort: " << endl;
    s1.display();

    s1.mergeSort(0, MAX - 1);
    cout << "\n\nAfter Sort: " << endl;
    s1.display();

    return 0;
}