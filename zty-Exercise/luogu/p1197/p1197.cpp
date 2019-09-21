#include<bits/stdc++.h>
using namespace std;
const int N = 400010;
int n,m,fa[N],x,y,k,at[N],ans[N];
bool vis[N];
struct e{
    int x,y;
};
vector<e>ed;
vector<int>G[N];
void add_edge(int x,int y){
    ed.push_back(e{x,y});
    int mm=ed.size();
    G[x].push_back(mm-1);
}
inline int read(){
    register int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
    return x;
}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(){
    n=read();m=read();
    for(int i=0;i<n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        x=read();y=read();
        add_edge(x,y);
        add_edge(y,x);
    }
    k=read();
    memset(vis,1,sizeof(vis));
    for(int i=1;i<=k;i++){at[i]=read();vis[at[i]]=0;}
    int cnt=0;
    for(int i=0;i<n;i++){
        if(vis[i]){
            cnt++;
            for(int j=0;j<G[i].size();j++){
                e & E=ed[G[i][j]];
                if(vis[E.y]){
                    x=find(E.x);y=find(E.y);
                    if(x!=y)fa[x]=y,cnt--;
                }
            }
        }
    }
    ans[k]=cnt;
    for(int i=k;i>=1;i--){
        vis[at[i]]=1;
        cnt++;
        for(int j=0;j<G[at[i]].size();j++){
            e & E=ed[G[at[i]][j]];
            if(vis[E.y]){
                x=find(E.x);y=find(E.y);
                if(x!=y)fa[x]=y,cnt--;
            }
        }
        ans[i-1]=cnt;
    }
    for(int i=0;i<=k;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}