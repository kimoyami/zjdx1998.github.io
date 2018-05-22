#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
char f[2001][2001];
bool ans[2001];
int main()
{
    int i,j,k;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            cin>>f[i][j];
    for(i=1;i<=m;i++)
    {
        j=1;
        while(j<=n&&f[j][i]=='0')j++;
        k=j;
        j++;
        while(j<=n&&f[j][i]=='0')j++;
        if(j>n)ans[k]=1;
    }
    i=1;
    while(i<=n&&ans[i]==1)i++;
    if(i<=n)cout<<"YES";
    else cout<<"NO";
    return 0;
}