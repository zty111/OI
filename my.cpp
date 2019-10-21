#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
const int inf = 0x7fffffff;
const int N = 50010;
struct Node {
    Node * ch[2];
    int r, v, s, cnt = 1;
    int cmp(int x) const {
        if(x == v) return -1;
        else return x < v ? 0 : 1;
    }
    void maintain() {
        s = cnt;
        if(ch[0] != NULL) s += ch[0]->s;
        if(ch[1] != NULL) s += ch[1]->s;
    }
};
Node * root = NULL;
void rotate(Node * &o, int d) {
    Node * k = o->ch[d^1]; o->ch[d^1] = k->ch[d]; k->ch[d] = o;
    o->maintain(); k->maintain(); o = k;
}
void insert(Node * &o, int x) {
    if(o == NULL) {o = new Node(); o->ch[0] = o->ch[1] = NULL; o->r = rand(); o->v = x;} 
    else {
        int d = o->cmp(x);
        if(d == -1) o->cnt++;
        else {insert(o->ch[d], x); if(o->ch[d]->r > o->r) rotate(o, d^1);}
    }
    o->maintain();
}
void remove(Node * &o, int x) {
    int d = o->cmp(x);
    if(d == -1) {
        if(o->cnt > 1) o->cnt--;
        else if(o->ch[0] == NULL) o = o->ch[1];
        else if(o->ch[1] == NULL) o = o->ch[0];
        else {
            int d2 = (o->ch[0]->r > o->ch[1]->r ? 1 : 0);
            rotate(o, d2); remove(o->ch[d2], x);
        } 
    } else remove(o->ch[d], x);
    if(o != NULL) o->maintain();
}
int kth(Node * o, int k) {
    if(o == NULL || k <= 0 || k > o->s) return 0;
    int s = (o->ch[0] == NULL ? 0 : o->ch[0]->s);
    if(k > s && k <= s + o->cnt) return o->v;
    else if(k <= s) return kth(o->ch[0], k);
    else return kth(o->ch[1], k - s - o->cnt);
}
int Rank(Node * o, int x) {
    if(o == NULL) return 0;
    int le = o->ch[0] == NULL ? o->cnt: o->ch[0]->s + o->cnt;
    if(o->v == x) return le - o->cnt + 1;
    else if(o->v < x) return le + Rank(o->ch[1], x);
    else if(o->v > x) return Rank(o->ch[0], x);
}
int getpre(Node * o, int x) {
    int res = -inf;
    while(o != NULL) {
        if(o->v < x) res = o->v, o = o->ch[1];
        else o = o->ch[0];
    }
    return res;
}
int getsuf(Node * o, int x) {
    int res = inf;
    while(o != NULL) {
        if(o->v > x) res = o->v, o = o->ch[0];
        else o = o->ch[1];
    }
    return res;
}
inline char nc(){
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1==p2 && (p2= (p1=buf) + fread(buf,1,100000,stdin), p1==p2)? EOF : *p1++;
}
inline int read(){
    int x = 0, f = 1; char ch = nc();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = nc();}
    while(ch >= '0' && ch <= '9') x = (x<<3) + (x<<1) + ch - 48, ch = nc();
    return x * f;
}
#define mid ((tree[o].l+tree[o].r)>>1)
#define lt (o<<1)
#define rt (o<<1|1)
#define lson lt, tree[o].l, mid
#define rson rt, mid + 1, tree[o].r
int w[N];
struct SEG {
    int l, r;
    Node * root = NULL;
}tree[N * 8];
void build(int o, int l, int r) {
    tree[o].l = l;
    tree[o].r = r;
    for(int i = l; i <= r; i++)
        insert(tree[o].root, w[i]);
    if(l != r)  build(lson), build(rson);
}
void qup(int o, int p, int k) {
    remove(tree[o].root, w[p]);
    insert(tree[o].root, k);
    if(tree[o].l == tree[o].r) return;
    if(p > mid) qup(rt, p, k);
    else qup(lt, p, k);
}
int qrank(int o, int l, int r, int k) {
    if(tree[o].l > r || tree[o].r < l) return 0;
    if(tree[o].l >= l && tree[o].r <= r) return Rank(tree[o].root, k);
    else return qrank(lt, l, r, k) + qrank(rt, l, r, k);
}
int qnum(int l, int r, int k) {
    int L = 0, R = 1e8;
    while(L < R) {
        int Mid = (L + R + 1) / 2;
        if(qrank(1, l, r, Mid) < k) L = Mid;
        else R = Mid - 1;
    } return R;
}
int qpre(int o, int l, int r, int k) {
    if(tree[o].l > r || tree[o].r < l) return -inf;
    if(tree[o].l >= l && tree[o].r <= r) return getpre(tree[o].root, k);
    else return max(qpre(lt, l, r, k), qpre(rt, l, r, k));
}
int qsuf(int o, int l, int r, int k) {
    if(tree[o].l > r || tree[o].r < l) return inf;
    if(tree[o].l >= l && tree[o].r <= r) return getsuf(tree[o].root, k);
    else return min(qsuf(lt, l, r, k), qsuf(rt, l, r, k));
}
int main() {
    int n = read(), m = read();
    for(int i = 1; i <= n; i++) w[i] = read();
    build(1, 1, n);
    for(int i = 1;i <= m; i++) {
        int opt = read();
        if(opt == 3) {
            int pos = read(), k = read();
            qup(1, pos, k);
            w[pos] = k;
        } else {
            int l = read(), r = read(), k = read();
            if(opt==1) printf("%d\n", qrank(1, l, r, k) + 1);
            else if(opt==2) printf("%d\n", qnum(l, r, k));
            else if(opt==4) printf("%d\n", qpre(1, l, r, k));
            else if(opt==5) printf("%d\n", qsuf(1, l, r, k));
        }
    }
    return 0;
}