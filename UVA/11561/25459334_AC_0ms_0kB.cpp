#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (1e9 + 5)
#define MOD (int)(1e9 + 7)
#define n_l '\n'
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: "; cerr << to_string(__VA_ARGS__) << endl
template <typename T, size_t N> int SIZE(const T (&t)[N]){ return N; } template<typename T> int SIZE(const T &t){ return t.size(); } string to_string(const string s, int x1=0, int x2=1e9){ return '"' + ((x1 < (int)s.size()) ? s.substr(x1, x2-x1+1) : "") + '"'; } string to_string(const char* s) { return to_string((string) s); } string to_string(const bool b) { return (b ? "true" : "false"); } string to_string(const char c){ return string({c}); } template<size_t N> string to_string(const bitset<N> &b, int x1=0, int x2=1e9){ string t = ""; for(int __iii__ = min(x1,SIZE(b)),  __jjj__ = min(x2, SIZE(b)-1); __iii__ <= __jjj__; ++__iii__){ t += b[__iii__] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(const A (&v), int x1=0, int x2=1e9, C... coords); int l_v_l_v_l = 0, t_a_b_s = 0; template <typename A, typename B> string to_string(const pair<A, B> &p) { l_v_l_v_l++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; l_v_l_v_l--; return res; } template <typename A, typename... C> string to_string(const A (&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(t_a_b_s, ' '); string res = ""; bool first = true; if(l_v_l_v_l == 0) res += n_l; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2-x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; l_v_l_v_l++; if(e != l){ if(rnk > 1) { res += n_l; t_a_b_s = l_v_l_v_l; }; } else{ t_a_b_s = 0; } res += to_string(*e, coords...); l_v_l_v_l--; } res += "]"; if(l_v_l_v_l == 0) res += n_l; return res; } void dbgm(){;} template<typename Heads, typename... Tails> void dbgm(Heads H, Tails... T){ cerr << to_string(H) << " | "; dbgm(T...); }
#define dbgm(...) cerr << "[" << #__VA_ARGS__ << "]: "; dbgm(__VA_ARGS__); cerr << endl
#define run(a, b) cerr << fixed << setprecision(6) << (double) (b - a) / (double) (CLOCKS_PER_SEC) << " s" << endl;

vector<vector<bool>> vis;
vector<vector<char>> mapp;
int m, n;

int ans = 0;

bool cekW(int a, int b) {
    if(mapp[a][b] == '#') {
        return true;
    }
    return false;
}

bool cekG(int a, int b) {
    if(mapp[a][b] == 'G') {
        return true;
    }
    return false;
}

bool cekT(int a, int b) {
    if(a + 1 < m) {
        if(mapp[a+1][b] == 'T') {
            return true;
        }
    }
    if(a - 1 >= 0) {
        if(mapp[a-1][b] == 'T') {
            return true;
        }
    }
    if(b + 1 < n) {
        if(mapp[a][b+1] == 'T') {
            return true;
        }
    }
    if(b - 1 >= 0) {
        if(mapp[a][b-1] == 'T') {
            return true;
        }
    }
    return false;
}

void go(int i, int j) {
    vis[i][j] = true;
    if(cekW(i, j) == true) {
        return;
    }
    if(cekG(i, j) == true) {
        ans++;
        // cout << "h" << endl;
    }
    if(cekT(i, j) == true) {
        return;
    }
    // cout << i << " " << j << endl;
    if(i+1 < m) {
        if(vis[i+1][j] == false)
            go(i+1, j);
    }
    if(i-1 >= 0) {
        if(vis[i-1][j] == false)
            go(i-1, j);
    }
    if(j+1 < n) {
        if(vis[i][j+1] == false)
            go(i, j+1);
    }
    if(j-1 >= 0) {
        if(vis[i][j-1] == false)
            go(i, j-1);
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> n >> m) {
        ans = 0;
        mapp.assign(m, vector<char>(n));
        vis.assign(m, vector<bool>(n, false));
        pair<int, int> startLoc;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                cin >> mapp[i][j];
                if(mapp[i][j] == 'P') {
                    startLoc.first = i;
                    startLoc.second = j;
                }
            }
        }
        // for(int i = 0; i < m; i++) {
        //     for(int j = 0; j < n; j++) {
        //         cout << mapp[i][j];
        //     }
        //     cout << '\n';
        // }
        go(startLoc.first, startLoc.second);
        cout << ans << '\n';
    }
    return 0;
}