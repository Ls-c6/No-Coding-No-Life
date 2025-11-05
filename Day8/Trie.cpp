#include <string>
#include <vector>
#include <iostream>
using namespace std;
int node=0;
vector<int> ck(50*1e4+50,0);
vector<vector<int>> trie(50*1e4+50,vector<int>(26,0));

void insert(string &s)
{
    int now=0;
    for (int i=0;i<s.size();++i)
    {
        if (trie[now][s[i]-'a']==0)
        {
            trie[now][s[i]-'a']=++node;
            now=node;
        }
        else now=trie[now][s[i]-'a'];
    }
    ++ck[now];
    return;
}


int find(string &s)
{
    int now=0;
    for (int i=0;i<s.size();++i)
    {
        if (trie[now][s[i]-'a']==0) return 0;
        now=trie[now][s[i]-'a'];
    }
    if (!ck[now]) return 0;
    return ck[now]++;
}


int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n;
    vector<string> name(n);
    for (int i=0;i<n;++i) cin>>name[i];
    for (string &s:name) insert(s);
    cin>>m;
    string s;
    for (int i=0;i<m;++i)
    {
        cin>>s;
        int flag=find(s);
        if (!flag) cout<<"WRONG\n";
        else if (flag==1) cout<<"OK\n";
        else cout<<"REPEAT\n";
    }
    return 0;
}

