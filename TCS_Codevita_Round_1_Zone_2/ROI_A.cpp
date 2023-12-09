/*
    ok.
    solve questions.
*/
#include "bits/stdc++.h"
using namespace std;
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
#define int long long int
 
// const int mod = (1LL << 32LL);
const int mod = 1e9 + 7;    
// const int mod = 998244353;
 
/*
    5 1
    0 0 1 1 0
    0 0 1 2 0 
    2 2 2 1 0 
    9 3
    0 1 0 1 1 1 0 0 1

    0 1 1 2 3 4 4 4 5
    5 5 4 4 3 2 1 1 1
    
     int ans = *std::ranges::partition_point(std::ranges::iota_view(0, int(1E9) + 1),
        [&](int k) {
            int L = 0, R = 0;
            for (int i = 0; i < n; i++) {
                L -= k;
                R += k;
                L = std::max(L, l[i]);
                R = std::min(R, r[i]);
                if (L > R) {
                    return true;
                }
            }
            return false;
        });
    std::cout << ans << "\n";

*/

void solve() {
    int n; cin >> n;
    vector<array<int,3>> a(n);
    for(auto &i : a) {
        cin >> i[0] >> i[1] >> i[2];
        // cin >> x >> y >> z;
    }
    int m; cin >> m;
    int p[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> p[i][j];
    }
    int time; cin >> time;
    time--;
    // sort(a.begin(), a.end(), [&](auto l, auto r) -> bool{
    //     if()
    // });
    int l = 0 , r = 0;
    for(int i = 0; i < n; i++){
        // auto [k, buy, sell] = a[i];
        int k = a[i][0];
        int buy = a[i][1];
        int sell = a[i][2];
        buy--;
        sell--;
        if(buy > time) continue;
        if(sell == -1 || sell > time){
            r += k * (p[i][time] - p[i][buy]);
        }
        else{
            l += k * (p[i][sell] - p[i][buy]);
        }
    }
    cout << l << endl << r << endl;
}

signed main()
{
    // pre();
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    int T = 1;
    cout << fixed << setprecision(9);
    // cin >> T; 
    for(int i = 1; i <= T; i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}