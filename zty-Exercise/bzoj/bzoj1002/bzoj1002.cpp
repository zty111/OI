#include<bits/stdc++.h>
using namespace std;
struct Bint{
    int a[110],len;
}f[105];
Bint mul(Bint A,int k){
    for(int i=1;i<=A.len;i++)
        A.a[i]*=k;
    for(int i=1;i<=A.len;i++){
        A.a[i+1]+=A.a[i]/10;
        A.a[i]%=10;
        if(i==A.len&&A.a[i+1]>0)A.len++;
    }return A;
}
Bint red(Bint A,Bint B){
    A.a[1]+=2;
    int j=1;
    while(A.a[j]>=10){A.a[j]%=10;A.a[j+1]++;j++;}
    for(int i=1;i<=A.len;i++){
        A.a[i]-=B.a[i];
        if(A.a[i]<0){A.a[i+1]--;A.a[i]+=10;}
    }
    while(A.a[A.len]==0)A.len--;
    return A;
}
int main(){
    int n;
    scanf("%d",&n);
    f[1].a[1]=1;f[2].a[1]=5;
    f[1].len=f[2].len=1;
    for(int i=3;i<=n;i++){
        f[i]=red(mul(f[i-1],3),f[i-2]);
    }
    for(int i=f[n].len;i>=1;i--){
        printf("%d",f[n].a[i]);
    }
    return 0;
}