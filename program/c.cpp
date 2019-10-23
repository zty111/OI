#include <bits/stdc++.h>
using namespace std;
#define in(x) (string)argv[x]
const int end_times = 30; // times you want to compare
const int print_times = 10;
int main(int argc, char * argv[]) {
    system(("g++ " + in(1) + ".cpp -o r.out").c_str());
    system(("g++ " + in(2) + ".cpp -o first").c_str());
    system(("g++ " + in(3) + ".cpp -o second").c_str());
    int cnt = 1;
    time_t begin_process, end_process;
    double tim1 = 0, tim2 = 0;
    cout<< fixed << setprecision(2);
    while(1) {
        if(cnt % print_times == 0) cout<<cnt<<" provisionally same"<<endl<<endl;
        system(("./r.out > " + in(2) + ".in").c_str());
        if(cnt % print_times == 0) {
            begin_process = clock();
            system("./first");
            end_process = clock();
            cout<<"This is the first program  ";
            tim1 += (double)(end_process - begin_process) / CLOCKS_PER_SEC * 1000.0;
            cout << (double)(end_process - begin_process) / CLOCKS_PER_SEC * 1000.0 << "ms" << endl;

            begin_process = clock();
            system("./second");
            end_process = clock();
            tim2 += (double)(end_process - begin_process) / CLOCKS_PER_SEC * 1000.0;
            cout<<"This is the second program ";
            cout << (double)(end_process - begin_process) / CLOCKS_PER_SEC * 1000.0 << "ms" << endl;
            cout<<endl;
        } else {
            system("./first");
            system("./second");
        }
        if(system( ("diff " + in(2) + ".out " + in(3) + ".out -w").c_str() )){
            cout<<cnt<<" Wrong answer"<<endl;
            return 0;
        }
        cnt++;
        if(cnt > end_times) {
            cout<<endl;
            cout<<"Same answer"<<endl;
            cout<< fixed << setprecision(4);
            cout<<"First  program takes " << tim1 / cnt << "ms on average" << endl;
            cout<<"Second program takes " << tim2 / cnt << "ms on average" << endl;
            cout<<endl;
            return 0;
        }
    }
    return 0;
}