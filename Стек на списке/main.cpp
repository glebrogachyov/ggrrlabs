#include <iostream>
using namespace std;


struct Node
{
    int x;
    Node *prev;
    Node *next;
};

class DLLStack
{
public:
    DLLStack ();
    ~DLLStack ();
    void push(int el);
    void pop();
    void display();
    int size();
    bool empty();
private:
    Node *Head;
    Node *Tail;
};


int main() {
    DLLStack test;
    test.push(3);
    test.push(4);
    test.push(305);
    test.push(1);
    test.push(0);
    test.push(-34);
    test.push(3747);
    test.push(-212);
    test.push(7);
    test.pop();
    test.pop();
    test.display();
    cout << test.size();
    return 0;
}

DLLStack::DLLStack ()
{
    Head=nullptr;
    Tail=nullptr;
};

DLLStack::~DLLStack ()
{
    while (Head)
    {
        Tail=Head->next;
        delete Head;
        Head=Tail;
    }
};

void DLLStack::push(int el)
{
    Node *temp = new Node;
    temp->next=nullptr;
    temp->x=el;
    if (Head == nullptr)
    {
        temp->prev=nullptr;
        Head=temp;
        Tail=temp;
    } else {
        temp->next=Head;
        Head->prev=temp;
        Head=temp;
    }
};

void DLLStack::pop()
{
    Node *temp=Head;
    Head=temp->next;
    Head->next = temp->next->next;
};

void DLLStack::display()
{
    Node *temp=Head;
    while (temp)
    {
        cout<<temp->x<<" ";
        temp=temp->next;
    }
    cout<<endl;
};
int DLLStack::size()
{
    Node *temp=Head;
    int x=0;
    while (temp)
    {
        x++;
        temp=temp->next;
    }
    return x;
};

bool DLLStack::empty()
{
    if (!Head)
        return true;
    else
        return false;
};
