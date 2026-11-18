/*Bai tap 2: Lap trinh nhap chuoi plaintext P va chuoi khoa K tu ban phim 
Ma hoa chuoi P bang thuat toan RC4. Hien chuoi ma hoa ra man hinh
Giai ma va hien ket qua ra man hinh*/
#include<iostream>
using namespace std;
int main(){
	unsigned char T[256],S[256];
	string K,P,C; int i,j,k,t;
	cout<<"Nhap chuoi plaintext = "; getline(cin,P);
	/*Khoi tao*/
	cout<<"Nhap K = "; getline(cin,K);
	for(i=0 ;i<=255; i++){
		T[i] = (unsigned char)K[i % K.size()];
		S[i] = i;
	}
	//Tao chuoi S gia ngau nhien
	j = 0;
	for (i = 0; i<=255;i++){
		j = (j + S[i] + T[i]) % 256;
		swap (S[i] , S[j]);
	}
	/*Sinh khoan luong*/
	i,j=0;
	for (int x=0 ;x<P.size(); x++){
		i = (i + 1) % 256;
		j = (j + S[i]) % 256;
		swap (S[i] , S[j]);
		t = (S[i] + S[j]) % 256;
		k = S[t];
		char h=P[x]^k;
		C=C+h;
	}
	cout <<"Chuoi ma hoa : "<<C;
	
	//Giai ma
	/*Khoi tao*/
	for(i=0 ;i<=255; i++){
		T[i] = (unsigned char)K[i % K.size()];
		S[i] = i;
	}
	//Tao chuoi S gia ngau nhien
	j = 0;
	for (i = 0; i<=255;i++){
		j = (j + S[i] + T[i]) % 256;
		swap (S[i] , S[j]);
	}
	/*Sinh khoan luong*/
	i,j=0; P="";
	for (int x=0 ;x<C.size(); x++){
		i = (i + 1) % 256;
		j = (j + S[i]) % 256;
		swap (S[i] , S[j]);
		t = (S[i] + S[j]) % 256;
		k = S[t];
		char h=C[x]^k;
		P=P+h;
	}
	cout<<endl <<"Chuoi ma hoa : "<<P; 
}
