#include <bits/stdc++.h>

using namespace std;
typedef pair<long long,long long> point;
int gcd(int a,int b) {
    if(!b)
        return a;
    return gcd(b,a%b);
}
point get_slope(point a,point b) {
        int x = a.first-b.first;
        int y = a.second - b.second;
        int gc = gcd(x,y);
        x/=gc;
        y/=gc;
        if(y<0) {
            x*=-1;
            y*=-1;
        }
        return point(x,y);

}
point xy[100000];
int main()
{
    int n;
    cin >>n;
    for(int i=0;i<n;i++) {
        cin>>xy[i].first >> xy[i].second;
    }
    map<point,int> slopes;
    int clines = 0;
    point cslope;
    for(int i=1;i<n;i++) {
        point nslope = get_slope(xy[0],xy[i]);
        if(!slopes.count(nslope)) {
            slopes[nslope] = 1;
            continue;
        }
        if(slopes[nslope]==1)
            clines++;
        slopes[nslope]++;
        cslope = nslope;
    }
    if(slopes.size() < 3) {
        cout<<"YES";
        return 0;
    }
    if(clines > 1) {
        cout<<"NO";
        return 0;
    }

    slopes.clear();
    point base;
    for(int i=1;i<n ;i++) {
        point nslope = get_slope(xy[0],xy[i]);
      if(nslope == cslope)
        continue;
     base = xy[i];
     break;
    }
    point sslope = {0,0};
    bool other = 0;
    for(int i=1;i<n  && !other;i++) {
         point nslope = get_slope(xy[0],xy[i]);
      if(nslope == cslope || xy[i] == base)
        continue;

      if(sslope == point(0,0)) {
        sslope = get_slope(base,xy[i]);
      }
      else {
        other = (get_slope(base,xy[i]) != sslope);
      }
    }
    cout<<((other)?"NO":"YES");
    return 0;
}
/*
5
3 3
6 3
0 0
10 0
-10 0
*/
