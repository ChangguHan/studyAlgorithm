#include <iostream>

using namespace std;

int main() {
    int M,N;
    cin >> M >> N;
    for (int i=M; i<=N; i++) {
        if(i==1) continue;
        bool sw =false;
        for (int j=2; j*j<=i; j++) {
            if(i%j == 0) {
                sw = true;
                break;
            }

        }
        if(!sw) cout << i << '\n';
    }



    return 0;
}