#include <iostream>
// 3시간, 4문제
using namespace std;
#include <string>
#include <vector>
#include <set>
#include <algorithm>
// 그냥 N*N으로 추가한다음 sort하면 될것같은데
// set으로 하면 될것같음

using namespace std;

vector<int> solution(vector<int> numbers) {
    set<int> tmp;
    for(int i=0; i<numbers.size(); i++) {
        for(int j=i+1; j<numbers.size(); j++) {
            tmp.insert(numbers[i] + numbers[j]);
        }
    }
    // sort(tmp.begin(), tmp.end());

    vector<int> answer(tmp.begin(), tmp.end());
    sort(answer.begin(), answer.end());
    return answer;
}
int main() {
    vector<int> numbers;
    numbers.push_back(2);
    numbers.push_back(1);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(1);
    for(int x : solution(numbers)) cout << x << ' ';
    return 0;
}