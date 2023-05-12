#include <iostream>
#include <math.h>
// #include <array>
using namespace std;
// 1 xay dung cau truc va cau truc danh sach lien ket don
struct node
{
    int data;
    node *pnext;
};
struct List
{
    node *head;
    node *tail;
};
// 2 ham khoi tao danh sach lien ket don va ham khoi tao dia chi node tu 1 so nguyen
node *createNode(int value)
{
    node *p = new node;
    if (p == NULL)
        return NULL;
    p->data = value;
    p->pnext = NULL;
    return p;
}
// 3 viet ham chen node vao dau danh sach
void addHead(List &l, node *p)
{
    if (l.tail == NULL)
    {
        l.head = p;
        l.tail = p;
    }
    else
    {
        p->pnext = l.head; // noi moc dia chi
        l.head = p;        // di doi dia chi ve dau
    }
}
// 4 viet ham chen node vao cuoi danh sach
void addTail(List &l, node *p)
{
    if (l.tail == NULL)
    {
        l.head = p;
        l.tail = p;
    }
    else
    {
        l.tail->pnext = p;
        l.tail = p;
        // l.head = p;
    }
}
void createList(List &l)
{
    l.head = l.tail = NULL;
}
// 11 hàm in danh sách
void printList(List l)
{
    for (node *i = l.head; i != NULL; i = i->pnext)
    {
        cout << i->data << "\t";
    }
    cout << endl;
}
// câu 5 viết hàm nhập giá trị cho danh sách theo phương pháp thử công từ bàn phím, dùng hàm chèn đầu danh sách, điều kiện kết thúc tự qui định
void inputNumber(List &l, int &n)
{
    cout << "nhap so luong n=";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        float k;
        cout << "nhap a[" << i << "]=";
        cin >> k;
        addHead(l, createNode(k));
    }
};
// 6 viết hàm nhật giá trị cho danh sách, các giá trị [-99;99]
//  số lượng nhập ngẫu nhiên [39;59]
void randomList(List &l)
{
    int n = 0 + rand() % 21;

    for (int i = 1; i <= n; i++)
    {
        int value = -99 + rand() % 199;
        addTail(l, createNode(value));
    }
}
// 7 viết hàm nhập giá trị cho danh sách từ mảng 1 chiều
void copyArr(List &l, int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        int value = *(arr + i);
        addTail(l, createNode(value));
    }
}
// 8 viet ham chen node vao giua danh sach
void addMid(List &l, node *p)
{
    if (l.tail == NULL)
    {
        l.head = p;
        l.tail = p;
    }
    else
    {
        l.tail->pnext = p;
        l.tail = p;
    }
}
void printPlus(List l)
{
    for (node *i = l.head; i != NULL; i = i->pnext)
    {
        cout << i->data << "/" << i << endl;
    }
    cout << endl;
}
int counter(List l)
{
    int n = 0;
    for (node *i = l.head; i != NULL; i = i->pnext)
    {
        n++;
    }
    return n;
}
node *middle(List l)
{
    int compare = 0;
    int n;
    if (counter(l) % 2 == 0)
    {
        n = counter(l) / 2;
    }
    else
    {
        n = counter(l) / 2 + 1;
    }
    node *p;
    for (node *i = l.head; i != NULL; i = i->pnext)
    {
        compare++;
        if (compare == n)
        {
            p = i;
            break;
        }
    }
    return p;
}
node *findNode(List l, int value)
{
    node *p;
    for (node *i = l.head; i != NULL; i = i->pnext)
    {
        if (i->data == value)
        {
            p = i;
            return p;
        }
    }
    return p;
}
bool isExist(List l, int value)
{
    node *p;
    for (node *i = l.head; i != NULL; i = i->pnext)
    {
        if (i->data == value)
            return true;
    }
    return false;
}
void insertMid(List &l, node *q, node *p)
{
    //neu ton tai node q thi thuc hien chen giua
    if (q != NULL)
    {
        //gan con tro next node p bang con tro next node q
        p->pnext = q->pnext;
        //gan con tro next node q bang node p
        q->pnext = p;
        //neu q la phan tu cuoi cung thi chen node p vao cuoi
        if (q == l.tail)
        {
            l.tail = p;
        }
    }
    //nguoc lai khong ton tai node q thi chen node p vao dau
    else
    {
        //goi ham chen dau
        addHead(l, p);
    }
}
node *findBefore(List &l, node *value)
{
    node *p;
    node *temporary = l.head;
    for (node *i = l.head; i != NULL; i = i->pnext)
    {
        if (i->data == value->data)
        {
            p = temporary;
            // return p;
        }
        temporary = i;
    }
    return p;
}
int printValue(node *p)
{
    return p->data;
}
int main()
{
    int n;
    int number;
    // int array[] = {1, 12, 32, 4};
    // int length = sizeof(array) / sizeof(*array);
    // srand(time(0));
    List l;
    createList(l);
    // randomList(l);
    addHead(l, createNode(2));
    addHead(l, createNode(3));
    addHead(l, createNode(11));
    addHead(l, createNode(15));
    addHead(l, createNode(16));
    addHead(l, createNode(17));
    // insertMid(l, findNode(l, 11), createNode(4));
    // insertMid(l, findBefore(l, findNode(l, 11)), createNode(4));
    // printList(l);
    cout << "---result---" << endl;
    cout << isExist(l, 22) << endl;
    return 0;
}
