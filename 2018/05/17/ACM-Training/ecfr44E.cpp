#include<bits/stdc++.h>
using namespace std;
const int N = 500010;
#define rep(i,n) for(int i=1;i<=n;i++)

int n,k,d;
int t[N],a[N];
int lowbit(int x){return (x)&(-x);}

int Query(int x){
    int ans=0;
    while(x){
        ans+=t[x];
        x-=lowbit(x);
    }
    return ans;
}

void Modify(int l,int r,int delta){
    if(l>r) return;
    int x=l;
    while(x<=n){
        t[x]+=delta;
        x+=lowbit(x);
    }
    x=r+1;
    while(x<=n){
        t[x]-=delta;
        x+=lowbit(x);
    }
}

int main(){
    scanf("%d%d%d",&n,&k,&d);
    rep(i,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    rep(i,n)
        if(i==1 || Query(i-1)){
            int j = upper_bound(a+1,a+n+1,a[i]+d) - a - 1;
            Modify(i+k-1,j,1);
        }
    Query(n)?puts("YES"):puts("NO");
    return 0;
}

//dp, 如果1~i-1已经被安排的明明白白，现在安排第i位，那么第[i+k-1,j]也可以被安排
// 其中a[j]是小于a[i]+d的最大的数。 因为k过大，维护要用树状数组。
