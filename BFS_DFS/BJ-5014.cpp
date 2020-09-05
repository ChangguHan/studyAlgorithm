// 최소값 BFS로 풀면될듯
// 위로만 가면 DP 가능한데, 위아래로 해야되서 BFS
// 1e7
// 이거 시간복잡도 어떻게 계산해야돼??
// 이따가 찾아보기

#include <iostream>
#include <queue>

using namespace std;
int F,S,G,U,D;
bool visit[1000010];
// bool visit[100];
int main() {
    cin >> F >> S >> G >> U >> D;
    queue<int> q;
    q.push(S);
    fill(visit, visit+1000010, false);
    // fill(visit, visit+100, false);
    visit[S] =1;
    int time=0;
    if(S==G) {
        cout << time <<'\n';
        return 0;
    }
    

    while(!q.empty()) {
        time++;
        int qsize = q.size();
        while(qsize--) {
            int eq = q.front(); q.pop();
            if(eq+U<=1000000) {
                if(eq+U == G) {
                    cout << time << '\n';
                    return 0;
                }
                if(visit[eq+U] == false) {
                    visit[eq+U]=1;
                    q.push(eq+U);
                }

            }

            if(eq-D>=1 ) {
                if(eq-D == G) {
                    cout << time << '\n';
                    return 0;
                }
                if(visit[eq-D] == false) {
                    visit[eq-D]=1;
                    q.push(eq-D);
                }

            }
            
        }
    }

    cout << "use the stairs" << '\n';

    return 0;
}
