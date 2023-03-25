#include <iostream>
#include <time.h>
using namespace std;

struct node
{
    int data;
    node *pnext;
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
struct Queue
{
    node *Front;
    node *Rear;
};
void createQueue(Queue &q)
{
    q.Front = q.Rear = NULL;
}
void enQueue(Queue &q, node *p)
{
    if (q.Front == NULL)
    {
        q.Front = q.Rear = p;
    }
    else
    {

        q.Rear->pnext = p;
        q.Rear = p;
    }
}
void deQueue(Queue &s, node *p)
{
    if (s.Front == NULL)
    {
        s.Front = p;
    }
    else
    {
        p->pnext = s.Front;
        s.Front = p;
    }
}
void printQueue(Queue s)
{
    cout << "Queue  =  < ";
    for (node *i = s.Front; i != NULL; i = i->pnext)
    {
        cout << i->data << "  ";
    }
    cout << ">" << endl;
}
int pop(Queue &s, int &value)
{
    if (s.Front == NULL)
        return 0;
    node *p = s.Front;        // 1
    s.Front = s.Front->pnext; // move
    value = p->data;
    delete p; // thu hoi
    return 1;
}
int main()
{
    Queue s;
    createQueue(s);
    // while (true)
    // {
    //     int value;
    //     int chon;
    //     cout << "-------- Queue --------" << endl;
    //     cout << "\t1.Push in Queue" << endl;
    //     cout << "\t2.Pop from Queue" << endl;
    //     cout << "\t3.Top" << endl;
    //     cout << "\t4.Empty" << endl;
    //     cout << "\t5. (No) Full" << endl;
    //     cout << "\t6. Exit" << endl;
    //     cout << "Nhap lua chon: ";
    //     cin >> chon;
    //     switch (chon)
    //     {
    //     case 1:
    //     {
    //         cout << "Nhap gia tri: ";
    //         cin >> value;
    //         deQueue(s, createNode(value));
    //         cout << "--------------" << endl;
    //         cout << "Ket qua: \n";
    //         printQueue(s);
    //         cout << "--------------" << endl;
    //     }
    //     break;
    //     case 2:
    //     {
    //         int x = 0;
    //         pop(s, x);
    //         cout << "Ket qua: ";
    //         printQueue(s);
    //         cout << "--------------" << endl;
    //     }
    //     break;
    //     default:
    //         break;
    //     }
    // }
    return 0;
}
