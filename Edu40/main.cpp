#include <bits/stdc++.h>
#define loop(n) for(int i=0;i<n;i++)
#define loopi(s,n) for(int i=s;i<n;i++)
#define pb(x) push_back(x)

using namespace std;
vector <vector <int> > graph;
int n;
int shortst[1000];
typedef pair<int,int> pii;
void shortest(int s) {
    //memset(shortst,10000,n);
    fill(shortst,shortst+n,10000);
    shortst[s] = 0;

    priority_queue<pii, vector<pii>, greater<pii> > pa;
    pa.push({0,s});
    while(!pa.empty()) {
        pii cur = pa.top();
        pa.pop();
        int i = cur.second;

        int d = cur.first;
        if(d > shortst[i])
            continue;
        for(int j=0;j<graph[i].size();j++) {
            if(d+1  < shortst[graph[i][j]])
                {
                    shortst[graph[i][j]] = d+1;
                    pa.push({d+1,graph[i][j]});
                }
        }

    }

}
int main()
{
        int m,s,t;
        cin>>n>>m>>s>>t;
        graph.resize(n);
        loop(m) {
        int a,b;
        cin>>a>>b;
        a--,b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
        }
        shortest(s-1);
        int k = shortst[t-1]+1;
        int sol = n*(n-1)/2 - m;
        sol -=k*(k-1)/2 - (k-1);
        cout<<sol;

      return 0;
}
