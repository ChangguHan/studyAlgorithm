#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int> &A, int F, int M) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> rs;
    int sum=0;
    for(int x=0; x<A.size(); x++) sum+=A[x];
    if((sum+6*F)/(A.size() + F)<M) {
        rs.push_back(0);
        return rs;
    } else if((sum+1*F)/(A.size() + F)>M) {
        rs.push_back(0);
        return rs;
    }

    int needed = (A.size() + F) * M - sum;
    for (int i=0; i<F; i++) {
        rs.push_back(needed/F);
    }
    for (int i=0; i<(needed%F); i++) rs[i]++;

    return rs;

}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(6);
    // v.push_back(3);
    // v.push_back(4);
    int F=1;
    int M=1;
    vector<int> rs = solution(v,F,M);

    for(int x=0; x<rs.size(); x++) cout << rs[x] <<' ';

    return 0;
}