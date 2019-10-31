#include<bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
    return x;
}
struct qus{
    int l,r,id,pos;
}a[50010];
bool cmp(qus A,qus B){
    if(A.pos==B.pos){
        if(A.pos%2==1)
        return A.r<B.r;
        else return A.r>B.r;
    }
    return A.pos<B.pos;
}
int n,m,k,len,L,R,ans[50010],Ans,c[50010],cnt[50010];
inline void del(int x){
    Ans-=(2*cnt[c[x]]-1);cnt[c[x]]--;
}
inline void add(int x){
    Ans+=(2*cnt[c[x]]+1);cnt[c[x]]++;
}
int main(){
    n=read();m=read();k=read();
    len=sqrt(n);
    for(int i=1;i<=n;i++){
        c[i]=read();
    }
    for(int i=1;i<=m;i++){
        a[i].l=read();a[i].r=read();a[i].id=i;
        a[i].pos=a[i].l/len+1;
    }
    sort(a+1,a+1+m,cmp);
    L=1;
    for(int i=1;i<=m;i++){
        while(L<a[i].l)del(L++);
        while(R>a[i].r)del(R--);
        while(L>a[i].l)add(--L);
        while(R<a[i].r)add(++R);
        ans[a[i].id]=Ans;
    }
    for(int i=1;i<=m;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}