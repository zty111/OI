#include<bits/stdc++.h>
using namespace std;
int n;
inline int read(){
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
    return x;
}
struct pt{
    int id,w,h;
    long long ans;    
}A[100010],s[100010];
const int inf = 0x3f3f3f3f;
int top,p,l,r,num,minn=inf;
long long now;
int main(){
    n=read();
    for(int i=1;i<=n;i++){
        A[i].id=i;
        A[i].w=read();
        A[i].h=read();
        A[i].ans=0;
        if(A[i].h<minn)num=i,minn=A[i].h;
    }
    s[++top]=A[num];
    l=r=num;
    s[0].h=A[0].h=A[n+1].h=inf;
    for(int i=1;i<=n;i++){
        int add=0;
        if(A[l-1].h<A[r+1].h)p=--l;
        else p=++r;
        while(top&&A[p].h>s[top].h){
            s[top].w+=add;
            A[s[top].id].ans=now+s[top].w;
            now+=1ll*s[top].w*(min(A[p].h,s[top-1].h)-s[top].h);
            add=s[top].w;
            top--;
        }
        A[p].w+=add;
        s[++top]=A[p];
    }
    for(int i=1;i<=n;i++)printf("%lld\n",A[i].ans);
    return 0;
}