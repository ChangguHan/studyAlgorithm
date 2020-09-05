#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int topni[4][9];
int K;
int rs=0;
bool topniCheck[4] = {false};

void topni_turn(int topidx, int wise) {
    topniCheck[topidx] = true;
    if(topidx==3) {
        if(topni[topidx-1][2] != topni[topidx][6] && topniCheck[topidx-1] == false) {
            topni_turn(topidx-1,wise *-1);
        }
    }else if(topidx==0) {
        if(topni[topidx][2] != topni[topidx+1][6] && topniCheck[topidx+1] == false) {
            topni_turn(topidx+1, wise *-1);
        }
    } else{
        if(topni[topidx-1][2] != topni[topidx][6] && topniCheck[topidx-1] == false) {
            topni_turn(topidx-1,wise *-1);
        }
        if(topni[topidx][2] != topni[topidx+1][6] && topniCheck[topidx+1] == false) {
            topni_turn(topidx+1, wise *-1);
        }
    }
    int tmp;
    if(wise == 1) {
        tmp = topni[topidx][7];
        for (int i=7; i>0; i--) {
            topni[topidx][i] = topni[topidx][i-1];
        }
        topni[topidx][0] = tmp;
    } else if(wise == -1) {
        tmp = topni[topidx][0];
        for(int i=1; i<8; i++) {
            topni[topidx][i-1] = topni[topidx][i];
        }
        topni[topidx][7] = tmp;
    }

    // cout << topni;


}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string strtmp;

    for (int j=0; j<4; j++) {
        cin >> strtmp;
        for (int i=0; i<8; i++) {
            topni[j][i] = strtmp[i]-'0';
        }
    }
    cin >> K;
    while(K--) {
        int topidx, wise;
        cin >> topidx >> wise;
        fill(topniCheck, topniCheck+4, false);
        topni_turn(topidx-1, wise);
    }

    for (int j=0; j<4; j++) {
        if(topni[j][0]) rs += (1<<j);
    }

    cout << rs;
    return 0;
}