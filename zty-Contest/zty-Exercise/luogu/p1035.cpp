#include<bits/stdc++.h>
using namespace std;
int main(){
	int k,i;
	scanf("%d",&k);
	double sum=0;
	for(i=1;sum<=k;i++){
		sum+=1.0/i;
	}
	printf("%d",i-1);
	return 0;
}
