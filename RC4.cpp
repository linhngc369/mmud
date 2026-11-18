
#include <bits/stdc++.h>
using namespace std;

void MangHoanVi(const string& K, vector<char>& S) {
    int n = K.length();

    for (int i = 0; i < 256; i++) {
        S[i] = (char)i;
    }

    int j = 0;
    for (int i = 0; i < 256; i++) {
        j = (j + (unsigned char)S[i] + (unsigned char)K[i % n]) % 256;
        swap(S[i], S[j]);
    }
}

string RC4(const string& P, const string& K) {
    vector<char> S(256);
    MangHoanVi(K, S);

    int f = 0;
    int j = 0;
    string kq = P;

    for (size_t i = 0; i < P.length(); i++) {
        f = (f + 1) % 256;
        j = (j + (unsigned char)S[f]) % 256;

        swap(S[f], S[j]);

        int iK = ((unsigned char)S[f] + (unsigned char)S[j]) % 256;
        char byte_khoa = S[iK];

        kq[i] = P[i] ^ byte_khoa;
    }

    return kq;
}

int main() {
    string P;
    cout<<"Nhap P: "; getline(cin,P);
    string K;
    cout<<"Nhap K: "; getline(cin,K);

    cout << "P: " << P << endl;
    cout << "K: " << K << endl;

    string c = RC4(P, K);
    cout << "C: " << c << endl;

    string p = RC4(c, K);
    cout << "P: " << p << endl;

    return 0;
}

