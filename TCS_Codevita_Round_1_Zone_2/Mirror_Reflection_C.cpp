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
    string s; cin >> s;
    string p; cin >> p;
    int n = s.size();
    char res[5][3*n];
    for(int i = 0; i < 3*n; i++){
        for(int j = 0; j < 5; j++) res[j][i] = ' ';
    }
    int idx = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            res[1][idx] = res[2][idx] = '|';
            idx++;
        }
        else if(s[i] == '2'){
            if(p[i] == 'S'){
                res[0][idx + 1] = '_';
                res[1][idx + 2] = '|';
                res[1][idx + 1] = '_';
                res[2][idx] = '|';
                res[2][idx + 1] = '_';
            }
            else{
                res[0][idx + 1] = '_';
                res[1][idx + 0] = '|';
                res[1][idx + 1] = '_';
                res[2][idx + 2] = '|';
                res[2][idx + 1] = '_';
            }
            idx += 3;
        }
        else if(s[i] == '3'){
            if(p[i] == 'S' || p[i] == 'D' || p[i] == 'U'){

                res[0][idx] = '_';
                res[1][idx] = '_';
                res[2][idx] = '_';

                res[1][idx + 1] = '|';
                res[2][idx + 1] = '|';
            }
            else{
                res[0][idx + 1] = '_';
                res[1][idx + 1] = '_';
                res[2][idx + 1] = '_';

                res[1][idx] = '|';
                res[2][idx] = '|';
            }
            idx += 2;
        }
        else if(s[i] == '4'){
               /*
                       _
                      |_|
                      |_|


                      |_|
                        |
                        
                       _|
                      | |
                       _
                       _|
                       _|

                       _
                       _|  S,L,R,U,D
                      |_    
            */
            if(p[i] == 'S'){
                res[1][idx] = res[1][idx + 2] = res[2][idx + 2] = '|';
                res[1][idx + 1] = '_';
            }
            else if(p[i] == 'R' || p[i] == 'L'){
                res[1][idx] = res[1][idx + 2] = res[2][idx] = '|';
                res[1][idx + 1] = '_';
            }
            else{
                res[1][idx + 1] = '_';
                res[1][idx + 2] = res[2][idx + 2] = res[2][idx] = '|';
            }
            idx += 3;
        }
        else if(s[i] == '5'){
            /*
                       _
                      |_ 
                       _|
                       _
                       _|
                      |_ 

            */
             if(p[i] != 'S'){
                res[0][idx + 1] = '_';
                res[1][idx + 2] = '|';
                res[1][idx + 1] = '_';
                res[2][idx] = '|';
                res[2][idx + 1] = '_';
            }
            else{
                res[0][idx + 1] = '_';
                res[1][idx + 0] = '|';
                res[1][idx + 1] = '_';
                res[2][idx + 2] = '|';
                res[2][idx + 1] = '_';
            }
            idx += 3;
        }
        else if(s[i] == '6'){
            /*
                       _
                      |_
                      |_|
            */
            if(p[i] == 'S'){
                res[0][idx + 1] = '_';
                res[1][idx] = res[2][idx] = res[2][idx + 2] = '|';
                res[1][idx + 1] = res[2][idx + 1] = '_';
            }
            else if(p[i] == 'L' || p[i] == 'R'){
                res[0][idx + 1] = '_';
                res[1][idx + 2] = res[2][idx] = res[2][idx + 2] = '|';
                res[1][idx + 1] = res[2][idx + 1] = '_';
            }
            else{
                res[1][idx] = res[1][idx + 2] = '|';
                res[2][idx] = '|';
                for(int j = 0; j < 3; j++) res[j][idx + 1] = '_';
            }
            idx += 3;
        }
        else if(s[i] == '7'){
            /*
                       _
                        |
                        |
            */
            if(p[i] == 'S'){
                res[0][idx] = '_';
                res[1][idx + 1] = res[2][idx + 1] = '|';
            }
            else if(p[i] == 'L' || p[i] == 'R'){
                res[0][idx + 1] = '_';
                res[1][idx] = res[2][idx] = '|';
            }
            else{
                res[1][idx + 1] = res[2][idx + 1] = '|';
                res[2][idx] = '_';
            }
            idx += 2;
        }
        else if(s[i] == '8'){
              /*
                       _
                      |_|
                      |_|

            */
            for(int j = 0; j < 3; j++) res[j][idx + 1] = '_';
            res[1][idx] = res[1][idx + 2] = res[2][idx] = res[2][idx + 2] = '|';
            idx += 3;
        }
        else if(s[i] == '9'){
            /*
                       _
                      |_|
                       _|
            */
            if(p[i] == 'S'){
                res[1][idx] = res[1][idx + 2] = '|';
                res[2][idx + 2] = '|';
                for(int j = 0; j < 3; j++) res[j][idx + 1] = '_';
            }
            else if(p[i] == 'L' || p[i] == 'R'){
                res[1][idx] = res[1][idx + 2] = '|';
                res[2][idx] = '|';
                for(int j = 0; j < 3; j++) res[j][idx + 1] = '_';
            }
            else{
                res[0][idx + 1] = '_';
                res[1][idx + 2] = res[2][idx] = res[2][idx + 2] = '|';
                res[1][idx + 1] = res[2][idx + 1] = '_';
            }
            idx += 3;
        }
        else{
            res[0][idx + 1] = res[2][idx + 1] = '_';
            res[1][idx] = res[1][idx + 2] = res[2][idx] = res[2][idx + 2] = '|';
            idx += 3;
        }
    }

    for(int j = 0; j < 5; j++){
        for(int i = 0; i < 3*n; i++) cout << res[j][i];
            cout << endl;
    }
}

signed main()
{
    // pre();
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    int T = 5;
    cout << fixed << setprecision(9);
    // cin >> T; 
    for(int i = 1; i <= T; i++){
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}