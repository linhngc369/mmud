#include <iostream>
using namespace std ;
int main () {
	unsigned char T[256] ,S[256];
	string K ; int i,j,k,t;
	//khoitao
	cout<<"Nhap K : ";getline(cin,K);
	for (int i =0 ; i<=255 ; i++){
		T[i]= K[i % K.size()];
		S[i] = i; // S[1]=1
	}
j = 0 ;
for (i = 0 ; i <= 255 ;i++){
	j = (j + S[i] + T[i]) % 256;
	swap (S[i],S[j]);
}
// sinh khoa luong
i , j =0;
for (int x =1 ; x <=10 ; x++){
	i = (i + 1) % 256 ; 
	j = (j + S[i]) % 256 ;
	swap (S[i],S[j]);
	t = (S[j] + S[i]) % 256 ;
	k = S[t];
	cout<<k<<" ";
}
}
