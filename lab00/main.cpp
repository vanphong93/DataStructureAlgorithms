
#include <cstdlib>
#include <iostream>

using namespace std;
// Câu1  nhập mảng từ bàn phím
void nhapSo(float *a, int &n) {
  cout << "nhap so luong n=";
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << "nhap a[" << i << "]=";
    cin >> *(a + i);
  }
};

// Câu3 In mảng
void xuatSo(float *a, int &n) {
  cout << "---Mang---" << endl;
  for (int i = 0; i < n; i++) {

    cout << "  " << *(a + i);
  }
  cout << "\n";
}
// cau 2: random values
void randomValues(float *a, int &n) {
  srand(time(NULL));
  int input = 10 + random() % 11;
  n = input;
  for (int i = 0; i < n; i++) {
    *(a + i) = -268 + rand() % 608;
  };
  xuatSo(a, n);
}
// Câu4 tính tổng
float tong(float *a, int &n) {
  float s = 0;
  for (int i = 0; i < n; i++) {
    s += *(a + i);
  }
  return s;
}
// Câu 5 tính tổng và tích các phần tử trong
void tongTich(float *a, int &n) {
  float sum = 0;
  float multi = 1;
  for (int i = 0; i < n; i++) {
    multi *= *(a + i);
    sum += *(a + i);
  }
  cout << "tich = " << multi << endl;
  cout << "tong = " << sum << endl;
}
// Câu 6 đếm số lần xuất hiên của phần tử X
int dem(float *a, int &n) {
  long x;
  int k = 0;
  cout << "nhap x= ";
  cin >> x;
  for (int i = 0; i < n; i++) {
    if (a[i] == x) {
      k++;
    };
  };
  cout << "so lan xuat hien x= " << x << " la " << k << endl;
  return k;
}
// Câu 7 trả về phần tử chẵn
void phanTuChan(float *a, int &n) {
  cout << "Cac phan tu chan";
  for (int i = 0; i < n; i++) {
    if ((int)*(a + i) % 2 == 0) {
      cout << " " << *(a + i);
    }
  }
  cout << endl;
}
// Câu 8 tìm vị trí phần tử nhở nhất
int min(float *a, int &n) {
  int x = 0;
  for (int i = 0; i < n; i++) {
    if (*(a + i) < x) {
      x = *(a + i);
    };
  }
  return x;
}
// Câu9 xuất in ra mảng đảo ngược
void mangNguoc(float *a, int &n) {
  float *b = new float[n];
  for (int i = 0; i < n; i++) {
    *(b + n - 1 - i) = *(a + i);
  }
  xuatSo(b, n);
}
// Câu10 Trả về các số âm trong mảng
void soAm(float *a, int &n) {
  cout << "Cac so am ";
  for (int i = 0; i < n; i++) {
    int x = (int)*(a + i);
    if (x == *(a + i) && x < 0) {
      cout << " " << *(a + i);
    }
  }
  cout << endl;
}
void include(float *a, int &n) {
  long x;
  long y;
  int count = 0;
  cout << "nhap x= ";
  cin >> x;
  cout << "nhap y= ";
  cin >> y;
  cout << "cac so thuoc doan [x,y] la";
  for (int i = 0; i < n; i++) {
    if (x <= *(a + i) && *(a + i) <= y) {
      cout << " " << *(a + i);
      count++;
    }
  }
  cout << " co " << count << " thuoc doan" << endl;
  cout << endl;
}
int main() {
  bool condition = true;
  float *a = new float[100]; // khai bao so phan tu mang
  int n = 0;                 // tao bien tham chieu
  int choose;
  while (condition) {
    cout << "--Chose--\n";
    cout << "1. Nhap gia tri vao mang\n";
    cout << "2. Tao gia tri ngau nhien [-268,339], so luong [10,20]\n";
    cout << "3. In mang \n";
    cout << "4. Tong cac gia tri trong mang \n";
    cout << "5. Tong va tich viet cung 1 ham\n";
    cout << "6. Dem so lan xuat hien cua x\n";
    cout << "7. Tra ve phan tu chan le dua vao phan nguyen\n";
    cout << "8. Phan tu nho nhat trong mang\n";
    cout << "9. In ra mang dao nguoc\n";
    cout << "10. Tra ve cac so am trong mang\n";
    cout << "11. Tra ve cac so thuoc doan [x,y]\n";
    cout << "12. Tra ve so luong cac so trong doan [x,y]\n";
    cout << "13. Thoat \n";
    cout << "Input = ";
    cin >> choose;
    switch (choose) {
    case 1:
      nhapSo(a, n);
      xuatSo(a, n);
      break;
    case 2:
    case 3:
      randomValues(a, n);
      break;
    case 4:
      cout << "Tong cac gia tri trong mang \n" << tong(a, n) << endl;
      break;
    case 5:
      tongTich(a, n);
      break;
    case 6:
      dem(a, n);
      break;
    case 7:
      phanTuChan(a, n);
      break;
    case 8:
      cout << "Min = " << min(a, n) << endl;
      break;
    case 9:
      mangNguoc(a, n);
      break;
    case 10:
      soAm(a, n);
      break;
    case 11:
    case 12:
      include(a, n);
      break;
    default:
      condition = false;
    }
  }
  return 0;
}
