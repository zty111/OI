#include<bits/stdc++.h>
using namespace std;
const int maxn = 5000010;
struct node{
    node* ch[2];
    int v,r,s;
    void maintain(){s=1+ch[0]->s+ch[1]->s;}
};
node* null=new node();
node* root=null;
node* nodes[maxn];
int cnt;
void newnode(node* &o,int w){
    o=nodes[++cnt];
    o->s=1; o->ch[0]=o->ch[1]=null;
    o->v=w; o->r=rand();
}
node* merge(node* a,node* b){
    if(a==null)return b;
    if(b==null)return a;
    if(a->r > b->r){
        node* p=b;
        p->ch[0]=merge(a,p->ch[0]);
        p->maintain();return p;
    }
    else{
        node* p=a;
        p->ch[1]=merge(p->ch[1],b);
        p->maintain();return p;
    }
}
void split(node* o,int k,node* &x,node* &y){
    if(o==null){x=y=null;return;}
    if(o->v<=k){
        x=o;
        split(x->ch[1],k,x->ch[1],y);
        x->maintain();
    }
    else{
        y=o;
        split(y->ch[0],k,x,y->ch[0]);
        y->maintain();
    }
}
void Delete(node* &o,int w){
    node *x,*y,*z;
    split(o,w,x,z);
    split(x,w-1,x,y);
    y=merge(y->ch[0],y->ch[1]);
    o=merge(merge(x,y),z);
}
void Insert(node* &o,int w){
    node *x,*y,*z; 
    split(o,w,x,y);
    newnode(z,w);
    o=merge(merge(x,z),y);
}
int getval(node* o,int w){
    if(w==o->ch[0]->s+1)return o->v;
    else if(w<=o->ch[0]->s)return getval(o->ch[0],w);
    else return getval(o->ch[1],w-o->ch[0]->s-1);
}
int getkth(node* &o,int w){
    node *x,*y;
    split(o,w-1,x,y);
    int ans=x->s+1;
    o=merge(x,y);
    return ans;
}
int getpre(node* &o,int w){
    node *x,*y;
    int k,ans;
    split(o,w-1,x,y);
    if(!x)return -2147483647;
    k=x->s;
    ans=getval(x,k);
    o=merge(x,y);
    return ans;
}
int getnex(node* &o,int w)
{
    node *x,*y;
    int ans;
    split(o,w,x,y);
    if(!y)return 2147483647;
    else ans=getval(y,1);
    o=merge(x,y);
    return ans;
}
int main()
{
    int n,f,w;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d %d",&f,&w);
        if(f==1)Insert(root,w);
        else if(f==2)Delete(root,w);
        else if(f==3)printf("%d\n",getkth(root,w));
        else if(f==4)printf("%d\n",getval(root,w));
        else if(f==5)printf("%d\n",getpre(root,w));
        else printf("%d\n",getnex(root,w));
    }
    return 0;
}
