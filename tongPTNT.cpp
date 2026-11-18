//--------------------Tinh tong cac phan tu nguyen thuy----------------------
#include <iostream>
#include <cmath>
using namespace std;

int mu(int a, int m, int p) {
    int b = 1;
    for (int i = 1; i <= m; i++) {
        b = (b * a) % p;
    }
    return b;
}

bool ktra(int n){
 if(n<2) return false;
 for(int i=2;i<=sqrt(n);i++){
  if(n%i==0) return false ;
 }
 return true;
}

int main() {
    int p;
    do {
  cout<<"Nhap P = ";
  cin>>p;
 }while(!ktra(p));
    
    cout << "Cac phan tu nguyen thuy cua " << p << " la: ";
    int demPTNT = 0;
    int tong = 0; // Them bien tinh tong
    
    for (int a = 1; a < p; a++) {
        int dem = 0;
        for (int i = 2; i < p; i++) {
            if (mu(a, i, p) == a) {
                dem++;
            }
        }
        if (dem == 0) {
            cout << a << " ";
            demPTNT++;
            tong = tong + a; // Cong don phan tu nguyen thuy tim duoc
        }
    }
    
    cout << "\nSo phan tu nguyen thuy la: " << demPTNT;
    cout << "\nTong cac phan tu nguyen thuy la: " << tong;
    cout << endl;
    return 0;
}
