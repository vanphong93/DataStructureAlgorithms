#include <iostream>
#include <time.h>
using namespace std;
// Câu 1   xây dựng cấu trúc dữ liệu sinh viên
struct student
{
    int id;
    string name;
    float gpa;
};
typedef student ST;
void xuat(ST ST)
{
    cout << "Thong tin sinh vien" << endl;
    cout << "\t+id : " << ST.id << endl;
    cout << "\t+name : " << ST.name << endl;
    cout << "\t+gpa : " << ST.gpa << endl;
}
// Câu 2     xay dung cau truc va cau truc danh sach lien ket don
struct node
{
    ST data;
    node *pnext;
};
struct List
{
    node *head;
    node *tail;
};
// câu 3 ham khoi tao danh sach lien ket don va ham khoi tao dia chi node
node *createNode(ST value)
{
    node *p = new node;
    if (p == NULL)
        return NULL;
    p->data = value;
    p->pnext = NULL;
    return p;
}
void createList(List &l)
{
    l.head = l.tail = NULL;
}
// câu 4 hàm thêm sinh viên vào đầu danh sách
void addHead(List &l, node *p)
{

    p->pnext = l.head; // noi moc dia chi
    l.head = p;        // di doi dia chi ve dau
}
// câu 5 hàm thêm sinh viên vào cuối danh sách
void addTail(List &l, node *p)
{

    l.tail->pnext = p;
    l.tail = p;
}
// cau 6 ham nhap danh sach sinh vien tu ban phim
void inputHandle(List &l, int &n)
{
    cout << "nhap so luong sinh vien n=";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ST data;
        cout << "nhap ten sinh vien khong khoang trang ";
        cin >> data.name;
        cout << "nhap diem gpa ";
        cin >> data.gpa;
        data.id = i + 1;
        addHead(l, createNode(data));
    }
};
// câu 8 viết hàm in danh sách sinh viên
void printList(List l)
{
    for (node *i = l.head; i != NULL; i = i->pnext)
    {
        xuat(i->data);
    }
    cout << endl;
}
// câu 7 hàm sinh viên theo phương pháp nhập tự động
void autoInput(List &lis)
{
    int n = 1 + rand() % 5;

    for (int i = 1; i <= n; i++)
    {
        string nameList[] = {"Tuan", "Nam", "Hai", "Vu", "Nhi"};
        string hoList[] = {"Nguyen", "Tran", "Huynh", "Pham", "Vo"};
        string demList[] = {"Nguyen", "Tran", "Huynh", "Pham", "Vo"};
        string fullName = hoList[rand() % 5] + " " + demList[rand() % 5] + " " + nameList[rand() % 5];
        ST ST;
        ST.gpa = rand() % 10 + (rand() % 11) / 10.0;
        ST.id = i;
        ST.name = fullName;
        addHead(lis, createNode(ST));
    }
}
// câu 9 viết hàm tìm kiếm sinh viên theo ID
node *timST(int Id, List lis)
{
    for (node *i = lis.head; i != NULL; i = i->pnext)
    {
        if (Id == i->data.id)
            return i;
    }
    return NULL;
}
// câu 8 viết hàm tìm kiếm sinh viên theo ten
node *findName(string name, List lis)
{
    for (node *i = lis.head; i != NULL; i = i->pnext)
    {
        if (name == i->data.name)
            return i;
    }
    return NULL;
}
// câu 11 viết hàm tìm kiếm sinh viên theo GPA
node *findGpa(float point, List lis)
{
    for (node *i = lis.head; i != NULL; i = i->pnext)
    {
        if (point == i->data.gpa)
        {
            return i;
        }
    }
    return NULL;
}
// câu 12 ham tim kiem sv diem gpa cao nhat
node *maxPoint(List lis)
{
    float maxPoint = 0;
    for (node *i = lis.head; i != NULL; i = i->pnext)
    {
        float temp = i->data.gpa;
        if (temp > maxPoint)
        {
            maxPoint = temp;
        }
    }
    for (node *i = lis.head; i != NULL; i = i->pnext)
    {
        if (maxPoint == i->data.gpa)
        {
            return i;
        }
    }
}
// câu 13 ham tim kiem sv diem gpa thap nhat
node *minPoint(List lis)
{
    float minPoint = 10;
    for (node *i = lis.head; i != NULL; i = i->pnext)
    {
        float temp = i->data.gpa;
        if (temp < minPoint)
        {
            minPoint = temp;
        }
    }
    for (node *i = lis.head; i != NULL; i = i->pnext)
    {
        if (minPoint == i->data.gpa)
        {
            return i;
        }
    }
}
int main()
{
    int n;
    srand(time(0));
    student ST1 = {1, "Nguyen Hai Phong", 3.4};
    student ST2 = {2, "Tran Thanh Nhan", 9};
    student ST3 = {3, "Le Viet Tien", 7};
    student ST4 = {4, "Pham Van Manh", 5};
    student ST5 = {5, "Tien Hai Dung", 9};
    List lis;
    List listAuto;
    List listHandle;
    createList(lis);
    addHead(lis, createNode(ST1));
    addHead(lis, createNode(ST2));
    addHead(lis, createNode(ST3));
    addHead(lis, createNode(ST4));
    addHead(lis, createNode(ST5));
    //   cout << "test 6 nhap sinh vien bang tay" << endl;
    // inputHandle(listHandle, n);
    // printList(listHandle);
    cout << "test 9 tim kiem sinh vien" << endl;
    node *idFind = timST(1, lis);
    if (idFind)
    {
        cout << "Sinh vien tim theo ID " << endl;
        xuat(idFind->data);
    }
    else
    {
        cout << "Khong co thong tin sinh vien" << endl;
    }

    cout << "test 10 tim kiem sinh vien theo ten" << endl;
    node *nameStu = findName("Pham Van Manh", lis);
    if (nameStu)
    {
        cout << "Sinh vien tim theo ten " << endl;
        xuat(nameStu->data);
    }
    else
    {
        cout << "Khong co thong tin sinh vien" << endl;
    }
    cout << "test 11 tim kiem sinh vien theo gpa" << endl;
    node *point = findGpa(9, lis);
    if (point)
    {
        cout << "Sinh vien tim theo gpa " << endl;
        xuat(point->data);
    }
    else
    {
        cout << "Khong co thong tin sinh vien" << endl;
    }
    cout << "test 12 tim kiem sinh vien diem cao nhat" << endl;
    node *max = maxPoint(lis);
    xuat(max->data);
    cout << "test 13 tim kiem sinh vien diem thap nhat" << endl;
    node *min = minPoint(lis);
    xuat(min->data);
    cout << "test 8 in danh sach sinh vien" << endl;
    printList(lis);
    cout << "test 7 nhap so sinh vien ngau nhien" << endl;
    autoInput(listAuto);
    printList(listAuto);
    return 0;
}
