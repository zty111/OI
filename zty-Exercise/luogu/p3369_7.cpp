#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>t;
ll T,opt,num;
inline ll read(){
    ll f=1;
    ll x=0;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
int main(){
    T=read();
    while(T--)
    {
        opt=read();
        num=read();
        if(opt==1)
            t.insert((num<<20)+T);
        if(opt==2)
            t.erase(t.lower_bound(num<<20));
        if(opt==3)
            printf("%lld\n",t.order_of_key(num<<20)+1);
        if(opt==4)
            printf("%lld\n",*t.find_by_order(num-1)>>20);
        if(opt==5)
            printf("%lld\n",*(--t.lower_bound(num<<20))>>20);
        if(opt==6)
            printf("%lld\n",*t.upper_bound((num+1)<<20)>>20);
    }
    return 0;
}
