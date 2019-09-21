#include<bits/stdc++.h>
using namespace std;
const int p =1e8+7;
inline void read(int & x){
    x=0;char ch=getchar();int f=1;
    while(ch<'0'||ch>'9'){if(ch='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=((x<<1)+(x<<3)+ch-48)%p;ch=getchar();}
    x*=f;
}
int a[200],ans[200],cnt;
int main(){
    int n,m;
    read(n);read(m);
    for(int i=0;i<=n;i++)
        read(a[i]);
    for(int i=1;i<=m;i++){
        int sum=0;
        for(int j=n;j>=0;j--)
            sum=(1ll*sum*i+a[j])%p;
        if(sum==0)ans[++cnt]=i;
    }
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;i++)
        printf("%d\n",ans[i]);
    return 0;
}