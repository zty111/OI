#include <cstdio>
#include <iostream>
using namespace std;
const char usr_name[] = "zty111";
const char password[] = "zty20030212";
int main() {
    system("git add *");
    system("git commit -m \"2019\"");
    system("git push -u origin master");
    system(usr_name);
    system(password);
    printf("OK\n");
    return 0;
}