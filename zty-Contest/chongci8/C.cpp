#include <bits/stdc++.h>
using namespace std;
int RR,C,Q,a[50010][20];
struct tree {
    int lt,rt,num,laz,len,sum,mid,l,r;
}c[200010][16];
#define ls c[o][j].lt
#define rs c[o][j].rt
void pushdown(int o,int j) {
    c[ls][j].laz = c[o][j].laz;
    c[rs][j].laz = c[o][j].laz;
    c[ls][j].sum = c[o][j].laz ? c[ls][j].num : c[ls][j].len - c[ls][j].num;
    c[rs][j].sum = c[o][j].laz ? c[rs][j].num : c[rs][j].len - c[rs][j].num;
    c[o][j].laz = -1;
}
void build(int o, int L, int R, int j) {
    c[o][j].mid = ((L+R)>>1);
    c[o][j].laz = -1;
    c[o][j].l = L; c[o][j].r = R; c[o][j].len = R-L+1;
    c[o][j].lt = (o << 1); c[o][j].rt = (o << 1 | 1);
    if(L == R) {
        c[o][j].num = a[L][j];
        c[o][j].sum = a[L][j] ^ 1;
        return;
    }
    build(ls, L, c[o][j].mid, j);
    build(rs, c[o][j].mid + 1, R, j);
    c[o][j].num = c[ls][j].num + c[rs][j].num;
    c[o][j].sum = c[ls][j].sum + c[rs][j].sum;
}
void update(int o, int L, int R, int x, int j) {
    if(c[o][j].l >= L && c[o][j].r <= R) {
        c[o][j].laz = x;
        c[o][j].sum = (x ? c[o][j].num : c[o][j].len - c[o][j].num);
        return;
    }
    if(c[o][j].laz != -1) pushdown(o,j);
    if(L <= c[o][j].mid)update(ls,L,R,x,j);
    if(R > c[o][j].mid)update(rs,L,R,x,j);
    c[o][j].sum = c[ls][j].sum + c[rs][j].sum;
}
int query(int j) {
    return c[1][j].sum;
}
int main() {
    scanf("%d %d %d", &RR, &C, &Q);
    for(int i = 1; i <= RR; i++){
        char ch = getchar();
        while(ch != '0' && ch != '1') ch = getchar();
        for(int j = 1; j <= C; j++){
            a[i][j] = ch - 48;
            ch = getchar();
        }
    }
    for(int i = 1; i <= C; i++) build(1,1,RR,i);
    for(int i = 1; i <= Q; i++) {
        int r1,r2,c1,c2,x;
        scanf("%d %d %d %d %d", &r1, &r2, &c1, &c2, &x);
        for(int j = c1; j <= c2; j++)
            update(1,r1,r2,x,j);
        int ans = 0;
        for(int j = 1; j <= C; j++)
            ans += query(j);
        printf("%d\n", ans);
    }
    return 0;
}