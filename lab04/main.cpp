
#include <iostream>
#include <cmath>
using namespace std;
// tao cau truc node
struct Node
{
    int data;
    Node *left;
    Node *right;
};
// tao cau truc cay
struct Tree
{
    Node *root;
};
// khoi tao node.value-->node*
Node *createNode(int value)
{
    Node *p = new Node;
    p->data = value;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void createTree(Tree &t)
{
    t.root = NULL;
}
void addNode(Tree &t, Node *p)
{
    if (t.root == NULL)
    {
        t.root = p;
    }
    else
    // di tim node*position thi hop
    {
        Node *i = t.root;
        Node *position;
        bool datatype = true;
        while (i != NULL)
        {
            position = i;
            if (p->data < i->data)
            {
                i = i->left;
            }
            else if (p->data > i->data)
            {
                i = i->right;
            }
        }
        // gan dia chi
        if (p->data < position->data)
        {
            position->left = p;
        }
        else if (p->data > position->data)
        {
            position->right = p;
        }
    }
}
void printTree(Node *p)
{
    if (p != NULL)
    {
        printTree(p->left);
        cout << p->data << "\t";
        printTree(p->right);
    }
}
bool search(Tree t, int x)
{
    Node *i = t.root;
    while (i != NULL)
    {
        if (x == i->data)
        {
            return true;
        }
        if (x < i->data)
        {
            i = i->left;
        }
        else if (x > i->data)
        {
            i = i->right;
        }
    }
}
void counter(Node *p, int &count)
{
    if (p != NULL)
    {
        count++;
        counter(p->left, count);
        counter(p->right, count);
    }
}
void counterNull(Node *p, int &count)
{
    if (p != NULL)
    {
        if (p->left == NULL && p->right == NULL)
            count++;
        counter(p->left, count);
        counter(p->right, count);
    }
}
void total(Node *p, int &sum)
{
    if (p != NULL)
    {
        sum = sum + p->data;
        total(p->left, sum);
        total(p->right, sum);
    }
}
void inputManual(Tree &t)
{
    bool stopProgram = false;
    while (!stopProgram)
    {
        int input;
        cout << "Nhap n hoac (-1 de thoat) = ";
        cin >> input;
        if (input > 0)
        {
            addNode(t, createNode(input));
        }
        else if (input == -1)
        {
            stopProgram = true;
        }
    }
}
int main()
{
    Tree t;
    createTree(t);
    int n = 0;
    int sum = 0;
    int choose;
    bool isExit = false;
    while (isExit == false)
    {
        cout << "Xin hay chon menu \n 3.Nhap du lieu tu ban phim \n 9.Dem toan bo \n 10.Dem so not la cua cay"
             << endl;
        cout << "Chon = ";
        cin >> choose;
        switch (choose)
        {
        case 3:
            inputManual(t);
            cout << "-----------Ket Qua-----------" << endl;
            printTree(t.root);
            cout << endl;
            break;
        case 9:
            counter(t.root, n);
            cout << "-----------Ket Qua-----------" << endl;
            cout << n << endl;
            cout << "--------------------------------" << endl;
            break;
        case 10:
            counterNull(t.root, n);
            cout << "-----------Ket Qua-----------" << endl;
            cout << n << endl;
            cout << "--------------------------------" << endl;
        default:
            isExit = true;
            break;
        }
    }
    return 0;
}