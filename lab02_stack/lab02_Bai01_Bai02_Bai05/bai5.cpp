#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;

struct node
{
    int data;
    node *pnext;
};
struct Stack
{
    node *Top;
};

node *createNode(int value)
{
    node *p = new node;
    if (p == NULL)
        return NULL;
    p->data = value;
    p->pnext = NULL;
    return p;
}
void createStack(Stack &s)
{
    s.Top = NULL;
}
void push(Stack &s, node *p)
{
    if (s.Top == NULL)
    {
        s.Top = p;
    }
    else
    {
        p->pnext = s.Top;
        s.Top = p;
    }
}
void printStack(Stack s)
{
    cout << "Stack = < ";
    for (node *i = s.Top; i != NULL; i = i->pnext)
    {
        cout << i->data << "  ";
    }
    cout << ">" << endl;
}

int main()
{
    bool condision = true;
    Stack s;
    createStack(s);
    int value;
    cout << "Nhap gia tri: ";
    cin >> value;
    while (value >= 1)
    {
        if (value == 1)
        {
            push(s, createNode(1));
            break;
        }

        int x = value % 2;
        value = value / 2;
        push(s, createNode(x));
    }
    cout << "--------------" << endl;
    cout << "Ket qua nhi phan: \n";
    printStack(s);
    cout << "--------------" << endl;
    return 0;
}
