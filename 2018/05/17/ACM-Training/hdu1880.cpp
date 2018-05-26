#include<bits/stdc++.h>
using namespace std;
const int MOD = 100007;
#define rep(i,n) for(int i=1;i<=n;i++)

string ls[MOD+3],rs[MOD+3];

map<int,int> hash1,hash2;

unsigned int getHash(char *s){
   unsigned int seed = 131;
    unsigned int h = 0;
    while (*s)
        h = h * seed + (*s++);
    return (h & 0x7FFFFFFF);
}
int m,cnt;
char str[150];
int main(){
    while(cin.getline(str,150),strcmp(str,"@END@")){
        char *right =  strchr(str,']');
        right+=2;
        char *left = strtok(str,"]");
        strcat(left,"]");
        string sright(right);
        string sleft(left);
        ls[++cnt]=sleft;
        rs[cnt]=sright;
        hash1.insert(make_pair(getHash(left),cnt));
        hash2.insert(make_pair(getHash(right),cnt));
    }
    scanf("%d\n",&m);
    rep(i,m){
        cin.getline(str,150);
        int gethash = getHash(str);
        if(str[0]=='['){
            if(hash1.find(gethash)!=hash1.end())
                cout<<rs[hash1.find(gethash)->second]<<endl;
            else puts("what?");
        }
        else{
            if(hash2.find(gethash)!=hash2.end()) {
                    string tls=ls[hash2.find(gethash)->second];
                    tls.erase(tls.begin());
                    tls.erase(tls.end()-1);
                    cout<<tls<<endl;
            }
            else puts("what?");
        }
    }
    return 0;
}
