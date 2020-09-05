#include <iostream>

using namespace std;
int map[4][2];
int pp=0;
int maxv = 0;

int main() {
    for(int j=0; j<4; j++) {
        for (int i=0; i<2; i++) {
            cin >>map[j][i];
        }
        pp = pp -map[j][0] + map[j][1];
        maxv = max(maxv, pp);
    }

    cout <<maxv;
    

    return 0;
}