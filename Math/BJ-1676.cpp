#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int rs=0;
    rs += N/125;
    rs += N/25;
    rs += N/5;

    cout << rs << '\n';

    return 0;
}