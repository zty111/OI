#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    int tim = 0;
    while(1){
    system("./r.out > 1.in");
    system("./c.out < 1.in > c.o");
    system("./c1.out < 1.in > c1.o");
    if(system("diff c.o c1.o -w")) {
        printf("Wrong answer\n"); 
        system("more 1.in");
        return 0;
    }
        if(++tim % 1000 == 0) cout<<tim<<endl;
    }
    return 0;
}