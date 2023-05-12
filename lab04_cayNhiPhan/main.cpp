
#include <iostream>
#include <cmath>
#include <time.h>
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
            else if (p->data == i->data)
            {
                cout << "Gia tri da ton tai" << endl;
                return;
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
void nRl(Node *p)
{
    if (p != NULL)
    {
        cout << p->data << "\t";
        nRl(p->right);
        nRl(p->left);
    }
}
void lRn(Node *p)
{
    if (p != NULL)
    {
        lRn(p->left);
        cout << p->data << "\t";
        lRn(p->right);
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
void countSma(Node *p, int &count, int &n)
{
    if (p != NULL)
    {
        if (p->data < n)
            count++;
        countSma(p->left, count, n);
        countSma(p->right, count, n);
    }
}
int total(Node *p, int &sum)
{
    if (p != NULL)
    {
        sum = sum + p->data;
        total(p->left, sum);
        total(p->right, sum);
    }
    return sum;
}
int totalEven(Node *p, int &sum)
{
    if (p != NULL)
    {
        if (p->data % 2 == 0)
        {
            sum = sum + p->data;
        }

        totalEven(p->left, sum);
        totalEven(p->right, sum);
    }
    return sum;
}
int totalOdd(Node *p, int &sum)
{
    if (p != NULL)
    {
        if (p->data % 2 != 0)
        {
            sum = sum + p->data;
        }

        totalOdd(p->left, sum);
        totalOdd(p->right, sum);
    }
    return sum;
}
void inputManual(Tree &t)
{
    bool stopProgram = false;
    while (!stopProgram)
    {
        int input;
        cout << "Nhap so n (hoac 999 de thoat) = ";
        cin >> input;
        if (input == 999)
        {
            stopProgram = true;
        }
        else
        {
            addNode(t, createNode(input));
        }
    }
}
void randomValue(Tree &t)
{
    srand(time(NULL));
    int n = 10 + rand() % 11;
    for (int i = 0; i < n; i++)
    {
        int x = -385 + rand() % 1787;
        addNode(t, createNode(x));
    }
}
void findNode(Tree &t)
{
    int node;
    cout << "Nhap gia tri tim kiem: " << endl;
    cin >> node;
    if (search(t, node))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
}
void removeNode(Tree &t, int node)
{
    Node *i = t.root;
    while (i != NULL)
    {
        if (i->data == node)
        {
            if (i->left == NULL && i->right == NULL)
            {
                t.root = NULL;
            }
            else if (i->left == NULL)
            {
                Node *p = i->right;
                delete (i);
                i = p;
            }
            else if (i->right == NULL)
            {
                Node *p = i->left;
                delete (i);
                i = p;
            }
            else
            {
                Node *p = i->right;
                Node *q = i->left;
                Node *r = i->right;
                delete (i);
                i = p;
                i = q;
                i = r;
            }
        }
    }
}
void maxMin(Node *p, int &min, int &max)
{
    if (p != NULL)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        if (p->data < min)
        {
            min = p->data;
        }

        maxMin(p->left, min, max);
        maxMin(p->right, min, max);
    }
}
int main()
{
    Tree t;
    createTree(t);
    int max;
    int min;
    int count = 0;
    int n = 0;
    int sum = 0;
    int sumOdd = 0;
    int sumEven = 0;
    int choose;
    bool isExit = false;
    while (isExit == false)
    {
        cout << "Xin hay chon menu \n 3.Nhap du lieu tu ban phim \n 4.Ham tao cay tu dong doan[-358,1358] ,so luong tao [10,20] \n 5.Duyet cay theo NLR,LNR,LRN \n 6.Tim kiem gia tri X \n 9.Dem toan bo \n 10.Dem so not la cua cay \n 12.Dem so not nho hon gia tri X \n 17.Tinh tong cac not \n 18.Tinh tong cac not chan \n 19.Tinh tong cac not le \n 20.So sanh tong cac nut chan va tong nut le \n 21.Tinh max va min"
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
        case 4:
            randomValue(t);
            cout << "-----------Ket Qua-----------" << endl;
            printTree(t.root);
            cout << endl;
            break;
        case 5:
            cout << "-----------Left Node Right-----------" << endl;
            printTree(t.root);
            cout << endl;
            cout << "-----------Node Right Left-----------" << endl;
            nRl(t.root);
            cout << endl;
            cout << "-----------Left Right Node ------------" << endl;
            lRn(t.root);
            cout << endl;
            break;
        case 6:
            cout << "-----------Ket Qua-----------" << endl;
            findNode(t);
            cout << "--------------------------------" << endl;
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
            break;
        case 12:
            count = 0;
            cout << "Nhap so X = ";
            cin >> n;
            countSma(t.root, count, n);
            cout << "-----------Ket Qua-----------" << endl;
            cout << count << endl;
            cout << "--------------------------------" << endl;
            break;
        case 17:
            sum = 0;
            cout << "-----------Ket Qua-----------" << endl;
            cout << total(t.root, sum) << endl;
            cout << "--------------------------------" << endl;
            break;
        case 18:
            sum = 0;
            cout << "-----------Ket Qua-----------" << endl;
            cout << totalEven(t.root, sum) << endl;
            cout << "--------------------------------" << endl;
            break;
        case 19:
            sum = 0;
            cout << "-----------Ket Qua-----------" << endl;
            cout << totalOdd(t.root, sumOdd) << endl;
            cout << "--------------------------------" << endl;
            break;
        case 20:
            cout << "-----------Ket Qua-----------" << endl;
            sumEven = 0;
            sumOdd = 0;
            totalEven(t.root, sumEven);
            totalOdd(t.root, sumOdd);
            if (sumEven > sumOdd)
            {
                cout << sumEven << " > " << sumOdd << endl;
                cout << "tong nut chan lon hon tong nut le" << endl;
            }
            else if (sumEven < sumOdd)
            {
                cout << sumEven << " < " << sumOdd << endl;
                cout << "tong nut chan nho hon tong nut le" << endl;
            }
            else
            {
                cout << sumEven << "=" << sumOdd << endl;
                cout << "tong nut chan nut le bang nhau" << endl;
            }

            cout << "--------------------------------" << endl;
            break;
        case 21:
            max = t.root->data;
            min = t.root->data;
            maxMin(t.root, min, max);
            cout << "-----------Ket Qua-----------" << endl;
            cout << "Min = " << min << endl;
            cout << "Max = " << max << endl;
            cout << "--------------------------------" << endl;
            break;
        default:
            isExit = true;
            break;
        }
    }
    return 0;
}