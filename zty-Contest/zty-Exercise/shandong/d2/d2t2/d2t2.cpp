#include<bits/stdc++.h>
using namespace std;
int n,x[5050],cnt,f[5050];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>x[i];
    sort(x+1,x+1+n);
    for(int i=1;i<=n;i++){
        int maxx=0,num=0;
        for(int k=1;k<=cnt;k++)
            if(f[k]>maxx&&f[k]<=x[i])
                maxx=f[k],num=k;
        if(maxx!=0)
            f[num]++;
        else{
            cnt++;
            f[cnt]=1;
        }
    }
    cout<<cnt<<endl;
    return 0;
}