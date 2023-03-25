#include <iostream>
#include <time.h>
using namespace std;

struct node {
  int data;
  node *pnext;
};
struct Stack {
  node *Top;
};

node *createNode(int value) {
  node *p = new node;
  if (p == NULL)
    return NULL;
  p->data = value;
  p->pnext = NULL;
  return p;
}
void createStack(Stack &s) { s.Top = NULL; }
void push(Stack &s, node *p) {
  if (s.Top == NULL) {
    s.Top = p;
  } else {
    p->pnext = s.Top;
    s.Top = p;
  }
}
void printStack(Stack s) {
  cout << "Stack s = Top < ";
  for (node *i = s.Top; i != NULL; i = i->pnext) {
    cout << i->data << "  ";
  }
  cout << ">" << endl;
}
int pop(Stack &s, int &value) {
  if (s.Top == NULL)
    return 0;
  node *p = s.Top;      // 1
  s.Top = s.Top->pnext; // move
  value = p->data;
  delete p; // thu hoi
  return 1;
}
int getTop(Stack s) {
  if (s.Top == NULL)
    return 0;
  return s.Top->data;
}
int main() {
  bool condision = true;
  Stack s;
  createStack(s);
  while (condision) {
    int chon;
    cout << "-------- Demo Stack --------" << endl;
    cout << "\t1.push" << endl;
    cout << "\t2.pop" << endl;
    cout << "\t3.Top" << endl;
    cout << "\t4.Empty" << endl;
    cout << "\t5. (No) Full" << endl;
    cout << "\t6. Exit" << endl;
    cout << "Nhap lua chon: ";
    cin >> chon;

    switch (chon) {
    case 1:
      while (true) {
        int value;
        cout << "Nhap gia tri (0 de thoat): ";
        cin >> value;
        if (value == 0) {
          break;
        } else {
          push(s, createNode(value));
        }
      }
      cout << "--------------" << endl;
      cout << "Ket qua: \n";
      printStack(s);
      cout << "--------------" << endl;
      break;
    case 2: {
      int x = 0;
      if (pop(s, x)) {
        cout << "Da lay ra gia tri: " << x << endl;
      } else {
        cout << "X ko co gia tri, ham rong" << endl;
      }
      cout << "Ket qua: ";
      printStack(s);
      cout << "--------------" << endl;
    } break;
    case 3: {
      int result;
      result = getTop(s);
      if (result) {
        cout << "Top= " << s.Top->data << endl;
      } else {
        cout << "Top khong co du lieu " << endl;
      }
    } break;
    case 4: {
      if (getTop(s)) {
        cout << "Ham co du lieu " << endl;
      } else {
        cout << "Ham rong " << endl;
      }
    } break;
    case 5: {
      cout << "Always not full" << endl;
    } break;
    case 6: {
      condision = false;
    } break;
    default:
      break;
    }
  }
  return 0;
}
