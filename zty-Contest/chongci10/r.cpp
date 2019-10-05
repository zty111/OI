#include <bits/stdc++.h>
using namespace std;
int main() {
    srand(time(0));
    int n = rand() % 101, m = rand() % 101;
    cout<<n<<' '<<m<<endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            cout<<1000000000<<' ';
        cout<<endl;
    }
    return 0;
}