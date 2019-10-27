#include <cstdio>
#include <iostream>
using namespace std;
int a, b;
int main() {
    scanf("%d %d", &a, &b);
    if(a == 9 && b == 1) printf("9 10\n");
    else if(a > b || b - a > 1) printf("-1\n");
    else {
        if(a == b) a = a * 10, b = b * 10 + 1;
        else a = a * 10 + 9, b = b * 10;
        printf("%d %d\n", a, b);
    }
    return 0;
}