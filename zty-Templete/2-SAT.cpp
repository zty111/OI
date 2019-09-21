#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m, s[N << 1], mark[N << 2], c;
vector<int> G[N << 1];
bool dfs(int x) {
    if(mark[x ^ 1]) return false;
    if(mark[x]) return true;
    mark[x] = 1;
    s[c++] = x;
    for(int i = 0; i < G[x].size(); i++)
        if(!dfs(G[x][i])) return false;
    return true;
}
bool solve() {
    for(int i = 2; i <= (n << 1); i += 2)
        if(!mark[i] && !mark[i + 1]){
            c = 0;
            if(!dfs(i)) {
                while(c > 0) mark[s[--c]] = 0;
                if(!dfs(i + 1)) return false;
            }
        }
    return true;
}
void add_clause(int x, int xval, int y, int yval) {
    x = (x << 1) + xval;
    y = (y << 1) + yval;
    G[x ^ 1].push_back(y);
    G[y ^ 1].push_back(x);
}
inline int read() {
    int x = 0; char ch = getchar();
    while(ch < '0' || ch > '9')ch = getchar();
    while(ch >= '0' && ch <= '9')x = x * 10 + ch - 48, ch =getchar();
    return x;
}
int main(){
    n=read(); m=read();
    for(int i = 1; i <= m; i++){
        int a = read(), b = read(), c = read(), d = read();
        add_clause(a, b, c, d);
    }
    if(!solve()) printf("IMPOSSIBLE\n");
    else {
        printf("POSSIBLE\n");
        for(int i = 1; i <= n; i++)
            printf("%d ", mark[(i<<1) ^ 1]);
    }
    return 0;
}