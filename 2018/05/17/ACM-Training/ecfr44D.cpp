#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i=1;i<=n;i++)
ll n,H;
ld Check(ll mid) {
    ll x = max((mid-H+2)/2,0LL);
    return ( (ld)x*(H+H-1+x)/2+(ld)(mid-x)*(mid-x+1)/2 ) >=n;
}

int main(){
    cin>>n>>H;
    ll L=1,R=1e18;
    while(R-L>1){
        ll Mid = (L+R)>>1;
        if(Check(Mid)) R=Mid;
        else           L=Mid;
    }
    if(Check(L)>) cout<<L<<endl;
    else          cout<<R<<endl;
    return 0;
}

//二分答案，推公式检测   但 一定要注意 /---\ 的数据