#include <iostream>
using namespace std;

int solution(int A, int B) {
    int cnt=0;
    int rs = A*B;
    while(rs!=0) {
        if(rs % 2 == 1) cnt++;
        rs = rs/2;
    }

    return cnt;
}
int main() {
    cout <<solution(3,7);
    return 0;
}