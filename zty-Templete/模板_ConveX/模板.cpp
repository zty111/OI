using namespace std;

const int N=100010;
const int M=1010;
const int INF=0x7f7f7f7f;
int m,n;

namespace DSU//并查集 
{
	int fa[N];
	
	int find(int x)
	{
		if(fa[x]==x) return fa[x];
		return fa[x]=find(fa[x]);
	}
	void unite(int t1,int t2)
	{
		fa[find(t2)]=find(t1);
	}
	bool query(int t1,int t2)
	{
		return find(t1)==find(t2);
	}
	void init()
	{
		for(int i=1;i<=n;i++) fa[i]=i;
	}
}
namespace WDSU//权值并查集 
{
	int fa[N];
	
	void maintain(int x,int fa){;}
	
	int find(int x)
	{
		if(x!=fa[x])
		{
			int f=fa[x];
			fa[x]=find(fa[x]);
			maintain(x,f);
		}
		return fa[x];
	}
	void unite(int t1,int t2)
	{
		fa[find(t2)]=find(t1);
	}
}
namespace CAL//邻接表 
{
	int head[N],cnt;
	
	struct node
	{
		int from;
		int to;
		int nxt;
		int val;
	}edge[N<<1];
	
	void addedge(int x,int y,int z)
	{
		edge[++cnt].to=y;
		edge[cnt].nxt=head[x];
		edge[cnt].val=z;
		edge[cnt].from=x;
		head[x]=cnt;
	}
}
namespace MST_Kruskal//最小生成树 
{
	using namespace CAL;
	
	bool cmp(node a,node b)
	{
		return a.val<b.val;
	}
	void init()
	{	
		sort(edge+1,edge+m+1,cmp);
	}
	int kruskal()
	{
		using namespace DSU;
		int ans=0;
		for(int i=1;i<=m;i++)
		{
			int t1=edge[i].from;
			int t2=edge[i].to;     
			int p1=find(t1);
	        int p2=find(t2);
	        if(p1==p2) continue;
	        ans+=edge[i].val;
	        fa[p1]=p2;
	        if(++cnt==n) break;
	    }
	    return ans;
	}
}
namespace MST_Prim//最小生成树 
{
	int dep[M];
	bool vis[M];
	int T[M][M];
	
	void init()
	{	
		memset(dep,0x3f,sizeof(dep));
		dep[1]=0;
	}
	int Prim()
	{
		int ans=0;
		for(int i=1,tmp=INF,k=0;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(!vis[j]&&dep[j]<tmp)
				{
					tmp=dep[j];
					k=j;
				}
			}
			vis[k]=true;
			ans+=tmp;
			for(int j=1;j<=n;j++)
			{
				if(!vis[j])
				dep[j]=min(dep[j],T[k][j]);
			}
		}
		return ans;
	}
}
namespace SP_SPFA//最短路 
{
	int s;
	int t;
	int dep[N];
	bool vis[N];
	int val[N];
	
	using namespace CAL;
	
	void SPFA()
	{
		priority_queue<int>q;
		q.push(s);
		dep[s]=0;
		vis[s]=true;
		while(!q.empty())
		{
			int x=q.top();
			q.pop();
			vis[x]=false;
			for(int i=head[x];i;i=edge[i].nxt)
			{
				int v=edge[i].to;
				if(dep[v]>dep[x]+val[i])
				{
					dep[v]=dep[x]+val[i];
					if(vis[v]) continue;
					q.push(v);
					vis[v]=true;
				}
			}
		}
	}
}
namespace SP_Dijkstra_Heap//最短路 
{
	int s,t;
	int dep[N];
	bool vis[N];
	int val[N];
	
	using namespace CAL;
	
