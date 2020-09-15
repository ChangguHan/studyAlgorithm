#include <iostream>
#include <tuple>
using namespace std;

int main() {
    tuple<int, int, int> a;
    a = {2,4,3};
    cout << 1 << '\n';
    cout << 1 << '\n';
    int c,d,e; tie(c,d,e) = a;
    pair<int, int> z(7,2);
    cout << z.first << '\n';

    return 0;
}