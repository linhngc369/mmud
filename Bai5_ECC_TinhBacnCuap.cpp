///Bai 5 P(xp,yp) là 1 điểm thuộc Ep(a,b). Lập trình nhập tọa độ điểm P rồi tính bậc n của điểm P đó, với a và p nhập từ bàn phím
#include<iostream>
using namespace std;

struct Diem {
	int x;
	int y;
};

struct Diem Tong(int Xp,int Yp, int Xq, int Yq, int a, int p)
{
	struct Diem R;
	int L,TS,MS,MS1;

	if(Xp==Xq && (Yp+Yq)%p == 0) // 2 diem doi nhau
	{
		R.x=-1;
		R.y=-1;
		return R; // tong la diem 0 o vo cuc
	}
	else if(Xp==-1 && Yp ==-1) // diem P la diem 0
	{
		R.x=Xp;
		R.y=Yp;
		return R; //Tong P+Q la diem Q
	}
	else if(Xq==-1 && Yq==-1)
	{
		R.x=Xp;
		R.y=Yp;
		return R; //Tong P+Q la diem P
	}
	else if(Xp==Xq && Yp==Yq) // 2 diem trung nhau
	{
		TS = (3*Xp*Xp+a)%p; //Tuso
		MS = (2*Yp)%p; //Mauso

		for(int i = 0;i<p;i++)
			if(i*MS%p==1)
			{
				MS1 = i;
				break;
			}

		L= TS*MS1%p; // LAMDA
	}
	else
	{
		TS=(Yq-Yp+p)%p; //TuSo
		MS=(Xq-Xp+p)%p; //MauSo

		for(int i = 0;i<p;i++)
			if(i*MS%p==1)
			{
				MS1 = i;
				break;
			}

		L = TS*MS1%p; // LAMDA
		cout<<endl<<"L2= "<<L;
	}

	R.x = (L*L-Xp-Xq+p+p)%p;
	R.y = (L*(Xp-R.x+p)- Yp+p)%p;

	return R;
}

int main()
{
	int Xp,Yp,Xq,Yq;
	int n,a,p;

	cout<<"Nhap Xp= "; cin>>Xp;
	cout<<"Nhap Yp= "; cin>>Yp;
	cout<<"Nhap a= "; cin>>a;
	cout<<"Nhap p= "; cin>>p;

	struct Diem R;

	// Tinh bac cua diem P
	n=1;
	Xq=Xp;
	Yq=Yp;

	while (Xq!=-1 || Yq!=-1)
	{
		n++;

		R = Tong(Xp,Yp,Xq,Yq,a,p);

		Xq=R.x;
		Yq=R.y;

		cout<<n<<"P: ("<<R.x<<","<<R.y<<")"<<endl;
	}

	cout<<endl<<"Bac cua diem P = "<<n;
}
