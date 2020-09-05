// 입력 받으면서 더해서 내려가면서 체크하면 되지 않나

#include <iostream>
#include <string>

using namespace std;

int N,M;
int map[1010][1010];
int col[1010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int j=0; j<N; j++) {
        string ip;
        cin >> ip;
        int cnt=0;
        for (int i=0; i<M; i++) {
            if(ip[i]=='1') cnt++;
            else cnt=0;
            map[j][i] = cnt;
        }
    }

    int maxv=0;
    for (int i=0; i<M; i++) {
        fill(col, col+1010, 0);
        for (int j=0; j<N; j++) {
            if(map[j][i] !=0) {
                col[map[j][i]]++;
                for(int kk= map[j][i]+1; kk<=1010; kk++) col[kk]=0;
                int sum=0;
                for(int k=1000; k>=1; k--) {
                    if(col[k]!=0) sum+=col[k];
                    if(sum>=k) {
                        maxv = max(k,maxv);
                    }
                }
            }
            else {
                fill(col, col+1010, 0);
            }
        
        }   

    }

    cout << maxv*maxv << '\n';




    return 0;
}