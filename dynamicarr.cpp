#include <bits/stdc++.h>

using namespace std;

class Dynamic_array
{

    int *data;
    int size;
    int capacity;

    public:

    Dynamic_array(int c = 2)
    {
        capacity = c;
        data = new int[capacity];
        size = 0;
    }

    void append(int value)
    {
        if (size == capacity)
        {
            resize(2 * capacity);
        }

        data[size] = value;
        size++;
    }

    void resize(int c)
    {
        int *newe = new int[c];

        for (int i = 0; i < size; i++)
        {
            newe[i] = data[i];
        }

        delete[] data;

        data = newe;
        capacity = c;
    }

    void display()
    {

        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Dynamic_array d1;

    d1.append(1);
    d1.append(2);
    d1.append(3);
    d1.append(4);
    d1.append(5);

    d1.display();

    return 0;
}