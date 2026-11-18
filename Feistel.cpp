
// feistel 2 lop
#include <iostream>
#include <string>
using namespace std;

// Ham F thuc hien phep cong giua R_{i-1} va K_i
char F(char R, char K) {
    return R + K;
}

int main() {
    string P;
    char K[10];     // Mang chua khoa ban dau va cac khoa con
    char L[10], R[10];
    char C[2];      // Chua 2 ky tu cua khoi Ciphertext

    cout << "Nhap khoi plaintext: "; 
    getline(cin, P);
    
    cout << "Nhap khoa K: "; 
    cin >> K[0];

    // Gan 2 nua khoi plaintext ban dau
    L[0] = P[1];
    R[0] = P[0];

    int n = 2; // 2 vong Feistel
    for (int i = 1; i <= n; i++) {
        // Dich xoay vong K[0] i lan
        K[i] = K[0] << i;
        
        R[i] = L[i - 1] ^ F(R[i - 1], K[i]);
        L[i] = R[i - 1];
    }

    // Ghep ket qua thanh khoi Ciphertext
    C[0] = L[n];
    C[1] = R[n];

    // Xuat ket qua
    cout << "Ciphertext: " << C[0] << C[1] << endl;

    return 0;
}
