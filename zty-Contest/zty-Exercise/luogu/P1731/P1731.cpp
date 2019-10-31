#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int n,m,ans,s,v,v_min[20],s_min[20],h[20],r[20];
int v_max(int dep){
    int ans=0;
    int hi=h[dep+1],ri=r[dep+1];
    if(hi==inf)hi=20000;
    if(ri==inf)ri=200;
    for(int i=dep;i>=1;i--){
        hi--;ri--;
        ans+=hi*ri*ri;
        if(ans>20000)return 20000;
    }
    return ans;
}
void dfs(int dep){
    if(dep<1){if(n==v)ans=min(ans,s);return;}
    if(s+s_min[dep]>=ans)return;
    if(v+v_min[dep]>n||v+v_max(dep)<n)return;
    if(2*(n-v)/r[dep+1]+s>ans)return;
    for(int i=min(int(sqrt(n-v)),r[dep+1]-1);i>=dep;i--)
        for(int j=min((n-v)/(i*i),h[dep+1]-1);j>=dep;j--){
            r[dep]=i;h[dep]=j;
            if(dep==m)s=i*i;
            s+=2*i*j;
            v+=i*i*j;
            dfs(dep-1);
            v-=i*i*j;
            s-=2*i*j;
            r[dep]=inf;h[dep]=inf;
        }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=19;i++)h[i]=r[i]=inf;
    for(int i=1;i<=m;i++){
        v_min[i]=v_min[i-1]+i*i*i;
        s_min[i]=s_min[i-1]+i*i;
    }
    ans=inf;
    dfs(m);
    if(ans!=inf)printf("%d\n",ans);
    else printf("0\n");
    return 0;
}