// 5를 먼저 때고 구하면 안되나
// O(N/5) >> 1000

#include <iostream>

using namespace std;

int main() {
    int N; cin >> N;
    for(int i=N/5; i>=0; i--) {
        int rest = N-i*5;
        if(rest%3==0) {
            cout << i+rest/3 << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';

    return 0;
}