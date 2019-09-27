#include <bits/stdc++.h>
using namespace std;
int main() {
    srand(time(0));
    cout<<1<<endl;
    long long n = rand()%500000, m = rand()%4000000+n;
    cout<<n<<' '<<m<<endl;
    for(int i = 1; i <= n; i++)cout<<(long long)rand()+m<<endl;
    return 0;
}