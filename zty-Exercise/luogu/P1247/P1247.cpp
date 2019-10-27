#include <cstdio>
using namespace std;
const int N = 500010;
int k, a[N], sum, b;
int main() {
    scanf("%d", &k);
    for(int i = 1; i <= k; i++) {
        scanf("%d", &a[i]);
        sum ^= a[i];
    }
    if(!sum) printf("lose\n");
    else {
        for(int i = 1; i <= k; i++)
            if((a[i] ^ sum) < a[i]) {
                int x = a[i] - (a[i] ^ sum);
                printf("%d %d\n", x, i);
                a[i] ^= sum;
                for(int j = 1; j <= k; j++)
                    printf("%d ", a[j]);
                break;
            }
    }
    return 0;
}