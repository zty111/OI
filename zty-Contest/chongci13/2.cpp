#include <bits/stdc++.h>
using namespace std;
int n, m, p, ans, a[4000005];
inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
    char ch=nc();int sum=0;
    while(ch<'0'||ch>'9')ch=nc();
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
    return sum;
}
int main() {
    n = read(); m = read();
    for(int i = 1; i <= 2 *n; i++) a[i] = read();
    sort(a+1, a+1+n*2);
    for(int i = 1; i <= m; i++) {
        p = read();
        p = (p ^ ans) % (n * 2) + 1;
        ans = a[p];
        printf("%d\n", ans);
    }
    return 0;
}