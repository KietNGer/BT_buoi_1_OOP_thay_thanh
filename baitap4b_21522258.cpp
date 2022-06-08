#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct HocSinh
{
    char cHoVaTen[30];
    double iDiemToan;
    double iDiemVan;
};

void nhap(HocSinh &HS)
{
    cout << "-Nhap ho va ten cua hoc sinh: ";
    fflush(stdin);
    gets(HS.cHoVaTen);
    cout << "-Nhap diem toan cua hoc sinh: ";
    cin >> HS.iDiemToan;
    cout << "-Nhap diem van cua hoc sinh: ";
    cin >> HS.iDiemVan;
}

void Tinh_diem_trung_binh_cua_hoc_sinh(HocSinh HS)
{
    double s=0;
    s = (1.0 * (HS.iDiemToan + HS.iDiemVan)) / 2;
    cout << "\nDiem trung binh cua hoc sinh do la: " << s;
}

int main()
{
    HocSinh HS;
    nhap(HS);
    Tinh_diem_trung_binh_cua_hoc_sinh(HS);
    return 0;
}
