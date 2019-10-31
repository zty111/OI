#include<bits/stdc++.h>
using namespace std;
const int p = 1e7;
const int maxn = 1<<25;
int n,opt,x,a[maxn+10];
void read(int &a){
    a=0;int f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){a=a*10+ch-48;ch=getchar();}
    a*=f;
}
void add(int x,int d){
    for(;x<=maxn;x+=x&-x)a[x]+=d;
}
int query(int x){
    int ret=0;
    for(;x>0;x-=x&-x)ret+=a[x];
    return ret;
}
int kth(int x){
    int rt=maxn;
    for(int i=rt;i;i>>=1){
        if(a[rt-i]>=x)rt-=i;
        else x-=a[rt-i];
    }
    return rt-p;
}
int main(){
    read(n);
    for(int i=1;i<=n;i++){
        read(opt);read(x);
        switch(opt){
            case 1:add(x+p,1);break;
            case 2:add(x+p,-1);break;
            case 3:printf("%d\n",query(x+p-1)+1);break;
            case 4:printf("%d\n",kth(x));break;
            case 5:printf("%d\n",kth(query(x+p-1)));break;
            case 6:printf("%d\n",kth(query(x+p)+1));break;
        }
    }
    return 0;
}
