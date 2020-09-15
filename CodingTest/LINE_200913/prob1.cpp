#include <iostream>

using namespace std;

#include <string>
#include <vector>


// 배열안에다 모두 두고,
// 2개 이상인것들을 카운트해나감
// 그리고 상자 개수에서 카운트 뺸것을 제출
int solution(vector<vector<int>> boxes) {
    int N = boxes.size();
    int nums[1000010];
    fill(nums, nums+1000010,0);
    // int nums[100];
    // fill(nums, nums+100,0);
    for(auto x : boxes) {
        nums[x[0]]++;
        nums[x[1]]++;
    }
    int cnt=0;
    for(int i=0; i<1000010; i++) {
    // for(int i=0; i<100; i++) {
        if(nums[i]>1) {
            cnt += nums[i]/2;
        }
    }
    
    return N-cnt;
}
int main() {

    vector<vector<int>> boxes;
    vector<int> e;

    e.clear();
    e.push_back(1);
    e.push_back(2);
    boxes.push_back(e);

    e.clear();
    e.push_back(2);
    e.push_back(1);
    boxes.push_back(e);

    e.clear();
    e.push_back(3);
    e.push_back(3);
    boxes.push_back(e);

    e.clear();
    e.push_back(4);
    e.push_back(5);
    boxes.push_back(e);

    e.clear();
    e.push_back(5);
    e.push_back(6);
    boxes.push_back(e);

    e.clear();
    e.push_back(7);
    e.push_back(8);
    boxes.push_back(e);

    cout << solution(boxes) << '\n';
    return 0;
}
