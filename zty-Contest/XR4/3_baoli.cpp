#include <cstdio>
#include <iostream>
using namespace std;
const long long inf = 1e7;
long long a, b, x, y, ans, Y;
int main() {
    cin>>a>>b;
    if(a <= 1e4 && b <= inf)
    for(x = 0, y = 0, Y = 0;x <= inf; x++) {
        long long now = x * x + a * x + b;
        if(now < Y) continue;
        while(now > Y) y++, Y = y * y;
        if(now == Y) {
            ans++;
            y++;
            Y = y * y;
            cout<<x<<' '<<y-1<<endl;
        }
    }
    if(ans >= inf)cout<<"inf"<<endl;
    else cout<<ans<<endl;
    return 0;
}