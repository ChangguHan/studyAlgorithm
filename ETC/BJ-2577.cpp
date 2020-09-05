#include <iostream>
#include <string>

using namespace std;

int a,b,c;
int nums[10];
int main() {
    cin >> a >> b >> c;
    int rs = a*b*c;
    string rss = to_string(rs);
    for (int i=0; i<rss.size(); i++) {
        nums[rss[i]-'0']++;
    }

    for (int i=0; i<10; i++) {
        cout << nums[i] << '\n';
    }





    return 0;
}