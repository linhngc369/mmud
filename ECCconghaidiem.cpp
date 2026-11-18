
#include<bits/stdc++.h>

using namespace std;
int main(){
    int a,p,xp,yp,xq,yq;
    int L,TS,MS,MS1;
    int xr, yr;

    cout<<"Nhap a, p:";
    cin>>a>>p;
    cout<<"Nhap xp, yp: ";
    cin>>xp>>yp;
    cout<<"Nhap xq,yq: ";
    cin>>xq>>yq;

    TS = (yq - yp + p) % p;
    MS = (xq - xp + p) % p;

    for(int i=1 ; i<p ; i++){
        if((i*MS)%p == 1){
            MS1 = i;
            break;
        }
    }

    L = TS * MS1 % p;

    xr = (L*L - xq - xp + p + p) % p;
    if(xr < 0)
        xr += p;

    yr = (L*(xp-xr+p) - yp + p) % p;
    if(yr<0)
        yr += p;

    cout<<"R = P+Q = ("<<xr<<","<<yr<<")";
    return 0;
}

