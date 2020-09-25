#include <iostream>


#include <string>
#include <vector>

using namespace std;

// 그래프탐색하면 되지 않을까?
// dfs로 하면서. O(M+N)
// 
int solution(vector<vector<int>> t1, vector<vector<int>> t2)
{
    int answer = -1;
    return answer;
}

int main() {
    

    vector<vector<int>> t1; vector<vector<int>> t2;

    vector<int> et1;
    et1.clear();
    et1.push_back(1);
    et1.push_back(2);
    t1.push_back(et1);

    et1.clear();
    et1.push_back(3);
    et1.push_back(4);
    t1.push_back(et1);

    et1.clear();
    et1.push_back(5);
    et1.push_back(6);
    t1.push_back(et1);

    et1.clear();
    et1.push_back(-1);
    et1.push_back(7);
    t1.push_back(et1);

    et1.clear();
    et1.push_back(8);
    et1.push_back(9);
    t1.push_back(et1);

    et1.clear();
    et1.push_back(-1);
    et1.push_back(-1);
    t1.push_back(et1);

    et1.clear();
    et1.push_back(-1);
    et1.push_back(-1);
    t1.push_back(et1);
    et1.clear();
    et1.push_back(-1);
    et1.push_back(-1);
    t1.push_back(et1);
    et1.clear();
    et1.push_back(-1);
    et1.push_back(-1);
    t1.push_back(et1);
    et1.clear();
    et1.push_back(-1);
    et1.push_back(-1);
    t1.push_back(et1);

    vector<int> et2;
    et2.clear();
    et2.push_back(1);
    et2.push_back(2);
    t2.push_back(et2);

    et2.clear();
    et2.push_back(-1);
    et2.push_back(-1);
    t2.push_back(et2);
    et2.clear();
    et2.push_back(-1);
    et2.push_back(-1);
    t2.push_back(et2);


    cout << solution(t1, t2) << '\n';
    return 0;
}