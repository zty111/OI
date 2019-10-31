#include <bits/stdc++.h>
using namespace std;
int n, s[7][100];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= 3; i++){
        int a;
        scanf("%d", &a);
        s[i][++s[i][0]] = a;
    }
    return 0;
}