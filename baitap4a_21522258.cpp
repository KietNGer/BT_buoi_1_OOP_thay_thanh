#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Date
{
    int iNgay;
    int iThang;
    int iNam;
};

bool Kiem_tra_nam_nhuan(Date D)
{
    if(((D.iNam % 4 == 0) && (D.iNam % 100 != 0)) || (D.iNam % 400 == 0))
        return true;
    else return false;
}

int Tim_so_ngay_trong_thang(Date D)
{
    int Ngay_trong_thang;
    switch(D.iThang)
    {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        Ngay_trong_thang = 31;
        break;
    case 4: case 6: case 9: case 11:
        Ngay_trong_thang = 30;
        break;
    case 2:
        if(Kiem_tra_nam_nhuan(D))
            Ngay_trong_thang = 29;
        else
            Ngay_trong_thang = 28;
    }
    return Ngay_trong_thang;
}

void Nhap_ngay(Date &D)
{
    do
    {
        cout << "-Nhap nam: ";
        cin >> D.iNam;
    }while(D.iNam < 1900 || D.iNam > 10000);

    do
    {
        cout << "-Nhap thang: ";
        cin >> D.iThang;
    }while(D.iThang < 1 || D.iThang > 12);

    do
    {
        cout << "-Nhap ngay: ";
        cin >> D.iNgay;
    }while(D.iNgay < 1 || D.iNgay > Tim_so_ngay_trong_thang(D));
}

void Xuat_ngay(Date D)
{
    cout << D.iNgay << "/" << D.iThang << "/" << D.iNam << endl;
}

Date Ngay_ke_tiep(Date D)
{
    if(D.iNgay < Tim_so_ngay_trong_thang(D))
        D.iNgay++;
    else if(D.iThang < 12)
    {
        D.iNgay = 1;
        D.iThang++;
    }
    else
    {
        D.iNgay = 1;
        D.iThang = 1;
        D.iNam++;
    }
    return D;
}

int main()
{
    Date D;
    Nhap_ngay(D);
    cout << "Ngay ke tiep la: ";
    Xuat_ngay(Ngay_ke_tiep(D));
    return 0;
}
