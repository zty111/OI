#include <bits/stdc++.h>
using namespace std;
int main() {
    int n = rand() % 7000;
    srand(time(0));
    cout<<n<<endl;
    long long a = 1ll * rand() * rand();
    cout<<a<<endl;
    for(int i = 3; i <= n; i++){
        cout<< 1ll*rand() * rand()<<' ';
    }
    cout<<a<<endl;
    cout<<endl;
    for(int i = 1; i <= n; i++)
        cout<<rand()<<' ';
    return 0;
}