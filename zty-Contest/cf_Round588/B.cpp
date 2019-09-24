#include <bits/stdc++.h>
using namespace std;
char s[300000];
int p, num[300000],n ,k;
int main() {
    scanf("%d %d", &n ,&k);
    scanf("%s", s + 1);
    if(n == 1 && k == 1){
        printf("0\n");
        return 0;
    }
    for(int i = 1; i <= n; i++)
        num[i] = s[i] - 48;
    p = num[1] == 1 ? 2 : 1;
    for(int i = 1; i <= k; i++) {
        while(!num[p] && p <= n) p++;
        if(p > n) break;
        if(p == 1) num[p++] = 1;
        else num[p++] = 0;
        if(p > n) break;
    }
    for(int i = 1; i <= n; i++)
        printf("%d",num[i]);
    printf("\n");
    return 0;
}