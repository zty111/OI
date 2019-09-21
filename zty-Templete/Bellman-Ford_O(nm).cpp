#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int d[N],from[N],e[N],to[N],cnt,s,n,m;
void add_edge(int u,int v,int d){
    ++cnt;e[cnt]=d;to[cnt]=v;from[cnt]=u;
}
void Bellman_Ford(){
    memset(d,0x3f,sizeof(d));
    d[s]=0;
    int flag;
    do{
        flag=0;
        for(int i=1;i<=cnt;i++){
            int v=to[i],u=from[i];
            if(d[u]+e[i]<d[v])
                d[v]=e[i]+d[u],flag|=1;
        }        
    }while(flag);
}
int main(){
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        add_edge(u,v,w);
    }
    Bellman_Ford();
    for(int i=1;i<=n;i++)cout<<d[i]<<' ';
    return 0;
}