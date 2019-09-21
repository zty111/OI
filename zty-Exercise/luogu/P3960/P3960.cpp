#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct Node{
    int v,s,cnt=1;
    Node* ch[2];
    void maintain(){
        s=cnt;
        if(ch[0]!=NULL)s+=ch[0]->s;
        if(ch[1]!=NULL)s+=ch[1]->s;
    }
    int cmp(int x)const{
        if(v==x)return -1;
        return x<v?0:1;
    }
};
Node* root=NULL;
void rotate(Node* &o,int d){
    Node* k=o->ch[d^1]; o->ch[d^1]=k->ch[d]; k->ch[d]=o;
    o->maintain(); k->maintain(); o=k;
}
void splay(Node* &o,int k){
    int d=o->cmp(k);
    if(d!=-1){
        Node* p=o->ch[d];
        int d2=p->cmp(k);
        if(d2!=-1){
            splay(p->ch[d2],k);
            if(d==d2)rotate(o,d^1);
            else rotate(o->ch[d],d);
        }
        rotate(o,d^1);
    }
}
void insert(Node* &o,int k){
    if(o==NULL){o=new Node();o->ch[0]=o->ch[1]=NULL; o->v=k; o->maintain(); splay(root,k);}
    else{
        int d=o->cmp(k);
        if(d==-1){o->cnt++;o->maintain();splay(root,k);}
        else insert(o->ch[d],k);
    }
    //o->maintain();
}
int pre(Node*,int);
void remove(int x){
    splay(root,x);
    if(root->cnt > 1){root->cnt--;return;}
    if(root->ch[0]==NULL)root=root->ch[1];
    else if(root->ch[1]==NULL)root=root->ch[0];
    else{
        int k=pre(root,x);
        splay(root->ch[0],k);
        Node* lc=root->ch[0];lc->ch[1]=root->ch[1];
        lc->maintain();
        root=lc;
    }
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
int pre(Node* o,int x){
    int res=-INF;
    while(o!=NULL){
        if(o->v<x)res=o->v,o=o->ch[1];
        else o=o->ch[0];
    }return res;
}
int suf(Node* o,int x){
    int res=INF;
    while(o!=NULL){
        if(o->v>x)res=o->v,o=o->ch[0];
        else o=o->ch[1];
    }return res;
}
void read(int &x){
    x=0;int f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    x*=f;
}
int main(){
    int n;
    read(n);
    for(int i=1;i<=n;i++){
        int opt,x;
        read(opt),read(x);
        if(opt==1)insert(root,x);
        if(opt==2)remove(x);
        if(opt==3){printf("%d\n",Rank(root,x));splay(root,x);}
        if(opt==4)printf("%d\n",kth(root,x));
        if(opt==5)printf("%d\n",pre(root,x));
        if(opt==6)printf("%d\n",suf(root,x));
    }
    return 0;
}