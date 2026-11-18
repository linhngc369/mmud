#include<bits/stdc++.h> // Thu vien tong hop trong C++ (ho tro cin, cout...)
using namespace std;

// 1. Ham tinh luy thua modulo: (a ^ n) % p
// Su dung thuat toan Binh phuong va Nhan de tinh nhanh va tranh tran so
// a: co so, n: so mu, p: modulo (so nguyen to)
long long powerMod(long long a, long long n, long long p){
    long long res = 1;
    a = a % p; // Thu gon co so a theo modulo p

    while(n > 0){
        if(n % 2 == 1) // Neu bit cuoi cung cua n la 1 (n le)
            res = res * a % p; // Nhan don co so a vao ket qua res va chia lay du cho p

        a = a * a % p; // Binh phuong co so a va chia lay du cho p
        n = n >> 1;    // Dich phai 1 bit (tuong duong phep chia nguyen n = n / 2)
    }

    return res; // Tra ve ket qua (a ^ n) % p
}

int main(){
    long long p; // Khai bao so nguyen to p
    cout << "Nhap so nguyen to p: ";
    cin >> p; // Nhap gia tri p tu ban phim

    cout << "Cac phan tu nguyen thuy cua " << p << " la: ";

    // Vong lap ngoai: duyet cac ung cu vien a tu 2 den p - 1
    for(int a = 2; a < p; a++){
        bool nguyenThuy = true; // Gia su ban dau a la phan tu nguyen thuy

        // Vong lap trong: kiem tra cac so mu k tu 1 den p - 2
        // Theo dinh ly Fermat nho, a^(p-1) % p == 1. Neu a la phan tu nguyen thuy thi
        // p - 1 phai la so mu duong nho nhat thoa man dieu kien nay.
        for(int k = 1; k < p - 1; k++){
            if(powerMod(a, k, p) == 1){ // Neu ton tai k < p - 1 ma (a ^ k) % p == 1
                nguyenThuy = false;     // Thi a khong phai la phan tu nguyen thuy
                break;                  // Dung kiem tra so a nay ngay lap tuc
            }
        }

        // Neu sau khi kiem tra het ma co nguyenThuy van la true thi in a ra man hinh
        if(nguyenThuy)
            cout << a << " ";
    }

    return 0;
}

