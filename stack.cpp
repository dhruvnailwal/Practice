#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node *prev;
    Node *next;
    int data;

    Node(int d)
    {
        prev = NULL;
        next = NULL;
        data = d;
    }
};

class Stack
{
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    void push(int val)
    {
        Node *newe = new Node(val);
        if (top == NULL)
        {
            top = newe;
        }
        else
        {
            top->next = newe;
            newe->prev = top;
            top = top->next;
        }
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "The stack is Empty\n";
            return;
        }
        else if (top->prev == NULL && top->next == NULL)
        {
            top = NULL;
            return;
        }

        Node *temp = top;
        top = top->prev;
        top->next = NULL;
        delete (temp);
    }

    void display()
    {
        if (top == NULL)
        {
            cout << "The stack is empty nothing to see \n";
            return;
        }

        Node *temp = top;

        cout << "Content of the Stack\n";

        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }

        cout << endl;
        return;
    }

    void peek()
    {
        if (top == NULL)
            return;

        cout << "The top element of the stack is :- " << top->data << endl;
    }
};

int main()
{
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    s.display();
    s.pop();
    s.peek();
    s.display();
    s.pop();
    s.peek();
    s.display();
    s.pop();
    s.peek();
    s.display();
    s.pop();
    s.peek();
    s.display();
    s.pop();
    s.peek();
    s.display();

    return 0;
}