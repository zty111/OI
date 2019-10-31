#include<bits/stdc++.h>
using namespace std;
struct pro{
    int id,st,t,pr;
    bool operator<(const pro B)const{
        if(pr==B.pr)return id>B.id;
        else return pr<B.pr;
    }
}A;
long long tim;
priority_queue<pro>Q;
int main(){
    while(scanf("%d%d%d%d",&A.id,&A.st,&A.t,&A.pr)==4){
        while(!Q.empty()&&tim+Q.top().t<=A.st){
            tim+=Q.top().t;
            printf("%d %lld\n",Q.top().id,tim);
            Q.pop();
        }
        if(!Q.empty()){
            pro u=Q.top();
            Q.pop();
            u.t-=A.st-tim;
            Q.push(u);
        }
        Q.push(A);
        tim=A.st;   
    }
    while(!Q.empty()){
        tim+=Q.top().t;
        printf("%d %lld\n",Q.top().id,tim);
        Q.pop();
    }
    return 0;
}