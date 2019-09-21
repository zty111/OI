#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;
int main(){
    for(int T=1;T<=10000;T++){
        system("./r.out > 1.in");
        system("./a.out < 1.in > my.out");
        double st=clock();
        system("./c.out < 1.in > 1.out");
        double ed=clock();
        if(system("diff 1.out my.out")){
            puts("Wrong Answer");
            return 0;
        }
        else{
            printf("Accept,测试点 #%d, 用时 %0.1fms\n",T,ed-st);
        }
    }
    return 0;
}