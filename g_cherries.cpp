#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Edge{

    public:
    int src;
    int dst;
    int wt;

    Edge(int s, int d, int w){
        src = s;
        dst = d;
        wt = w;
    }
};

class myComparator{

    public:
    int operator()(Edge* e1, Edge* e2){
        return e1->wt > e2->wt;
    }
};


int prims(int n, vector<pair<int, int> > v, int m){

	vector<pair<int, int> > adj[n+1];
	memset(adj, 0, sizeof(adj));

	bool vis[n+1][n+1];
	memset(vis, 0, sizeof(vis));

	// for(int i = 0; i <= n; i++){

	// 	for(int j = 0; j <= n; j++){

	// 		vis[i][j] = 0;
	// 	}
	// }

	for(int i = 0; i < m; i++){

		pair<int, int> p = v[i];
		vis[p.first][p.second] = true;
	}


	for(int i = 1; i <= n; i++){

		for(int j = i+1; j <= n; j++){

			if(!vis[i][j]){
				adj[i].push_back(make_pair(j, 2));
				adj[j].push_back(make_pair(i, 2));
			}else{
				adj[i].push_back(make_pair(j, 1));
				adj[j].push_back(make_pair(i, 1));
			}
		}
	}

	// for(int i = 1; i <= n; i++){


	// 	for(auto x : adj[i]){
	// 		cout<<i<<":"<<x.first<<"-"<<x.second<<endl;
	// 	}
	// }

	priority_queue<Edge *, vector<Edge *>, myComparator > pq;
	vector<bool> visited(n+1, false);

	Edge* min_edge;
	int e = 0, min_sugar = 0, start = 1;
	visited[start] = true;

	do{

		for(auto x : adj[start]){

			int u = start;
			pair<int, int> p = x;
			int v = p.first;
			int w = p.second;

			if(!visited[v])
				pq.push(new Edge(u, v, w));
		}

		min_edge = pq.top();
		pq.pop();

		if(!visited[min_edge->dst]){
			visited[min_edge->dst] = true;
			min_sugar += min_edge->wt;
			start = min_edge->dst;
			e++;
		}
	}while(!pq.empty() && e < n);

	return min_sugar;
}

int main(){

	int t;
	cin>>t;
	int case_no = 1;

	while(t--){

		int n, m;
		cin>>n>>m;
		
		vector<pair<int, int> > v(m);
		for(int i = 0; i < m; i++){

			int x, y;
			cin>>x>>y;
			v.push_back(make_pair(x, y));

		}

		int result = prims(n, v, m);
		cout<<"V :"<<v.size()<<" M:"<<m<<endl;
		//Case #x: y, where x is the test case number (starting from 1) and y is minimum possible sugar content.
		cout<<"Case #"<<case_no<<": "<<result<<endl;
		case_no++;

	}

	return 0;
}