#include <iostream>
#include <math.h>
using namespace std ;
int mu (int a,int m,int p){
	int b=1;
	for(int i=1;i<=m;i++)b=b*a%p;
	return b;
}
bool ktra(int n){ // kiem tra so nguyen to
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0) return false ;
	}
	return true;
}
int main () {
	int p;
	do {
	 cout<<"Nhap P = ";
	 cin>>p;
	}while(!ktra(p));
	cout<<"Phan Tu Nguyen Thuy Cua P La : ";
	for(int a=1;a<p;a++){
		int dem =0;
		for(int i =2 ; i<p;i++)
		if(mu(a,i,p)==a) dem++;
		if(dem==0) cout<<a<<" ";
	}
}
