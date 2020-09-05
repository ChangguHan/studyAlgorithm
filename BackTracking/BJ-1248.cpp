// -10 부터 10까지
// 각 조건에 안맞으면 바로바로ㅗ 가지치기
// 21^10


#include <iostream>
#include <string>
#include <vector>
using namespace std;

char map[20][20];
int N;
int nums[] = {-10,-9,-8,-7,-6,-5,-4,-3,-2,-1,0,
1,2,3,4,5,6,7,8,9,10};
bool chk[21];
vector<int> v;
void dfs(int n) {
    if(n==N) {
        for (int x : v) cout << x << ' ';
        exit(0);
    }
    for (int i=0; i<21; i++) {
        if(chk[i]) continue;
        if(v.size() == 0) {
            if(map[0][0] == '-' && nums[i] < 0) {
                chk[i]=1;
                v.push_back(nums[i]);
                dfs(n+1);
                v.pop_back();
                chk[i]=0;
            }else if (map[0][0] == '0'&& nums[i] == 0) {
                chk[i]=1;
                v.push_back(nums[i]);
                dfs(n+1);
                v.pop_back();
                chk[i]=0;
            }else if (map[0][0] == '+' && nums[i] > 0) {
                chk[i]=1;
                v.push_back(nums[i]);
                dfs(n+1);
                v.pop_back();
                chk[i]=0;
            }
        }
        // 다음 더하는것에 대해서만 비교하면 됨
        int vsize = v.size();
        for(int j=0; j<v.size(); j++) {
            int sum = v[j];
            for (int k=j+1; k<v.size(); k++) {
                sum += v[k];
            }
            sum += nums[i];
            if(map[j][vsize] == '-') {
                if( sum<0) {
                    chk[i]=1;
                    v.push_back(nums[i]);
                    dfs(n+1);
                    v.pop_back();
                    chk[i]=0;
                }
            }else if (map[j][vsize] == '0') {
                if(sum==0) {
                    chk[i]=1;
                    v.push_back(nums[i]);
                    dfs(n+1);
                    v.pop_back();
                    chk[i]=0;
                }
            }else if (map[j][vsize] == '+' ){
                if(sum>0) {
                    chk[i]=1;
                    v.push_back(nums[i]);
                    dfs(n+1);
                    v.pop_back();
                    chk[i]=0;
            }
        }
        
    }

}
int main() {
    cin >> N;
    string ip;
    cin >> ip;
    int idx=0;
    for (int j=0; j<N; j++) {
        for (int i=j; i<N; i++) {
            map[j][i] = ip[idx++];
        }
    }
    fill(chk, chk+21, false);

    dfs(0);


    return 0;
}