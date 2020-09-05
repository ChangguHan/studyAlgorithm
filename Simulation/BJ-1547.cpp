#include <iostream>

#define MAX 50
using namespace std;

int map[] = {0,1,0,0};

int main() {
    int N;
    cin >> N;
    while (N--) {
        int a,b;
        cin >> a >> b;
        int tmp = map[b];
        map[b] = map[a];
        map[a] = tmp;

    }

    int rs = -1;
    for (int i=1; i<4; i++) {
        if(map[i] == 1) rs = i;
    }
    cout << rs;

    return 0;
}
