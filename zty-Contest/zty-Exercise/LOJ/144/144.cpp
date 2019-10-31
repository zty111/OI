#include<cstdio>
using namespace std;
inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
    char ch=nc();int x=0;
    while(ch<'0'||ch>'9')ch=nc();
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=nc();
    return x;
}
const int mod = 998244353;
int n,m,u,v,op,fa[4000010],ans;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main(){
    n=read();m=read();
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        op=read();u=read();v=read();
        if(op==0){
            int fu=find(u),fv=find(v);
            fa[fu]=fv;
        }
        else{
            int fu=find(u),fv=find(v);
            if(fu==fv)ans=(ans<<1)+1;
            else ans=(ans<<1);
            if(ans>mod)ans%=mod;
        }
    }
    printf("%d\n",ans);
    return 0;
}