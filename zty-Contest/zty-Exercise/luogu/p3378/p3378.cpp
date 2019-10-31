#include<cstdio>
#include<iostream>
using namespace std;
const int N = 1000010;
int heap[N],n;
void up(int p){
    while(p>1){
        if(heap[p]<heap[p>>1]){
            swap(heap[p],heap[p/2]);
            p>>=1;
        }
        else break;
    }
}
void insert(int val){
    heap[++n]=val;
    up(n);
}
int gettop(){
    return heap[1];
}
void down(int p){
    int s=(p<<1);
    while(s<=n){
        if(s<n&&heap[s]>heap[s+1])s++;
        if(heap[s]<heap[p]){
            swap(heap[s],heap[p]);
            p=s,s=(p<<1);
        }
        else break;
    }
}
void extract(){
    heap[1]=heap[n--];
    down(1);
}
inline int read(){
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x;
}
int main(){
    int nn=read();
    for(int i=1;i<=nn;i++){
        int opt=read();
        if(opt==1){
            int x=read();
            insert(x);
        }
        else if(opt==2){
            printf("%d\n",gettop());
        }
        else extract();
    }
    return 0;
}