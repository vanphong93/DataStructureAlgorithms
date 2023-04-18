#include <iostream>
#include <time.h>
using namespace std;
// Câu 1   xây dựng cấu trúc dữ liệu sinh viên
struct SinhVien
{
    int maSV;
    string hoTen;
    float diemMH;
};
typedef SinhVien SV;
void xuatSV(SV sv)
{
    cout << "\nThong tin sinh vien" << endl;
    cout << "\t+Ma SV : " << sv.maSV << endl;
    cout << "\t+Ho ten : " << sv.hoTen << endl;
    cout << "\t+Diem TB : " << sv.diemMH << endl;
}
// Bước 1.Tạo cấu trúc node
struct node
{
    SV data;
    node *pnext;
};
// Bước 2.Tạo cấu trúc danh sách lkđ
struct List
{
    node *head;
    node *tail;
};
// Bước 3. Chuyển ST==>node*
node *createNode(SV value)
{
    node *p = new node;
    p->data = value;
    p->pnext = NULL;
    return p;
}
// Bước 4.Khởi tạo danh sách
void createList(List &l)
{
    l.head = l.tail = NULL;
}
// câu 4 hàm thêm sinh viên vào đầu danh sách
// void addHead(List &l, node *p)
// {

//     p->pnext = l.head; // noi moc dia chi
//     l.head = p;        // di doi dia chi ve dau
// }
/*Câu 1.Chèn node vào cuối
Input:
    +list l
    +node*p
Output
    +list& l=>&
    +bool
*/
bool addTail(List &l, node *p)
{

    if (l.head == NULL)
    {
        l.head = l.tail = p;
        return true;
    }
    else
    {
        l.tail->pnext = p;
        l.tail = p;
        return true;
    }
    return false;
}
/*Câu 2.Xuat sinh vien
Input:
    +list l
Output
    +Thong tin sinh vien: maSV,name,gpa.
*/
void xuat(List l)
{
    for (node *i = l.head; i != NULL; i = i->pnext)
    {
        xuatSV(i->data);
    }
}
/*Câu 3.Viet ham tim kiem sv theo ma sv, neu tim thay tra ve dia chi node neu khong tra ve null
Input:
    +list dsSV
    + int maSV
Output
    +node* =>return
*/
node *timSV(List l, int maSV)
{
    for (node *i = l.head; i != NULL; i = i->pnext)
    {
        if (i->data.maSV == maSV)
        {
            return i;
        }
    }
    return NULL;
}
/*Câu 4.Viet ham dem sinh vien co diem duoi trung binh
Input:
    +list dsSV
    + float diem
Output
    +int counter =>return
*/
int demSV(List l, float diem)
{
    int counter = 0;
    for (node *i = l.head; i != NULL; i = i->pnext)
    {
        if (i->data.diemMH < diem)
        {
            counter++;
        }
    }
    return counter;
}
/*Câu 5.Viet ham tinh diem trung binh cua lop
Input:
    +list dsSV
Output
    +float diemTB =>return
*/
float diemTB(List l)
{
    float result = 0;
    int counter = 0;
    float sum = 0;
    for (node *i = l.head; i != NULL; i = i->pnext)
    {
        counter++;
        sum = sum + i->data.diemMH;
    }
    return result = sum / counter;
}
/*Câu 6.Viet ham tim ma sinh vien dau tien co diem  lon nhat
Input:
    +list dsSV
Output
    +int maSV =>return
*/
int maxSV(List l)
{
    int result = l.head->data.maSV;
    float point = l.head->data.diemMH;
    for (node *i = l.head; i != NULL; i = i->pnext)
    {
        if (i->data.diemMH > point)
        {
            point = i->data.diemMH;
            result = i->data.maSV;
        }
    }
    return result;
}
/*Câu 7.Viet ham tim tra ve cac sinh vien co diem tren 8
Input:
    +list dsSV
    +int diem=8
Output
    +arraySV
*/
int *timCacMaSV(List l, float diem)
{
    int soSV = demSV(l, diem);
    int *arraySV = new int[soSV];
    int counter = 0;
    for (node *i = l.head; i != NULL; i = i->pnext)
    {
        if (i->data.diemMH > diem)
        {
            arraySV[counter] = i->data.maSV;
            counter++;
        }
    }
    return arraySV;
}
/*Câu 8.Viet ham cap nhat diem mon hoc theo ma sv
Input:
    +list dsSV
    +int maSV
    +int diem
Output
    +False bao loi khong tim thay
    +True Thong tin sinh vien: maSV,name,gpa.
*/
bool updateSV(List l, int maSV, float diem)
{
    node *newData;
    newData = timSV(l, maSV);
    if (newData != NULL)
    {
        newData->data.diemMH = diem;
        return true;
    }
    else
    {
        return false;
    }
}
/*Câu 9.Viet ham sao chep sinh sang danh sach moi

Input:
    +list dsSV
Output
    +list newList =>return
    +xuat thong tin: maSV,name,gpa.
Y tuong:
    +Tao list moi
    +Duyet vong lap for list cu->tao data tung phan tu ->add data vao list moi
*/
List copyList(List l)
{
    List newList;
    createList(newList);
    for (node *i = l.head; i != NULL; i = i->pnext)
    {
        SinhVien sv = {i->data.maSV, i->data.hoTen, i->data.diemMH};
        addTail(newList, createNode(sv));
    }
    return newList;
}

