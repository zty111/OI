#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
struct process{
    int i,p;
}q[N];
struct pro{
    int m,cnt,i;
    bool operator <(const pro B)const{
        if(m==B.m)return i>B.i;
        else return m<B.m;
    }
};
priority_queue<pro>q1;
priority_queue<int>q2[N];
int m,cnt,r[N],vis[N];
char s[20];
int main(){
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%s",s+1);
        if(s[1]=='c'&&s[2]=='r'){
            int i,m,p;
            scanf("%d%d%d",&i,&m,&p);
            if(!r[i]||(r[i]&&vis[r[i]])){
                int old=r[i];
                r[i]=++cnt;
                q[cnt]=process{i,p};
                q1.push((pro){m,cnt,i});
                if(old&&vis[old])q2[cnt]=q2[old];
            }
            else printf("Error\n");
        }
        else if(s[1]=='m'){
            int i,p;
            scanf("%d%d",&i,&p);
            if(r[i])q2[r[i]].push(p);
            else printf("Error\n");
        }
        else if(s[1]=='p'){
            int i;
            scanf("%d",&i);
            if(r[i]){
                if(q2[r[i]].empty()){printf("Empty\n");}
                else{
                    printf("Process: %d\n",q2[r[i]].top());
                    q2[r[i]].pop();
                }
            }
            else printf("Error\n");
        }
        else if(s[1]=='r'){
            long long maxx=0;
            int num=0;
            for(int i=1;i<=cnt;i++){
                if(vis[i])continue;
                if(q2[i].empty())continue;
                if(1ll*q2[i].top()*q[i].p>maxx){
                    maxx=1ll*q2[i].top()*q[i].p;
                    num=i;
                }
            }
            if(num!=0){
                printf("Run: %lld\n",maxx);
                q2[num].pop();
            }
            else printf("Empty\n");
        }
        else if(s[1]=='c'){
            int i,p;
            scanf("%d%d",&i,&p);
            if(r[i])q[r[i]].p=p;
            else printf("Error\n");
        }
        else if(s[1]=='k'&&s[5]=='m'){
            if(q1.empty())printf("Empty\n");
            else{
                int now=q1.top().cnt,pid=q1.top().i;
                q1.pop();
                while((!q1.empty())&&vis[now]){
                    now=q1.top().cnt;
                    pid=q1.top().i;
                    q1.pop();
                }
                if(!vis[now]){
                    printf("Kill: %d\n",pid);
                    vis[now]=1;
                }
                else printf("Empty\n");
            }
        }
        else if(s[1]=='k'){
            int i;
            scanf("%d",&i);
            if(r[i])vis[r[i]]=1;
            else printf("Error\n");
        }
    }
    return 0;
}