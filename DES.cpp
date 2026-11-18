#include<iostream>
using namespace std;
char F(char R, char Ki){
	return R+Ki;
}
string E(char k,string P)
{
	char R[3] , L[3] , K[3];
	int n=2;
	string C="xx";
	K[0] = k;
	L[0] = P[1]; 
	R[0] = P[0];
	for(int i=1;i<=n;i++)
	{
		K[i] = K[0]<<i;
		R[i] = L[i-1]^F(R[i-1] , K[i]);
		L[i] = R[i-1];
	}
	C[0] = L[n];
	C[1] = R[n];
	return C;
}

string D(char k,string C)
{
	char L[3],R[3],K[3];
	string P="xx";
	int n=2;
	K[0] = k;
	L[n] = C[0];
	R[n] = C[1];
	for(int i=n; i>=1;i--)
	{
		K[i] = K[0]<<i;
		L[i-1] = R[i]^F(L[i],K[i]);
		R[i-1] = L[i];
	}
	P[0]=R[0];
	P[1]=L[0];
	return P;
}
string EEE(char K1,char K2, char K3, string P){
	string C = "";
	C = E(K1,P);
	C = E(K2,C);
	C = E(K3,C);
	return C;
}
string DDD(char K1,char K2, char K3, string C){
	string P = "";
	P = D(K3,C);
	P = D(K2,P);
	P = D(K1,P);
	return P;
}
int main()
{
	string P,C;
	char K1,K2,K3;
	cout<<"Nhap 1 khoi plaintext: ";getline(cin,P);
	cout<<"Nhap khoa K1: ";cin>>K1;
	cout<<"Nhap khoa K2: ";cin>>K2;
	cout<<"Nhap khoa K3: ";cin>>K3;
	//Ma hoa
	if(P.size()%2==1) P = P + 'x';
	for(int i =0 ; i<P.size();i+=2){
		string t = "";
		t =t + P[i] +P[i+1];
		C = C + EEE(K1,K2,K3,t);
	}
	cout << "Ciphertext: " << C << endl;
		P = "";
	
	for(int i =0 ; i<C.size();i+=2){
		string t = "";
		t = t+ C[i] +C[i+1];
		P = P + DDD(K1,K2,K3,t);
	}
	cout<<"Plaintext: "<<P;
}
