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
    for(int i=1;n&&i<=id;i+=k){
        n--;
        ans+=a[i];
        a[i]=-1;
    }
    if(n)
        for(int i=id;n;i--){
            if(a[i]!=-1){
                ans+=a[i];
                n--;
            }
        }
    cout<<ans<<endl;
    return 0;
}
//小结：本题WA了3发，前两次是看错题，题意是求最大值。 只需扫一遍所有符合条件的a[i]<a[1]+l，然后按照贪心的策略求出可行的a[i]作为每一个木桶的最小边; 