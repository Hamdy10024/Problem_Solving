#include <bits/stdc++.h>
#define loop(k,n) for(int i=k;i<n;i++)
#define pb(x) push_back(x)
using namespace std;

typedef pair<long long ,long long > ii;
int main()
{
    int n,v;
    cin>>n>>v;
    ii poi[n];
    loop(0,n)
    {
        cin>>poi[i].second;
    }

    loop(0,n)
    {
        cin>>poi[i].first;
        poi[i].first-=v;
    }
    sort(poi,poi+n);
    double all = 0,tot=0;
    int i=0;
    while(i < n && poi[i].first <= 0 )
    {
        all+=1.0*poi[i].first*poi[i].second;
        tot+=poi[i].second;
        i++;
    }
    while(i<n && all < 0)
    {
        double facr =1.0*poi[i].first*poi[i].second;
        if(all+facr < 0 )
        {
            tot+=poi[i].second;
            all+=facr;
        }
        else
        {
            double port = -1.0*all/poi[i].first;
            all=0;
            tot+=port;
        }
        i++;
    }
    i=0;
    while (all<0)
    {

        double facr =1.0*poi[i].first*poi[i].second;
        if(all - facr >0)
        {
            double port = all/poi[i].first;
            all=0;
            tot-=port;
        }
        else
        {
            all-=facr;
            tot-=poi[i].second;
        }
        i++;
    }
    printf("%.9f",tot);
    return 0;
}
