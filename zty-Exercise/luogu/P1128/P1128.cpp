#include<bits/stdc++.h>
using namespace std;
int n,A,B,C,a[10000100];
double ans;
int main(){
    scanf("%d%d%d%d%d",&n,&A,&B,&C,a+1);
    for (int i=2;i<=n;i++)
    a[i] = ((long long)a[i-1] * A + B) % 100000001;
    for (int i=1;i<=n;i++)
    a[i] = a[i] % C + 1;
    a[n+1]=a[1];
    for(int i=1;i<=n;i++)ans+=1.0/max(a[i],a[i+1]);
    printf("%.3f",ans);
    return 0;
}