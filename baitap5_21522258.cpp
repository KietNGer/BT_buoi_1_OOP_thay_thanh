#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct NhanVien
{
    char cMaNhanVien[8];
    char cHoVaTen[20];
    char cPhongBan[10];
    int iLuongCoBan;
    int iThuong;
    int iThucLanh;
};

void nhap(NhanVien NV[], int &n)
{
    cout << "Nhap so luong nhan vien can luu thong tin: ";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cout << "Nhap nhan vien thu " << i+1 << " :\n";
        cout << "-Nhap ma nhan vien: ";
        fflush(stdin);
        gets(NV[i].cMaNhanVien);
        cout << "-Nhap ho va ten nhan vien: ";
        fflush(stdin);
        gets(NV[i].cHoVaTen);
        cout << "-Nhap phong ban nhan vien do dang cong tac: ";
        fflush(stdin);
        gets(NV[i].cPhongBan);
        cout << "-Luong co ban cua nhan vien do la: ";
        cin >> NV[i].iLuongCoBan;
        cout << "-So tien thuong cua nhan vien: ";
        cin >> NV[i].iThuong;
    }
    cout << "\n";
}

void in_ra_danh_sach_NV(NhanVien NV[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "-Ma nhan vien: " << NV[i].cMaNhanVien;
        cout << "\n-Ho va ten nhan vien: " << NV[i].cHoVaTen;
        cout << "\n-Phong ban nhan vien do dang cong tac: " << NV[i].cPhongBan;
        cout << "\n-Luong co ban cua nhan vien do la: " << NV[i].iLuongCoBan;
        cout << "\n-So tien thuong cua nhan vien: " << NV[i].iThuong;
        cout << "\n-Thuc lanh cua nhan vien do: " << NV[i].iLuongCoBan + NV[i].iThuong << endl;
        cout << endl;
    }
}

void Tong_thuc_lanh_cua_tat_ca_NV(NhanVien NV[], int n)
{
    int sum=0;
    long total=0;
    cout << "Thuc lanh cua cac nhan vien: \n";
    for(int i = 0; i < n; i++)
    {
        sum = NV[i].iLuongCoBan + NV[i].iThuong;
        cout << "-Thuc lanh cua nhan vien thu " << i+1 << " la: " << NV[i].iLuongCoBan + NV[i].iThuong << endl;
        total += sum;
    }
    cout << "Tong thuc lanh cua tat ca nhan vien la: " << total;
}

int tim_luong_co_ban_thap_nhat(NhanVien NV[], int n)
{
    int min = NV[0].iLuongCoBan;
    for(int i = 0; i < n; i++)
    {
        if(NV[i].iLuongCoBan < min)
            min = NV[i].iLuongCoBan;
    }
    return min;
}

void in_ra_nhan_vien_co_luong_co_ban_thap_nhat(NhanVien NV[], int n)
{
    cout << "\nDanh sach nhan vien co luong co ban thap nhat: \n";
    int luong_co_ban_thap_nhat = tim_luong_co_ban_thap_nhat(NV,n);
    for(int i = 0; i < n; i++)
    {
        if(NV[i].iLuongCoBan == luong_co_ban_thap_nhat)
        {
            cout << "-Ma nhan vien: " << NV[i].cMaNhanVien;
            cout << "\n-Ho va ten nhan vien: " << NV[i].cHoVaTen;
            cout << "\n-Phong ban nhan vien do dang cong tac: " << NV[i].cPhongBan;
            cout << "\n-Luong co ban cua nhan vien do la: " << NV[i].iLuongCoBan;
            cout << "\n-So tien thuong cua nhan vien: " << NV[i].iThuong;
            cout << "\n-Thuc lanh cua nhan vien do: " << NV[i].iLuongCoBan + NV[i].iThuong << endl;
            cout << endl;
        }
    }
}

void dem_so_luong_nhan_vien_co_muc_thuong_tren_1200000(NhanVien NV[], int n)
{
    int count=0;
    for(int i = 0; i < n; i++)
    {
        if(NV[i].iThuong >= 1200000)
            count++;
    }
    cout << "So luong nhan vien co muc thuong >= 1200000: " << count <<  endl;
}

void sap_xep(NhanVien NV[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(strcmp(NV[i].cPhongBan,NV[j].cPhongBan) == 0)
            {
                if(NV[i].cMaNhanVien < NV[j].cMaNhanVien)
                {
                    NhanVien c = NV[i];
                    NV[i] = NV[j];
                    NV[j] = c;
                }
            }
           else if(strcmp(NV[i].cPhongBan,NV[j].cPhongBan) != 0)
           {
               if(strcmp(NV[i].cPhongBan,NV[j].cPhongBan) > 0)
               {
                   NhanVien d = NV[i];
                    NV[i] = NV[j];
                    NV[j] = d;
               }
           }
        }
    }
}

int main()
{
    NhanVien NV[5];
    int n;
    nhap(NV, n);
    Tong_thuc_lanh_cua_tat_ca_NV(NV, n);
    cout << endl;
    in_ra_nhan_vien_co_luong_co_ban_thap_nhat(NV,n);
    dem_so_luong_nhan_vien_co_muc_thuong_tren_1200000(NV,n);
    cout << "\n";
    cout << "==Danh sach nhan vien==\n";
    sap_xep(NV, n);
    in_ra_danh_sach_NV(NV, n);
    return 0;
}
