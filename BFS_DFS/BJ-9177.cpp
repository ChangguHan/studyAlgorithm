// 각각 인덱스 관리해서 맞으면 재귀 넘어가고
// 틀리면 다시 돌아옴


#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N;
string a,b,c;
bool rs = false;

// 메모리 초과 잡기 위해, 지나온길 안지나가게
bool chk[1010][1010];

// 재귀로하면 시간초과나옴
// void dfs(int aai, int bbi, int cci) {
//     if(cci == c.length()) {
//         rs = true;
//         return;
//     }
//     if(rs) return;

//     if(c[cci] == a[aai]) dfs(aai+1, bbi, cci+1);
//     if(c[cci] == b[bbi]) dfs(aai, bbi+1, cci+1);
// }


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for(int i=1; i<=N; i++) {
        rs = false;
        cin >> a >> b >>c;
        // dfs(0,0,0);
        queue<pair<int, int> > q;
        fill(&chk[0][0], &chk[1009][1010], false);
        int si = 0;
        if(c[0] == a[0]) q.push(make_pair(1,0));
        if(c[0] == b[0]) q.push(make_pair(0,1));
        while(!q.empty()) {
            si++;
            if(si==c.size()) {
                rs = true;
                break;
            }
            int qsize = q.size();
            for (int j=0; j<qsize; j++) {
                auto eq = q.front(); q.pop();
                if(c[si] == a[eq.first]){
                    if(!chk[eq.first+1][eq.second])  {
                        chk[eq.first+1][eq.second] = 1;
                        q.push(make_pair(eq.first+1,eq.second));
                    }
                    
                }
                if(c[si] == b[eq.second]){
                    if(!chk[eq.first][eq.second+1])  {
                        chk[eq.first][eq.second+1] = 1;
                        q.push(make_pair(eq.first,eq.second+1));
                    }
                    

                }
            }

        }
        // if(si==c.size()) rs = true;



        cout << "Data set "<< i << ": ";
        if(rs) cout << "yes\n";
        else cout << "no\n";

    }


    return 0;
}