#include <bits/stdc++.h>

using namespace std;

    int mats[4][100][100];
int validate(bool bas,int k,int n)
{
    int s = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            s+=(((i+j)%2)^(mats[k][i][j] == bas));
        }
    return s;
}
int main()
{
    int n;
    cin>>n;
    pair<int,int> st[4];
    for(int i=0; i<4; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<n; k++){
             char s;
             cin>>s;
             mats[i][j][k] = (s=='1');
            }
    int allsecs=0;
    for(int i=0; i<4; i++)
    {
        st[i].first = validate(0,i,n);
        st[i].second = validate(1,i,n);
        allsecs+=st[i].second;
    }
    int ms = 4*100*100;
      for(int i=0; i<4; i++)
        for(int j=i+1; j<4; j++)
        {
            int tot = st[i].first + st[j].first + allsecs - st[i].second - st[j].second;
            ms = min(ms,tot);

        }
        cout<<ms;
    return 0;
}
