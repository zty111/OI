#include<bits/stdc++.h>
using namespace std;
int n,m,u,v,fa[10010];
char ch[20];
inline void sroot(int x){
    for(int c=0,p=fa[x];x;p=fa[x]){
        fa[x]=c;c=x;x=p;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%s%d%d",ch,&u,&v);
        sroot(u);
        if(ch[0]=='Q'){
            while(fa[v]!=0&&v!=u)v=fa[v];
            if(u==v)puts("Yes");
            else puts("No");
        }
        else if(ch[0]=='C')fa[u]=v;
        else fa[v]=0;
    }
    return 0;
}