#include<bits/stdc++.h>
using namespace std;
vector<int>A;
int n,opt,x;
void read(int & x){
    x=0;int f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    x*=f;
}
int main(){
    read(n);
    for(int i=1;i<=n;i++){
        read(opt);read(x);
        int pos=lower_bound(A.begin(),A.end(),x)-A.begin();
        switch(opt){
            case 1:A.insert(A.begin()+pos,x);break;
            case 2:A.erase(A.begin()+pos,A.begin()+pos+1);break;
            case 3:printf("%d\n",pos+1);break;
            case 4:printf("%d\n",A[x-1]);break;
            case 5:printf("%d\n",A[pos-1]);break;
            case 6:printf("%d\n",*upper_bound(A.begin(),A.end(),x));break;
        }
    }
    return 0;
}
