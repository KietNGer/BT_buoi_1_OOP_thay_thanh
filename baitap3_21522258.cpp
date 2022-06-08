#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct PhanSo
{
    int iTuSo;
    int iMauso;
};

void Nhap_phan_so(PhanSo &PS)
{
    cout << "-Nhap tu so: ";
    cin >> PS.iTuSo;
    cout << "-Nhap mau so: ";
    cin >> PS.iMauso;
}

PhanSo Chinh_sua_phan_so(PhanSo a)
{
    if(a.iMauso < 0)
    {
        a.iMauso *= -1;
        a.iTuSo *= -1;
    }
    return a;
}

void Xuat_phan_so(PhanSo PS)
{
    cout << PS.iTuSo << "/" << PS.iMauso << endl;
}

//a) Rut gon phan so

int Tim_UCLN(int a, int b)
{
    if(a < 0)
        a *= -1;
    if(b < 0)
        b *= -1;
    if(a == 0 && b != 0)
    {
        return b;
    }
    if(a != 0 && b == 0)
    {
        return a;
    }
    while(a != b)
    {
        if(a > b)
            a -= b;
        else if(b > a)
            b -= a;
    }
    return a;
}

int Rut_gon_phan_so(PhanSo &PS)
{
    int ok = 3;
    if(PS.iMauso == 0) 
    {
        ok = 0;
    }
    else if(PS.iTuSo == 0)
    {
        ok = 1;
    }
    else if(PS.iTuSo != 0 && PS.iMauso != 0)
    {
        ok = 2;
    }
    return ok;
}

//b) Tim phan so lon nhat va xuat ket qua

PhanSo Tim_phan_so_lon_nhat(PhanSo a, PhanSo b)
{
    PhanSo c;
    if((a.iTuSo*b.iMauso) == (a.iMauso*b.iTuSo))
    {
        return a;
    }
    else if((a.iTuSo*b.iMauso) > (a.iMauso*b.iTuSo))
    {
        c = a;
    }
    else if((a.iTuSo*b.iMauso) < (a.iMauso*b.iTuSo))
    {
         c = b;
    }
    return c;
}

//c) Tinh tong, hieu, tich, thuong cua hai phan so

PhanSo Tong_hai_phan_so(PhanSo a, PhanSo b)
{
    PhanSo d;
    d.iTuSo = a.iTuSo*b.iMauso + b.iTuSo*a.iMauso;
    d.iMauso = a.iMauso*b.iMauso;
    return d;
}

PhanSo Hieu_hai_phan_so(PhanSo a, PhanSo b)
{
    PhanSo e;
    e.iTuSo = a.iTuSo*b.iMauso - b.iTuSo*a.iMauso;
    e.iMauso = a.iMauso*b.iMauso;
    return e;
}

PhanSo Tich_hai_phan_so(PhanSo a, PhanSo b)
{
    PhanSo f;
    f.iTuSo = a.iTuSo*b.iTuSo;
    f.iMauso = a.iMauso*b.iMauso;
    return f;
}

PhanSo Thuong_hai_phan_so(PhanSo a, PhanSo b)
{
    PhanSo g;
    g.iTuSo = a.iTuSo*b.iMauso;
    g.iMauso = a.iMauso*b.iTuSo;
    return g;
}

int main()
{
    PhanSo PS1;
    PhanSo PS2;
    PhanSo PS3;
    PhanSo PS4;
    PhanSo PS5;
    cout << "a/ Rut gon phan so va xuat ra ket qua: \n";
    Nhap_phan_so(PS1);
    Chinh_sua_phan_so(PS1);
    cout << "Ket qua sau khi rut gon phan so la: ";
    if(Rut_gon_phan_so(PS1) == 0)
    {
        cout << "Khong ton tai phan so\n";
    }
    else if(Rut_gon_phan_so(PS1) == 1)
    {
        cout << "0\n";
    }
    else if(Rut_gon_phan_so(PS1) == 2)
    {
        int UCLN = Tim_UCLN(PS1.iTuSo, PS1.iMauso);
        PS1.iTuSo = PS1.iTuSo / UCLN;
        PS1.iMauso = PS1.iMauso / UCLN;
        cout << PS1.iTuSo << "/" << PS1.iMauso << endl;
    }
    cout << "\nb/ Phan so lon nhat trong hai phan so la: \n";
    cout << "Nhap phan so thu nhat: \n";
    Nhap_phan_so(PS2);
    cout << "Nhap phan so thu hai: \n";
    Nhap_phan_so(PS3);
    cout << "Phan so lon nhat la: ";
    Xuat_phan_so(Tim_phan_so_lon_nhat(Chinh_sua_phan_so(PS2), Chinh_sua_phan_so(PS3)));
    cout << "\nc/ Tinh tong hieu tich thuong cua hai phan so: \n";
    cout << "Nhap phan so thu nhat: \n";
    Nhap_phan_so(PS4);
    cout << "Nhap phan so thu hai: \n";
    Nhap_phan_so(PS5);
    cout << "Tong hai phan so la: ";
    PhanSo PS6 = Tong_hai_phan_so(Chinh_sua_phan_so(PS4), Chinh_sua_phan_so(PS5));
    Xuat_phan_so(PS6);
    cout << "Hieu hai phan so la: ";
    PhanSo PS7 = Hieu_hai_phan_so(Chinh_sua_phan_so(PS4), Chinh_sua_phan_so(PS5));
    Xuat_phan_so(PS7);
    cout << "Tich hai phan so la: ";
    PhanSo PS8 = Tich_hai_phan_so(Chinh_sua_phan_so(PS4), Chinh_sua_phan_so(PS5));
    Xuat_phan_so(PS8);
    cout << "Thuong hai phan so la: ";
    PhanSo PS9 = Thuong_hai_phan_so(Chinh_sua_phan_so(PS4), Chinh_sua_phan_so(PS5));
    Xuat_phan_so(PS9);
    return 0;
}
