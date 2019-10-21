#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1000010;
char s[N];
int x[N], y[N], z;
int main() {
    scanf("%s", s);
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        if(s[i] == 'Z') z = 1;
        if(z && s[i] != 'Z') {
            printf("-1\n");
            return 0;
        }
    }
    for(int i = 0; i < len; i++) {
        char ch = s[i];
        if(ch == 'X') x[i] = 1;
        else if(ch == 'Y') y[i] = 1;
    }
    for(int i = 0; i < len; i++)
        printf("%d", x[i]);
    printf("\n");
    for(int i = 0; i < len; i++)
        printf("%d", y[i]);
    printf("\n");
    return 0;
}