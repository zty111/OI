#include<cstdio>
using namespace std;
const int N = 500010;
int n,m,c[N];
void add(int x,int k){
    for(;x<=n;x+=x&-x)c[x]+=k;
}
int ask(int x){
    int ans=0;
    for(;x;x-=x&-x)ans+=c[x];
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        add(i,a);
    }
    for(int i=1;i<=m;i++){
        int flag,x,k;
        scanf("%d %d %d",&flag,&x,&k);
        if(flag==1)add(x,k);
        if(flag==2)printf("%d\n",ask(k)-ask(x-1));
    }
    return 0;
}