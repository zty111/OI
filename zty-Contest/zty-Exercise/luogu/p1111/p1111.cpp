#include<bits/stdc++.h>
using namespace std;
inline int read(){
    register int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
    return x;
}
int m,n,fa[100010],s[100010],ans=-1;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
struct road{
    int x,y,t;
}a[100010];
bool cmp(road A,road B){
    return A.t<B.t;
}
int main(){
    n=read();m=read();
    for(int i=1;i<=n;i++){fa[i]=i;s[i]=1;}
    for(int i=1;i<=m;i++){
        a[i].x=read();a[i].y=read();a[i].t=read();
    }
    sort(a+1,a+1+m,cmp);
    for(int i=1;i<=m;i++){
        int x=find(a[i].x),y=find(a[i].y);
        if(x!=y){
            fa[x]=y;
            s[y]+=s[x];
            if(s[y]==n){ans=a[i].t;break;}
        }
    }
    printf("%d\n",ans);
    return 0;
}