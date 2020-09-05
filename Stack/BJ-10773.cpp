#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int K;
    cin >> K;
    vector<int> s;
    while(K--) {
        int e;
        cin >> e;
        if(e==0) s.pop_back();
        else s.push_back(e);
    }
    int sv=0;
    for(int x : s) sv +=x;
    cout << sv << '\n';


    return 0;
}