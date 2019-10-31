#include<bits/stdc++.h>
using namespace std;
const int N = 100000;
int n,a0,a1,b0,b1;
int p[N],cnt,ans[20000][32],c;bool vis[N];
void pre(){
    int m=sqrt(2e9+0.5);
    for(int i=2;i<=m;i++){
        if(!vis[i])p[++cnt]=i;
        for(int j=1;j<=cnt&&i*p[j]<=m;j++){
            vis[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
}
int gcd(int a,int b){
    if(!b)return a;
    else return gcd(b,a%b);
}
int main(){
    pre();
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        memset(ans,0,sizeof(ans));
        scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
        int temp=b1;
        for(int i=1;i<=cnt;i++){
            int now=1;
            while(b1%p[i]==0){
                b1/=p[i];
                now*=p[i];
                ans[i][++ans[i][0]]=now;
            }
        }
        int cntans=0;b1=temp;
        for(int i=1;i<=cnt;i++){
            if(ans[i][0]==0)continue;
            for(int k=1;k<=ans[i][0];k++){
                if(gcd(ans[i][k],a0)==a1&&((ans[i][k]*b0)/gcd(ans[i][k],b0)==b1))cntans++;
                for(int j=i+1;j<=cnt;j++){
                    if(ans[j][0]==0)continue;
                    for(int kk=1;kk<=ans[j][0];kk++){
                        int now=ans[i][k]*ans[j][kk];
                        if(now==96)cout<<now<<endl;
                        if(gcd(now,a0)==a1&&((now*b0)/gcd(now,b0)==b1))cout<<now<<endl,cntans++;
                    }
                }
            }
        }
        printf("%d\n",cntans);
    }
    return 0;
}