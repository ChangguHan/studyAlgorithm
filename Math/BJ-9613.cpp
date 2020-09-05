#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if(a==0) return b;
    return gcd(b%a, a);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int nums[110];
        for (int i=0; i<n; i++) {
            cin >> nums[i];
        }
        long long int rs=0;

        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                rs += gcd(nums[i], nums[j]);

            }
        }
        cout << rs << '\n';

    }

    // cout << gcd(100,2000) << '\n';

    return 0;
}