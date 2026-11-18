/*P(Xp,Yp) la mot diem thuoc Ep(a,b).Lap trinh nhap toa do diem P roi tinh tich R=2P,voi a va p nhap tu ban phim*/
#include<iostream>
using namespace std;
int main(){
	int Xp,Yp,a,p,Xr,Yr;
	cout<<"Nhap p= ";cin>>p;
	cout<<"Nhap Xp= ";cin>>Xp;
	cout<<"Nhap Yp= ";cin>>Yp;
	cout<<"Nhap a= ";cin>>a;
	int L,TS,MS,MS1; //Lambda
	TS=(3*(Xp*Xp)%p+a+p)%p;
	MS=(2*Yp+p)%p;
	for(int i=1;i<p;i++){
		if(i*MS%p==1) {MS1=i;break;}
	} 
	L=TS*MS1%p;
	Xr=(L*L%p-2*Xp+p)%p;
	Yr=(L*(Xp-Xr+p)%p-Yp+p+p)%p;
	cout<<"Xr= "<<Xr<<", Yr= "<<Yr;
}
//Nhan nhieu %p luon , tru xong +p luon
