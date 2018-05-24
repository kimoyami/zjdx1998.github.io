#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i=1;i<=n;i++)
ll n,H;

int Check(ll tn){
    if(H>=tn) return ((ld)(1+tn)*tn/2>=n);
    ld M = (ld)(tn+H)/2;
    return (1+M)*M/2 + (H+M-1)*(M-H)/2 >= n;

}

int main(){
    cin>>n>>H;
    ll L=1,R=1e18;
    while(R-L>1){
        ll Mid = (L+R)>>1;
        if(Check(Mid)) R=Mid;
        else           L=Mid;
    }
    if(Check(L)) cout<<L<<endl;
    else          cout<<R<<endl;
    return 0;
}

//二分答案，推公式检测 ,我只考虑了两种情况，一种是-----\  一种是 /---\，其实第二种可以转换为 /\ 
