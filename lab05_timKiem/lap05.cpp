#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;
/*Câu 3 .Viet ham xuat mang
Input:
    +int &n
    +float *a
Output
    +Cac gia tri mang *(a+i)
*/
void printArr(float *a, int &n)
{
    cout << "---Xuat Mang---" << endl;
    for (int i = 0; i < n; i++)
    {

        cout << "  " << *(a + i);
    }
    cout << "\n";
}
/*Câu 1.Viet ham nhap tu dong x trong khong [100,999] voi so luong [30,50]
Input:
    +int &n
Output
    +float *a
*/
float *randomX(int &n)
{
    srand(time(NULL));
    n = 30 + rand() % 21;
    float *a = new float[n];
    for (int i = 0; i < n; i++)
    {
        *(a + i) = 100 + rand() % 900;
    };
    return a;
}
/*Câu 2.Viet ham nhap tu dong y tang dan bit phan tu dau tien <=130 voi so luong [30,50], cac phan tu ke nhau khong qua 15
Input:
    +int &n
Output
    +float *a
*/
float *randomY(int &n)
{
    srand(time(NULL));
    int firstValue = rand() % 131;
    int space = 1 + rand() % 15;
    n = 30 + rand() % 21;
    float *a = new float[n];
    for (int i = 0; i < n; i++)
    {

        *(a + i) = firstValue + space * i;
    };
    return a;
}
/*Câu 4.tim kiem tuyen tinh mang x, y
Input:
    +float *a
    +int n
    +int value
Output
    +boolean
*/
bool linearSea(float *a, int n, int value)
{
    for (int i = 0; i < n; i++)
    {
        if (*(a + i) == value)
        {
            return true;
        }
    }
    return false;
}
/*Câu 5.tim kiem nhi phan mang  y
Input:
    +float *a
    +int n
    +int value
    +int &counter
Output
    +boolean
*/
bool binarySea(float *a, int n, int value, int &counter)
{
    int left = counter = 0, right = n - 1, mid;
    while (left <= right)
    {
        counter++;
        mid = (left + right) / 2;
        if (*(a + mid) == value)
            return true;

        if (value > *(a + mid))
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}
/*Câu 6.tim kiem noi suy mang  y
Input:
    +float *a
    +int n
    +int value
Output
    +boolean
*/
/*Câu 7.so sanh cach tim kiem noi suy va nhi phan
Input:
    +int counterBin
    +int counterIn
Output
    +cout counterBin and cout counterBin
*/
bool interpolation(float *a, int n, int value, int &counter)
{
    int left = counter = 0, right = n - 1, mid;
    while (left <= right)
    {
        counter++;
        int aR = *(a + right);
        int aL = *(a + left);
        mid = left + ((right - left) / (aR - aL)) * (value - aL);
        if (*(a + mid) == value)
            return true;

        if (value > *(a + mid))
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}
int main()
{
    int x, y, countBin, countInt;
    float *arrayX;
    float *arrayY;
    int choose = 0;
    while (true)
    {
        cout << "Xin hay chon menu \n 1.Tao mang array X \n 2.Tao mang array Y \n 3.Xuat mang X \n 4.Xuat mang Y \n 5.Tim kiem tuyen tinh mang X \n 6.Tim kiem tuyen tinh mang Y \n 7.Tim kiem nhi phan mang Y \n 8.Tim kiem noi suy mang Y \n 9.So sanh so lan tim kiem \n"
             << endl;
        cout << "Chon = ";
        cin >> choose;
        switch (choose)
        {
        case 1:
            arrayX = randomX(x);
            cout << "-------------------" << endl;
            cout << "Da tao mang X thanh coong" << endl;
            cout << "-------------------" << endl;
            break;
        case 2:
            arrayY = randomY(y);
            cout << "-------------------" << endl;
            cout << "Da tao mang Y thanh coong" << endl;
            cout << "-------------------" << endl;
            break;
        case 3:
            cout << "-------------------" << endl;
            printArr(arrayX, x);
            cout << "-------------------" << endl;
            break;
        case 4:
            cout << "-------------------" << endl;
            printArr(arrayY, y);
            cout << "-------------------" << endl;
            break;
        case 5:
            cout << "---------Gia tri 100----------" << endl;
            cout << linearSea(arrayX, x, 100) << endl;
            cout << "-------------------" << endl;
            break;
        case 6:
            cout << "---------Gia tri 100----------" << endl;
            cout << linearSea(arrayY, y, 100) << endl;
            cout << "-------------------" << endl;
            break;
        case 7:
            cout << "---------Gia tri 100----------" << endl;
            cout << binarySea(arrayY, y, 100, countBin) << endl;
            cout << "-------------------" << endl;
            break;
        case 8:
            cout << "---------Gia tri 100----------" << endl;
            cout << interpolation(arrayY, y, 100, countInt) << endl;
            cout << "-------------------" << endl;
            break;
        case 9:
            cout << "---------So sanh Binary va Interpolation----------" << endl;
            cout << "Binary: " << countBin << " Interpolation: " << countInt << endl;
            cout << "-------------------" << endl;
            break;
        default:
            return 1;
            break;
        }
    }

    return 0;
}