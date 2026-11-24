#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node *next;
    int data;

    Node(int val)
    {
        next = NULL;
        data = val;
    }
};

class LinkedList
{

    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    Node *gethead()
    {
        return head;
    }

    void insert_at_head(int num)
    {
        Node *newe = new Node(num);

        if (head == NULL)
        {
            head = newe;
            return;
        }

        newe->next = head;
        head = newe;
        return;
    }

    void insert_at_k(int num, int k)
    { // after kth position

        Node *newe = new Node(num);

        if (head == NULL)
        {
            insert_at_head(num);
            return;
        }

        int count = 0;
        Node *temp = head;

        while (temp && count < k)

        {
            count++;
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "There are less than K element in the Linked List unable to add" << endl;
            return;
        }

        Node *nextt = temp->next;
        temp->next = newe;
        newe->next = nextt;

        return;
    }

    void delete_at_head()
    {

        if (head == NULL)
        {
            return;
        }

        if (head->next == NULL)
        {
            delete (head);
            return;
        }

        Node *temp = head;
        head = head->next;
        delete (temp);

        return;
    }

    void delete_at_k(int k)
    {
        if (head == NULL)
        {
            return;
        }

        if (k == 0)
        {
            delete_at_head();
        }

        int count = 0;
        Node *temp = head;

        while (temp)
        {
            if (count == k - 1)
            {
                break;
            }
            count++;
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Element is less than k can not delete" << endl;
            return;
        }

        Node *nextt = temp->next;
        temp->next = nextt->next;

        delete (nextt);

        return;
    }

    void display()
    {
        Node *temp = head;

        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;

        return;
    }

    void reverse()
    {
        if (head == NULL)
            return;

        Node *temp = head;
        Node *nextt = NULL;
        Node *prev = NULL;

        while (temp)
        {
            nextt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextt;
        }

        head = prev;

        return;
    }

    int get_mid()
    {

        if (head == NULL)
            return -1;

        Node *slow = head;
        Node *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow->data;
    }
};

int main()
{

    LinkedList l1;

    l1.insert_at_head(9);
    l1.insert_at_head(7);
    l1.insert_at_head(5);
    l1.insert_at_head(3);
    l1.insert_at_head(1);

    cout << "Linked List 1 :- ";
    l1.display();

    // cout << "Reversed Linked List \n";
    // l1.reverse();
    // l1.display();

    // cout << "The middle Value of the linked list is :- " << l1.get_mid() << endl;

    LinkedList l2;
    l2.insert_at_head(12);
    l2.insert_at_head(11);
    l2.insert_at_head(10);
    l2.insert_at_head(8);
    l2.insert_at_head(6);
    l2.insert_at_head(4);
    l2.insert_at_head(2);

    cout << "Linked List 2 :- ";
    l2.display();

    Node *temp1 = l1.gethead();
    Node *temp2 = l2.gethead();

    Node *dummy = new Node(-1);
    Node *head = dummy;

    while (temp1 && temp2)
    {
        if (temp1->data < temp2->data)
        {
            dummy->next = new Node(temp1->data);
            temp1 = temp1->next;
        }
        else
        {
            dummy->next = new Node(temp2->data);
            temp2 = temp2->next;
        }

        dummy = dummy->next;
    }
    
    while (temp1)
    {
        dummy->next = new Node(temp1->data);
        temp1 = temp1->next;
        dummy = dummy->next;
    }
    while (temp2)
    {
        dummy->next = new Node(temp2->data);
        temp2 = temp2->next;
        dummy = dummy->next;
    }


    
    Node *temp = head->next;

    cout<<"The merged List :- ";

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
    return 0;
}