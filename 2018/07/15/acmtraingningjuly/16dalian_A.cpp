#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
#define rep(i,n) for(int i=1;i<=n;i++)

int n,m,x,y;
int fa[N],enemy[N];
int gp[N];

int find(int root){
    if(fa[root]==root) return root;
    else return fa[root] = find(fa[root]);
}

int main(){
    while(~scanf("%d%d%d%d",&n,&m,&x,&y)){
        bool flag = true;
        rep(i,n) fa[i]=i;
        memset(gp,0,sizeof(gp));
        memset(enemy,0,sizeof(enemy));
        rep(i,m){
            int s,t;
            scanf("%d%d",&s,&t);
            if(find(s)==find(t)){
                flag = false;
            }
            if(enemy[find(s)])
                fa[enemy[find(s)]]=find(t);
            enemy[find(s)]=find(t);
            if(enemy[find(t)])
                fa[enemy[find(t)]]=find(s);
            enemy[find(t)]=find(s);
        }
        int lv=0,v;
        rep(i,x){
            scanf("%d",&v);
            if(lv) {
                if(find(enemy[v])==find(lv)) flag=false;
                fa[v]=find(lv);
            }
            gp[find(v)]=1;
            if(!enemy[v]) enemy[v]=n+1;
            lv = v;
        }
        lv=0;
        rep(i,y){
            scanf("%d",&v);
            if(lv) {
                if(find(enemy[v])==find(lv)) flag=false;
                fa[v]=find(lv);
            }
            if(!enemy[v]) enemy[v]=n+1;
            if(gp[find(v)]) flag=false;
            lv=v;
        }
        rep(i,n)
            if(!enemy[find(i)]) flag=false;
        if(!flag){
            puts("NO");
            continue;
        }
        puts("YES");
    }
    return 0;
}
