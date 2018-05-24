#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
const int MOD = 100000007;
#define rep(i,n) for(int i=1;i<=n;i++)
#define rep0(i,n) for(int i=0;i<n;i++)

int n,m,f[N][27],p[N]={1,0};

bool Judge(int x,int y,int len){
    int a[27]={0},b[27]={0};
    rep0(i,26){
        a[i]=(f[x+len-1][i]-1LL*f[x-1][i]*p[len]%MOD+MOD)%MOD;
        b[i]=(f[y+len-1][i]-1LL*f[y-1][i]*p[len]%MOD+MOD)%MOD;
    }
    sort(a,a+26);sort(b,b+26);
    rep0(i,26)
        if(a[i]!=b[i]) return false;
    return true;
}
char str[N];
int main(){
    scanf("%d%d",&n,&m);
    scanf("%s",str+1);
    rep(i,n) p[i]=p[i-1]*2%MOD;
    rep(i,n)
        rep0(j,26)
            f[i][j]=(f[i-1][j]*2%MOD+(str[i]-'a'==j))%MOD;
    rep(i,m){
        int x,y,len;
        scanf("%d%d%d",&x,&y,&len);
        Judge(x,y,len)?puts("YES"):puts("NO");
    }
    return 0;
}
//字符串Hash:把字符串做成01串（26个字符每个字符都做），数据友好，MOD=1e8+7都没有卡掉。