	struct heap
	{
		int u;
		int d;
		bool operator <(const heap &b)
		const
		{
			return b.d<d;
		}
	};
	void Dijkstra()
	{
		priority_queue<heap>q;
		for(int i=1;i<=n;i++)
		{
			if(i==s) dep[i]=0;
			else dep[i]=INF;
		}
		q.push((heap){s,0});
		while(!q.empty())
		{
			heap cur=q.top();
			q.pop();
			int x=cur.u;
			int d=cur.d;
			if(d!=dep[x]) continue;
			for(int i=head[x];i;i=edge[i].nxt)
			{
				int v=edge[i].to;
				if(dep[v]>dep[x]+val[i])
				{
					dep[v]=dep[x]+val[i];
					q.push((heap){v,dep[v]});
				}
			}
		}
	}
}
namespace SP_Floyd//最短路 
{
	int T[M][M];
	
	void Floyd()
	{
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					int x=max(T[i][k],T[j][k]);
					T[i][j]=min(x,T[i][j]);
				}
			}
		}
	}
}
namespace NC//负环 
{
	bool vis[N];
	int dep[N];
	bool jud;
	
	using namespace CAL;
	
	void DFS_SPFA(int x)
	{
		vis[x]=true;
		for(int i=head[x];i;i=edge[i].nxt)
		{
			int v=edge[i].to;
			if(dep[v]<dep[x]+edge[i].val)
			{
				if(vis[v])
				{
					jud=true;
					break;
				}
				if(jud) break;
				dep[v]=dep[x]+edge[i].val;
				DFS_SPFA(v);
			}
		}
		vis[x]=false;
	}
}
namespace LCA//最近公共祖先 
{
	int anc[N][20];
	const int M=19;
	int fa[N];
	int dep[N];
	
	using namespace CAL;
	
	void DFS(int x,int deep)
	{
		anc[x][0]=fa[x];
		for(int i=1;i<=M;i++)
		{
			if(dep[x]<(1<<i)) break;
			anc[x][i]=anc[anc[x][i-1]][i-1];
		}
		for(int i=head[x];i;i=edge[i].nxt)
		{
			int v=edge[i].to;
			dep[v]=deep+1;
			DFS(v,deep+1);
		}
	}
	
	int solve(int t1,int t2)
	{
		if(dep[t1]<dep[t2]) swap(t1,t2);
		int d=dep[t1]-dep[t2];
		for(int i=M;~i;i--)
		{
			if(d&(1<<i))
			{
				t1=anc[t1][i];
			}
			if(t1==t2) return t1;
		}
		for(int i=M;~i;i--)
		{
			if(anc[t1][i]!=anc[t2][i])
			{
				t1=anc[t1][i];
				t2=anc[t2][i];
			}
		}
		return anc[t1][0];
	}
}
namespace Tarjan//缩点 
{
	int stack[N],top;
	bool jud[N];//instack
	int dfn[N];
	int low[N];
	int idx,tot;
	int color[N];
	int sum[N];
	int val[N];
	
	using namespace CAL;
	
	void tarjan(int x)
	{
		stack[++top]=x;
		jud[x]=true;
		dfn[x]=low[x]=++idx;
		for(int i=head[x];i;i=edge[i].nxt)
		{
			int v=edge[i].to;
			if(!dfn[v])
			{
				tarjan(v);
				low[x]=min(low[x],low[v]);
			}
			else if(jud[v])
			{
				low[x]=min(low[x],dfn[v]);
			}
		}
		if(dfn[x]==low[x])
		{
			tot++;
			while(stack[top+1]!=x)
			{
				color[stack[top]]=tot;
				sum[tot]+=val[stack[top]];
				jud[stack[top--]]=false;
			}
		}
	}
	
	void cpl()
	{
		for(int i=1;i<=n;i++)
		{
			if(!dfn[i]) tarjan(i);
		}
	}
}
namespace BGM_Hungary//二分图匹配 
{
	using namespace CAL;
	int matched[N];
	bool ask[N];
	int ans;
	
	bool DFS(int x)
	{
		for(int i=head[x];i;i=edge[i].nxt)
		{
			int v=edge[i].to;
			if(ask[v]) continue;
			ask[v]=true;
			if(matched[v]==0)
			{
				matched[v]=x;
				return true;
			}
			if(DFS(matched[v]))
			{
				matched[v]=x;
				return true;
			}
			return false;
		}
	}
	
	void init()
	{
		for(int i=1;i<=n;i++)
		{
			memset(ask,0,sizeof(ask));
			if(DFS(i)) ans++;
		}
	}
}
namespace MF_DINIC//最大流
{
    struct node
    {
        int to;
        int nxt;
        int val;
    }edge[M];
    
