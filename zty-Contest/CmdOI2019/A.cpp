#include <bits/stdc++.h>
using namespace std;
int n, k, x[1000], y[1000];
vector<double> s;
inline int read() {
    char ch = getchar();
    int x = 0;
    while(ch > '9' || ch < '0') ch = getchar();
    while(ch <= '9' && ch >= '0') x = x * 10 + ch - 48, ch = getchar();
    return x;
}
inline double dist(int a, int b) {
    return sqrt((double)(x[a] - x[b]) * (x[a] - x[b]) + (double)(y[a] - y[b]) * (y[a] - y[b]));
}
int main() {
    n = read(); k = read();
    for(int i = 1; i <= n; i++) {
        x[i] = read(); y[i] = read();
    }
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            for(int z = j + 1; z <= n; z++){
                double a = dist(i, j);
                double b = dist(i, z);
                double c = dist(j, z);
                double p = (a + b + c) / 2;
                s.push_back(sqrt(4.0 * p * (p - a) * (p - b) * (p - c)));
            }
    sort(s.begin(), s.end());
    cout<<s[k - 1]<<endl;
    return 0;
}