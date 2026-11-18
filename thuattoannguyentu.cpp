#include<bits/stdc++.h> // Thu vien tong hop trong C++ (ho tro cin, cout...)
using namespace std;

// 1. Ham tinh luy thua modulo: (a ^ m) % p
// a: co so, m: so mu, p: modulo (thuong la so nguyen to)
int mu(int a, int m, int p){
    int b = 1; // Khoi tao bien ket qua b = 1
    // Lap m lan, moi lan nhan b voi a roi chia lay du cho p de tranh tran so
    for(int i = 1; i <= m; i++) b = b * a % p;
    return b; // Tra ve gia tri (a ^ m) % p
}

int main(){
    int p; // Khai bao so nguyen to p
    cout << "Nhap p = "; 
    cin >> p; // Nhap gia tri p tu ban phim

    // Vong lap ngoai: duyet cac co so a tu 1 den p - 1
    for(int a = 1; a < p; a++){
        // Vong lap trong: duyet cac so mu i tu 1 den p - 1
        for(int i = 1; i < p; i++){
            // Tinh va in ra gia tri (a ^ i) % p, cach nhau bang dau tab (\t)
            cout << mu(a, i, p) << "\t";
        }
        cout << endl; // Xuong dong sau khi in xong toan bo luy thua cua mot so a
    }
}

