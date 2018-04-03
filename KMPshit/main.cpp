#include <bits/stdc++.h>

using namespace std;
void create_lps(string &str,int lps[]) {
lps[0] = 0;
int l=0;
int i=1;
while(i<str.size())
    if(str[i] == str[l])
        lps[i++]=++l;
    else if (l == 0)
        lps[i++]= 0;
    else
       (l = lps[l-1]);

}
int nc(string &str1,string &str2,int lps[]) {
    int i=0,j=0;
    int c = 0;
    if(str2.size() > str1.size())
        return 0;
    for(i=0;i<str1.size();) {
        if(str1[i] == str2[j]) {
            i++;
            j++;
            if(j == str2.size()) {
              c++;
              j=0;
            }
        }
        else {
            if(j==0) {
                i++;

            }
            else {
                j = lps[j-1];
            }
        }
    }
return c;
}
int main()
{
    string a,b;
    cin >>a>>b;
    int lps[b.size()];

    create_lps(b,lps);

    cout<<nc(a,b,lps);
    return 0;
}
