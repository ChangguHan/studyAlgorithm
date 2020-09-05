#include <iostream>
using namespace std;
int main() {
    int cnt = 10;
    int N = 12;

    int cntb = cnt;
    for(int i=2; i<=cnt; i++) {
        // cnt의 소수 먼저 구하기
        if(cntb%i == 0) {
            
            if(N%i==0) {
                cntb = cntb/i;
                N = N/i;
                i--;
                if(cntb==1) break;
            }
        }
        // 소수 구하면 계속 약분해주기
    }

    cout << cntb << '\n';
    cout << N << '\n';



    return 0;
}