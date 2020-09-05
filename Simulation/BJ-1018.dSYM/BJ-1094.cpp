#include <iostream>

using namespace std;

// bool map[7];
int cnt;

int main() {
    // fill(map, map+6, false);
    
    int n;
    cin >> n;

    for (int i=6; i>=0; i--) {
        if(n<(1<<i)) continue;
        n -= (1<<i);
        cnt++;


    }

    cout << cnt;

    
    return 0;
}
