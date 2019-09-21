#include<bits/stdc++.h>
using namespace std;
int n,a,b[100010],num;
void print(){
    for(int i=1;i<=num;i++)printf("%d ",b[i]);
    printf("\n");
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        if(a>b[num]||i==1)b[++num]=a;
        else{
            int p=lower_bound(b+1,b+num+1,a)-b;
            //cout<<p<<endl;
            b[p]=a;
        }
        //print();
    }
    printf("%d\n",num);
    return 0;
}