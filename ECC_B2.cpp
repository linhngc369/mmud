/*P(xp,yp) và Q(xq,yq) la 2 diem khac nhau thuoc Ep(a,b) Lap trinh nhao toa do 2 diem roi tinh tong 2 diem do, voi p nhap tu ban phim P=23 xp yp xq yq =  3 10 9 7 kq : xr yr17 20*/
#include<iostream>
using namespace std;
int main(){
	int Xp,Yp,Xq,Yq,Xr,Yr,p;
	cout<<"Nhap p= ";cin>>p;
	cout<<"Nhap Xp= ";cin>>Xp;
	cout<<"Nhap Yp= ";cin>>Yp;
	cout<<"Nhap Xq= ";cin>>Xq;
	cout<<"Nhap Yq= ";cin>>Yq;
	int L,TS,MS,MS1; //Lambda
	TS=(Yq-Yp+p)%p;
	MS=(Xq-Xp+p)%p;
	for(int i=1;i<p;i++){
		if(i*MS%p==1) {MS1=i;break;}
	} 
	L=TS*MS1%p;
	Xr=(L*L%p-Xp-Xq+p+p)%p;
	Yr=(L*(Xp-Xr+p)%p-Yp+p)%p;
	cout<<"Xr= "<<Xr<<", Yr= "<<Yr;
}
