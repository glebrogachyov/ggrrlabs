#include <iostream>
using namespace std;

struct Node
{
    int x;
    Node *prev;
    Node *next;
};

class DLLQueue
{
public:
    DLLQueue ();
    ~DLLQueue ();
    void enqueue(int el);
    void dequeue();
    void display();
    int size();
    bool empty();
private:
    Node *Head;
    Node *Tail;
};

int main() {
    DLLQueue test;
    test.enqueue(7);
    test.enqueue(8);
    test.enqueue(235);
    test.enqueue(1);
    test.enqueue(0);
    test.enqueue(-234);
    test.enqueue(4574);
    test.enqueue(7);
    test.enqueue(7);
    test.dequeue();
    test.dequeue();
    test.dequeue();
    test.display();
    cout << test.size();
    return 0;
}

DLLQueue::DLLQueue ()
{
    Head=nullptr;
    Tail=nullptr;
};

DLLQueue::~DLLQueue ()
{
    while (Head)
    {
        Tail=Head->next;
        delete Head;
        Head=Tail;
    }
};

void DLLQueue::enqueue(int el)
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

void DLLQueue::dequeue()
{
    Node *temp=Tail;
    Tail=temp->prev;
    Tail->next= nullptr;
};

void DLLQueue::display()
{
    Node *temp=Head;
    while (temp) //temp!=nullptr
    {
        cout<<temp->x<<" ";
        temp=temp->next;
    }
    cout<<endl;
};
int DLLQueue::size()
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

bool DLLQueue::empty()
{
    if (!Head)
        return true;
    else
        return false;
};
