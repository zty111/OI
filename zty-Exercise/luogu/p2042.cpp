#include<bits/stdc++.h>
using namespace std;
struct node{
    node* ch[2];
    int v,s,flip,dat,lmax,rmax,sum;
    int cmp(int x)const{
        if(x==ch[0]->s+1)return -1;
        return x<=ch[0]->s?0:1;
    }
    void pushdown(){
        if(flip){
            flip=0;
            swap(ch[0],ch[1]);
            ch[0]->flip=!ch[0]->flip;
            ch[1]->flip=!ch[1]->flip;
        }
    }
    void maintain(){
        s=ch[0]->s+ch[1]->s+1;
        sum=ch[0]->sum+ch[1]->sum;
        lmax=max(ch[0]->lmax,ch[0]->sum+ch[1]->lmax);
        rmax=max(ch[1]->rmax,ch[1]->sum+ch[0]->rmax);
        dat=max(ch[0]->dat,ch[1]->dat);
        dat=max(dat,ch[0]->rmax+ch[1]->lmax);
    }
};
node* null=new node();
node* root;
node nodes[1000010];
int tot;
void rotate(node* &o,int d){
    node* k=o->ch[d^1];
    o->ch[d^1]=k->ch[d];
    k->ch[d]=o;
    o->maintain();
    k->maintain();
    o=k;
}
void splay(node* &o,int k){
    int d=o->cmp(k);
    if(d==1)k-=o->ch[0]->s+1;
    if(d!=-1){
        node* p=o->ch[d];
        int d2=p->cmp(k);
        int k2=(d2==0?k:k-p->ch[0]->s-1);
        if(d2!=-1){
            splay(p->ch[d2],k2);
            if(d==d2)rotate(o,d^1);
            else rotate(o->ch[d],d);
        }
        rotate(o,d^1);
    }
}
void split(node* o,int k,node* &l,node* &r){
    splay(o,k);
    l=o;
    r=o->ch[1];
    o->ch[1]=NULL;
    l->maintain();
}
void merge(node* &l,node* &r){
    if(l==null)l=r;
    else{
        splay(l,l->s);
        l->ch[1]=r;
        l->maintain();
    }
}
int n,m,a[500010];
inline void read(int &x){
    x=0;int f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    x*=f;
}
node* newnode(int x){
    o=&nodes[tot++];
    o->flip=0;
    o->v=x;
    o->dat=o->rmax=o->lmax=o->sum=o->v;
}
void build(node* &o,int l,int r){
    o=null;
    if(l>r)return;
    if(l==r)o=newnode(a[l]);
    int m=(l+r)>>1;
    build(o->ch[0],l,m-1);
    build(o->ch[1],m+1,r);
    o->maintain();
}
char s[15];
int main(){
    read(n);read(m);
    for(int i=1;i<=n;i++)read(a[i]);
    build(root,1,n);
    for(int i=1;i<=m;i++){
        scanf("%s",s);
        if(s[0]=='I'){

        }
        else if(s[0]=='D'){

        }
        else if(s[0]=='M'&&s[1]=='A'&&s[2]=='K'){
            
        }
        else if(s[0]=='R'){

        }
        else if(s[0]=='G'){

        }
        else{
            
        }
    }
    return 0;
}
