#include <iostream>
#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

class PriorityQueue
{
public:
    void heapify(int i);
    void push(int el); // Добавляет элемент в очередь
    void pop();        // Удаляет верхний элемент из очереди
    int top();         // Возвращает верхний элемент очереди, не удаляя его
private:
    vector<int> queue;
};

void heapsort(vector<int> &vec);


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    PriorityQueue a; // создается очередь из элементов <5,12,7,7,3>
    a.push(6);
    a.push(3);
    a.push(19);
    a.push(1);
    a.push(12);
    cout << "Вершина после добавления 5:" << a.top() << endl;
    a.pop();
    cout << "Вершина после удаления 1:" << a.top() << endl;
    a.push(13);
    a.push(10);
    cout << "Вершинапосле добавления 2:" << a.top() << endl;
    a.pop();
    a.pop();
    a.pop();
    cout << "Вершина послед удаления 3:" << a.top() << endl;

    vector <int> vec; // создаётся вектор <5,4,6,3,2,8,2,29>
    vec.push_back(5);
    vec.push_back(4);
    vec.push_back(6);
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(8);
    vec.push_back(2);
    vec.push_back(29);

    for (int i = 0; i < vec.size(); i++)
        cout << vec [i]<< " ";
    cout << endl;

    heapsort(vec); //сортировка вектора кучей

    for (int i = 0; i < vec.size(); i++)
        cout << vec [i]<< " ";

    return 0;
}

void heapsort(vector<int> &vec) {
    PriorityQueue tmp;
    for (int i = 0; i < vec.size(); i++)
        tmp.push(vec[i]);

    for (int i = vec.size() - 1; i >= 0; i--)
    {
        vec[i] = tmp.top();
        tmp.pop();
        tmp.heapify(0);
    };
}





void PriorityQueue::heapify(int i)
{
    int leftChild;
    int rightChild;
    int largestChild;

    for ( ; ; )
    {
        leftChild = 2 * i + 1;
        rightChild = 2 * i + 2;
        largestChild = i;

        if (leftChild < queue.size() && queue[leftChild] > queue[largestChild])
        {
            largestChild = leftChild;
        }

        if (rightChild < queue.size() && queue[rightChild] > queue[largestChild])
        {
            largestChild = rightChild;
        }

        if (largestChild == i)
        {
            break;
        }

        int temp = queue[i];
        queue[i] = queue[largestChild];
        queue[largestChild] = temp;
        i = largestChild;
    }
}

void PriorityQueue::push(int el)  // Добавляет элемент в очередь
{
    queue.push_back(el);
    int i = queue.size()-1;
    int parent = (i - 1) / 2;

    while (i > 0 && queue[parent] < queue[i])
    {
        int temp = queue[i];
        queue[i] = queue[parent];
        queue[parent] = temp;

        i = parent;
        parent = (i - 1) / 2;
    }
}

void PriorityQueue::pop()  // Удаляет верхний элемент из очереди
{
    if (queue.empty())
        cerr << "Queue is empty.";
    queue[0] = queue[queue.size()-1];
    queue.pop_back();
    heapify (0);
}

int PriorityQueue::top()  //Возвращает верхний элемент очереди, не удаляя его
{
    if (queue.empty())
        cerr << "Queue is empty.";
    return queue.front();
}
