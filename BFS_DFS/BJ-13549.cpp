// 매초마다 2배 곱한거 큐에 넣기

#include <iostream>
#include <queue>

using namespace std;

int const inf = 1e5;
// int const inf = 100;
int N,K;
bool visit[100010];
int main() {
    cin >> N >> K;
    queue<int> q;

    if(N==K) {
        cout << 0 << '\n';
        return 0;
    }
    q.push(N);
    visit[N] =1;

    int time=0;

    while(!q.empty()) {
        time++;
        int qsize = q.size();
        while(qsize-- ) {
            int eq = q.front(); q.pop();
            // 여기는 2의 배수가 다 들어있을 수밖에 없어
            if(eq+1<=inf) {
                if(!visit[eq+1]) {
                    if(eq+1 == K) {
                        cout << time << '\n';
                        return 0;
                    }
                    visit[eq+1]=1;
                    q.push(eq+1);

                }
            }
            if(eq-1>=0) {
                if(!visit[eq-1]) {
                    if(eq-1 == K) {
                        cout << time << '\n';
                        return 0;
                    }
                    q.push(eq-1);
                    visit[eq-1]=1;

                }
            }
            if(eq*2<=inf) {
                if(!visit[eq*2]) {
                    if(eq*2 == K) {
                        cout << time << '\n';
                        return 0;
                    }
                    q.push(eq*2);
                    visit[eq*2]=1;

                }
            }
        }
        
    }


    return 0;
}