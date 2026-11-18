
#include<bits/stdc++.h>

using namespace std;
int main(){
    int a,p,xp,yp;
    int L,TS,MS,MS1;
    int xr, yr;

    cout<<"Nhap a, p, xp, yp: ";
    cin>>a>>p>>xp>>yp;

    TS = (3*xp*xp + a + p) % p;
    MS = (2*yp + p) % p;

    for(int i=1 ; i<p ; i++){
        if((i*MS)%p == 1){
            MS1 = i;
            break;
        }
    }

    L = TS * MS1 % p;

    xr = (L*L - 2*xp) % p;
    if(xr < 0)
        xr += p;

    yr = (L*(xp-xr+p) - yp + p) % p;
    if(yr<0)
        yr += p;

    cout<<"R = 2P = ("<<xr<<","<<yr<<")";
    return 0;
}

