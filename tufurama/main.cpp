#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int seg[800000],epis[200000];
int n;
void add(int i,int s,int v,int l,int r) {
    if(s>=l && s<=r) {
        seg[i]+=v;
    }
    else
        return;
    if(l>=r)
        return;
    int m = l+r;
    m/=2;
    add(i+i+1,s,v,l,m);
    add(i+i+2,s,v,m+1,r);
}
int get_seg(int i,int a,int b,int l ,int r) {
    a = max(a,l);
    b = min(b,r);
    if(a>b)
        return 0;
    if(a==l && b == r)
        return seg[i];
    int m = l+r;
    m/=2;
    return get_seg(i+i+1,a,b,l,m) + get_seg(i+i+2,a,b,m+1,r);
}

int main()
{
    cin>>n;
    long long  total = 0;
    priority_queue <pii , vector <pii> ,greater <pii> > pq;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        x = min(x,n);
        x--;
        total += get_seg(0,0,x,0,n-1);
        if(x > i) {
            pq.push({x,i});
            add(0,i,1,0,n-1);
        }
        while(!pq.empty() && pq.top().first == i) {
            pii t = pq.top();
            pq.pop();
            add(0,t.second,-1,0,n-1);
        }

    }
    cout <<total;
    return 0;
}
