#include <array>
#include <iostream>
#include <time.h>

using namespace std;
// 1 tao cau truc node
#define SIZE 9
struct node
{
    int data;
    node *pnext;
};
// 2 bien gia tri thanh node
node *createNode(int value)
{
    node *p = new node;
    if (p == NULL)
        return NULL;
    p->data = value;
    p->pnext = NULL;
    return p;
}
// 3 tao cau truc bucket
struct Bucket
{
    node *head;
    node *tail;
};
// 4 khoi tao bucket
void createBucket(Bucket &b) { b.head = b.tail = NULL; }
void addBucket(Bucket &l, node *p)
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
// 5 cau truc bang bam
struct HashTable
{
    Bucket Buckets[SIZE];
};
void insertValues(HashTable &h, int value)
{
    int position = value % SIZE;
    addBucket(h.Buckets[position], createNode(value));
}
void createHashTable(HashTable &h)
{
    for (int i = 0; i < SIZE; i++)
        createBucket(h.Buckets[i]);
}
void printHashTable(HashTable &h)
{
    cout << "---------------------" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        node *p = h.Buckets[i].head;
        cout << "Bucket " << i << ": ";
        while (p != NULL)
        {
            cout << p->data << " \t";
            p = p->pnext;
        }
        cout << endl;
    }
}
/*--------------------------------------------------------*/
/*Câu 2.Viết hàm khởi tạo tự động [856,988], số lượng [45,95]
Input:
    +HashTable &h
Output
    +In ra các giá trị
*/
void randomValues(HashTable &h)
{
    srand(time(NULL));
    int n = 45 + rand() % 51;
    for (int i = 0; i <= n; i++)
    {
        insertValues(h, 856 + rand() % 133);
    }
}
/*Câu 3.Viết hàm nhập giá trị bảng băm từ mảng D
Input:
    +HashTable &h
    +int arr[]
    +int length
Output
    +In ra các giá trị
*/
void addDataArray(HashTable &h, int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        insertValues(h, arr[i]);
    }
}
/*Câu 4.Viết hàm nhập giá cho bảng băm từ bàn phím
Input:
    +HashTable &h
Output
    +In ra các giá trị
*/
void input(HashTable &h)
{
    int n = 0;
    while (n != 9999)
    {
        cout << "Nhap gia tri n hoac 9999 de thoat = ";
        cin >> n;
        if (n != 9999)
        {
            insertValues(h, n);
        }
    }
}
/*Câu 5.Viết hàm kiem tra bang bam rong hay khong, tra ve true hoac false
Input:
    +HashTable &h
Output
    +bool
*/
bool tableEmpty(HashTable &h)
{
    for (int i = 0; i < SIZE; i++)
    {
        node *p = h.Buckets[i].head;
        if (p != NULL)
        {
            return true;
        }
    }
    return false;
}
/*Câu 6.Dem gia tri luu tru trong bang bam
Input:
    +HashTable &h
Output
    +int n (counter)
*/
int count(HashTable &h)
{
    int n = 0;
    for (int i = 0; i < SIZE; i++)
    {
        node *p = h.Buckets[i].head;
        while (p != NULL)
        {
            n++;
            p = p->pnext;
        }
    }
    return n;
}
/*Câu 7.Viết hàm tim gia tri X, tra ve true hoac false
Input:
    +HashTable &h
    +int value
Output
    +bool
*/
bool search(HashTable &h, int value)
{
    for (int i = 0; i < SIZE; i++)
    {
        node *p = h.Buckets[i].head;
        while (p != NULL)
        {
            if (p->data == value)
                return true;
            p = p->pnext;
        }
    }
    return false;
}
/*Câu 8.TIm gia tri max min trong bang
Input:
    +HashTable &h
    +int max
    +int min
Output
    +In ra các giá trị
*/
void maxMin(HashTable &h, int &max, int &min)
{
    for (int i = 0; i < SIZE; i++)
    {
        node *p = h.Buckets[i].head;
        while (p != NULL)
        {
            if (p->data > max)
            {
                max = p->data;
            }
            if (p->data < min)
            {
                min = p->data;
            }
            p = p->pnext;
        }
    }
}
/*Câu 9.Viết hàm dem gia tri chan le va so snh
Input:
    +HashTable &h
Output
    +even > odd return 1
    +even <odd return -1
    + return 0

*/
int countOddEven(HashTable &h)
{
    int odd = 0;
    int even = 0;
    for (int i = 0; i < SIZE; i++)
    {
        node *p = h.Buckets[i].head;
        while (p != NULL)
        {
            if (p->data % 2 == 0)
            {
                even++;
            }
            else
            {
                odd++;
            }

            p = p->pnext;
        }
    }
    if (even > odd)
    {
        return 1;
    }
    else if (even < odd)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    HashTable h;
    HashTable hRandom;
    HashTable hInput;
    createHashTable(h);
    createHashTable(hRandom);
    createHashTable(hInput);
    int arr[] = {50, 75, 25, 30, 10, 90, 70, 60, 30, 70, 90};
    cout << "Cau2" << endl;
    randomValues(hRandom);
    printHashTable(hRandom);
    cout << "Cau3" << endl;
    addDataArray(h, arr, 11);
    printHashTable(h);
    cout << "Cau4" << endl;
    input(hInput);
    printHashTable(hInput);
    cout << "Cau5" << endl;
    cout << "Ket qua " << tableEmpty(h) << endl;
    cout << "Cau6" << endl;
    cout << "Ket qua " << count(h) << endl;
    cout << "Cau7" << endl;
    cout << "Ket qua " << search(h, 75) << endl;
    cout << "Cau8" << endl;
    int max = -999;
    int min = 999;
    maxMin(h, max, min);
    cout << "Ket qua max " << max << endl;
    cout << "Ket qua min " << min << endl;
    cout << "Cau9" << endl;
    cout << "Ket qua " << countOddEven(h) << endl;
    return 0;
}
