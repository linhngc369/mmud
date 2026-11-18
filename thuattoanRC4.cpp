#include <bits/stdc++.h> 
using namespace std;

// 1. Ham tao mang hoan vi S (Buoc KSA - Key-Scheduling Algorithm trong RC4)
// Muc dich: Khoi tao mang S gom 256 phan tu (tu 0 den 255) va xao tron mang S dua tren khoa K
void MangHoanVi(const string& K, vector<char>& S) {
    int n = K.length(); // Lay do dai cua khoa K
    
    // Khoi tao gia tri ban dau cho mang S: S[0] = 0, S[1] = 1, ..., S[255] = 255
    for (int i = 0; i < 256; i++) {
        S[i] = (char)i;
    }

    // Xao tron mang S dua vao tung ky tu cua khoa K
    int j = 0;
    for (int i = 0; i < 256; i++) {
        // Ep kieu (unsigned char) de tranh gia tri am khi chuyen doi ma ASCII
        j = (j + (unsigned char)S[i] + (unsigned char)K[i % n]) % 256;
        swap(S[i], S[j]); // Hoan doi vi tri hai phan tu S[i] va S[j]
    }
}

// 2. Ham ma hoa va giai ma RC4 (Buoc PRGA - Pseudo-Random Generation Algorithm)
// P: Van ban dau vao (co the la ban ro de ma hoa, hoac ban ma de giai ma)
// K: Khoa bi mat
string RC4(const string& P, const string& K) {
    vector<char> S(256); // Khai bao vector S kich thuoc 256 byte
    MangHoanVi(K, S);    // Goi ham tao mang hoan vi S tu khoa K

    int f = 0;           // Chi so i trong thuat toan chuan (dat ten la f de tranh trung bien vong lap)
    int j = 0;
    string kq = P;       // Chuoi ket qua, khoi tao bang P de co cung do dai

    // Lap qua tung ky tu cua chuoi dau vao P
    for (size_t i = 0; i < P.length(); i++) {
        f = (f + 1) % 256;
        j = (j + (unsigned char)S[f]) % 256;

        swap(S[f], S[j]); // Tiep tuc hoan doi vi tri trong mang S de tao tinh ngau nhien

        // Tinh chi so iK de lay ra 1 byte khoa (keystream) tu mang S
        int iK = ((unsigned char)S[f] + (unsigned char)S[j]) % 256;
        char byte_khoa = S[iK];

        // Thuc hien phep XOR (^) tung ky tu cua P voi byte_khoa vua sinh ra
        kq[i] = P[i] ^ byte_khoa;
    }
    return kq; // Tra ve chuoi sau khi ma hoa (hoac giai ma)
}

int main() {
    // Nhap ban ro P (dung getline de doc duoc ca dau cach)
    string P;
    cout << "Nhap P: "; 
    getline(cin, P);

    // Nhap khoa bi mat K
    string K;
    cout << "Nhap K: "; 
    getline(cin, K);

    // In lai ban ro P va khoa K vua nhap
    cout << "P: " << P << endl;
    cout << "K: " << K << endl;

    // Ma hoa: Goi ham RC4 voi ban ro P va khoa K de tao ra ban ma c
    string c = RC4(P, K);
    cout << "C: " << c << endl;

    // Giai ma: Goi lai chinh ham RC4 voi ban ma c va khoa K (vi (P ^ K) ^ K = P)
    string p = RC4(c, K);
    cout << "P: " << p << endl;

    return 0;
}

