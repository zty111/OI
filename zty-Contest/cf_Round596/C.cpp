#include <cstdio>
#include <iostream>
using namespace std;
int n, p;
int main() {
    scanf("%d %d", &n, &p);
    for(int i = 1; i <= 10000; i++) {
        int x = n - p * i, cnt = 0;
        if(x < i) break;
        while(x) {
            cnt++;
            x -= x & -x;
        }
        if(cnt <= i) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}