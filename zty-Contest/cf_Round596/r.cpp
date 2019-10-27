#include <cstdlib>
#include <iostream>
using namespace std;
const int A = 1e9, B = 1000;
int main() {
    srand(time(0));
    int n = rand() % A, p = rand() % 2000 - 1000;
    cout<<n<<' '<<p<<endl;
    return 0;
}