#include <array>
#include <iostream>
#include <time.h>

using namespace std;
// 1 tao cau truc node
#define SIZE 7
struct node {
  int data;
  node *pnext;
};
// 2 bien gia tri thanh node
node *createNode(int value) {
  node *p = new node;
  if (p == NULL)
    return NULL;
  p->data = value;
  p->pnext = NULL;
  return p;
}
// 3 tao cau truc bucket
struct Bucket {
  node *head;
  node *tail;
};
// 4 khoi tao bucket
void createBucket(Bucket &b) { b.head = b.tail = NULL; }
void addBucket(Bucket &l, node *p) {
  if (l.tail == NULL) {
    l.head = p;
    l.tail = p;
  } else {
    l.tail->pnext = p;
    l.tail = p;
  }
}
// 5 cau truc bang bam
struct HashTable {
  Bucket Buckets[SIZE];
};
void insertValues(HashTable &h, int value) {
  int position = value % SIZE;
  addBucket(h.Buckets[position], createNode(value));
}
// random values 856-988, quantity 45-95
void randomValues(HashTable &h) {
  srand(time(NULL));
  int n = 45 + rand() % 51;
  for (int i = 0; i <= n; i++) {
    insertValues(h, 856 + rand() % 133);
  }
}
void createHashTable(HashTable &h) {
  for (int i = 0; i < SIZE; i++)
    createBucket(h.Buckets[i]);
}
void printHashTable(HashTable &h) {
  cout << "---------------------" << endl;
  for (int i = 0; i < SIZE; i++) {
    node *p = h.Buckets[i].head;
    cout << "Bucket " << i << ": ";
    while (p != NULL) {
      cout << p->data << " \t";
      p = p->pnext;
    }
    cout << endl;
  }
}

void addDataArray(HashTable &h, int *arr, int length) {
  for (int i = 0; i < length; i++) {
    insertValues(h, arr[i]);
  }
}
bool search(HashTable &h, int value) {
  for (int i = 0; i < SIZE; i++) {
    node *p = h.Buckets[i].head;
    while (p != NULL) {
      if (p->data == value)
        return true;
      p = p->pnext;
    }
  }
  return false;
}
void remove(HashTable &h, int value) {
  int position = value % SIZE;
  node *p = h.Buckets[position].head;
  node *q = NULL;
  while (p != NULL) {
    if (p->data == value) {
      if (q == NULL)
        h.Buckets[position].head = p->pnext;
      else
        q->pnext = p->pnext;
      delete p;
      return;
    }
    q = p;
    p = p->pnext;
    cout << "Khong tim thay gia tri" << endl;
  }
}
int summOdds(HashTable &h) {
  int sum = 0;
  for (int i = 0; i < SIZE; i++) {
    node *p = h.Buckets[i].head;
    while (p != NULL) {
      if (p->data % 2 == 1) {
        sum += p->data;
      }
      p = p->pnext;
    }
  }
  return sum;
}
int maxValue(HashTable &h) {
  int max = 0;
  for (int i = 0; i < SIZE; i++) {
    node *p = h.Buckets[i].head;
    while (p != NULL) {
      if (p->data > max) {
        max = p->data;
      }
      p = p->pnext;
    }
  }
  return max;
}
void bucketEmpty(HashTable &h) {
  for (int i = 0; i < SIZE; i++) {
    node *p = h.Buckets[i].head;
    cout << "Bucket " << i;
    if (p != NULL) {
      cout << " is not empty" << endl;
    } else {
      cout << " is empty" << endl;
    }
  }
}
void input() {
  int n;
  cout << "Nhap vao so luong phan tu = ";
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cout << "arr[" << i << "] = ";
    cin >> arr[i];
  }
  HashTable h;
  createHashTable(h);
  addDataArray(h, arr, n);
  printHashTable(h);
}
int main() {
  int choice;
  HashTable h;
  createHashTable(h);
  int arr[] = {100, 300, 34, 68, 56, 45, 76};
  cout << "arr[] = {100, 300, 34, 68, 56, 45, 76} " << endl;
  cout << "Xin hay chon menu \n 1.Tao du lieu trong doan [856;988], so luong "
          "[45;95] \n 2.Tao du lieu tu mang 1 chieu \n 3.Nhap du lieu tu ban "
          "phim \n 4.In bang bam "
          "\n 5.Xoa gia tri trong bang \n 6.Tim gia tri trong bang \n 7.Tong "
          "cac gia tri le trong bang \n 8.Kiem tra bang bam co rong khong \n "
          "9.In ra so lon nhat co trong bang \n 10.Thoat chuong trinh"
       << endl;
  cout << "Chon = ";
  cin >> choice;
  switch (choice) {
  case 1:
    randomValues(h);
    printHashTable(h);
    break;
  case 2:
  case 4:
    addDataArray(h, arr, 7);
    printHashTable(h);
    break;
  case 3:
    input();
    break;
  case 5:
    int valueDelete;
    addDataArray(h, arr, 7);
    cout << " arr[] = {100, 300, 34, 68, 56, 45, 76} " << endl;
    cout << "Nhap gia tri xoa = ";
    cin >> valueDelete;
    remove(h, valueDelete);
    printHashTable(h);
    break;
  case 6:
    int valueSearch;
    addDataArray(h, arr, 7);
    cout << " arr[] = {100, 300, 34, 68, 56, 45, 76} " << endl;
    cout << "Nhap gia tri = ";
    cin >> valueSearch;
    if (search(h, valueSearch)) {
      cout << "Ton tai " << valueSearch << " trong bang" << endl;
    } else {
      cout << "Khong ton tai " << valueSearch << " trong bang" << endl;
    }
    break;
  case 7:
    addDataArray(h, arr, 7);
    cout << " arr[] = {100, 300, 34, 68, 56, 45, 76} " << endl;
    cout << "Tong cac so le trong bang = " << summOdds(h) << endl;
    break;
  case 8:
    addDataArray(h, arr, 7);
    cout << " arr[] = {100, 300, 34, 68, 56, 45, 76} " << endl;
    printHashTable(h);
    cout << "--kiem tra rong--" << endl;
    bucketEmpty(h);
    break;
  case 9:
    randomValues(h);
    printHashTable(h);
    cout << "----------------" << endl;
    cout << "gia tri lon nhat trong bang = " << maxValue(h) << endl;
    break;
  case 10:
    cout << "Exited" << endl;
    break;
  default:
    return 0;
  }
  return 0;
}
