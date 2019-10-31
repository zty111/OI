#include<cstdio>
#include<algorithm>
using namespace std;
int a[1010],b[1010],n,k;
double c[1010];
bool check(double L){
    for(int i=1;i<=n;i++)
        c[i]=a[i]-b[i]*L;
    sort(c+1,c+1+n);
    int cnt=0;double ret=0.0;
    for(int i=1;i<=n;i++){
        if(cnt<k&&c[i]<0)
            cnt++;
        else ret+=c[i];
    }
    return ret>=0.0?1:0;
}
int main(){
    while(scanf("%d %d",&n,&k)==2&&(n||k)){
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        double mid,l=0.0,r=100.0;
        while(r-l>1e-9){
            mid=r-(r-l)/2;
            if(check(mid))l=mid;
            else r=mid;
        }
        printf("%.0f\n",l*100);
    }
    return 0;
}