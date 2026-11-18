//2DES
#include<iostream>
using namespace std;
char F(char R,char Ki){
	return R + Ki;
}
//Ham ma hoa DES
string E(char k,string P){
	char R[3],L[3],K[3];
	int n=2;
	string C="xx";
	K[0] = k;
	L[0] = P[1];
	R[0] = P[0];
	for(int i=1;i<=2;i++){
		K[i] = K[0] << i;
		R[i] = L[i-1] ^ F(R[i-1] , K[i]);
		L[i] = R[i-1];
	}
	C[0] = L[n];
	C[1] = R[n];
	return C;
}

//Ham giai ma DES
string D(char k, string C){
	char L[3],R[3],K[3];
	string P = "xx";
	int n=2;
	K[0] = k;
	L[n] = C[0];
	R[n] = C[1];
	for(int i=n;i>=1;i--){
		K[i] = K[0] << i;
		L[i-1] = R[i] ^ F(L[i] , K[i]);
		R[i-1] = L[i];
	}
	P[0] = R[0];
	P[1] = L[0];
	return P;
}

//Ham ma hoa 2DES
string EE(char K1,char K2, string P){
	string C;
	C = E(K1,P);
	C = E(K2,C);
 	return C;
}

//Ham giai ma 2DES
string DD(char K1, char K2, string C){
	string P;
	P = D(K2,C);
	P = D(K1,P);
	return P;
}

int main(){
	string P,C;
	char K1,K2;
	cout<<"Nhap plaintext: ";
	getline(cin,P);
	cout<<"Nhap khoa K1: ";
	cin>>K1;
	cout<<"Nhap khoa K2: ";
	cin>> K2;
	
	//Them X neu plaintext co so ky tu le
	if(P.size() % 2 == 1){
		P = P + 'X';
	}
	
	//Ma hoa 2DES
	for(int i=0;i<P.size();i=i+2){
		string t = "";
		t = t + P[i] + P[i+1];
		C = C + EE(K1,K2,t);
	}
	
	cout<<"Ciphertext: "<<C<<endl;
	
	//Giai ma 2DES
	P = "";
	for(int i=0;i<C.size();i=i+2){
		string t = "";
		t = t + C[i] + C[i+1];
		P = P + DD(K1,K2,t);
	}
	cout<<"Plaintext: "<<P;
	return 0;
}
