#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 500010;
inline int read(){
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x;
}
struct qus{
    int l,r,id;
}q[N];
bool cmp(qus A,qus B){
    return A.r<B.r;
}
int a[N],mp[2*N],pre[N],ans[N],n,c[N];
void insert(int p,int k){
    for(;p<=n;p+=p&-p)c[p]+=k;
}
int query(int p){
    int ans=0;
    for(;p>0;p-=p&-p)ans+=c[p];
    return ans;
}
int main(){
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        pre[i]=mp[a[i]];
        mp[a[i]]=i;
    }
    int m=read();
    for(int i=1;i<=m;i++){
        q[i].l=read();
        q[i].r=read();
        q[i].id=i;
    }
    sort(q+1,q+1+m,cmp);
    int j=0;
    for(int i=1;i<=m;i++){
        while(j<q[i].r){
            insert(++j,1);
            if(pre[j]!=0)insert(pre[j],-1);
        }
        ans[q[i].id]=query(q[i].r)-query(q[i].l-1);
    }
    for(int i=1;i<=m;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}