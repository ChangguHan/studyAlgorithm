#include <iostream>

// 세그먼트리로
// 제일 작은거 빼고 그 양쪽을 구하는걸로

#include <vector>
#include <cmath>
using namespace std;

// 최대 1e9, int 가능
vector<int> tree;
int nums[100010];

int solution(vector<int> histogram)
{
    int st=0, en=1;
    int sum = 0, rs = histogram.size();
    while(1) {
        bool sw=false; 
        int wid = en - st - 1;
        if (histogram[st][en] * wid < histogram[st][en + 1] * (en - st)){
            en++;
            sw=1;
        }
        else if(histogram[st][en]*wid < historgram[st+1][en]*(en-st-2)){
            st++;
            sw=
        }
        
    }
    int N = histogram.size();
    int h = ceil(log2(N));
    tree.resize(1<<(h+1));
    for(int i=0; i<histogram.size(); i++){
        nums[i] = histogram[i];
    }
    // 세그먼트리 생성, 가장 작은것 인덱스 반환
    maket(1,0,N-1);


    
    return getMaxV(1,0,N-1,0,N-1);
}
int main() {
    vector<int> histogram;

    histogram.push_back(2);
    histogram.push_back(2);
    histogram.push_back(2);
    histogram.push_back(3);

    // histogram.push_back(6);
    // histogram.push_back(5);
    // histogram.push_back(7);
    // histogram.push_back(3);
    // histogram.push_back(4);
    // histogram.push_back(2);

    cout << solution(histogram) << '\n';
    return 0;
}