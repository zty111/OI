#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[20][20],f[16][226][16][16][2][2];
//i行,j格,左边界l,右边界r,左边单调性,右边单调性
struct state{
    int a,b,c,d,e,f;
    //state(int a,int b,int c,int d,int e,int f):a(a),b(b),c(c),d(d),e(e),f(f){}
}p[16][226][16][16][2][2];
void print(int a,int b,int c,int d,int e,int f){
    if(!b)return;
    state & pn=p[a][b][c][d][e][f];
    print(pn.a,pn.b,pn.c,pn.d,pn.e,pn.f);
    for(int y=c;y<=d;y++)printf("%d %d\n",a,y);
}
int i,j,l,r,x,y,t;
inline void update(int data,int L,int R,int X,int Y){
    if(data<f[i][j][l][r][x][y])return;
    f[i][j][l][r][x][y]=data;
    p[i][j][l][r][x][y]=(state){i-1,j-t,L,R,X,Y};
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            a[i][j]+=a[i][j-1];//sum
        }
    for(i=1;i<=n;i++)
        for(j=1;j<=k;j++)
            for(l=1;l<=m;l++)
                for(r=l;r<=m;r++){
                    if((t=r-l+1)>j)break;
                    int now=a[i][r]-a[i][l-1];
                    for(x=0;x<2;x++)
                        for(y=0;y<2;y++)
                            update(now,m,0,x,y);
                            x=1;y=0;
                    for (int p=l;p<=r;++p)
						for (int q=p;q<=r;++q)
							update(f[i-1][j-t][p][q][1][0]+now,p,q,1,0);
					x=0,y=1;
					for (int p=1;p<=l;++p)
						for (int q=r;q<=m;++q)
							update(f[i-1][j-t][p][q][1][0]+now,p,q,1,0),
							update(f[i-1][j-t][p][q][1][1]+now,p,q,1,1),
							update(f[i-1][j-t][p][q][0][1]+now,p,q,0,1),
							update(f[i-1][j-t][p][q][0][0]+now,p,q,0,0);
					x=y=0;
					for (int p=l;p<=r;++p)
						for (int q=r;q<=m;++q)
							update(f[i-1][j-t][p][q][1][0]+now,p,q,1,0),
							update(f[i-1][j-t][p][q][0][0]+now,p,q,0,0);
					x=y=1;
					for (int p=1;p<=l;++p)
						for (int q=l;q<=r;++q)
							update(f[i-1][j-t][p][q][1][0]+now,p,q,1,0),
							update(f[i-1][j-t][p][q][1][1]+now,p,q,1,1);

                }
    int ans=0,ai=0,al=0,ar=0,ax=0,ay=0;
	for (i=1;i<=n;++i)
		for (l=1;l<=m;++l)
			for (r=1;r<=m;++r)
				for (x=0;x<2;++x)
					for (y=0;y<2;++y)
						if (ans<f[i][k][l][r][x][y])
						{
							ans=f[i][k][l][r][x][y];
							ai=i,al=l,ar=r,ax=x,ay=y;
						}
	printf("Oil : %d\n",ans);
	print(ai,k,al,ar,ax,ay);
    return 0;
}