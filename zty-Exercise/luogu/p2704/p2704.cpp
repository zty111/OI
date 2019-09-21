#include<bits/stdc++.h>
using namespace std;
int n,m,c[1<<10],v[110][1<<10];
int f[2][1<<10][1<<10],ok[110];
char ch[110][11];
const int inf=0x3f3f3f3f;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            cin>>ch[i][j];
            ok[i]=(ok[i]<<1)+(ch[i][j]=='P'?1:0);
        }

    for(int i=0;i<(1<<m);i++){
        int s=i;
        while(s>0){
            if((s&1)==1)c[i]++;
            s>>=1;
        }
    }
    v[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int x=0;x<(1<<m);x++){
            if((x|ok[i])==ok[i])
                if(!((x>>2)&x)&&!((x<<2)&x)&&!((x>>1)&x)&&!((x<<1)&x))
                    v[i][x]=1;
        }
    memset(f,-0x3f,sizeof(f));
    f[0][0][0]=0;int o=1;
    for(int i=1;i<=n;i++,o^=1){
        for(int j=0;j<(1<<m);j++){
            if(!v[i][j])continue;
            for(int k=0;k<(1<<m);k++){
                if(!v[i-1][k])continue;
                if((j&k)!=0)continue;
                int maxx=-inf;
                for(int l=0;l<(1<<m);l++)
                    if((j&l)==0)maxx=max(f[o^1][k][l],maxx);
                //cout<<i<<' '<<j<<' '<<k<<' '<<maxx<<endl;
                f[o][j][k]=maxx+c[j];
            }
        }
    }
    int ans=-inf;
    for(int j=0;j<(1<<m);j++){
        if(!v[n][j])continue;
        for(int k=0;k<(1<<m);k++){
            if(!v[n-1][k])continue;
            if((j&k)!=0)continue;
            ans=max(ans,f[o^1][j][k]);
        }
    }
    cout<<ans<<endl;
    return 0;
}