//Bai 1: Lập trình mô phỏng các phương pháp mã hóa/ giải mã 3 cấp sử dụng thuật toán Feistel đơn giản (3DES // EEE)
#include <iostream>
using namespace std ;
char F (char R , char Ki){
	return R + Ki ;
}
string E(char k , string P){
	char L[3],R[3],K[3];
	string C = "xx";
	R[0]=P[0];
	L[0]=P[1];
	K[0]=k;
	int n = 2 ;
	for (int i=1 ; i<=n ; i++){
		K[i]=K[0]<<i;
		R[i]=L[i-1]^F(R[i-1],K[i]);
		L[i]=R[i-1];
	} 
	C[0]=L[n];
	C[1]=R[n];
	return C;
}
string D(char k , string C){
	char L[3],R[3],K[3];
	string P="xx";
	int n = 2 ;
	R[n]=C[1];
	L[n]=C[0];
	K[0]=k;
	for (int i = n ; i>=1 ; i--){
		K[i]=K[0]<<i;
		R[i-1]=L[i];
		L[i-1]=R[i]^F(L[i],K[i]);
		
	} 
	P[1]=L[0];
	P[0]=R[0];
	return P;
}
 int main (){
 	string P , C = "xx" ; char K1,K2,K3;
 	cout<<"Nhap Mot Khoi plaintext: " ; getline(cin,P);
 	cout<<"Nhap Khoa K1 : " ; cin>>K1;
 	cout<<"Nhap Khoa K2 : " ; cin>>K2;
 	cout<<"Nhap Khoa K3 : " ; cin>>K3;
 	//ma hoa
 	C=E(K1,P);
 	C=E(K2,C);
 	C=E(K3,C);
 	cout<<"Ciphertext : "<<C<<endl;
 	//giai ma 
 	P=D(K3,C);
 	P=D(K2,P);
 	P=D(K1,P);
 	cout<<"Plaintext : "<<P;


 }
