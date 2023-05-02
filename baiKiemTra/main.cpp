
/*
Ho va ten Ho Van Phong
Mssv 22210069
De 01
*/
#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;
// tao cau truc node
struct Node
{
    double data;
    Node *left;
    Node *right;
};
// tao cau truc cay
struct Tree
{
    Node *root;
};
// khoi tao node.value-->node*
Node *createNode(double value)
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
// in tree
void printTree(Node *p)
{
    if (p != NULL)
    {
        printTree(p->left);
        cout << p->data << "\t";
        printTree(p->right);
    }
}
/*Câu 1.Viet ham chen node kieu so thuc Double vao cay
    +Tree &t
    +node* p
Output
    +thanh cong -> return 1
    +that bai -> return -1
*/
int addNode(Tree &t, Node *p)
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

                return -1;
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
        return 1;
    }
}

/*Câu 2.Viet ham tao cay tu mang 1 chieu
Input:
    +Tree &t
    +int arr[]
    +int n
Output
    +Tree &t=>&

*/
void copyArr(Tree &t, double arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        addNode(t, createNode(arr[i]));
    }
}

/*Câu 3.Viết hàm duyệt cây node, left right
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

/*Câu 4.Viết hàm tim kiem gia tri X
Input:
    +Tree &t
    +int x
Output
    +Node *p
    +Null

*/
Node *search(Tree t, double x)
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
/*Câu 5.Tinh gia tri trung binh cac node
Input:
    +Ham tinh tong total o cau 8
    +Ham dem node counter
Output
    +Ham tinh tong/ham dem node
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
/*Câu 6.Viet ham dem cac node chi co 1 nhanh con
Input:
    +Ham tinh tong total o cau 8
    +Ham dem node counter
Output
    +Ham tinh tong/ham dem node
*/
void counterBranch(Node *p, int &count)
{
    if (p != NULL)
    {
        if (p->left == NULL && p->right != NULL || p->left != NULL && p->right == NULL)
            count++;
        counter(p->left, count);
        counter(p->right, count);
    }
}
/*Câu 7.Viết hàm tinh tich gia tri lon nhat va nho nhat
Input:
    +Tree t

Output
    +double result=max*min

*/

double maxAndMin(Tree t)
{
    double max = t.root->data;
    double min = t.root->data;
    double result;
    Node *i = t.root;
    while (i != NULL)
    {

        if (max <= i->data)
        {
            max = i->data;
            i = i->right;
        }
    }
    Node *k = t.root;
    while (k != NULL)
    {

        if (min >= k->data)
        {
            min = k->data;
            k = k->left;
        }
    }
    return result = max * min;
}
/*Câu 8.Tong cac gia tri cua cay
Input:
    +Node *p (root)
    +int &count
Output
    +count

*/
double total(Node *p, double &sum)
{
    if (p != NULL)
    {
        sum = sum + p->data;
        total(p->left, sum);
        total(p->right, sum);
    }
    return sum;
}
/*Câu 9.Tao 2 cay nhi phan ko chua not goc
Input:
    +Tree t
    +Tree &left
    +Tree &right
    +Ham con addNewDatta
Output
    +Tree  left
    +Tree right
    +in cac gia tri

*/
void addNewData(Node *p, Tree &t)
{
    if (p != NULL)
    {
        addNewData(p->left, t);
        addNode(t, p);
        addNewData(p->right, t);
    }
}
void createFromTree(Tree t, Tree &leftTr, Tree &rightTr)
{
    Node *i = t.root;
    leftTr.root = i->left;
    rightTr.root = i->right;
    addNewData(i->left, leftTr);
    addNewData(i->right, rightTr);
}

int main()
{
    Tree t;
    createTree(t);
    cout << "Cau 2. Tao cay tu mang 1 chieu" << endl;
    double array[] = {50.1, 75.1, 60.2, 30.4, 70.7, 90.5, 75.2, 25.3, 30.4, 10.5, 90.5};
    copyArr(t, array, 11);
    cout << "Cau 3. Duyet cay" << endl;
    printTree(t.root);
    cout << endl;
    cout << "Cau 4.Viet ham tim kiem gia tri X" << endl;
    cout << "Ket qua " << search(t, 90.5) << endl;
    cout << "Cau 5. Tim tong gia tri trung binh cac node" << endl;
    double sum = 0;
    int n = 0;
    counter(t.root, n);
    cout << "Ket Qua " << total(t.root, sum) / n << endl;
    cout << "Cau 6. Dem cac node co 1 nhanh con" << endl;
    int branch = 0;
    counterBranch(t.root, branch);
    cout << "Ket Qua " << branch << endl;
    cout << "Cau 7.Tich gia tri nho nhat va lon nhat" << endl;
    cout << "Ket qua " << maxAndMin(t) << endl;
    cout << "Cau 8.Tong cac node" << endl;
    double totalSum = 0;
    cout << "Ket Qua " << total(t.root, totalSum) << endl;
    cout << "Cau 9.Khoi tao 2 cay nhi phan ko chua not goc tu cay ban dau" << endl;
    Tree leftBranch, rightBranch;
    createFromTree(t, leftBranch, rightBranch);
    cout << "LEFT" << endl;
    printTree(leftBranch.root);
    cout << endl;
    cout << "RIGHT" << endl;
    printTree(rightBranch.root);
    return 0;
}