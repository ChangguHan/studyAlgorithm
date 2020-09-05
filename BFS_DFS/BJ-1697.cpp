// chk 해야됨

#include <iostream>
#include <queue>

using namespace std;

bool chk[100010];
int main() {
    int N,K;
    cin >> N >> K;
    chk[N] = 1;
    queue<int> q;
    q.push(N);
    int time=0;
    if(N==K) {
        cout << time << '\n';
        return 0;
    }
    bool sw = false;
    while(!q.empty()) {
        time++;
        int qsize = q.size();
        while(qsize--) {
            int eq = q.front();q.pop();
            if(eq*2 <=100000) {
                if(!chk[eq*2]) {
                    if(eq*2 == K) {
                        sw = true;
                        break;
                    }
                    chk[eq*2] = 1;
                    q.push(eq*2);
                }
            }

            if(eq+1 <=100000) {
                if(!chk[eq+1]) {
                    if(eq+1 == K) {
                        sw = true;
                        break;
                    }
                    chk[eq+1] = 1;
                    q.push(eq+1);
                }
            }

            if(eq-1 >=0) {
                if(!chk[eq-1]) {
                    if(eq-1 == K) {
                        sw = true;
                        break;
                    }
                    chk[eq-1] = 1;
                    q.push(eq-1);
                }
            }

        }
        if(sw) break;
        
    }

    cout << time << '\n';

    return 0;
}