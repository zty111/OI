#include<cstdio>
#include<cstring>
#include<algorithm>
#define re register
using namespace std;
int n,m;
int u,v;
int val[100010];
int head[100010];
struct node{
    int to,next;
}edge[200010];
struct node1{
    int l,r,ll,rr,w,lazy;
}tree[400010];
struct ret{
    int l,r,w;
};
int tid[100010];
int tx[100010];
int top[100010];
int deep[100010];
int cnt;

int size[100010];
int son[100010];
int fa[100010];
int a,b;
int c;
char ch;
int k;
void adde(int u,int v){
    edge[++k].to=v;
    edge[k].next=head[u];
    head[u]=k;
}
void dfs1(int now,int f){
    size[now]=1;
    fa[now]=f;
    deep[now]=deep[f]+1;
    for(re int i=head[now];i;i=edge[i].next){
        int mp=edge[i].to;
        if(mp==f)continue;
        dfs1(mp,now);
        size[now]+=size[mp];
        if(size[mp]>size[son[now]])son[now]=mp;
    }
}
void dfs2(int now,int top1){
    tx[now]=++cnt;
    tid[cnt]=now;
    top[now]=top1;
    if(!son[now])return ;
    dfs2(son[now],top1);
    for(int i=head[now];i;i=edge[i].next){
        int mp=edge[i].to;
        if(mp!=fa[now]&&mp!=son[now])dfs2(mp,mp);
    }
}
void build(int now,int l,int r){
    tree[now].l=l;
    tree[now].r=r;
    if(l==r){
        tree[now].ll=val[tid[l]];tree[now].rr=val[tid[l]];tree[now].w=1;
        return ;//忘记返回 
    }
    int mid=l+r>>1;
    build(now<<1,l,mid);
    build(now<<1|1,mid+1,r);
    tree[now].ll=tree[now<<1].ll;
    tree[now].rr=tree[now<<1|1].rr;
    if(tree[now<<1].rr==tree[now<<1|1].ll) tree[now].w=tree[now<<1].w+tree[now<<1|1].w-1;
    else tree[now].w=tree[now<<1].w+tree[now<<1|1].w;
}
void ondata(int now){
    if(tree[now].l==tree[now].r)return ;
    tree[now<<1].ll=tree[now<<1|1].ll=tree[now<<1].rr=tree[now<<1|1].rr=tree[now<<1].lazy=tree[now<<1|1].lazy=tree[now].lazy;
    tree[now].lazy=0;
    tree[now<<1].w=tree[now<<1|1].w=1;
}
void change(int now,int l,int r,int w){
    if(tree[now].l>=l&&tree[now].r<=r){
        tree[now].ll=w;
        tree[now].rr=w;
        tree[now].w=1;
        tree[now].lazy=w;
        return ;
    }
    if(tree[now].lazy)ondata(now);
    int mid=(tree[now].l+tree[now].r)>>1;
    if(mid<l)change(now<<1|1,l,r,w);
    else if(mid>=r)change(now<<1,l,r,w);
    else change(now<<1,l,mid,w),change(now<<1|1,mid+1,r,w);
    tree[now].ll=tree[now<<1].ll;
    tree[now].rr=tree[now<<1|1].rr;
    if(tree[now<<1].rr==tree[now<<1|1].ll) tree[now].w=tree[now<<1].w+tree[now<<1|1].w-1;
    else tree[now].w=tree[now<<1].w+tree[now<<1|1].w;
}
ret find(int now,int l,int r){
    if(tree[now].l>=l&&tree[now].r<=r){
        ret temp; 
        temp.l=tree[now].ll,temp.r=tree[now].rr,temp.w=tree[now].w;
        return temp;
    }
    if(tree[now].lazy)ondata(now);
    int mid=(tree[now].l+tree[now].r)>>1;
    if(mid>=r)return find(now<<1,l,r);
    else if(mid<l)return find(now<<1|1,l,r);
    else {
        ret temp1=find(now<<1,l,mid),temp2=find(now<<1|1,mid+1,r),temp;
        temp.l=temp1.l,temp.r=temp2.r;//写成了temp1 
        temp.w=temp1.w+temp2.w;
        if(tree[now<<1].rr==tree[now<<1|1].ll)temp.w--; 
        return temp;
    }
}
int findway(int x,int y){
    int sum=0;
    int l1=-1,l2=-1;
    while(top[x]!=top[y]){
        if(deep[top[x]]<deep[top[y]])swap(x,y),swap(l1,l2);
        ret temp=find(1,tx[top[x]],tx[x]);
        sum+=temp.w;
        if(temp.r==l1)sum--;
        l1=temp.l;
        x=fa[top[x]];
    }
    if(deep[x]>deep[y])swap(x,y),swap(l1,l2);
    ret temp=find(1,tx[x],tx[y]);
    sum+=temp.w;
    if(temp.r==l2)sum--;
    if(temp.l==l1)sum--;//写反 
    return sum;
}
void changeway(int x,int y,int w){
    while(top[x]!=top[y]){
        if(deep[top[x]]<deep[top[y]])swap(x,y);
        change(1,tx[top[x]],tx[x],w);
        x=fa[top[x]];
    }
    if(deep[x]>deep[y])swap(x,y);
    change(1,tx[x],tx[y],w);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&val[i]);
    for(int i=1;i<n;i++)scanf("%d%d",&u,&v),adde(u,v),adde(v,u);
    dfs1(1,1);
    dfs2(1,1);
    build(1,1,n);
    for(int i=1;i<=m;i++){
        scanf("\n%c",&ch);
        switch(ch){
            case 'Q':{
                scanf("%d%d",&a,&b);
                printf("%d\n",findway(a,b));
                break;
            }
            case 'C':{
                scanf("%d%d%d",&a,&b,&c);
                changeway(a,b,c);
                break;
            }
        }
    }
    return 0;
}