#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
#define inf 0x7fffffff
#define MSIZE (1<<k)-1
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;i++)

vector<int> sta;
int w[N],size[N],n,k,head[N],mx[N],sum,root;
bool vis[N];
int mxsum;
ll Hash[1<<11],ans;
struct edge{
    static int es;
    int to,next;
    void ins(int x,int y){
        to = y; next = head[x]; head[x] = edge::es++;
    }
}e[N];
int edge::es = 0;

void getroot(int x,int fa){
    size[x] = 1; mx[x] = 0;
    for(int i = head[x];i+1;i=e[i].next){
        if(e[i].to==fa || vis[e[i].to]) continue;
        getroot(e[i].to,x);
        size[x]+=size[e[i].to];
        mx[x] = max(mx[x],size[e[i].to]);
    }
    mx[x] = max(mx[x],sum-size[x]);
    if(mx[x]<mx[root]) root = x;
}

void getHash(int x,int fa,int s){
    sta.push_back(s);
    for(int i=head[x];i+1;i=e[i].next){
        if(vis[e[i].to] || e[i].to==fa) continue;
        getHash(e[i].to,x,s|(1<<w[e[i].to]));
    }
}

ll cal(int x,int s){
    ll ret = 0;
    sta.clear();
    memset(Hash,0,sizeof(Hash));
    getHash(x,0,s);
    int cnt = sta.size();
    for (int i = 0; i < cnt; i++) Hash[sta[i]]++;
    for (int i = 0; i < cnt; i++){
        Hash[sta[i]]--;
        ret += Hash[mxsum];
        for (int s0 = sta[i]; s0; s0 = (s0 - 1) & sta[i]){
            ret += Hash[(mxsum) ^ s0];
        }
        Hash[sta[i]]++;
    }
    return ret;
}

void work(int x){
    ans+=cal(x,(1<<w[x]));
    vis[x]=1;
    for(int i=head[x];i+1;i=e[i].next){
        if(vis[e[i].to]) continue;
        ans-=cal(e[i].to,(1<<w[x])|(1<<w[e[i].to]));
        sum=size[e[i].to];
        getroot(e[i].to,root=0);
        work(root);
    }
}

int main(){
    while(~scanf("%d%d",&n,&k)){
        memset(head,-1,sizeof(head));
        memset(vis,0,sizeof(vis));
        int x,y;edge::es=0;ans=0;mxsum=(1<<k)-1;
        rep(i,n) scanf("%d",&w[i]),w[i]--;
        rep(i,n-1){
            scanf("%d%d",&x,&y);
            e[edge::es].ins(x,y);
            e[edge::es].ins(y,x);
        }
        if(k==1){
            printf("%lld\n",(long long)n*n);
            continue;
        }
        sum = n; mx[0]=inf;
        getroot(1,root = 0);
        work(root);
        printf("%lld\n",ans);
    }
    return 0;
}
