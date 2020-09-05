// 최소경로니까 다익스트라로

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using pi2 = pair<int, int>;

const int inf = 1e6;
int dist[810];
int N,E;
vector<pair<int, int> > adj[810];

int nums[810][810];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> E;
    fill(&nums[0][0], &nums[809][810],inf);
    for (int i=0; i<E; i++ ){
        int a,b,c;
        cin >> a >> b >> c;
        nums[a][b] = min(nums[a][b], c);
        nums[b][a] = min(nums[b][a], c);
    }
    int st,en;
    cin >> st >> en;
    for (int i=1; i<=N; i++) nums[i][i] = 0;

    for (int k=1; k<=N; k++) 
        for (int j=1; j<=N; j++)
            for (int i=1; i<=N; i++) {
                if(nums[j][i] > nums[j][k]+nums[k][i]) {
                    nums[j][i] = nums[j][k] + nums[k][i];
                }
            }
    
    int rs = nums[1][st] + nums[st][en] + nums[en][N];
    if(rs > nums[1][en]+nums[en][st]+nums[st][N]) {
        rs = nums[1][en]+nums[en][st]+nums[st][N];
    }
    if(rs >= inf) rs = -1;



    cout << rs <<'\n';
    



    return 0;
}