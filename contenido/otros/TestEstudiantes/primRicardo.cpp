#include <bits/stdc++.h>
#include <string.h>
#define rep(x, y, z) for (long long x = y; x < z; x++)
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define pb push_back
#define mk make_pair
#define ll long long
#define INF 1000000000

using namespace std;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<ii> vii;
const int mod = 1000000007;
vector<vii> g;
bool mst[100000];
int padres[100000];
int currentValue[100000];
priority_queue< ii, vector<ii>, greater<ii> > keys;

void init(int n)
{
    keys.push(ii(0,0));
    rep(i,0,n)
    {
        currentValue[i]=INF;
        padres[i]=i;
        mst[i]=false;
    }
    currentValue[0]=0;
}

void prim()
{
    if(keys.empty())
    return;
    ii fkey=keys.top();
    keys.pop();
    int node=fkey.second;
    cout<<"Estoy en el nodo "<<node<<endl;
    rep(i,0,g[node].size())
    {
        ii next=g[node][i];
        if(!mst[next.first] && next.second<currentValue[next.first])
        {
            cout<<"Estoy metiendo a la cola el par "<<next.second<<" "<<next.first<<endl;
            keys.push(ii(next.second, next.first));
            padres[next.first]=node;
            currentValue[next.first]=next.second;
        }
    }
    mst[node]=true;
    prim();
}

int main()
{
    int n,m,x,y,z;
    cin>>n>>m;
    init(n);
    g.assign(n+1, vii());
    rep(i,0,m)
    {
        cin>>x>>y>>z;
        g[x].pb(ii(y,z));
        g[y].pb(ii(x,z));
    }
    prim();
    int total=0;
    rep(i,0,n)
    {
        cout<<"Soy "<<i<<" y mi padre es "<<padres[i]<<endl;
        total+=currentValue[i];
    }
    cout<<total<<endl;
}