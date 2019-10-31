#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int inf = 0x3f3f3f3f;
inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-')f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}
const int _N = 35;
const int N = 4000;
const int M = 20000;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int n, m, p, a[_N][_N], ex, ey, sx, sy, tx, ty, ans, pre[_N][_N];
inline int id(int x, int y) {
    return ((x - 1) * m + y - 1) * 4;
}
queue<pair<int, int> > q;
queue<int> Q;
int cnt, nxt[M], h[N], to[M], e[M], dis[N], vis[N];
void add_edge(int u, int v, int d) {
    cnt++; nxt[cnt] = h[u]; h[u] = cnt; to[cnt] = v; e[cnt] = d;
}
void bfs(int ex, int ey, int px, int py, int d) {
    memset(pre, -1, sizeof(pre));
    pre[px][py] = 1;
    pre[ex][ey] = 0;
    q.push(make_pair(ex, ey));
    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int i = 0; i <= 3; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(a[nx][ny] && pre[nx][ny] == -1) {
                pre[nx][ny] = pre[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
    if(d == 4) return;
    int num = id(px, py);
    for(int i = 0; i <= 3; i++) {
        int x = px + dx[i], y = py + dy[i];
        if(pre[x][y] > 0) add_edge(num+d, num+i, pre[x][y]);
    }
    add_edge(num+d, id(ex, ey)+(d+2)%4, 1);
}
void spfa(int sx, int sy) {
    int num;
    memset(dis, -1, sizeof(dis));
    for(int i = 0; i <= 3; i++) {
        int x = sx + dx[i], y = sy + dy[i];
        if(pre[x][y] != -1) {
            num = id(sx, sy) + i;
            dis[num] = pre[x][y];
            Q.push(num);
            vis[num] = 1;
        }
    }
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        vis[u] = 0;
        for(int i = h[u]; i; i = nxt[i]) {
            int v = to[i];
            if(dis[v] == -1 || dis[v] > dis[u] + e[i]) {
                dis[v] = dis[u] + e[i];
                if(!vis[v]) {
                    Q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
}
int main() {
    n = read(); m = read(); p = read();
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            a[i][j] = read();
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) if(a[i][j]) {
            if(a[i-1][j]) bfs(i-1, j, i, j, 0);
            if(a[i][j+1]) bfs(i, j+1, i, j ,1);
            if(a[i+1][j]) bfs(i+1, j, i, j, 2);
            if(a[i][j-1]) bfs(i, j-1, i, j, 3);
        }
    while(p--) {
        ex = read(); ey = read(); sx = read(); sy = read(); tx = read(); ty = read();
        if(sx == tx && sy == ty) {
            printf("0\n");
            continue;
        }
        bfs(ex, ey, sx, sy, 4);
        spfa(sx, sy);
        ans = inf;
        int num = id(tx, ty);
        for(int i = 0; i <= 3; i++)
            if(dis[num+i] != -1)
                ans = min(ans, dis[num+i]);
        if(ans == inf) printf("-1\n");
        else printf("%d\n", ans);
    }
    return 0;
}