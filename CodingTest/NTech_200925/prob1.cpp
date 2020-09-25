#include <iostream>


#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> flowers)
{
    int cnt[400];
    fill(cnt, cnt+400, 0);
    for(auto x : flowers) {
        int st = x[0];
        int en = x[1];
        for(int i=st; i<en; i++) {
            cnt[i]++;
        }
    }
    
    int rs=0;
    for(int i=1; i<=365; i++) {
        if(cnt[i] >0) rs++;
    }
    return rs;
}
int main() {
    vector<vector<int>> flowers;
    vector<int> e;
    
    // e.clear();
    // e.push_back(2);
    // e.push_back(5);
    // flowers.push_back(e);
    // e.clear();
    // e.push_back(3);
    // e.push_back(7);
    // flowers.push_back(e);
    // e.clear();
    // e.push_back(10);
    // e.push_back(11);
    // flowers.push_back(e);

    e.clear();
    e.push_back(3);
    e.push_back(4);
    flowers.push_back(e);
    e.clear();
    e.push_back(4);
    e.push_back(5);
    flowers.push_back(e);
    e.clear();
    e.push_back(6);
    e.push_back(7);
    flowers.push_back(e);
    e.clear();
    e.push_back(8);
    e.push_back(10);
    flowers.push_back(e);
    

    cout << solution(flowers) << '\n';
    return 0;
}