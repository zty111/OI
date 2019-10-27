#include <cstdio>
using namespace std;
bool solve(int n, int m) {
    if(!m) return false;
    if(n / m == 1) return !solve(m, n % m);
    else return true;
}
int main() {
    int T, n, m;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &n, &m);
        if(n < m) {n ^= m; m ^= n; n ^= m;}
        if(solve(n, m)) printf("Stan wins\n");
        else printf("Ollie wins\n");
    }
    return 0;
}