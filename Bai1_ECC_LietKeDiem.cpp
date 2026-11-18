#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int a,b,p; 
	int d=0;
	int x,y;
	cout<<"Nhap a = "; cin>>a;
	cout<<"Nhap b = "; cin>>b;
	cout<<"Nhap p = "; cin>>p;
	for(int x=0;x<p;x++){
		int VP = (x*x*x + a*x +b) %p;
		for(y=0;y<p;y++){
		int VT = (y*y)%p;
		if(VT==VP){
			d++;
			cout<<d<<": ("<<x<<","<<y <<")"<<endl;
		}
	}
	cout<<"Tong so diem tren duong cong (chua tinh diem 0) = "<<d;
}
}