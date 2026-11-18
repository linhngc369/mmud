/*Lap trinh tinh so dem co tren duong cong Ep(a,b) voi a,b,p nhap tu ban phim 
Liet ke cac diem cua duong cong do ra man hinh */
/*#include<iostream>
using namespace std;
int main(){
	int a,b,p,x,y;
	cout<<"Nhap p = " ; cin>>p;
	cout<<"Nhap a = "; cin>>a;
	cout<<"Nhap b = "; cin>>b; 
	int dem=0;
	for(int i=0;i<=p-1;i++){
		for(int j=0;j<=p-1;j++){
			if((i*i)%p == ((j*j*j) + a*j + b)%p){
				cout<<i<<"&"<<j<<endl;
				dem++;
			}
		}
	}
	cout<<dem;
}*/

#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int a,b,p,x,y,VP,VT,d=0;
	cout<<"Nhap a= ";cin>>a;
	cout<<"Nhap b= ";cin>>b;
	cout<<"Nhap p= ";cin>>p;
	for(x=0;x<p;x++){
		//VP=(x*x*x + a*x + b) %p;
		VP = (((x*x)%p*x)%p + (a*x)%p+b)%p;
		for(y=0;y<p;y++){
			VT=(y*y)%p;
			if(VT == VP) {d++; cout<<d<<": ("<<x<<","<<y<<")"<<endl;}
		}
	} 
	cout<<"Tong so diem tren duong cong (chua tinh diem 0) = "<<d;
}
