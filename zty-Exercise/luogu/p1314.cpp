#include<bits/stdc++.h>
using namespace std;
const int N = 200100;
typedef long long ll;
int n,m,w[N],v[N],l[N],r[N],W,Wn=0x3f3f3f3f;
ll pre[N],prn[N];
ll s,Ans,ans;
inline int read(){
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
    return x;
}
bool check(int x){
    memset(pre,0,sizeof(pre));
    memset(prn,0,sizeof(prn));
    for(int i=1;i<=n;i++){
        if(w[i]>=x){
            pre[i]=pre[i-1]+v[i];
            prn[i]=prn[i-1]+1;
        }
        else{
            pre[i]=pre[i-1];
            prn[i]=prn[i-1];
        }
    }
    Ans=-s;
    for(int i=1;i<=m;i++){
        Ans+=(pre[r[i]]-pre[l[i]-1])*(prn[r[i]-prn[l[i]-1]]);
    }
    return Ans<=0;
}
int main(){
    n=read();m=read();
    scanf("%lld",&s);
    for(int i=1;i<=n;i++){
        w[i]=read();v[i]=read();
        W=max(W,w[i]);
        Wn=min(Wn,w[i]);
    }
    for(int i=1;i<=m;i++){
        l[i]=read();r[i]=read();
    }
    int L=Wn-1,R=W+2;
    ans=0x3f3f3f3f3f3f3f3f;
    while(L<=R){
        int mid=(L+R)/2;
        if(check(mid))R=mid-1;
        else R
        Ans=abs(Ans);
        cout<<Ans<<endl;
        if(ans>Ans)ans=Ans;
    }
    printf("%lld",ans);
    return 0;
}
