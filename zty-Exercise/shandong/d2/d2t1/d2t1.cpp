#include<bits/stdc++.h>
using namespace std;
char a[110][110];
int n,ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    for(int i=2;i<=n-1;i++)
        for(int j=2;j<=n-1;j++){
            if(a[i][j]=='#'&&a[i-1][j]=='#'&&a[i+1][j]=='#'&&a[i][j-1]=='#'&&a[i][j+1]=='#')
                a[i][j]=a[i-1][j]=a[i+1][j]=a[i][j-1]=a[i][j+1]='.';
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(a[i][j]=='#')ans=1;
    if(ans)printf("NO\n");
    else printf("YES\n");
    return 0;
}