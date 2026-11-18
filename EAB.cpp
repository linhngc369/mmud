//P3-MMUD 1-32 
# include <iostream> 
using namespace std ;
int Left(int y ,int p){ 
	return (y*y)%p;
}
long long right(int x, int a , int p, int b){
	long long ba = x*x*x;
	return ba + a*x + b % p;
}
int main () {
	int a,p,b ;
	cin>>a>>b>>p;
	int dem=0;
	for(int x=0;x<p-1;x++){
		for(int y=0;y<p-1;y++){
			if (Left(y,p) == right(x,a,p,b)) {
			dem++;
			cout<<"(" <<Left(y,p)<<","<<right(x,a,p,b)<<")"<<endl;
		}
		//cout<<"Left" <<Left(y,p)<<" ";
		//cout<<endl;
		//cout<<"right"<<right(x,a,p,b)<<" "<<endl;
		}
	}
	
}
