#include<bits/stdc++.h>
using namespace std;
const int N = 10000;
int random(int n){
    return (long long)rand()*rand()%n;
}
int main(){
    srand(time(0));
    int t=1;
    cout<<t<<endl;
    while(t--){
        int n=random(N)+1;
        cout<<n<<endl;
        for(int i=1;i<=n;i++){
            int a=random(N)*2-N;
            cout<<a<<' ';
        }
        cout<<endl;
        int m=random(N)+1;
        cout<<m<<endl;
        for(int i=1;i<=m;i++){
            int ll=random(n)+1;
            int lr=random(n)+1;
            if(ll>lr)swap(ll,lr);
            int rl=random(n)+1;
            int rr=random(n)+1;
            if(rl>rr)swap(rl,rr);
            cout<<ll<<' '<<lr<<' '<<rl<<' '<<rr<<endl;
        }
    }
    return 0;
}