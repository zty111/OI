//
//  main.cpp
//  bzoj1004
//
//  Created by zty on 2019/5/19.
//  Copyright © 2019 zty. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll qpow(ll a,ll b,ll mod){
    ll ret=1;a%=mod;
    while(b){
        if(b&1)ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }return ret;
}

int main(int argc, const char * argv[]) {
    ll sr,sb,sg,m,p,n,c=1,ans=1;
    scanf("%lld %lld %lld %lld %lld",&sr,&sb,&sg,&m,&p);
    n=sr+sb+sg;
    for(int k=1;k<=sr;k++)
        c=c*(n-k+1)/k;
    ans=ans*c%p;c=1;n-=sr;
    for(int k=1;k<=sb;k++)
        c=c*(n-k+1)/k;
    ans=(ans*c%p)%p;ans=ans*qpow(m+1,p-2,p)%p;
    printf("%lld\n",(ans+p)%p);
    return 0;
}
