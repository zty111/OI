#include<bits/stdc++.h>
using namespace std; 
const int N=11,M=510;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
struct node2{ int c[N][N]; } ans[M];
bool operator< (node2 x,node2 y){
	for(int i = 1; i < N; i++)
		for(int j = 1; j<N; j++)
			if(x.c[i][j] != y.c[i][j])
				return x.c[i][j] < y.c[i][j];
	return 0;
}
struct node{ int x, y; };

vector<node> b[N * N];
vector<int> p[N * N]; 
int a[N][N], c[N][N], h[N][N], h1[N][N], h2[N][N];
int n, cnt = 0, tot = 0;

int read() {
	int x = 0, f = 1;
	char c = 0;
	for (; !isdigit(c); c=getchar()) if(c == '-') f = -1;
	for (; isdigit(c); c=getchar()) x = x * 10 + c - 48;
	return x * f;
}
int factor(int x) {
	int t = 0;
	for (int i = 1; i * i <= x; i++)
		t += (int)(x % i == 0);
	return t;
}
bool cmp(vector<node> x, vector<node> y) {
	if (x.size() == y.size())
		return factor(x[0].x) <= factor(y[0].x);
	return x.size() < y.size();
}
void divide(int t, int x){
	for (int i = 1; i <= n; i++)
		if (x % i == 0) p[t].push_back(i);
}
void dfs(int x, int y) {
	h[x][y] = 1;
	b[cnt].push_back((node){ x, y });
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx > 0 && tx <= n && ty > 0 && 
			ty <= n && !h[tx][ty] &&
			a[tx][ty] == a[x][y])
			dfs(tx, ty);
	}
}
void work(int dep);
void fillp(int t, int dep, int s, int tot) {
	if (dep > tot) work(t + 1);
	else {
		int x=b[t][dep].x, y = b[t][dep].y;
		for (int i = 0; i < p[t].size(); i++) {
			int u=p[t][i];
			if ((s == u || dep < tot) && s % u == 0 &&
				!h1[x][u] && !h2[y][u]){
				h1[x][u] = 1;
				h2[y][u] = 1;
				c[x][y] = u;
				fillp(t, dep + 1, s / u, tot);
				c[x][y] = 0;
				h1[x][u] = 0;
				h2[y][u]=0;
			}
		}
	}
}
void work(int dep) {
	if (dep > cnt) {
		tot++;
		for (int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				ans[tot].c[i][j] = c[i][j];
	} else {
		int num=b[dep][0].x;
		int tot=b[dep].size() - 1;
		fillp(dep, 1, num, tot);
	}
}
int main() {
	n = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (!h[i][j]) {
				cnt++;
				b[cnt].push_back((node){ a[i][j], 0 });
				dfs(i, j);
			}
	sort(b + 1, b + cnt + 1, cmp);
	for (int i = 1; i <= cnt; i++)
		divide(i, b[i][0].x);
	work(1);
	cout << tot << "\n";
	node2 t = ans[1];
	for (int i = 2; i <= tot; i++)
		t = min(t, ans[i]);
	for (int i = 1;i <= n; i++){
		for (int j = 1; j < n; j++)
			cout << t.c[i][j] << " ";
		cout << t.c[i][n] << "\n";
	}
	return 0;
}