#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char s[100010];
int num1, num2, ans;
int main() {
    scanf("%s", s+1);
    int len = strlen(s+1);
    for(int i = 1; i <= len; i++) {
        if(s[i] == ')') {
            if(num1 == 0) num1++, ans++;
            else num1--;
        } else {
            num1++;
        }
    }
    printf("%d\n", ans + num1 / 2);
    return 0;
}