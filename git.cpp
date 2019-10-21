#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    system("git add *");
    system("git commit -m \"2019\"");
    system("git push -u origin master");
    printf("OK\n");
    return 0;
}