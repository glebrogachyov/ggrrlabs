#include <iostream>
#include <vector>

using namespace std;

class stack
{
public:
    bool empty(); // Проверка вектора на пустоту
    void push(int el); // Добавляет элемент в стек
    void pop(); // Удаляет последний элемент из стека
    void display();
private:
    vector<int> stk;
};

int main() {
    stack test;
    test.pop();
    test.push(5);
    test.push(5);
    test.push(5);
    test.push(5);
    test.push(6);
    test.push(34);
    test.push(0);
    test.push(9);
    test.display();
    test.pop();
    test.pop();
    test.pop();
    test.display();
    return 0;
}


bool stack::empty()
{
    return stk.empty();
};
void stack::push(int el)
{
    stk.push_back(el);
};
void stack::pop()
{
    if(!empty())
        stk.pop_back();
    else
        cout << "Stack is empty.\n";
};
void stack::display()
{
    for (int i=0;i<stk.size();i++)
        cout << stk[i]<<" ";
    cout << endl;
};
