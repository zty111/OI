#include<bits/stdc++.h>
using namespace std;
inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
    char ch=nc();int sum=0;
    while(ch<'0'||ch>'9')ch=nc();
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
    return sum;
}
int main(){
    int T,a,b,c;
    T=read();
    while(T--){
        a=read();b=read();c=read();
        int x=b+c-a;
        int y=x/2;
        int s;
        if(b+c-a<0)s=c+1;
        else s=max(c-y,0);
        printf("%d\n",s);
    }
    return 0;
}