#include<bits/stdc++.h>
using namespace std;
const int N = 1000010;
map<int,int>mp;
int cnt;
struct node{
    int i,j,m;
}a[N];
int fa[N];
int find(int n){
    return fa[n]==n?n:fa[n]=find(fa[n]);
}
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        mp.clear();cnt=0;
        scanf("%d",&n);
        for(int i=1;i<=2*n;i++)fa[i]=i;
        for(int i=1;i<=n;i++){
            scanf("%d %d %d",&a[i].i,&a[i].j,&a[i].m);
            if(!mp.count(a[i].i))mp[a[i].i]=++cnt;
            if(!mp.count(a[i].j))mp[a[i].j]=++cnt;
            if(a[i].m==1)fa[find(mp[a[i].i])]=find(mp[a[i].j]);
        }
        bool flag=1;
        for(int i=1;i<=n;i++){
            if(a[i].m==0){
                if(find(mp[a[i].i])==find(mp[a[i].j]))
                       flag=0;
            }
        }
        if(flag)puts("YES");
        else puts("NO");
    }
    return 0;
}