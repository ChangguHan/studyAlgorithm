#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int cnt=0;
    if(N%5=0)

    cnt += N/5;
    N %=5;
    if(N%3==0) {
        cnt += N/3;
        cout << cnt << '\n';
    }else {
        cout << -1 << '\n';
    }


    return 0;
}