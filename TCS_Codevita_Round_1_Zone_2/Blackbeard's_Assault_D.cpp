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
    int n,m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m , 0));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> a[i][j];
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << a[i][j] << 
    //         ' ';
    //     }
    //     cout << endl;
    // }
    int dx[] = {0,0,1,-1};  
    int dy[] = {-1,1,0,0};

    int x,y; cin >> x >> y;


    int k; cin >> k;

    // cout << a[1][0] << endl;


    vector<vector<bool>> reach(n, vector<bool> (m , false));


    auto valid = [&](int x, int y) -> bool{
        return x >= 0 && x < n && y >= 0 && y < m && reach[x][y] == 0 && a[x][y] <= k;
    };


    auto ok = [&](int x, int y) -> bool{
        return x >= 0 && x < n && y >= 0 && y < m;
    };



    queue<pair<int,int>> q;
    if(a[x][y] == 0){
        q.push({x,y});
        reach[x][y] = 1;
    }

    while(q.size()){
        // auto [l , r] = q.front(); 
        int l = q.front().first;
        int r = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = l + dx[i], ny = r + dy[i];
            if(valid(nx, ny)){
                // cout << "marking " << nx << ' ' << ny << endl;
                q.push({nx,ny});
                reach[nx][ny] = 1;
            }
        }
    }


    int ans = 0;


    function<void(int,int,int)> f = [&](int ind, int jin, int val) -> void{
        a[ind][jin] = 0;
         for(int i = 0; i < 4; i++){
            int nx = ind + dx[i], ny = jin + dy[i];
            if(ok(nx, ny) && a[nx][ny] == val){
                f(nx,ny,val);
            }
        }
    };

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(reach[i][j] && a[i][j] != 0){
                ans++;
                f(i, j, a[i][j]);
            }
        }
    }
    // cout << ans << endl;

    if(ans > 0) cout << ans << endl;
    else cout << "NONE\n";
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