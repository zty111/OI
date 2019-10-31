#include<bits/stdc++.h>
using namespace std;
int cnt[10010],n,a,m;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        m=max(m,a);
        for(int j=1;j*j<=m;j++){
            if(a%j==0){
                cnt[j]++;
                if(j*j!=a)cnt[a/j]++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        while(cnt[m]<i)m--;
        printf("%d\n",m);
    }
    return 0;
}
