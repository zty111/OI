#include<bits/stdc++.h>
using namespace std;
int n,s,p,ans;
void dfs(int now,int sum,int last){
    if(sum>=s&&now<=n)return;
    if(now>n){if(sum==s)ans++;return;}
    if(last==-1)
        for(int i=1;i<=s;i++)
            dfs(now+1,sum+i,i);
    else
        for(int i=max(last-p,1);i<=last+p;i++)
            dfs(now+1,sum+i,i);
}
int main(){
    cin>>n>>s>>p;
    dfs(1,0,-1);
    cout<<ans;
    return 0;
}