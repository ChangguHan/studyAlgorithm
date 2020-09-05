#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i=2; i<=N; i++) {
        while(1) {
            if(N%i!=0) break;
            N/=i;
            cout << i << '\n';
        }
    }

    return 0;
}