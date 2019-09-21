#include<bits/stdc++.h>
using namespace std;
int main(){
	double a,now=2.0,x=0;
	int cnt=0;
	scanf("%lf",&a);
	while(x<a){
		x+=now;
		now*=0.98;
		cnt++;
	}
	printf("%d",cnt);
	return 0;
}
