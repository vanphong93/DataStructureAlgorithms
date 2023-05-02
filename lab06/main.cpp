#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;
void selectionSort(double a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        swap(a[i], a[min]);
    }
}
void print(double a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "\t";
        // printf("f=%10.3f", a[i]);
    }
    cout << endl;
}
void createData(double a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() + double((rand() % 1000)) / 1000;
    }
}
void dataRange(double a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        double b = 39000 + rand() % 60001;
        a[i] = b + double((rand() % 1000)) / 1000;
    }
}
double timeOut(double a[], int n)
{
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    selectionSort(a, n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}
void inputValue(double a[], int &n)
{
    cout << "Nhap so phan tu n= ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        double value;
        cout << "Nhap gia tri a[" << i << "] =";
        cin >> value;
        a[i] = value;
    }
}
double arrayA[int(1e6)];
int main()
{
    int n = 100000;
    srand(time(NULL));
    int choose;
    double time;

    while (true)
    {
        cout << "Xin hay chon menu \n 1.Tao mang array theo phuong phap thu cong \n 2.Khoi tao 100000 phan tu so thuc \n 3.Khoi tao 100000 phan tu so thuc trong khoang [39000,99000] \n 4.Xuat mang \n 5.Viet thuc ham sap xep tang dan \n 6.Viet ham tinh thoi gian thuc hien sap xep \n 9.So sanh thoi gian tao du lieu mang 10k,30k,50k,80k va 100k phan tu \n 10.Exit  \n"
             << endl;
        cout << "Chon = ";
        cin >> choose;
        switch (choose)
        {
        case 1:
            inputValue(arrayA, n);
            print(arrayA, n);
            cout << "-------------------" << endl;
            break;
        case 2:
            n = 100000;
            createData(arrayA, n);
            print(arrayA, n);
            cout << "-------------------" << endl;
            break;
        case 3:
             n = 100000;
            dataRange(arrayA, n);
            print(arrayA, n);
            cout << "-------------------" << endl;
            break;
        case 4:
            print(arrayA, n);
            cout << "-------------------" << endl;
            break;
        case 5:
            selectionSort(arrayA, n);
            print(arrayA, n);
            cout << "-------------------" << endl;
            break;
        case 6:
            time = timeOut(arrayA, n);
            cout << "Thoi gian " << time << endl;
            cout << "-------------------" << endl;
            break;
        case 9:
            n = 10000;
            time = timeOut(arrayA, n);
            cout << "Thoi gian tao 10000 phan tu" << time << endl;
            n = 30000;
            time = timeOut(arrayA, n);
            cout << "Thoi gian tao 30000 phan tu" << time << endl;
            n = 50000;
            time = timeOut(arrayA, n);
            cout << "Thoi gian tao 50000 phan tu" << time << endl;
            n = 80000;
            time = timeOut(arrayA, n);
            cout << "Thoi gian tao 80000 phan tu" << time << endl;
            n = 100000;
            time = timeOut(arrayA, n);
            cout << "Thoi gian tao 100000 phan tu" << time << endl;
            cout << "-------------------" << endl;
            break;
        default:
            return 1;
            break;
        }
    }

    return 0;
}