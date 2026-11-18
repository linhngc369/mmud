
#include <iostream>
#include <cmath>

using namespace std;


long long ucln(long long a, long long b) {
    while (b != 0) {
        long long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}


long long modInverse(long long a, long long mod){
    for (long long x = 1; x < mod; x++){
        if((a * x) % mod == 1){
            return x;
        }
    }
    return -1;
}


long long powerMod(long long cs, long long sm, long long mod) {
    long long result = 1;
    cs = cs % mod;

    while (sm > 0) {
        if (sm % 2 == 1) {
            result = (result * cs) % mod;
        }
        sm = sm >> 1;
        cs = (cs * cs) % mod;
    }

    return result;
}

int main() {
    long long p,q,n,phi,e,K,d,P,C,D;

    cout<<"Nhap p,q: "; cin>>p>>q;
    n = p * q;
    phi = (p - 1) * (q - 1);
    e = 2;

    while (e < phi) {
        if (ucln(e, phi) == 1) break;
        e++;
    }

    cout<<"e: "<<e<<endl;
    d = modInverse(e, phi);

    cout << "So nguyen to p = " << p << ", q = " << q << endl;
    cout << "Modulo n = " << n << endl;
    cout << "Ham Phi Euler phi(n) = " << phi << endl;
    cout << "Khoa cong khai: (e,n) = (" << e << "," << n << ")" << endl;
    cout << "Khoa bi mat: (d,n) = (" << d << "," << n << ")" << endl;

    cout<<"Nhap P: "; cin>>P;

    C = powerMod(P, e, n);
    D = powerMod(C, d, n);

    cout << "P = " << P << endl;
    cout << "C = " << C << endl;
    cout << "D = " << D << endl;

    return 0;
}

