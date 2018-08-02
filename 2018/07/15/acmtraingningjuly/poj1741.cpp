#include<bits/stdc++.h>
using namespace std;
#define inf 0x7fffffff;
const int N = 10005;
int n,k,sum,ans,root;
int head[N],deep[N],d[N],mx[N],size[N];
bool vis[N];

struct edge{
    static int es;
    int to,next,v;
    void ins(int u,int v,int w){
        to=v;this->v=w;next=head[u];head[u]=edge::es++;
    }
}e[N<<1];
int edge::es = 0;
void getroot(int x,int fa){
    size[x]=1;mx[x]=0;
    for(int i=head[x];i!=-1;i=e[i].next){
        if(e[i].to==fa||vis[e[i].to])continue;
        getroot(e[i].to,x);
        size[x]+=size[e[i].to];
        mx[x]=max(mx[x],size[e[i].to]);
    }
    mx[x]=max(mx[x],sum-size[x]);
    if(mx[x]<mx[root])root=x;
}
void getdeep(int x,int fa){
    deep[++deep[0]]=d[x];
    for(int i=head[x];i!=-1;i=e[i].next){
        if(e[i].to==fa||vis[e[i].to])continue;
        d[e[i].to]=d[x]+e[i].v;
        getdeep(e[i].to,x);
    }
}
int cal(int x,int now){
    d[x]=now;deep[0]=0;
    getdeep(x,0);
    sort(deep+1,deep+deep[0]+1);
    int t=0,l,r;
    for(l=1,r=deep[0];l<r;){
        if(deep[l]+deep[r]<=k){t+=r-l;l++;}
        else r--;
    }
    return t;
}
void work(int x){
    ans+=cal(x,0);
    vis[x]=1;
    for(int i=head[x];i!=-1;i=e[i].next){
        if(vis[e[i].to])continue;
        ans-=cal(e[i].to,e[i].v);
        sum=size[e[i].to];
        getroot(e[i].to,root=0);
        work(root);
    }
}
int u,v,w;
int main(){
    while(scanf("%d%d",&n,&k),n+k){
        ans=0;root=0;edge::es=0;
        memset(vis,0,sizeof(vis));
        memset(head,-1,sizeof(head));
        for(int i=1;i<n;i++){
            scanf("%d%d%d",&u,&v,&w);
            e[edge::es].ins(u,v,w);
            e[edge::es].ins(v,u,w);
        }
        sum=n;mx[0]=inf;
        getroot(1,0);
        work(root);
        printf("%d\n",ans);
    }
    return 0;
}
