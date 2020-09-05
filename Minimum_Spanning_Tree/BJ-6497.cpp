// 처음에 총 합 구해주고, 최소스패닝 값 빼줌

#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

tuple<int, int, int> edge[200010];
int p[200010];

int find(int v ) {
    if(p[v]<0) return v;
    return p[v] = find(p[v]);
}

bool is_diff_group(int v1, int v2) {
    v1 = find(v1); v2 = find(v2);
    if(v1==v2) return 0;
    if(p[v1] == p[v2]) p[v1]--;
    if(p[v1] < p[v2]) p[v2] = v1;
    else p[v1] = v2;
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        int m,n;
        cin >> m >> n;
        if(m==0 && n==0) break;
        int sum=0;
        fill(p,p+m,-1);
        for (int i=0; i<n; i++) {
            int a,b,c;
            cin >> a >> b >> c;
            edge[i] = tie(c,a,b);
            sum+=c;
        }
        sort(edge, edge+n);

        int ans=0;
        int cnt=0;
        for (int i=0; i<n; i++) {
            int c,v1,v2;
            tie(c,v1,v2) = edge[i];
            if(!is_diff_group(v1,v2)) continue;
            cnt++;
            ans +=c;
            if(cnt==m-1) break;
        }

        cout << sum-ans << '\n';
        


    }
    return 0;
}