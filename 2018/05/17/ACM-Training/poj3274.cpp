#include<map>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100007;
#define rep(i,n) for(int i=1;i<=n;i++)
#define rep0(i,n) for(int i=0;i<n;i++)
int a[N],f[N][31],n,k;
int cur,ans;

struct hashnode{
    int pos,next;
}hnode[N];
int nexthash[N];
unsigned int getHash(int i){
    unsigned int s[31]={0};
    unsigned int h=0,seed=1313;
    rep(j,k-1) {
        s[j]=f[i][j]-f[i][j-1]+N;
        h = h * seed + s[j];
    }
    return (h & 0x7FFFFFFF)%N;
}

bool compare(int x,int y){
    rep0(j,k-1)
        if(f[x][j+1]-f[x][j]!=f[y][j+1]-f[y][j]) return false;
    return true;
}

void initHash(int i){
    unsigned int code = getHash(i);
    int next = nexthash[code];
    while(next!=-1){
        if(compare(hnode[next].pos,i)){
            ans=max(ans,i-hnode[next].pos);
            return;
        }
        next=hnode[next].next;
    }
    hnode[cur].pos=i;
    hnode[cur].next=nexthash[code];
    nexthash[code]=cur++;
}

int main(){
    memset(nexthash,-1,sizeof(nexthash));
    scanf("%d%d",&n,&k);
    initHash(0);
    rep(i,n){
        scanf("%d",&a[i]);
        rep0(j,k)
            f[i][j]=f[i-1][j]+((a[i]&(1<<j))/(1<<j));
        initHash(i);
    }
    cout<<ans<<endl;
    return 0;
}

//f[i][j]表示前i个数字的第j位的和，那么很显然 如果区间[x,y]满足题意，那么forall j in 0...k f[x][j]=f[y][j]
//这题我本来用map来做hash，但是过不去，加了拉链法后过去了，坑点在于52行的init(0),可以思考下为什么。