#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;

ll n,m;

int main(){
    freopen("5024.in","w",stdout);
    srand(time(NULL));
    n=rand()%5+2; m=rand()%3+1;
    printf("%lld %lld QAQ\n",n,m);
    for(ll i=1; i<=n; i++) printf("%lld ",rand()%10+1);
    putchar('\n');

    for(ll i=1; i<n; i++) printf("%lld %lld\n",i,i+1);
    while(m--){
        printf("%lld %lld %lld %lld \n",rand()%n+1,rand()%2,rand()%n+1,(ll)rand()%2);
    }
    fclose(stdout);
    return 0;
}