#include <iostream>
#include <stack>
using namespace std;

class NStack
{
    int *a, *top, *next;
    int n; //No. of stacks
    int size; //Size fo main array
    int freeSpot; //Tells free space in main array

    public:
        NStack(int _n, int _s) : n(_n), size(_s)
        {
            freeSpot = 0;
            a = new int[size];
            top = new int[n];
            next = new int[size];

            for(int i = 0; i < n; i++)
            {
                top[i] = -1;
            }

            for(int i = 0; i < size; i++)
            {
                next[i] = i + 1;
            }
            next[size - 1] = -1;
        }

        //Push X into mth stack
        bool push(int X, int m)
        {
            if(freeSpot == -1) 
            {
                return false;
                // Stack overflow
            }

            // 1. Find index
            int index = freeSpot;

            // 2. Update freespot
            freeSpot = next[index];

            // 3. Insert
            a[index] = X;

            // 4. Update next
            next[index] = top[m - 1];

            // 5. Update top
            top[m - 1] = index;

            return true; // Push success
        }

        //Pop from mth stack
        int pop(int m)
        {
            if(top[m - 1] == -1)
            {
                return -1; //Stack underflow
            }

            int index = top[m - 1];
            top[m - 1] = next[index];
            int poppedElement = a[index];
            next[index] = freeSpot;
            freeSpot = index;
            return poppedElement;
        }

        ~NStack() 
        {
            delete[] a;
            delete[] top;
            delete[] next;
        }
};

int main() {

    NStack s(3, 6);
    cout << s.push(10, 1) << endl;
    cout << s.push(12, 1) << endl;
    cout << s.push(13, 1) << endl;
    cout << s.push(14, 2) << endl;
    cout << s.push(15, 3) << endl;
    cout << s.pop(1) << endl;
    cout << s.pop(2) << endl;
    return 0;
}

