///Bai 2 Nhập một chuỗi plaintext từ bàn phím. Lập trình mã hóa chuỗi bằng TT Feistel. HIện chuỗi mã hõa/ giải mã (tách chuỗi thành từng khối 16bit rồi áp dụng thuật toán)
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
string EEE(char K1 , char K2, char K3, string P){
	string C ;
	C=E(K1,P);
 	C=E(K2,C);
 	C=E(K3,C);
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
string DDD(char K1 , char K2, char K3, string C){
	string P;
	P=D(K3,C);
 	P=D(K2,P);
 	P=D(K1,P);
 	return P;
}
 int main (){
 	string P , C ; char K1,K2,K3;
 	cout<<"Nhap Mot Khoi plaintext: " ; getline(cin,P);
 	cout<<"Nhap Khoa K1 : " ; cin>>K1;
 	cout<<"Nhap Khoa K2 : " ; cin>>K2;
 	cout<<"Nhap Khoa K3 : " ; cin>>K3;
 	if(P.size() %2 ==1) P=P+'X';
 	//ma hoa
 	for (int i =0 ; i< P.size() ; i += 2){
 		string t = "";
 		t=t+P[i]+P[i+1];
 		C=C+EEE(K1,K2,K3,t);
	 }
 	cout<<"Ciphertext : "<<C<<endl;
 	P="";
 	cout<<P<<endl;
 	//giai ma 
 	for (int i =0 ; i< C.size()  ; i += 2){
 		string t = "";
 		t=t+C[i]+C[i+1];
 		P=P+DDD(K1,K2,K3,t);
	 }
	 if(P.size() %2 ==0) P.pop_back();
 	cout<<"Plaintext : "<<P;


 }
