#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int str[10][10];
int row[9], col[9], grid[9], cnt[512], num[512], tot;

const int a[10][10]={
    {6,6,6,6,6,6,6,6,6},
    {6,7,7,7,7,7,7,7,6},
    {6,7,8,8,8,8,8,7,6},
    {6,7,8,9,9,9,8,7,6},
    {6,7,8,9,10,9,8,7,6},
    {6,7,8,9,9,9,8,7,6},
    {6,7,8,8,8,8,8,7,6},
    {6,7,7,7,7,7,7,7,6},
    {6,6,6,6,6,6,6,6,6},
};

inline int g(int x,int y){
    return (x / 3) * 3 + y / 3;
}

inline void flip(int x ,int y ,int z){
    row[x] ^= 1 << z;
    col[y] ^= 1 << z;
    grid[g(x,y)] ^= 1 << z;
}

int ans;

int grade(){
    long long ret = 0;
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            ret=ret+str[i][j]*a[i][j];
    return ret;
}
 
bool dfs(int now){
    if (now == 0){
        ans=max(ans,grade());
        return 0;
    }
    int temp = 10, x, y;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++){
            if (str[i][j] != 0)continue;
            int val = row[i] & col[j] & grid[g(i,j)];
            if (!val) return 0;
            if (cnt[val] < temp) {
                temp = cnt[val];
                x = i, y = j;
            }
        }
    int val = row[x] & col[y] & grid[g(x,y)];
    for (; val; val -= val & -val){
        int z = num[val & -val];
        str[x][y] = 1 + z;
        flip(x, y, z);
        dfs(now-1);
        flip(x, y, z);
        str[x][y] = 0;
    }
    return 0;
}

int main(){
    for (int i = 0; i < 1 << 9; i++)
        for(int j = i; j; j -= j & -j)cnt[i]++;
    for (int i = 0; i < 9; i++)
        num[1 << i] = i;
    for(int i = 0; i < 9; i++)
        row[i] = col[i] = grid[i] = (1 << 9) - 1;

    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            scanf("%d", &str[i][j]);
    
	tot = 0;
    for (int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            if(str[i][j] != 0)flip(i, j, str[i][j] - 1);
            else tot++;

    dfs(tot);

    if(!ans)printf("-1\n");
    else printf("%d\n",ans);
}