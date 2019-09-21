//treap
//array version
#include<cstdio>
#include<cstring>
#include<algorithm>
#define inf 0x7fffffff
using namespace std;
//root big

struct data{
	int left,right;
	int prio,x,size;
}tre[10000+9];
int cnt=0,root=0;

int seed=703;
int rand(){
	return seed=int((long long)seed*19260817%2147483647);
}

void cals(int p){
	if(p==0){
		tre[p].size=0;
		return;
	}
	tre[p].size=1;
	tre[p].size+=tre[tre[p].left].size+tre[tre[p].right].size;
	return;
}

void ltn(int &p){
	int rp=tre[p].right;
	tre[p].right=tre[rp].left;
	tre[rp].left=p;
	p=rp;
	cals(tre[p].left);
	cals(tre[p].right);
	cals(p);
	return;
}

void rtn(int &p){
	int lp=tre[p].left;
	tre[p].left=tre[lp].right;
	tre[lp].right=p;
	p=lp;
	cals(tre[p].left);
	cals(tre[p].right);
	cals(p);
	return;
}

void insert(int &p,int x){
	if(p==0){
		p=++cnt;
		tre[p].size=1;
		tre[p].left=tre[p].right=0;
		tre[p].prio=rand();
		tre[p].x=x;
		return;
	}
	if(x<tre[p].x||(tre[p].x==x&&rand()&1)){
		insert(tre[p].left,x);
		tre[p].size++;
		if(tre[tre[p].left].prio>tre[p].prio) rtn(p);
	}
	else {
		insert(tre[p].right,x);
		tre[p].size++;
		if(tre[tre[p].right].prio>tre[p].prio) ltn(p);	
	}
	cals(p);
	return;
}

void del(int &p,int x){
	if(p==0) return;
	if(tre[p].x<x) del(tre[p].right,x);
	else if(x<tre[p].x) del(tre[p].left,x);
	else {
		if(tre[p].left==0) p=tre[p].right;
		else if(tre[p].right==0) p=tre[p].left;
		else {
			if(tre[tre[p].left].prio<tre[tre[p].right].prio){
				ltn(p);
				del(tre[p].left,x);
			}
			else {
				rtn(p);
				del(tre[p].right,x);
			}
		}
	}
	cals(p);
	return;
}

int rank(int p,int x){
	if(p==0) return 0;
	if(x<=tre[p].x) return rank(tre[p].left,x);
	if(tre[p].x<x) return rank(tre[p].right,x)+tre[tre[p].left].size+1;
}

int kth(int p,int k){
	if(tre[p].left==0) tre[tre[p].left].size=0;
	if(tre[tre[p].left].size+1==k) return tre[p].x;
	if(tre[tre[p].left].size+1<k) return kth(tre[p].right,k-tre[tre[p].left].size-1);
	return kth(tre[p].left,k);
}

int pre(int p,int x){
	if(p==0) return -inf;
	if(tre[p].x<x) return max(pre(tre[p].right,x),tre[p].x);
	if(x<=tre[p].x) return pre(tre[p].left,x);
}

int suf(int p,int x){
	if(p==0) return inf;
	if(tre[p].x<=x) return suf(tre[p].right,x);
	if(x<tre[p].x) return min(suf(tre[p].left,x),tre[p].x);
}



int main(){
	freopen("data.in","r",stdin);
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int opt,x;scanf("%d %d",&opt,&x);
		if(opt==1) insert(root,x);
		else if(opt==2) del(root,x);
		else if(opt==3) printf("%d\n",rank(root,x)+1);
		else if(opt==4) printf("%d\n",kth(root,x));
		else if(opt==5) printf("%d\n",pre(root,x));
		else if(opt==6) printf("%d\n",suf(root,x));
//		printf("root=%d size=%d i=%d\n",root,tre[root].size,i);
	}
	return 0;
}
