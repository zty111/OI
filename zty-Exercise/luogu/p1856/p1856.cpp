#include<bits/stdc++.h>
using namespace std;
const int N = 80010;
const int T = 10000;
struct bar{
    int x,y1,y2,flag;
}c1[N],c2[N];
int t1,t2;
bool cmp(bar A,bar B){
    return A.x==B.x?A.flag>B.flag:A.x<B.x;
}
int co[N],ans;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        c1[++t1].x=a;c1[t1].y1=b;c1[t1].y2=d;c1[t1].flag=1;
        c1[++t1].x=c;c1[t1].y1=b;c1[t1].y2=d;c1[t1].flag=-1;
        c2[++t2].x=b;c2[t2].y1=a;c2[t2].y2=c;c2[t2].flag=1;
        c2[++t2].x=d;c2[t2].y1=a;c2[t2].y2=c;c2[t2].flag=-1;
    }
    sort(c1+1,c1+t1+1,cmp);
    sort(c2+1,c2+t2+1,cmp);
    for(int i=1;i<=t1;i++){
        for(int j=c1[i].y1;j<c1[i].y2;j++){
            if(!co[j+T])++ans;
            co[j+T]+=c1[i].flag;
            if(!co[j+T])++ans;
        }
    }
    for(int i=1;i<=t2;i++){
        for(int j=c2[i].y1;j<c2[i].y2;j++){
            if(!co[j+T])++ans;
            co[j+T]+=c2[i].flag;
            if(!co[j+T])++ans;
        }
    }
    printf("%d\n",ans);
    return 0;
}