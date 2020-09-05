// dfs로 하면 될듯

#include <iostream>
#include <vector>

using namespace std;
vector<int> v;
vector<int> rs;
int nums[100010];
bool chk[100010];

// int nums[20];
// bool chk[20];


void dfs(int n) {


    if(nums[n] == n) {
        for (int x : v) {
            chk[x] = 1;
        }
        rs.push_back(n);
        return;
    }


    for (int i=0; i<v.size(); i++) {
        if(nums[n]==v[i]) {
            for (int j=i; j<v.size(); j++) {
                rs.push_back(v[j]);
            }
            for (int k=0; k<v.size(); k++) chk[v[k]] = 1;
            chk[nums[n]] = 1;
            return;
        }
    }

    if(chk[nums[n]]) {
        for(int x : v) chk[x] = 1;
    }else {
        v.push_back(nums[n]);
        dfs(nums[n]);
    }


}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        fill(chk, chk+n+1, false);
        rs.clear();
        for (int i=1; i<=n; i++) cin >> nums[i];
        for (int i=1; i<=n; i++) {
            if(!chk[i]) {
                v.clear();
                v.push_back(i);
                dfs(i);
            }
        }


        cout << n-rs.size() << '\n';


    }

    return 0;
}