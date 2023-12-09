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
    int n = s.size();
    int l = 0 , r = 0;
    for(int i = 0; i < n; i++) l += s[i] == '1' , r += s[i] == '0';
    if(l + r != n){
        cout << "INVALID\n";
        return;
    }
    string x = s;
    string y = s;
    sort(x.begin(), x.end());
    sort(y.rbegin(), y.rend());
    // cout << s << endl << x << endl;
    int res = 0, pro = 0;
    if(a > b){
        res = INT_MAX;
    }
    if(b > a){
        pro = INT_MAX;
    }
    for(int i = 0; i < n; i++){
        res += x[i] != s[i];
        pro += y[i] != s[i];
    }
    cout << min(res, pro) << endl;
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