int main()
{
    int *arrayPoint;
    // srand(time(0));
    List dsSV;
    createList(dsSV);
    SinhVien sv1 = {123, "Nguyen A", 8.8};
    SinhVien sv2 = {124, "Nguyen B", 9.7};
    SinhVien sv3 = {125, "Nguyen C", 2.9};
    SinhVien sv4 = {126, "Nguyen D", 9.7};
    SinhVien sv5 = {127, "Nguyen E", 4.8};
    SinhVien sv6 = {128, "Nguyen F", 7.5};
    addTail(dsSV, createNode(sv1));
    addTail(dsSV, createNode(sv2));
    addTail(dsSV, createNode(sv3));
    addTail(dsSV, createNode(sv4));
    addTail(dsSV, createNode(sv5));
    addTail(dsSV, createNode(sv6));
    cout << "Cau2. Xuat danh sach sinh vien" << endl;
    xuat(dsSV);
    cout << "Cau3. Tim SV" << endl;
    cout << "Ket qua: " << timSV(dsSV, 127) << endl;
    cout << "Ket qua: " << timSV(dsSV, 999) << endl;
    cout << "Cau4. Dem sinh co diem duoi trung binh" << endl;
    cout << "Ket qua: " << demSV(dsSV, 5) << endl;
    cout << "Cau5. Diem trung binh lop hoc" << endl;
    cout << "Ket qua: " << diemTB(dsSV) << endl;
    cout << "Cau6. Ma sv co diemMH lon nhat" << endl;
    cout << "Ket qua: " << maxSV(dsSV) << endl;
    cout << "Cau7. Cac ma sv co diem mon hoc tren 8" << endl;
    arrayPoint = timCacMaSV(dsSV, 8);
    for (int i = 0; i < demSV(dsSV, 8); i++)
    {
        cout << *(arrayPoint + i) << "\t";
    }
    cout << endl;
    cout << "Cau8. cap nhat diem mon hoc theo ma sv" << endl;
    bool result8 = updateSV(dsSV, 123, 10);
    if (result8)
    {
        cout << "Danh sach sinh vien da cap nhat diem: ";
        xuat(dsSV);
    }
    else
    {
        cout << "Khong tim thay sinh vien" << endl;
    }
    cout << "Cau9. Viet ham sao chep cac sv sang danh sach moi" << endl;
    cout << "Ket qua: " << endl;
    List copyFromList;
    copyFromList = copyList(dsSV);
    xuat(copyFromList);

    return 0;
}
