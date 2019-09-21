#include<bits/stdc++.h>
using namespace std;
int n,k,num[1<<11];
long long f[11][1<<11][101];
int getnum(int x){
    int ans=0;
    for(;x;x-=x&-x)ans++;
    return ans;
}
int main(){
    cin>>n>>k;
    int s=(1<<n);
    for(int i=0;i<s;i++)num[i]=getnum(i);
    for(int j=0;j<s;j++)
        if((j&(j<<1))||(j&(j>>1)))continue;
        else f[1][j][num[j]]=1;
    for(int i=2;i<=n;i++)
        for(int j=0;j<s;j++){
            if((j&(j<<1))||(j&(j>>1)))continue;
            for(int d=0;d<s;d++){
                if((d&(d<<1))||(d&(d>>1)))continue;
                if((j&d)||((j>>1)&d)||((j<<1)&d))continue;
                for(int c=0;c<=k;c++)if(c-num[j]>=0)
                    f[i][j][c]+=f[i-1][d][c-num[j]];
            }
        }
    long long ans=0;
    for(int i=0;i<s;i++)ans+=f[n][i][k];
    cout<<ans<<endl;
    return 0;
}