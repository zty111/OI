#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
const int A = 500000, B = 1e9;
int main() {
    int n = A;
    cout<<n<<endl;
    for(int i = 1; i <= n; i++) cout<<B<<' ';
    cout<<endl;
    for(int i = 2; i <= n; i++) {
        cout<<1<<' '<<i<<endl;
    }
    return 0;
}