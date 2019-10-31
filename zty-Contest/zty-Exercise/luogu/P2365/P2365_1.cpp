#include<bits/stdc++.h>
using namespace std;
const int N = 5010;
typedef long long ll;
ll sumC[N],sumT[N],f[N];
int n,S;
int main(){
    scanf("%d%d",&n,&S);
    for(int i=1;i<=n;i++){
        int c,t;
        scanf("%d%d",&t,&c);
        sumC[i]=sumC[i-1]+c;
        sumT[i]=sumT[i-1]+t;
    }
    memset(f,0x3f,sizeof(f));
    f[0]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<i;j++)
            f[i]=min(f[i],f[j]+sumT[i]*(sumC[i]-sumC[j])+S*(sumC[n]-sumC[j]));
    printf("%lld\n",f[n]);
    return 0;
}