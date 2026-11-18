#include<bits/stdc++.h> // Thu vien tong hop trong C++ (ho tro cin, cout...)
using namespace std;

int main(){
    // Khai bao cac bien cho duong cong Elliptic: y^2 = x^3 + ax + b (mod p)
    // a: tham so cua duong cong | p: so nguyen to modulo
    // xp, yp: toa do diem P | xq, yq: toa do diem Q (voi P != Q)
    int a, p, xp, yp, xq, yq;
    
    // L: he so goc lambda | TS: tu so | MS: mau so | MS1: nghich dao modulo cua mau so
    int L, TS, MS, MS1;
    
    // xr, yr: toa do diem ket qua R = P + Q
    int xr, yr;

    // Nhap tham so a, modulo p va toa do 2 diem P(xp, yp), Q(xq, yq)
    cout << "Nhap a, p:";
    cin >> a >> p;
    cout << "Nhap xp, yp: ";
    cin >> xp >> yp;
    cout << "Nhap xq,yq: ";
    cin >> xq >> yq;

    // BUOC 1: Tinh tu so (TS) va mau so (MS) cua he so goc duong thang di qua P va Q
    // Cong thuc he so goc cong 2 diem khac nhau: lambda = (yq - yp) / (xq - xp) mod p
    TS = (yq - yp + p) % p; // Cong them p de tranh phep tru ra so am
    MS = (xq - xp + p) % p;

    // BUOC 2: Tim nghich dao modulo cua MS theo modulo p (luu vao MS1)
    // Tim i sao cho (i * MS) % p == 1
    for(int i = 1; i < p; i++){
        if((i * MS) % p == 1){
            MS1 = i;
            break;
        }
    }

    // BUOC 3: Tinh he so goc lambda: L = (TS * MS^-1) mod p
    L = TS * MS1 % p;

    // BUOC 4: Tinh hoanh do xr cua diem R = P + Q
    // Cong thuc: xr = (lambda^2 - xq - xp) mod p
    xr = (L * L - xq - xp + p + p) % p;
    if(xr < 0) // Chuan hoa ket qua ve khoang [0, p - 1] neu bi am
        xr += p;

    // BUOC 5: Tinh tung do yr cua diem R = P + Q
    // Cong thuc: yr = (lambda*(xp - xr) - yp) mod p
    yr = (L * (xp - xr + p) - yp + p) % p;
    if(yr < 0) // Chuan hoa ket qua ve khoang [0, p - 1] neu bi am
        yr += p;

    // In ra toa do diem ket qua R = P + Q = (xr, yr)
    cout << "R = P+Q = (" << xr << "," << yr << ")";
    return 0;
}
