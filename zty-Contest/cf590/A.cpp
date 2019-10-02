#include <bits/stdc++.h>
using namespace std;
int c[20];
int main() {
    int l, r;
    scanf("%d %d", &l, &r);
    for(int i = l; i <= r; i++) {
        int now = i, flag = 1;
        while(now) {
            if(c[now % 10]) flag = 0;
            c[now % 10] = 1;
            now /= 10;
        }
        if(flag){printf("%d\n", i); return 0;}
        for(int j = 0; j <= 9; j++) c[j] = 0;
    }
    printf("-1\n");
    return 0;
}