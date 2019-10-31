#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
int main() {
    int m = 5000, p = 998244353;
    cout<<m<<' '<<p<<endl;
    for(int i = 1; i <= m; i++) {
        int n = rand(), q = rand() % p;
        cout<<n<<' '<<q<<endl;
    }
    return 0;
}