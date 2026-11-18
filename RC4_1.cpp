  /*Bài tap 1: Lap trinh chuoi tu ban phim .AD thuat toan RC4 de sinh ra chuoi
khoa luong gom 10 so k hien chuoi khoa luong ra man hinh*/
#include<iostream>
using namespace std;
int main()
{
	unsigned char T[256],S[256];
	string K;int i,j,k,t;
	/*Khoi tao*/
	cout<<"Nhap K = ";getline(cin,K);
	for(i = 0 ;i <= 255 ;i++){
		T[i] = (unsigned char)K[i % K.size()];
		S[i] = i;
	}
	//Tao chuoi S gia ngau nhien
	j = 0;
	for (i = 0; i<=255; i++){
		j = (j + S[i] + T[i]) %256;
		swap (S[i] , S[j]);
	}
	/*Sinh khoa luong*/
	i,j=0;
	for(int x=1;x<=10;x++){		//Sinh ra 10 so k roi hien ra man hinh
		i = (i + 1) % 256;
		j = (j + S[i]) % 256;
		swap (S[i] , S[j]);
		t = (S[i] + S[j]) % 256;
		k = S[t];
		cout <<k<<" ";
	}
}
