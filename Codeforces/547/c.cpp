#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define PI acos(-1.0)
#define eps 1e-12
#define fi first
#define se second
#define MEM(a,b) memset((a),(b),sizeof(a))
#define mod(x) ((x)%MOD)
#define wz cout<<"-----"<<endl;
#define pb push_back
#define mp make_pair

#define vs vector<string> 
#define vi vector<int> 
#define vll vector<ll> 
#define vull vector<ull>
#define vb vector<bool>

#define pii pair<int,int>

#define msi map<string, int>
#define mci map<char, int>
#define mii map<int, int>

#define usi unordered_map<string, int>
#define uci unordered_map<char, int>
#define uii unordered_map<int, int>

const int INF_INT = 2147483647;
const ll INF_LL = 9223372036854775807LL;
const ull INF_ULL = 18446744073709551615Ull;
const ll P = 92540646808111039LL;

const ll maxn = 1e5 + 10, MOD = 1e9 + 7;
const int Move[4][2] = {-1,0,1,0,0,1,0,-1};
const int Move_[8][2] = {-1,-1,-1,0,-1,1,0,-1,0,1,1,-1,1,0,1,1};

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;

}

void init()
{

}
void solve()
{

}
const int MAX_N = 200008;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, tmp;
    cin >> T;
    int n = T - 1;
    vll q;
    q.pb(0);
    while(n--)
    {
        cin >> tmp;
        q.pb(tmp + q.back());
    }
    

    ll minn = INF_LL;
    bool m[MAX_N] = {0};
    for(int i = 0; i < T; i++)
    {
        minn = min(q[i], minn);
    }
    
    ll delta = 1 - minn;

    for(int i = 0; i < T; i++)
    {
       q[i] += delta;
       if(q[i] > T)
       {
           cout << "-1" << '\n';
           return 0;
       }
       else if(m[q[i]] == 1)
       {
           cout << "-1" << '\n';
           return 0;
       }
       m[q[i]] = 1;
    }

    for(auto i : q)
    {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}