    int head[N],cnt=-1;
    int level[N];
    int s,t;
    int res;
    
    void addedge(int x,int y,int z)
    {
        edge[++cnt].to=y;
        edge[cnt].nxt=head[x];
        edge[cnt].val=z;
        head[x]=cnt;
    }
    
    bool makelevel()
    {
        memset(level,0,sizeof(level));
        queue<int>q;
        while(!q.empty()) q.pop();
        level[s]=1;
        q.push(s);
        do
        {
            int x=q.front();
            q.pop();
            for(int i=head[x];~i;i=edge[i].nxt)
            {
                int v=edge[i].to;
                if(edge[i].val&&(!level[v]))
                {
                    level[v]=level[x]+1;
                    q.push(v);
                }
            }
        }
        while(!q.empty());
        return level[t];
    }
    
    int DFS(int x,int maxf)
    {
        if(x==t) return maxf;
        for(int i=head[x];~i;i=edge[i].nxt)
        {
            int v=edge[i].to;
            if(edge[i].val)
            if(level[v]==level[x]+1)
            {
                int f=DFS(v,min(maxf,edge[i].val));
                if(f>0)
                {
                    edge[i].val-=f;
                    edge[i^1].val+=f;
                    return f;
                }
            }
        }
        return 0;
    }
    
    void DINIC()
    {
        memset(head,-1,sizeof(head));
        while(makelevel())
        while(int tmp=DFS(s,INF)) res+=tmp;
    }
}
namespace BGM_Dinic//二分图匹配 
{
	using namespace MF_DINIC;
	
	void solve(int t1,int t2)
	{
		addedge(t1,t2+n,1);
		addedge(t1+n,t1,0);
		addedge(s,t1,1);
		addedge(t1,s,0);
		addedge(t2+n,t,1);
		addedge(t,t2+n,0);
	}
}
namespace Topo//拓扑排序 
{
	int indeg[N];
	int lis[N];
	int num;
	int tmp;
	
	using namespace CAL;
	
	void Topo()
	{
		priority_queue<int>q;
		while(!q.empty()) q.pop();
		for(int i=1;i<=n;i++)
		{
			if(indeg[i]==0)
			{
				q.push(i);
			}
			while(!q.empty())
			{
				tmp=q.top();
				lis[++num]=tmp;
				q.pop();
				for(int i=head[tmp];i;i=edge[i].nxt)
				{
					int v=edge[i].to;
					indeg[v]--;
					if(!indeg[v])
					{
						q.push(v);
					}
				}
			}
		}
		return;
	}
}
namespace FC//快速幂/快速乘 
{
	int FM(int a,int k,int mod)
	{
		int ans=0;
		for(;k;a=(a+a)%mod,k>>=1)
		{
			if(k&1) ans=ans+a%mod;
		}
		return ans;
	}
	int FP(int a,int k,int mod)
	{
		int ans=1;
		for(;k;a=1LL*a*a%mod,k>>=1)
		{
			if(k&1) ans=1LL*a*ans%mod;
		}
	}
}
namespace Phi//欧拉函数 
{
	bool vis[N];
	int phi[N];
	int p[N],cnt;
	
	int getphi(int x)
	{
		int k=x;
		int ans=x;
		for(int i=2;i*i<=k;i++)
		{
			if(k%i==0)
			{
				ans=ans/i*(i-1);
				while(k%i==0)
				k/=i;
			}
		}
		if(k>1)
		{
			ans=ans/k*(k-1);
		}
		return ans;
	}
	void getphi()
	{
		for(int i=2;i<N;i++)
		{
			if(!vis[i])
			{
				p[++cnt]=i;
				phi[i]=i-1;
			}
			for(int j=1;j<=cnt;j++)
			{
				int v=i*p[j];
				if(v>=N) break;
				vis[v]=true;
				if(i%p[j]==0)
				{
					phi[v]=phi[i]*p[j];
					break;
				}
				else phi[v]=phi[i]*phi[j];
			}
		} 
	}
}
namespace Linear_Shaker//线性筛 
{
	bool vis[N];
	int p[N],cnt;
	
