#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
struct Dte{
    int i,p,ph;
    bool operator < (const Dte B)const{
        return (1ll*p*ph)<(1ll*B.p*B.ph);
    }
};
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii> >q1;
priority_queue<int>q2[N];
priority_queue<Dte>q3;
int n,vis[N],h[N],mem[N];
char s[20];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        if(s[1]=='c'&&s[2]=='r'){
            int i,m,p;
            scanf("%d%d%d",&i,&m,&p);
            if(!vis[i]){
                q1.push(make_pair(-m,i));
                vis[i]=1;h[i]=p;mem[i]=m;
              //  if(!q2[i].empty())
              //     q3.push((Dte){i,q2[i].top(),h[i]});
            }
            else printf("Error\n");
        }
        else if(s[1]=='m'){
            int i,p;
            scanf("%d%d",&i,&p);
            if(vis[i]){
                q2[i].push(p);
                q3.push((Dte){i,p,h[i]});
            }
            else printf("Error\n");
        }
        else if(s[1]=='p'){
            int i;
            scanf("%d",&i);
            if(vis[i]){
                if(q2[i].empty()){printf("Empty\n");}
                else{
                    printf("Process: %d\n",q2[i].top());
                    q2[i].pop();
                    if(!q2[i].empty())q3.push((Dte){i,q2[i].top(),h[i]});
                }
            }
            else printf("Error\n");
        }
        else if(s[1]=='r'){
            if(q3.empty()){printf("Empty\n");continue;}
            int flag=1;Dte now=q3.top();q3.pop();
            while((!vis[now.i])||h[now.i]!=now.ph||q2[now.i].empty()||(now.p!=q2[now.i].top())){
                if(q3.empty()){
                    printf("Empty\n");
                    flag=0;
                    break;
                }
                now=q3.top();q3.pop();
            }
            if(!flag){continue;}
            printf("Run: %lld\n",1ll*now.p*now.ph);
            q2[now.i].pop();
            if(!q2[now.i].empty()){
                q3.push((Dte){now.i,q2[now.i].top(),h[now.i]});
            }
        }
        else if(s[1]=='c'){
            int i,p;
            scanf("%d%d",&i,&p);
            if(vis[i]){
                h[i]=p;
                if(!q2[i].empty())q3.push((Dte){i,q2[i].top(),h[i]});
            }
            else printf("Error\n");
        }
        else if(s[1]=='k'&&s[5]=='m'){
            if(q1.empty())printf("Empty\n");
            else{
                int pid=q1.top().second,mm=q1.top().first,flag=1;
                q1.pop();
                while((!vis[pid])||(mem[pid]!=(-mm))){
                    if(q1.empty()){flag=0;break;}
                    pid=q1.top().second;
                    mm=q1.top().first;
                    q1.pop();
                }
                if(flag){
                    printf("Kill: %d\n",pid);
                    vis[pid]=0;
                }
                else printf("Empty\n");
            }
        }
        else if(s[1]=='k'){
            int i;
            scanf("%d",&i);
            if(vis[i])vis[i]=0;
            else printf("Error\n");
        }
    }
    return 0;
}