#include<iostream>
using namespace std;
int cont[26];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;

    for(int i=0;i<s.length();i++)
    {
        cont[s[i]-'a']++;
    }
    int maxx=0;
    for(int i=0;i<26;i++)
    {
        maxx=maxx>cont[i]?maxx:cont[i];
    }
    cout<<maxx<<'\n';
}
