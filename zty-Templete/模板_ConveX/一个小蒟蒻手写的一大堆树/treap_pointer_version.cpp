//treap
//pointer version 
#include<cstdio>
#include<cstring>
#include<algorithm>
#define null NULL
#define inf 0x7fffffff
using namespace std;
//root big

struct data{
	data *left,*right;
	int x,prio,size;
};
data *root=null;//null

int seed=703;
int rand(){
	return seed=int((long long)seed*19260817%2147483647);
}

void cals(data *&p){//null
	if(p==null) return;
	p->size=1;
	if(p->left!=null) p->size+=p->left->size;
	if(p->right!=null) p->size+=p->right->size;
	return;
}

void rturn(data *&p){//cals for three times
	data *leftp=p->left;
	p->left=leftp->right;
	leftp->right=p;
	p=leftp;
	cals(p->left);
	cals(p->right);
	cals(p);
	return;
}

void lturn(data *&p){//cals for three times
	data *rightp=p->right;
	p->right=rightp->left;
	rightp->left=p;
	p=rightp;
	cals(p->left);
	cals(p->right);
	cals(p);
	return;
}

void insert(data *&p,int x){
	if(p==null){
		p=new data;
		p->left=p->right=null;
		p->x=x;
		p->prio=rand();
		p->size=1;
		return;
	}
	if(x<p->x||(x==p->x&&rand()&1)){
		insert(p->left,x);
		p->size++;
		if((p->left->prio)>(p->prio)) rturn(p);
		return;
	}
	else {
		insert(p->right,x);
		p->size++;
		if((p->right->prio)>(p->prio)) lturn(p);
		return;
	}
}

void del(data *&p,int x){
	if(p==null) return;
	if(x<p->x){
		del(p->left,x);
	}
	else if(p->x<x){
		del(p->right,x);
	}
	else {
		if(p->left==null){
			p=p->right;
		}
		else if(p->right==null){
			p=p->left;
		}
		else {
			if((p->left->prio)>(p->right->prio)) rturn(p),del(p->right,x);
			else lturn(p),del(p->left,x);
		}
	}
	cals(p);
	return;
}

int rank(data *&p,int x){//output=rank+1
	if(p==null){
		return 0;
	}
	if(x<=p->x){
		return rank(p->left,x);
	}
	if(p->x<x){
		return rank(p->right,x)+1+(p->left==null?0:p->left->size);
	}
} 

int search(data *&p,int rank){
	if(p->left==null){
		if(rank==1) return p->x;
		return search(p->right,rank-1);
	}
	if(rank==p->left->size+1) return p->x;
	if(rank<=p->left->size){
		return search(p->left,rank);
	}
	if(rank>p->left->size+1){
		return search(p->right,rank-(p->left->size)-1);
	}
}

int pre(data *p,int x){//max
	if(p==null){
		return -inf;
	}
	if(x<=(p->x)) return pre(p->left,x);
	if((p->x)<x) return max(pre(p->right,x),p->x);
} 

int suf(data *p,int x){//min
	if(p==null){
		return inf;
	}
	if(x<p->x) return min(suf(p->left,x),p->x);
	if(p->x<=x) return suf(p->right,x);
}

int main(){
	//freopen("data.in","r",stdin); 
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int opt,x;scanf("%d %d",&opt,&x);
		if(opt==1){
			insert(root,x);
		}
		else if(opt==2) del(root,x);
		else if(opt==3) printf("%d\n",1+rank(root,x));
		else if(opt==4) printf("%d\n",search(root,x));
		else if(opt==5) printf("%d\n",pre(root,x));
		else if(opt==6) printf("%d\n",suf(root,x));
		//printf("size=%d i=%d\n",root->size,i);
	}
	return 0;
}
