#include<bits/stdc++.h>
using namespace std;
char s[100];
int n[100];
int main(){
    scanf("%s",s+1);
    int len=strlen(s+1);
    for(int i=1;i<=len;i++)n[i]=s[i]-48;
    n[len]++;
    int x=0;
    for(int i=1;i<=len;i++){
        n[i]+=x*10;
        x=n[i]%2;
        n[i]/=2;
    }
    if(x>0)n[len]++;
    int p=len;
    while(n[p]==10){n[p]=0;n[--p]++;}
    for(int i=min(1,p);i<=len;i++)s[i]=n[i]+48;
    int now=min(1,p);
    while(n[now]==0)now++;
    printf("%s\n",s+now);
    return 0;
}