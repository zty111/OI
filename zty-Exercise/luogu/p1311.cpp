#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
    x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
}
int n,k,p,color,low,now,ans;
int la[55],cnt[55],sum[55];
int main(){
    read(n);read(k);read(p);
    for(int i=1;i<=n;i++){
        read(color);read(low);
        if(low<=p)now=i;
        if(now>=la[color]){
            sum[color]=cnt[color];
        }
        la[color]=i;
        cnt[color]++;
        ans+=sum[color];
    }
    printf("%d\n",ans);
    return 0;
}