	void getprime()
	{
		for(int i=2;i<N;i++)
		{
			if(!vis[i])
			{
				p[++cnt]=i;
			}
			for(int j=1;j<=cnt;j++)
			{
				int v=i*p[j];
				if(v>=N) break;
				vis[v]=true;
				if(i%p[j]==0) continue;
			}
		} 
	}
}
namespace Inv//逆元 
{
	int inv[N];
	int p;//p is prime 
	
	void getinv()
	{
		inv[1]=1;
		for(int i=2;i<=N;i++)
		{
			inv[i]=1LL*(p-p/i)*inv[p%i]%p;
		}
	}
}
namespace Gcd//最大公约数 
{
	int gcd(int a,int b)
	{
		return b?gcd(b,a%b):a;
	}
}
namespace Cantor//康托展开 
{
	int fac[N];
	int mod;
	bool vis[N];
	
	void getfac()
	{
		fac[0]=1;
		for(int i=1;i<=n;i++)
		{
			fac[i]=1LL*fac[i-1]*i%mod;
		}
	}
	int cantor(int *A,int n)
	{
	    int res=0;
	    for(int i=0;i<n;i++)
	    {
	        int cnt=0;
	        for(int j=i+1;j<n;j++)
	        {
	            if(A[j]<A[i]) cnt++;
	        }
	        res+=1LL*fac[n-i-1]*cnt;
	    }
	    return res;
	}
	void decantor(int x,int n)
	{
	    memset(vis,0,sizeof(vis));
	    for(int i=1,j=1;i<=n;i++)
	    {
	        int cur=x/fac[n-i];
	        for(j=1;j<=n;j++)
	        {
	            if(!vis[j])
	            {
	                if(!cur) break;
	                else cur--;
	            }
	        }
	        printf("%d ",j);
	        vis[j]=true;
	        x=x%fac[n-i];
	    }
	}
}
namespace MatrixPow//矩阵快速幂 
{
	struct Matrix
	{
		int T[M][M];
	}E;
	int mod;
	inline Matrix mul(Matrix X,Matrix Y)
	{
	    Matrix Z;
	    memset(Z.T,0,sizeof(Z.T));
	    for(register int i=1;i<=n;i++)
	    for(register int j=1;j<=n;j++)
	    for(register int k=1;k<=n;k++)
	    {
	        Z.T[i][j]=(1LL*Z.T[i][j]%mod+1LL*X.T[i][k]*Y.T[k][j]%mod)%mod;
	    }
	    return Z;
	}
	Matrix pow(Matrix M,long long k)
	{
	    Matrix ans=E;
	    for(;k;k>>=1,M=mul(M,M))
	        if(k&1) ans=mul(ans,M);
	    return ans;
	}
}
namespace Segment_Tree//线段树 
{
	int sum[N];
	int add[N];
	
	#define ls rt<<1
	#define rs rt<<1|1
	
	void init(){;}
	void maintain(int rt){;}
	void pushdown(int rt,int k){;}
	
	void build(int rt,int l,int r)
	{
		init();
		if(l==r)
		{
			scanf("%d",&sum[rt]);
			return;
		}
		int mid=(l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
		maintain(rt);
	}
	void update(int rt,int l,int r,int ql,int qr,int k)
	{
		if(ql<=l&&qr>=r)
		{
			add[rt]+=k;
			sum[rt]+=(r-l+1)*k;
			return;
		}
		pushdown(rt,r-l+1);
		int mid=(l+r)>>1;
		if(ql<=mid)
		{
			update(ls,l,mid,ql,qr,k);
		}
		if(qr>mid)
		{
			update(rs,mid+1,r,ql,qr,k);
		}
	}
	int query(int rt,int l,int r,int ql,int qr)
	{
		if(ql<=l&&qr>=r)
		{
			return sum[rt];
		}
		pushdown(rt,r-l+1);
		int mid=(l+r)>>1;
		int ret=0;
		if(ql<=mid) 
		{
			ret+=query(ls,l,mid,ql,qr);
		}
		if(qr>mid) 
		{
			ret+=query(rs,mid+1,r,ql,qr);
		}
		return ret;
	}	
}
namespace ST//ST表 
{
	int f[M][M];
	
