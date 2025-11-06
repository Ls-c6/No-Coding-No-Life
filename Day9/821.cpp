    #include <queue>
    #include <vector>
    #include <stdio.h>
    #include <algorithm>
    #include <unordered_set>
    using namespace std;
    int a,b,n,mx,k=0;
    vector<int> vis;
    vector<vector<int>> Map(101);

    int bfs(int st,int ed)
    {
        vis.assign(mx+1,1);
        vis[st]=0;
        queue<pair<int,int>> q;
        q.push({st,0});
        while (!q.empty())
        {
            auto [c,cnt]=q.front();
            q.pop();
            if (c==ed) return cnt;
            for (int &i:Map[c]) if (vis[i]-->0) q.push({i,cnt+1});
        }
        return 0;
    }

    int main()
    {
        while (scanf("%d%d",&a,&b)!=EOF)
        {
            n=0,mx=-1;
            double sum=0;
            unordered_set<int> s;
            if (!a && !b) break;
            s.insert(a);
            s.insert(b);
            mx=max({mx,a,b});
            Map[a].push_back(b);
            while (scanf("%d%d",&a,&b)!=EOF)
            {
                if (!a && !b) break;
                s.insert(a);
                s.insert(b);
                mx=max({mx,a,b});
                Map[a].push_back(b);
            }
            n=s.size();
            for (auto i=s.cbegin();i!=s.cend();++i) for (auto j=s.cbegin();j!=s.cend();++j) if (*i!=*j) sum+=bfs(*i,*j);
            printf("Case %d: average length between pages = %.3f clicks\n",++k,sum/(n*(n-1)));
            Map.assign(101,{});
        }
        return 0;
    }
