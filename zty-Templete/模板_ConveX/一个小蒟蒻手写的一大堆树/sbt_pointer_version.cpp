//sbt
//pointer version
#include<cstdio>
#include<cstring>
#include<algorithm>
#define null NULL
#define inf 0x7fffffff
using namespace std;

struct data{
	data *left,*right;
	int size,x,cnt;
};
data *root=null;

int cals(data *&p){
	if(p==null) return 0;
	p->size=1;
	if(p->left!=null) p->size+=p->left->size;
	if(p->right!=null) p->size+=p->right->size;
	return p->size;
}

void ltn(data *&p){
	data *rp=p->right;
	p->right=rp->left;
	rp->left=p;
	p=rp;
	cals(p->left);
	cals(p->right);
	cals(p);
	return;
}

void rtn(data *&p){
	data *lp=p->left;
	p->left=lp->right;
	lp->right=p;
	p=lp;
	cals(p->left);
	cals(p->right);
	cals(p);
	return;
}

void insert(data *&p,int x){
	if(p==null){
		p=new data;
		p->size=1;
		p->cnt=1;
		p->x=x;
		p->left=p->right=null;
		return;
	}
	if(x<p->x){
		insert(p->left,x);
		p->size++;
		if(cals(p->left->left)>cals(p->right)) rtn(p);
		return;
	}
	else {
		insert(p->right,x);
		p->size++;
		if(cals(p->right->right)>cals(p->left)) ltn(p);
		return;
	}
}

data *fmax(data *p){
	if(p==null){
		return p;
	}
	while(p->right!=null) p=p->right;
	return p;
}

void del(data *&p,int x){
	if(p->x==x){
		data *lp=fmax(p->left);
		if(lp==null) p=p->right;
		return;
	}
	if(x<p->x){
		del(p->left,x);
		p->size--;
		return;
	}
	if(p->x<x){
		del(p->right,x);
		p->size--;
		return;
	}
}

int rank(data *p,int x){
	if(p==null){
		return 0;
	}
	if(p->x<x){
		return cals(p->left)+1+rank(p->right,x);
	}
	if(p->x==x){
		return rank(p->left,x);
	}
	if(x<p->x){
		return rank(p->left,x);
	}
}

int search(data *p,int x){
	int ls=cals(p->left)+1;
	if(ls==x) return p->x;
	if(ls<x) return search(p->left,x);
	if(x<ls) return search(p->right,x);
}

int pre(data *p,int x){
	if(p==null){
		return -inf;
	}
	if(p->x<x){
		return max(p->x,pre(p->right,x));
	}
	if(x<=p->x){
		return pre(p->left,x);
	}
}

int suf(data *p,int x){
	if(p==null){
		return inf;
	}
	if(x<p->x){
		return min(p->x,suf(p->left,x));
	}
	if(p->x<=x){
		return suf(p->right,x);
	}
}

int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int opt,x;scanf("%d %d",&opt,&x);
		if(opt==1) insert(root,x);
		else if(opt==2) del(root,x);
		else if(opt==3) printf("%d\n",rank(root,x)+1);
		else if(opt==4) printf("%d\n",search(root,x));
		else if(opt==5) printf("%d\n",pre(root,x));
		else if(opt==6) printf("%d\n",suf(root,x));
	}
	return 0;
}
