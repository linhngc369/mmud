/*BaiTap3: Lap trinh nhap mot so nguyen p tu ban phim hãy hien ra man hinh 
tat ca cac phan tu nguyen thuy cua p
VD p=19
2 3 10 13 14 15*/

#include<iostream>
using namespace std;
int mu(int a, int m,int p){
	int b=1;
	for(int i=1;i<=m;i++) b=b*a%p;
	return b;
}
int main(){
	int p;
	cout<<"Nhap p = "; cin>>p;
	cout<<"Cac phan tu nguyen thuy cua "<<p<<" la : "<<endl;
	for(int a=1;a<p;a++){
		int dem = 0;
		for(int i=2;i<p;i++) 
			if (mu(a,i,p) == a) dem++;
		if(dem==0) cout<<a<<" ";
	}		
}
