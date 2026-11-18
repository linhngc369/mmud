// bài 2 P(xp,yp) Q(xq,yq) là 2 điểm khác nhau thuộc Ep(a,b). Lập trình nhập tọa độ 2 điểm rồi tính tổng 2 điểm đó, với p nhập từ bàn phím
#include<iostream>
using namespace std;
int main(){
	int xp,yp,xq,yq,xr,yr,p;
	cout<<"Nhap p = "; cin>>p;
	cout<<"Nhap Xp = "; cin>>xp;
	cout<<"Nhap Yp = "; cin>>yp;
	cout<<"Nhap Xq = "; cin>>xq;
	cout<<"Nhap Yq = "; cin>>yq;
	int L,TS,MS,MS1; //LAMDA
	TS=(yq-yp+p)%p;
	MS=(xq-xp+p)%p;
	for(int i = 1;i<p;i++)
		if(i*MS%p==1) {MS1 = i; break; }
	L=TS*MS1%p;
	xr = (L*L%p - xp-xq+p+p) %p;
	yr = (L*(xp-xr+p)%p-yp+p)%p;
	cout<<"Xr = "<<xr<<", Yr="<<yr;
}
