#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000000;
struct Splay{
    int ch[2],f,s,cnt,key;
}s[maxn];
int sz,root;
inline void clear(int x){
    s[x].ch[0]=s[x].ch[1]=s[x].s=s[x].cnt=s[x].key=0;
}
inline bool get(int x){
    return s[s[x].f].ch[1]==x;
}
inline void update(int x){
    if(x){
        s[x].s=s[x].cnt;
        if(s[x].ch[0])s[x].s+=s[s[x].ch[0]].s;
        if(s[x].ch[1])s[x].s+=s[s[x].ch[1]].s;
    }
}
inline void rotate(int x){
    int old=s[x].f, oldf=s[old].f, d=get(x);
    s[old].ch[d]=s[x].ch[d^1]; s[s[old].ch[d]].f=old;
    s[x].ch[d^1]=old; s[old].f=x;
    s[x].f=oldf;
    if(oldf)
        s[oldf].ch[s[oldf].ch[1]==old]=x;
    update(old); update(x);
}
inline void splay(int x){
    for(int fa;fa=s[x].f;rotate(x))
        if(s[fa].f)rotate((get(x)==get(fa))?fa:x);
    root=x;
}
inline void insert(int v){
    if(!root){sz++;s[sz].ch[0]=s[sz].ch[1]=s[sz].f=0;s[sz].key=v;root=sz;s[sz].cnt=s[sz].s=1;return;}
    int now=root,fa=0;
    while(1){
        if(s[now].key==v){s[now].cnt++;update(now);update(fa);splay(now);break;}
        fa=now;
        now=s[now].ch[s[now].key<v];
        if(now==0){
            sz++;
            s[sz].key=v; s[sz].ch[0]=s[sz].ch[1]=0; s[sz].s=s[sz].cnt=1;
            s[sz].f=fa; s[fa].ch[s[fa].key<v]=sz;
            update(fa); splay(sz); break;
        }
    }
}
inline int find(int v){
    int ans=0,now=root;
    while(1){
        if(v<s[now].key)now=s[now].ch[0];
        else{
            if(s[now].ch[0])ans+=s[s[now].ch[0]].s;
            if(v==s[now].key){splay(now);return ans+1;}
            ans+=s[now].cnt;
            now=s[now].ch[1];
        }
    }
}
inline int findx(int x){
    int now=root;
    while(1){
        if(s[now].ch[0] && x<=s[s[now].ch[0]].s)now=s[now].ch[0];
        else{
            int temp=s[now].cnt;
            if(s[now].ch[0])temp+=s[s[now].ch[0]].s;
            if(x<=temp)return s[now].key;
            x-=temp; now=s[now].ch[1];
        }
    }
}
inline int pre(){
    int now=s[root].ch[0];
    while(s[now].ch[1])now=s[now].ch[1];
    return now;
}
inline int suf(){
    int now=s[root].ch[1];
    while(s[now].ch[0])now=s[now].ch[0];
    return now;
}
inline void del(int x){
    int w=find(x);
    if(s[root].cnt>1){s[root].cnt--;update(root);return;}
    if(!s[root].ch[0] && !s[root].ch[1]){clear(root); root=0; return;}
    if(!s[root].ch[0]){int oroot=root;root=s[root].ch[1];s[root].f=0;clear(oroot);return;}
    else if(!s[root].ch[1]){int oroot=root;root=s[root].ch[0];s[root].f=0;clear(oroot);return;}
    int le=pre(),oroot=root;
    splay(le);
    s[root].ch[1]=s[oroot].ch[1];
    s[s[oroot].ch[1]].f=root;
    clear(oroot);
    update(root);
}
inline void read(int &x){
    x=0;int f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-48,ch=getchar();
    x*=f;
}
int main(){
    int n,opt,x;
    read(n);
    for(int i=1;i<=n;i++){
        read(opt);read(x);
        switch(opt){
            case 1: insert(x); break;
            case 2: del(x); break;
            case 3: printf("%d\n",find(x)); break;
            case 4: printf("%d\n",findx(x)); break;
            case 5: insert(x); printf("%d\n",s[pre()].key); del(x); break;
            case 6: insert(x); printf("%d\n",s[suf()].key); del(x); break;
        }
    }
    return 0;
}
