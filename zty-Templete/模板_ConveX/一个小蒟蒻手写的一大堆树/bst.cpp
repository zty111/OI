//bst
#include<cstdio>
#include<cstring>
#include<algorithm>
#define null -1
using namespace std;

int n,m;

struct data_bst_single{
	int left,right;
	int x;
};

data_bst_single bst[10000+9];
int cnt;

void define(){
	cnt=0;
	bst[0].x=-0x7fffffff;
	bst[0].left=null;
	bst[0].right=null;
	return;
}

void push(int x){
	int *root;
	root=&bst[0].right;
	while(*root!=null){
		root=x<bst[*root].x ? &bst[*root].left : &bst[*root].right;
	}
	*root=++cnt;
	bst[cnt].x=x;
	bst[cnt].left=bst[cnt].right=null;
	return;
}

bool del(int x){
	int *root;
	root=&bst[0].right;
	while(*root!=null&&bst[*root].x!=x){
		root=x<bst[*root].x?(&bst[*root].left):(&bst[*root].right);
	}
	if(*root==null) return false;
	if(bst[*root].left==null&&bst[*root].right==null){
		*root=null;
	}
	else if(bst[*root].left!=null&&bst[*root].right==null){
		*root=bst[*root].left;
	}
	else if(bst[*root].left==null&&bst[*root].right!=null){
		*root=bst[*root].right;
	}
	else {
		int *next;
		next=&bst[*root].left;
		while(bst[*next].right!=null) next=&bst[*next].right;
		if(bst[*next].left==null){
			bst[*next].left=bst[*root].left;
			bst[*next].right=bst[*root].right;
			*root=*next;
			*next=null;
		}
		else {
			int supp=bst[*next].left;
			bst[*next].left=bst[*root].left;
			bst[*next].right=bst[*root].right;
			*root=*next;
			*next=supp;
		}
	}
	return true;
}

int main(){
	define();
	char in[11];
	while(scanf("%s",in)&&in[0]!='e'){
		if(in[0]=='p'){
			int x;scanf("%d",&x);
			push(x);
		}
		if(in[0]=='d'){
			int x;scanf("%d",&x);
			printf("%d\n",del(x));
		}
	}
	return 0;
}
