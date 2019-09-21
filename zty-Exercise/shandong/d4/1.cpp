#include<bits/stdc++.h>
using namespace std;
int n,k,d;
struct node{
    int p,h;
    long long w;
    bool operator < (const node B)const{
        if(w==B.w)return h<B.h;
        else return w>B.w;
    }
}a[100010];
priority_queue<node>Q;
int main(){
    scanf("%d%d%d",&n,&k,&d);
    for(int i=1;i<=n;i++){
        scanf("%d%lld",&a[i].h,&a[i].w);
        a[i].p=i;
    }
    Q.push(a[1]);
    for(int i=2;i<=n;i++){
        while(!Q.empty()&&Q.top().p<i-k)Q.pop();
        node u=Q.top();
        a[i].w+=(u.w+(a[i].h>=u.h?d:0));
        Q.push(a[i]);
    }
    printf("%lld\n",a[n].w);
    return 0;
}