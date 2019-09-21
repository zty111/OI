#include<cstdio>
#define eat(x) x+n
#define enemy(x) x+2*n
using namespace std;
const int N = 150010;
int n,a,b,k,opt,ans;
char ch;int fa[N];
inline int find(int x){
    if(x==fa[x])return x;
    return fa[x]=find(fa[x]);
}
inline void merge(int x,int y){
    x=find(x);y=find(y);
    fa[x]=y;
}
int main(){
    for(int i=1;i<N;i++)fa[i]=i;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=k;i++){
        scanf("%d %d %d",&opt,&a,&b);
        if(a>n||b>n)ans++;
        else if(opt==1){
            if(find(eat(a))==find(b)){ans++;continue;}
            if(find(a)==find(eat(b))){ans++;continue;}
            merge(find(a),find(b));
            merge(find(eat(a)),find(eat(b)));
            merge(find(enemy(a)),find(enemy(b)));
        }else{
            if(find(a)==find(b)){ans++;continue;}
            if(find(a)==find(eat(b))){ans++;continue;}
            merge(find(eat(a)),find(b));
            merge(find(a),find(enemy(b)));
            merge(find(enemy(a)),find(eat(b)));
        }
    }
    printf("%d",ans);
    return 0;
}
