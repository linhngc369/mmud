//--------------------Tim phan tu nguyen thuy lon nhat, nho nhat----------------------
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
    int minPTNT = 0, maxPTNT = 0; // Them 2 bien luu min, max
    
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
            
            if (demPTNT == 1) {
                minPTNT = a; // So dau tien tim duoc luon la nho nhat
            }
            maxPTNT = a; // Cap nhat lien tuc den so cuoi cung se la lon nhat
        }
    }
    
    cout << "\nSo phan tu nguyen thuy la: " << demPTNT;
    if (demPTNT > 0) {
        cout << "\nPhan tu nguyen thuy nho nhat la: " << minPTNT;
        cout << "\nPhan tu nguyen thuy lon nhat la: " << maxPTNT;
    }
    cout << endl;
    return 0;
}
