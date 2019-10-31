#include<bits/stdc++.h>
using namespace std;
int n,m,c[100010][2];
void add(int x,int i){
    for(;x<=n;x+=x&-x)c[x][i]++;
}
int sum(int x,int i){
    int ans=0;
    for(;x;x-=x&-x)ans+=c[x][i];
    return ans;
}
inline int read(){
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
    return x;
}
int main(){
    n=read();m=read();
    for(int i=1;i<=m;i++){
        int opt=read(),l=read(),r=read();
        if(opt==1)add(l,0),add(r,1);
        else printf("%d\n",sum(r,0)-sum(l-1,1));
    }
    return 0;
}