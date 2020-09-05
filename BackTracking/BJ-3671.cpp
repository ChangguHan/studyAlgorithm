// 모든 경우의 수에 대해, 소수인지를 확인
// 소수인지는 어떻게 확인? >> 하나하나씩 나눠주면돼
// 하나하나씩 다 나누기 너무 오래걸리지 않을까?
// 그럼 N/2까지 나눴을때 return으로?

// 시갅복잡도
// N개의 숫자를 갖는것을 돌리고
// N^n개의 경우의 수
// 체크하려면 N번
// >> N^(n+2)
// N이 맥스 7개, 

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

char num[7];
char thisNum[7];
vector<int> v;
vector<int> m;
bool chk[7];
string ip;
int ans;

bool chkThisNum() {
    int numint;
    string nums;
    for (int i=0; i<v.size(); i++) {
        nums += v[i];
    }
    numint = stoi(nums);
    if(numint<=1) return 0;
    for (int i=0; i<m.size(); i++) {
        if(m[i] == numint) return 0;
    }
    
    for (int j=2; j<=sqrt(numint); j++) {
        if(numint%j == 0) return 0;
    }
    m.push_back(numint);
    return 1;
}

void dfs(int idx,int cnt, int N) {
    if(cnt== N) {
        if(chkThisNum()) {
            ans++;
            return;
        }
        return;
    }

    for (int i=0; i<ip.length(); i++) {
        if(chk[i]) continue;
        v.push_back(ip[i]);
        chk[i] = 1;
        dfs(i+1, cnt+1, N);
        v.pop_back();
        chk[i] = 0;
    }

}

int main() {
    int T;
    cin >> T;
    while(T--) {
        v.clear();
        m.clear();
        ans=0;
        cin >> ip;
        for (int i=0; i<ip.length(); i++) {
            num[i] = ip[i];
        }
        for (int i=1; i<= ip.length(); i++) {
            fill(chk, chk+7, 0);
            dfs(0,0,i);
        } 
        cout << ans << '\n';
    }

    return 0;
}
