// 각 시간마다 
// 벡터에 있는것 한칸씩 증가시키고,
// 무게비교해서 벡터에 넣음

#include <iostream>
#include <vector>

using namespace std;
int truck[1010];
int trL[1010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,w,L;
    cin >> n >> L >> w;
    for(int i=0; i<n; i++) cin >> truck[i];
    int tst=0;
    int ten =0;
    int tw=0;
    
    int time=0;
    while(tst!=n) {
        time++;

        // 트럭 한칸씩 밀어주기
        for(int i=tst; i<ten; i++) {
            trL[i]++;
            if(trL[i]==L+1) {
                tst++;
                tw-=truck[i];
            }
        }
        if(ten<n) {
            if(truck[ten] + tw <= w) {
                tw += truck[ten];
                trL[ten]++;
                ten++;
                
            }

        }

    }

    cout << time << '\n';


    return 0;
}