#include <bits/stdc++.h>
using namespace std;
int main() {
    int tim = 0;
    do{
    tim++;
    if(!(tim % 100)) cout<<tim<<"ok"<<endl;
    system("./r.out > 1.in");
    system("./a.out < 1.in > a.o");
    system("./c.out < 1.in > c.o");
    }while(!system("diff a.o c.o -w"));
    cout<<tim<<"wa"<<endl;
}