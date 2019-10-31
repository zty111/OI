#include <cstdio>
#include <cstdlib>
#include <cstring>
#define max_(a,b) (a>b?a:b)
using namespace std;
inline void read(int &x){
    x=0;char c=getchar();
    int f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    x=x*f;
}
typedef long long ll;
const ll inf=(1ll<<60);
struct Matrix{ll a[2][2];Matrix(){a[0][0]=a[0][1]=a[1][0]=a[1][1]=-inf;}};
inline Matrix operator *(Matrix A,Matrix B){
    Matrix C;
    for(int i=0;i<2;++i)
        for(int j=0;j<2;++j)
            for(int k=0;k<2;++k)
                C.a[i][j]=max_(C.a[i][j],A.a[i][k]+B.a[k][j]);
    return C;
}
const int N=100010;
int v[N],d[N],nxt[N<<1],to[N<<1],tot;
ll dp[N][2],ss;
inline void ins(int a,int b){to[++tot]=b;nxt[tot]=d[a];d[a]=tot;}
struct link_cut_tree{
    Matrix val[N],prd[N];
    int ch[N][2],fa[N];
    #define lc ch[x][0]
    #define rc ch[x][1]
    inline void pushup(int x){prd[x]=val[x];if(lc)prd[x]=prd[lc]*prd[x];if(rc)prd[x]=prd[x]*prd[rc];}
    inline bool root(int x){int y=fa[x];return !((ch[y][0]==x)||(ch[y][1]==x));}
    inline void rotate(int x){
        int y=fa[x],z=fa[y],k=ch[y][1]==x;
        if(!root(y))ch[z][ch[z][1]==y]=x;
        fa[x]=z;ch[y][k]=ch[x][k^1];if(ch[x][k^1])fa[ch[x][k^1]]=y;
        ch[x][k^1]=y;fa[y]=x;pushup(y);pushup(x);
    }inline void splay(int x){
        int y,z;
        while(!root(x)){
            y=fa[x],z=fa[y];
            if(!root(y)){(ch[y][1]==x)^(ch[z][1]==y)?rotate(x):rotate(y);}
            rotate(x);
        }
    }
    inline void access(int x){
        for(int y=0;x;x=fa[y=x]){
            splay(x);
            if(rc){
                val[x].a[0][0]+=max_(prd[rc].a[0][0],prd[rc].a[1][0]);
                val[x].a[1][0]+=prd[rc].a[0][0];
            }
            if(y){
                val[x].a[0][0]-=max_(prd[y].a[0][0],prd[y].a[1][0]);
                val[x].a[1][0]-=prd[y].a[0][0];
            }val[x].a[0][1]=val[x].a[0][0];
            rc=y;pushup(x);
        }
    }
    inline void modify(int x,ll y){
        access(x);splay(x);
        val[x].a[1][0]+=y;
        pushup(x);
    }
    inline void dfs(int x){
        dp[x][1]=v[x];
        for(int i=d[x];i;i=nxt[i]){
            int u=to[i];
            if(u!=fa[x]){
                fa[u]=x;
                dfs(u);
                dp[x][0]+=max_(dp[u][0],dp[u][1]);
                dp[x][1]+=dp[u][0];
            }
        }
        val[x].a[0][0]=val[x].a[0][1]=dp[x][0];
        val[x].a[1][0]=dp[x][1];
        prd[x]=val[x];
    }
}my;
int n,m;
char s[5];
inline void solve(int a,int x,int b,int y){
    my.modify(a,x?-inf:inf);my.modify(b,y?-inf:inf);
    my.splay(1);ss+=((x^1)+(y^1))*inf;
    ll p=ss-max_(my.prd[1].a[0][0],my.prd[1].a[1][0]);
    my.modify(a,x?inf:-inf);my.modify(b,y?inf:-inf);
    ss-=((x^1)+(y^1))*inf;
    if(p>inf){printf("-1\n");return;}
    printf("%lld\n",p);
}
int main(){
    read(n);read(m);scanf("%s",s);
    for(int i=1;i<=n;++i){read(v[i]);ss+=v[i];}
    int a,b,p1,p2;
    for(int i=1;i<n;++i){read(a);read(b);ins(a,b);ins(b,a);}
    my.dfs(1);
    for(int i=1;i<=m;++i){
        read(a);read(p1);read(b);read(p2);
        solve(a,p1,b,p2);
    } 
    return 0;
}