#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
long long ans;
int n,k,l,a[100010];
int main(){
    scanf("%d%d%d",&n,&k,&l);
    rep(i,k*n) cin>>a[i];
    sort(a+1,a+1+k*n);
    int id=upper_bound(a+1,a+1+k*n,a[1]+l)-a-1;
    if(id<n){
        cout << 0<<endl;
        return 0;
    }
    ans=0;
    for(int i=1;n>0&&i<=id;i+=k){
        n--;
        ans+=a[i];
        a[i]=-1;
    }
    if(n>0){
        for(int i=id;n>0;i--){
            if(a[i]!=-1){
                ans+=a[i];
                n--;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
