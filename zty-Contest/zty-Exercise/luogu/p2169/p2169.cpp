#include<cstdio>
const int N = 100001;
int tree[N],endd[N],n;
void add(int x,int c){
	for(;x<N;x+=x&-x)tree[x]+=c;
}
int ask(int x){
    int sum=0;
    for(;x;x-=x&-x)sum+=tree[x];
    return sum;
}
using namespace std;
int main(){
    scanf("%d",&n);
    int ans=0;
    for(int i=1;i<=n;i++){
        char ch[2];
        scanf("%s",ch);
        if(ch[0]=='A'){
            int del=0,st,ed;
            scanf("%d %d",&st,&ed);
            for(int p=ask(ed);p;p=ask(ed)){
                int l=0,r=ed;
                while(l<r){
                    int m=(l+r)/2;
                    if(ask(m)+1<=p)l=m+1;
                    else r=m;
                }
                if(endd[l]>=st)add(l,-1),del++,ans--;
                else break;
            }
            add(st,1);endd[st]=ed;ans++;
            printf("%d\n",del);
        }
        else printf("%d\n",ans);
    }
    return 0;
}
