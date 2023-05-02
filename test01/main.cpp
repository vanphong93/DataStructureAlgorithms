
/*
Ho va ten Ho Van Phong
Mssv 22210069

*/
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

                return;
            }
        }
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
/*Câu 2.Viết hàm tạo cây tự động trong khoảng [512,723], số lượng [50,60];
Input:
    +Tree &t
Output
    +Tree& t=>&
*/
void randomValue(Tree &t)
{
    srand(time(NULL));
    int n = 50 + rand() % 11;
    for (int i = 0; i < n; i++)
    {
        int x = 512 + rand() % 212;
        addNode(t, createNode(x));
    }
}
/*Câu 3.Viết hàm tạo cây tự đông từ n phần tử
Input:
    +Tree &t
    +int arr[]
    +int n
Output
    +Tree &t=>&

*/
void copyArr(Tree &t, int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        addNode(t, createNode(arr[i]));
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
/*Câu 4.Viết hàm duyệt cây NLR, LRN, LNR
Input:
    +Node *p
Output
    +p
    +p->left
    +p->right

*/
void NLR(Node *p)
{
    if (p != NULL)
    {
        NLR(p->right);
        NLR(p->left);
        cout << p->data << " Node: " << p << " Left: " << p->left << " Right: " << p->right << "\n";
    }
}
void LRN(Node *p)
{
    if (p != NULL)
    {
        LRN(p->left);
        LRN(p->right);
        cout << p->data << " Left: " << p->left << " Right: " << p->right << " Node: " << p << "\n";
    }
}
void LNR(Node *p)
{
    if (p != NULL)
    {
        LNR(p->left);
        LNR(p->right);
        cout << p->data << " Left: " << p->left << " Node: " << p << " Right: " << p->right << "\n";
    }
}
/*Câu 5.Viết hàm tim kiem gia tri X
Input:
    +Tree &t
    +int x
Output
    +Node *p
    +Null

*/
Node *search(Tree t, int x)
{
    Node *i = t.root;
    while (i != NULL)
    {
        if (x == i->data)
        {
            return i;
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
    return NULL;
}
/*Câu 6.Viết hàm đếm toàn bộ Node
Input:
    +Node *p (root)
    +int &count
Output
    +count

*/
void counter(Node *p, int &count)
{
    if (p != NULL)
    {
        count++;
        counter(p->left, count);
        counter(p->right, count);
    }
}

/*Câu 7.In ra cac node nhanh con lai
Input:
    +int inputValue
    +Tree s
    +search function
    +LNR function
Output
    +search ->NUll ->Khong ton tai value
    +search -> node*p->LNR->Xuat gia tri
*/
/*Câu 8.Viết hàm đếm node lớn hơn X và nhỏ hơn Y;
Input:
    +Node *p
    +int &x
    +int &y
    +int &count
Output
    +count
*/
void counterCompare(Node *p, int &x, int &y, int &count)
{
    if (p != NULL)
    {
        if (p->data < y && p->data > x)
        {
            count++;
        }

        counterCompare(p->left, x, y, count);
        counterCompare(p->right, x, y, count);
    }
}
/*Câu 9.Viết hàm đếm chẵn lẻ và so sanh
Input:
    +Node *p
    +int &even
    +int $odd
Output
    +even>odd return -1
    +even=odd return 0
    +even>odd return -1
*/
int counterOddEven(Node *p, int &even, int &odd)
{
    if (p != NULL)
    {
        if (p->data % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
        counterOddEven(p->left, even, odd);
        counterOddEven(p->right, even, odd);
    }
    if (even > odd)
    {
        return -1;
    }
    else if (even == odd)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    Tree t, s;
    createTree(t);
    createTree(s);
    cout << "Cau 2. Tao cay tu dong [512,723], so luong [50,60]" << endl;
    randomValue(t);
    printTree(t.root);
    cout << endl;
    cout << "Cau 3. Tao cay tu dong tu mang co n phan tu" << endl;
    int array[] = {50, 75, 25, 30, 10, 90, 70, 60, 30, 70, 90};
    copyArr(s, array, 11);
    printTree(s.root);
    cout << endl;
    cout << "Cau 4. Duyet cay theo NLR, LRN, LNR, kem them 3 dia chi Node,left,right" << endl;
    cout << "Duyet cay theo NLR" << endl;
    NLR(s.root);
    cout << "Duyet cay theo LRN" << endl;
    LRN(s.root);
    cout << "Duyet cay theo LNR" << endl;
    LNR(s.root);
    cout << "Cau 5. Tim kiem X" << endl;
    int x = 10;
    cout << "Nhap gia tri tim kiem X= ";
    cin >> x;
    cout << "Ket qua = " << search(s, x) << endl;
    cout << "Cau 6.Dem toan bo so Node" << endl;
    int numOfNode = 0;
    counter(s.root, numOfNode);
    cout << "Ket qua = " << numOfNode << endl;
    cout << "Cau 7.In ra cac node nhanh" << endl;
    int valueNode;
    cout << "Nhap gia tri data Node = ";
    cin >> valueNode;
    cout << "Cac not nhanh " << valueNode << endl;
    Node *branch;
    branch = search(s, valueNode);
    if (branch == NULL)
    {
        cout << "Khong ton tai " << valueNode << " trong cay" << endl;
    }
    else
    {
        LNR(search(s, valueNode));
    }

    cout << "Cau 8.Dem node >X va <Y " << endl;
    int valueX, valueY, numCompare;
    numCompare = 0;
    cout << "Nhap gia tri so sanh X= ";
    cin >> valueX;
    cout << "Nhap gia tri so sanh Y= ";
    cin >> valueY;
    counterCompare(s.root, valueX, valueY, numCompare);
    cout << "Ket qua = " << numCompare << endl;
    cout << "Cau 9.Dem chan le va so sanh" << endl;
    int numOfOdd = 0;
    int numOfEven = 0;
    cout << "Ket qua = " << counterOddEven(s.root, numOfEven, numOfNode) << endl;
    return 0;
}