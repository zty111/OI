#include<bits/stdc++.h>
using namespace std;
int prim[10]={2,3,5,7,11,13,17,19,23,29};
int ans,CNT,n;
void dfs(int i,int num,int cnt,int last){
    if(i==10){
        if(cnt>CNT||(cnt==CNT&&ans>num))
            ans=num,CNT=cnt;
        return;
    }
    long long t=1;
    for(int j=0;j<=last;j++){
        if(num*t>n)break;
        dfs(i+1,num*t,cnt*(j+1),j);
        t*=prim[i];
    }
}
int main(){
    scanf("%d",&n);
    dfs(0,1,1,10);
    printf("%d\n",ans);
    return 0;
}