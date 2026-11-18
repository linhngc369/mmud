/*BaiTap2: Lap trinh nhap mot so nguyen p tu ban phim hãy hien ra man hinh 
tat ca cac gia tri a thuoc[1,p-1] va cac luy thua tuong ung cua a (bao gom a,a^2,a^3 ... a^(p-1) trong modul p*/

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
	for(int a=1;a<p;a++){
		for(int i=1;i<p;i++) cout<<mu(a,i,p)<<" ";
		cout<<endl;
	}		
}
