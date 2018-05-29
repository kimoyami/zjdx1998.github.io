#include<bits/stdc++.h>
using namespace std;
const int N = 100001;
#define rep(i,n) for(int i=1;i<=n;i++)
#define rep0(i,n) for(int i=0;i<n;i++)
int T,n,m,a[N];
int prime[N];
bool hashprime[N];
vector<int> factor[N];

void Divide(int ith){
    int num = a[ith];
    for(int p=2;p*p<=num;p++){
        if(num%p==0){
            factor[p].push_back(ith);
            num/=p;
        }
    }
    if(num>1) factor[num].push_back(ith);
}

int Query(int l,int r,int num){
    return upper_bound(factor[num].begin(),factor[num].end(),r)-lower_bound(factor[num].begin(),factor[num].end(),l);
}

int read(){
    int num = 0; char ch = getchar();
    while(ch>'9'||ch<'0') ch = getchar();
    while(ch>='0'&&ch<='9'){
        num = num * 10 + ch - '0';
        ch = getchar();
    }
    return num;
}

int main(){
    int l,r,d;bool ansflag;
    scanf("%d",&T);
    while(T--){
        rep0(i,N) factor[i].clear();
        n=read();m=read();
        rep(i,n) {
            a[i]=read();
            Divide(i);
        }
        rep(i,m){
            ansflag=true;
            l=read();r=read();d=read();
            for(int p=2;p*p<=d;p++){
                int tot=0;
                while(d%p==0){
                    d/=p;
                    tot++;
                }
                if(Query(l,r,p)<tot){
                    ansflag=false;
                    break;
                }
            }
            if(ansflag && d>1 && Query(l,r,d)==0) ansflag=false;
            if(ansflag) puts("Yes");
            else        puts("No");
        }
    }
    return 0;
}

//操蛋数学（瞎搞）题，因为素因数拆分写错了wa了很多次才发现。
//思想是  用factor[i]记录包含i的数字下标，询问时二分统计个数>tot(di)即可。