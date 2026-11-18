#include <iostream> 
#include <cmath>    

using namespace std;

// 1. Ham tinh Uoc chung lon nhat (UCLN) bang thuat toan Euclid
// Muc dich: Dung de kiem tra xem hai so co nguyen to cung nhau hay khong (UCLN == 1)
long long ucln(long long a, long long b) {
    while (b != 0) {
        long long temp = a % b; // Luu so du cua phep chia a cho b
        a = b;                  // Gan b cho a
        b = temp;               // Gan so du cho b, lap lai den khi b = 0
    }
    return a; // Tra ve ket qua UCLN
}

// 2. Ham tim nghich dao modulo (d) cua a theo modulo mod
// Tim x sao cho: (a * x) % mod == 1
long long modInverse(long long a, long long mod) {
    for (long long x = 1; x < mod; x++) {
        if ((a * x) % mod == 1) {
            return x; // Tim thay so x thoa man thi tra ve ngay
        }
    }
    return -1; // Tra ve -1 neu khong ton tai nghich dao modulo
}

// 3. Ham tinh luy thua modulo: (cs ^ sm) % mod
// Su dung thuat toan Binh phuong va Nhan de tinh nhanh voi so mu lon, tranh tran so
// cs: co so (ban ro P hoac ban ma C)
// sm: so mu (khoa cong khai e hoac khoa bi mat d)
long long powerMod(long long cs, long long sm, long long mod) {
    long long result = 1;
    cs = cs % mod; // Thu gon co so truoc khi tinh

    while (sm > 0) {
        // Neu bit cuoi cung cua so mu sm la 1 (tuc la sm le)
        if (sm % 2 == 1) {
            result = (result * cs) % mod; // Nhan don co so vao ket qua va chia lay du
        }
        sm = sm >> 1;          // Dich bit sang phai 1 don vi (tuong duong phep chia nguyen sm = sm / 2)
        cs = (cs * cs) % mod;  // Binh phuong co so len va chia lay du cho vong lap tiep theo
    }

    return result;
}

int main() {
    // Khai bao cac bien theo chuan he mat ma RSA (dung long long de chua so nguyen lon)
    // p, q: hai so nguyen to | n: modulo cong khai | phi: gia tri ham Phi Euler
    // e: so mu cong khai | d: so mu bi mat | k: bien du (khong dung trong code)
    // P: Ban ro (Plaintext) | C: Ban ma (Ciphertext) | D: Ban giai ma (Decrypted text)
    long long p, q, n, phi, e, k, d, P, C, D;

    // BUOC 1: Nhap 2 so nguyen to p va q
    cout << "Nhap p,q: "; 
    cin >> p >> q;

    // BUOC 2: Tinh n va ham Phi Euler phi(n)
    n = p * q;
    phi = (p - 1) * (q - 1);

    // BUOC 3: Chon so mu cong khai e
    // Dieu kien: 1 < e < phi va e nguyen to cung nhau voi phi (tuc la ucln(e, phi) == 1)
    e = 2;
    while (e < phi) {
        if (ucln(e, phi) == 1) break; // Tim thay so e nho nhat thoa man thi dung vong lap
        e++;
    }

    cout << "e: " << e << endl;

    // BUOC 4: Tinh so mu bi mat d (la nghich dao modulo cua e theo mod phi)
    d = modInverse(e, phi);

    // In ra cac thong so cua bo khoa RSA vua tao
    cout << "So nguyen to p = " << p << ", q = " << q << endl;
    cout << "Modulo n = " << n << endl;
    cout << "Ham Phi Euler phi(n) = " << phi << endl;
    cout << "Khoa cong khai: (e,n) = (" << e << "," << n << ")" << endl;
    cout << "Khoa bi mat   : (d,n) = (" << d << "," << n << ")" << endl;

    // BUOC 5: Nhap thong diep can ma hoa (P phai la so nguyen nho hon n)
    cout << "Nhap P: "; 
    cin >> P;

    // BUOC 6: Thuc hien ma hoa va giai ma
    C = powerMod(P, e, n); // Cong thuc ma hoa RSA: C = (P ^ e) mod n
    D = powerMod(C, d, n); // Cong thuc giai ma RSA: D = (C ^ d) mod n (Ket qua D phai bang lai P ban dau)

    // In ket qua sau cung
    cout << "P = " << P << endl;
    cout << "C = " << C << endl;
    cout << "D = " << D << endl;

    return 0;
}
