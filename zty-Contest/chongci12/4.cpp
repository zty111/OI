#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 200010
#define ls x<<1
#define rs x<<1|1
using namespace std;
int n,m,ans[N],x,a[N],b[N],tot,t[N<<4],nx[N<<4],l[N],f[N];
struct node{int l,r,s;}q[N];
int cmp(node x,node y){return x.r<y.r;}
int read(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}
void add(int x,int y){t[++t[0]]=y;nx[t[0]]=l[x];l[x]=t[0];}
void add(int x){
	for(;x<=n;x+=x&-x) f[x]++;
}
int find(int x){
	int sum=0;
	for(;x;x-=x&-x) sum+=f[x];
	return sum;
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++){a[i]=read();b[a[i]]=i;} 
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j+=i){
			if(b[i]<b[j]) add(b[j],b[i]);
			else add(b[i],b[j]);
		}
	}
	for(int i=1;i<=m;i++) q[i]=(node){read(),read(),i};
	sort(q+1,q+1+m,cmp);x=1;
	for(int i=1;i<=n;i++){
		for(int k=l[i];k;k=nx[k]){add(t[k]),tot++;}
		while(q[x].r==i){
			ans[q[x].s]=tot;
			if (q[x].l!=1) ans[q[x].s]-=find(q[x].l-1);
			x++;
		}
		if(x>m) break;
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}