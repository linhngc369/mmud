#include<bits/stdc++.h> // Thu vien tong hop trong C++ (ho tro string, cin, cout...)
using namespace std;


char F(char R, char Ki){
    return R ^ Ki;
}


string E(string P, char k){
    char L[4], R[4], K[4]; 
    string C = "aa";       
    int n = 2;             

    
    L[0] = P[0];
    R[0] = P[1];
    K[0] = k;

 
    for(int i = 1; i <= n; i++){
        K[i] = K[0] << i;                
        R[i] = L[i-1] ^ F(R[i-1], K[i]); 
        L[i] = R[i-1];                   

    
    C[0] = L[n];
    C[1] = R[n];
    return C;
}


string D(string C, char k){
    char L[4], R[4], K[4];
    string D = "aa"; 
    int n = 2;

    L[n] = C[0];
    R[n] = C[1];
    K[0] = k;


    for(int i = n; i >= 1; i--){
        K[i] = K[0] << i;                
        L[i-1] = R[i] ^ F(L[i], K[i]);   
        R[i-1] = L[i];                   
    }

    D[0] = L[0];
    D[1] = R[0];
    return D;
}


string Dfull(string C, char K1, char K2, char K3){
    string plain = "";
    
    for(int i = 0; i < C.length(); i += 2){
        string c = C.substr(i, 2);
        string P = D(c, K3);       
        P = D(P, K2);              
        P = D(P, K1);             
        plain += P;               
    }
    return plain;
}


string Efull(string P, char K1, char K2, char K3){
    if(P.length() % 2 != 0) P += " "; 
    string cypher = "";
    
    for(int i = 0; i < P.length(); i += 2){
        string p = P.substr(i, 2); 
        string C = E(p, K1);       
        C = E(C, K2);             
        C = E(C, K3);              
        cypher += C;               
    }
    return cypher;
}

int main(){
    string P, C = "", D = "";
    char K1, K2, K3;
    
    
    cout << "P: "; getline(cin, P);
    
    
    cout << "K1, K2, K3: "; cin >> K1 >> K2 >> K3;
    
    
    C = Efull(P, K1, K2, K3);
    cout << "C: " << C << endl; 
    
    
    D = Dfull(C, K1, K2, K3);
    cout << "D: " << D << endl;
    
    return 0;
}
