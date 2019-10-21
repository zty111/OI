#include<bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;
struct Node{
    Node* ch[2];
    int r,v,s,cnt=1;
    int cmp(int x)const{
        if(x==v)return -1;
        else return x<v?0:1;
    }
    void maintain(){
        s=cnt;
        if(ch[0]!=NULL)s+=ch[0]->s;
        if(ch[1]!=NULL)s+=ch[1]->s;
    }
};
Node* root=NULL;
void rotate(Node* &o,int d){
    Node* k=o->ch[d^1]; o->ch[d^1]=k->ch[d]; k->ch[d]=o;
    o->maintain(); k->maintain(); o=k;
}
void insert(Node* &o,int x){
    if(o==NULL){o=new Node(); o->ch[0]=o->ch[1]=NULL; o->r=rand(); o->v=x;}
    else{
        int d=o->cmp(x);
        if(d==-1)o->cnt++;
        else{insert(o->ch[d],x); if((o->ch[d]->r)>(o->r))rotate(o,d^1);}
    }
    o->maintain();
}
void remove(Node* &o,int x){
    int d=o->cmp(x);
    if(d==-1){
        if(o->cnt>1)o->cnt--;
        else if(o->ch[0]==NULL)o=o->ch[1];
        else if(o->ch[1]==NULL)o=o->ch[0];
        else{
            int d2=(o->ch[0]->r > o->ch[1]->r ? 1:0);
            rotate(o,d2); remove(o->ch[d2],x);
        }
    }
    else remove(o->ch[d],x);
    if(o!=NULL)o->maintain();
}
int kth(Node* o,int k){
    if(o==NULL || k<=0 || k>o->s)return 0;
    int s=(o->ch[0]==NULL ? 0:o->ch[0]->s);
    if(k>s && k<=s+o->cnt)return o->v;
    else if(k<=s)return kth(o->ch[0],k);
    else return kth(o->ch[1],k-s-o->cnt);
}
int Rank(Node* o,int x){
    if(o==NULL)return 0;
    int le=o->ch[0]==NULL ? o->cnt:o->ch[0]->s + o->cnt;
    if(o->v==x)return le-o->cnt+1;
    else if(o->v<x)return le+Rank(o->ch[1],x);
    else if(o->v>x)return Rank(o->ch[0],x);
}
void read(int &x)
{
    x=0;int f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    x*=f;
}
int getpre(Node* o,int x){
    int res=-INF;
    while(o!=NULL){
        if(o->v<x)res=o->v,o=o->ch[1];
        else o=o->ch[0];
    }return res;
}
int getsuf(Node* o,int x){
    int res=INF;
    while(o!=NULL){
        if(o->v>x)res=o->v,o=o->ch[0];
        else o=o->ch[1];
    }return res;
}
int main()
{
    int n;
    read(n);
    for(int i=1;i<=n;i++)
    {
        int opt,x;
        read(opt),read(x);
        if(opt==1)insert(root,x);
        if(opt==2)remove(root,x);
        if(opt==3)printf("%d\n",Rank(root,x));
        if(opt==4)printf("%d\n",kth(root,x));
        if(opt==5)printf("%d\n",getpre(root,x));
        if(opt==6)printf("%d\n",getsuf(root,x));
    }
    return 0;
}