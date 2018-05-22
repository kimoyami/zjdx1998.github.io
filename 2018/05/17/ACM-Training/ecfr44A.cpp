#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)

int a[110],n;

int main(){
    scanf("%d",&n);
    rep(i,n/2) scanf("%d",&a[i]);
    sort(a+1,a+n/2+1);
    int oddcost=0,evencost=0;
    rep(i,n/2){
        oddcost+=abs(a[i]-(2*i-1));
        evencost+=abs(a[i]-2*i);
    }
    printf("%d\n",min(oddcost,evencost));
    return  0;
}
