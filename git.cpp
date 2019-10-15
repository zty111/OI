#include <cstdio>
#include <iostream>
using namespace std;
//git config --global credential.helper store
int main() {
    system("git add *");
    system("git commit -m \"2019\"");
    system("git push -u origin master");
    printf("OK\n");
    return 0;
}