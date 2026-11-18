//Lap trinh nhap chuoi P và chuỗi khóa K từ bàn phím. Mã hóa và giải mã bằng thuật toán RC4 in ra màn hình kết quả
#include <iostream>
#include <string>
using namespace std;

int main() {
    unsigned char T[256], S[256];
    string K, P; 
    int i, j, k, t;
    string C = "";

    // Nhap du lieu
    cout << "Nhap Chuoi Plaintext : ";
    getline(cin, P);
    cout << "Nhap K : ";
    getline(cin, K);

    // --- KSA (Key-Scheduling Algorithm) ---
    for (int idx = 0; idx <= 255; idx++) {
        T[idx] = (unsigned char)K[idx % K.size()];
        S[idx] = idx;
    }
    j = 0;
    for (i = 0; i <= 255; i++) {
        j = (j + S[i] + T[i]) % 256;
        swap(S[i], S[j]);
    }

    // --- Ma hoa (PRGA) ---
    i = 0; 
    j = 0;
    for (int x = 0; x < P.size(); x++) { // Sua <= thanh <
        i = (i + 1) % 256; 
        j = (j + S[i]) % 256;
        swap(S[i], S[j]);
        t = (S[j] + S[i]) % 256;
        k = S[t];
        char h = P[x] ^ k;
        C = C + h;
    }
    cout << endl;
    cout << "Chuoi Ma Hoa : " << C;

    // --- QUAN TRONG: Chay lai KSA truoc khi giai ma de dua mang S ve trang thai ban dau ---
    for (int idx = 0; idx <= 255; idx++) {
        T[idx] = (unsigned char)K[idx % K.size()];
        S[idx] = idx;
    }
    j = 0;
    for (i = 0; i <= 255; i++) {
        j = (j + S[i] + T[i]) % 256;
        swap(S[i], S[j]);
    }

    // --- Giai ma (PRGA) ---
    i = 0; 
    j = 0; 
    P = "";
    for (int x = 0; x < C.size(); x++) { // Sua <= thanh <
        i = (i + 1) % 256; 
        j = (j + S[i]) % 256;
        swap(S[i], S[j]);
        t = (S[j] + S[i]) % 256;
        k = S[t];
        char h = C[x] ^ k;
        P = P + h;
    }
    cout << endl;
    cout << "Chuoi Giai Ma : " << P;

    return 0;
}
