
#include<bits/stdc++.h>
using namespace std;

long long powerMod(long long a, long long n, long long p){
    long long res = 1;
    a = a % p;

    while(n > 0){
        if(n % 2 == 1)
            res = res * a % p;

        a = a * a % p;
        n = n >> 1;
    }

    return res;
}

int main(){
    long long p;
    cout << "Nhap so nguyen to p: ";
    cin >> p;

    cout << "Cac phan tu nguyen thuy cua " << p << " la: ";

    for(int a = 2; a < p; a++){
        bool nguyenThuy = true;

        for(int k = 1; k < p - 1; k++){
            if(powerMod(a, k, p) == 1){
                nguyenThuy = false;
                break;
            }
        }

        if(nguyenThuy)
            cout << a << " ";
    }

    return 0;
}

