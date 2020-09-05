// 다음껏 넘어가서, 이전것 다시 확인해주면 되지
// 다음껏 넘어가 각자, N
// 이전것 확인 : N
// O(N^2) : e10, 불가
// 메모리 하나 더써서 N 줄이자


#include <iostream>
#include <vector>

using namespace std;

// int map[10];
// bool chk[10];
// bool done[10];
int map[100010];
bool chk[100010];
bool done[100010];
int N;
vector<int> v;
int cnt=0;

void dfs(int i) {
    // for(int j=0; j<v.size(); j++) if(v[j]==map[i]) {
    //     cnt += v.size()-j-1;
    //     return;
    // }
    // if(!chk[map[i]]) {
    //     chk[map[i]] = 1;
    //     v.push_back(map[i]);
    //     dfs(map[i]);
    // }

    if(!chk[map[i]]) {
        chk[map[i]] = 1;
        dfs(map[i]);
    } else if(!done[map[i]]) {
        for(int kk = map[i]; kk != i; kk = map[kk]) {
            cnt++;
        }
        cnt++;
    }

    done[i] = 1;

    

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> N;
        fill(chk, chk+N+1, false);
        fill(done, done+N+1, false);
        for (int i=1; i<=N; i++) cin >> map[i];
        cnt=0;

        for (int i=1; i<=N; i++) if(!chk[i]) {
            // v.clear();
            chk[i] = 1;
            // v.push_back(i);
            dfs(i);

        }
        cout << N-cnt << '\n';
        
    }



    return 0;
}