	void calc()
	{
		int d=(int)(log(n)/log(2));
		for(int j=1;j<=d;j++)
		{
	        for(int i=1;i<=n-(1<<j)+1;i++)
	        {
	            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
			}
		}
	}
	int query(int L,int R)
    {
        int d=(log(R-L+1)/log(2));
        R=R-(1<<d)+1;
        return max(f[L][d],f[R][d]);
    }
}
namespace BIT//树状数组 
{
	int a[N];
	int lowbit(int x)
	{
		return x&-x;
	}
    void add(int rt,int x)
    {
        while(rt<=n)
        {
            a[rt]+=x;
            rt+=lowbit(rt);
        }
    }
    int sum(int x)
    {
        int num=0;
        while(x)
        {
            num+=a[x];
            x-=lowbit(x);
        }
        return num;
    }
}
namespace DBIT//树状差分数组 
{
	int lowbit(int x)
	{
	    return x&(-x);
	}
	int a[N];
	void change(int x,int y)
	{
	    while(x<=n)
	    {
	        a[x]+=y;
	        x+=lowbit(x);
	    }
	}
	int query(int x)
	{
	    int cnt=0;
	    while(x)
	    {
	        cnt+=a[x];
	        x-=lowbit(x);
	    }
	    return cnt;
	}
}
namespace Trie_Tree//Trie树/字典树 
{
	struct Trie
	{
	    int nxt[26];
	    bool st;
	    bool jud;
	}T[500010];
	
	char s[51];
	int n,m,cnt=1;
	
    void insert()
    {
        int rt=1;
        for(int i=0;s[i];i++)
        {
            int tmp=s[i]-'a';
            if(!T[rt].nxt[tmp])
            T[rt].nxt[tmp]=++cnt;
            rt=T[rt].nxt[tmp];
        }
        T[rt].jud=true;
        return;
    }
    
    int search()
    {
        int rt=1;
        for(int i=0;s[i];i++)
        {
            int tmp=s[i]-'a';
            if(!T[rt].nxt[tmp]) return 0;
            rt=T[rt].nxt[tmp];
        }
        if(!T[rt].jud) return 0;
        if(T[rt].st) return 2;
        T[rt].st=true; return 1;
    }
}
namespace KMP//KMP字符串匹配 
{
	char s1[N];
	char s2[N];
	int len1;
	int len2;
	int nxt[N];
	
	void getnxt()
	{
	    for(int i=1,j=0;i<len2;i++)
	    {
	        while(s2[i]!=s2[j]&&j) j=nxt[j];
	        if(s2[i]==s2[j]) nxt[i+1]=++j;
	        else nxt[i+1]=0;
	    }
	    return;
	}
	
	void calc()
	{
		for(int i=0,j=0;i<len1;i++)
	    {
	        while(s1[i]!=s2[j]&&j) j=nxt[j];
	        if(s1[i]==s2[j]) j++;
	        if(j==len2) printf("%d\n",i+2-len2);
	    }
	}
}
namespace Heap//堆 
{
	typedef pair<int,int> pii;
	int num;
	pii heap[N];
	
	bool operator >(pii &x,pii &y)
	{
		return x.first<y.first;
	}
	
	bool operator <(pii &x,pii &y)
	{
		return x.first>y.first;
	}
	
	void push(int x,int y)
	{
		heap[++num]=make_pair(x,y);
		for(int i=num,d=i>>1;d;)
		{
			if(heap[i]<heap[d])
			swap(heap[i],heap[d]);
			else break;
			i=d;
			d=i>>1;
		}
	}
	
	void pop()
	{
		heap[1]=heap[num--];
		for(int i=2,d=1;i<=num;)
		{
			if(i<num)
			if(heap[i]>heap[i+1]) i++;
			if(heap[i]<heap[d])
			swap(heap[i],heap[d]);
			else break;
			d=i;
			i=d<<1;
		}
	}
}

int main()
{
	return 0;
}
