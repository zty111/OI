#include <cstdio>
#include <iostream>
#include <cmath>
#include <map>
#include <string>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
int n, k, a;
inline int read() {
    int x = 0; char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
    return x;
}
int prim[N], vis[N], cnt;
long long ans;
map<int, int> mp;
const int mod1 = 386910137;
const int mod2 = 1e9+7;
const int mod3 = 687840301;
void work() {
    int s1 = 0,s2=0; //s1_2 = 0, s1_3 = 0, s2 = 0, s2_2 = 0, s2_3 = 0;
    for(int i = 1; i <= cnt && a; i++) {
        int v1 = 0, v2;
        while(a % prim[i] == 0) {
            a /= prim[i];
            v1++;
        }
        v1 %= k;
        v2 = (v1 == 0 ? 0 : k - v1);
        s1 = (s1 * 11 + v1) % mod1;
      /*  s1_2 = (s1_2 * 11 + v1) % mod2;
        s1_3 = (s1_3 * 11 + v1) % mod3;*/
        s2 = (s2 * 11 + v2) % mod1;/*
        s2_2 = (s2_2 * 11 + v2) % mod2;
        s2_3 = (s2_3 * 11 + v2) % mod3;*/
    }
 //   ans += min(mp[s2], min(mp[s2_2], mp[s2_3]));
    ans += mp[s2];
    mp[s1]++; 
    //if(s1_2 != s1) mp[s1_2]++; 
    //if(s1_3 != s1 && s1_3 != s2)mp[s1_3]++;
}
int main() {
    for(int i = 2; i <= 1e5; i++) {
        if(!vis[i]) prim[++cnt] = i;
        for(int j = 1; j <= cnt; j++) {
            if(prim[j] * i > 1e5) break;
            vis[prim[j] * i] = 1;
        }
    }
    n = read(); k = read();
    for(int i = 1; i <= n; i++) {
        a = read();
        work();
    }
    printf("%lld", ans);
    return 0;
}