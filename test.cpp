#include<iostream>
#include<vector>
#include<queue>
#include <climits> 

using namespace std;

const long int MAX = 1000001; 


long int factor[MAX] = { 1 }; 
  

void generatePrimeFactors() 
{ 
    factor[1] = 1; 
  
    for (long int i = 2; i < MAX; i++) 
        factor[i] = i; 
  
    for (long int i = 4; i < MAX; i += 2) 
        factor[i] = 2; 
  
 
    for (long int i = 3; i * i < MAX; i++) { 
        if (factor[i] == i) { 
            for (long int j = i * i; j < MAX; j += i) { 
              
                if (factor[j] == j) 
                    factor[j] = i; 
            } 
        } 
    } 
} 

long int findAllfactors(long int n) 
{ 
    if (n == 1) 
        return 1; 
  
    long int ans = 1; 
  

    long int dup = factor[n]; 
  
    
    long int c = 1; 
 
    long int j = n / factor[n]; 
  
    while (j != 1) { 
        
        if (factor[j] == dup) 
            c += 1; 
  
       
        else { 
            dup = factor[j]; 
            ans = ans * (c + 1); 
            c = 1; 
        } 
  
        j = j / factor[j]; 
    } 
  
    ans = ans * (c + 1); 
  
    return ans; 
} 


bool bfs(vector<vector<long int> > &graph, long int src,  
                                 long int dst, long int n, long int pred[], long int dist[]) 
{ 
    // create a queue which stores 
    // the paths 
    // vector<long int> path;
    vector<bool> visited(n+1, false);
    queue<long int> q;
    long int s;
    // path.push_back(src);
    for (long int i = 0; i <= n; i++) { 
        // visited[i] = false; 
        dist[i] = INT_MAX; 
        pred[i] = -1; 
    } 

    // if(src == dst){
    //   return true;
    // }

    q.push(src);
    visited[src] = true;

    while(!q.empty()){

    	s = q.front();
    	q.pop();
    	// cout<<s<<endl;
    	// if(s == dst){
    	// 	return path;
    	// }


   	for(auto x : graph[s]){
   		// cout<<"X : "<<x<<endl;
   		if(!visited[x]){
   			visited[x] = true;
   			dist[x] = dist[s]+1;
   			pred[x] = s;
   			q.push(x);
   			if(x == dst)
   				return true;
   			// visited[x] = true;
   		}

   		// }else if(!visited[x] && x == dst){
   		// 	path.push_back(x);
   		// 	return path;
   		}
   	}
   	return false;
}


vector<long int> shortestPath(vector<vector<long int>> graph, long int src, long int dst, long int v){

	long int pred[v+1], dist[v+1];

  if(src == dst){
    vector<long int> tmp;
    tmp.push_back(src);
    return tmp;
  }

	if(bfs(graph, src, dst, v, pred, dist) == false){
		return vector<long int>();
	}

	vector<long int> path;
	long int walk = dst;
	path.push_back(walk);
	while(pred[walk] != -1){
		path.push_back(pred[walk]);
		walk = pred[walk];
	}

	return path;
}
  

int main(){

	long int t;
	cin>>t;
	generatePrimeFactors();
	while(t--){

		long int n;
		cin>>n;

		vector<vector<long int> >graph(n+1);
		// vector<long int> result;
		// vector<pair<long int, long int> > adj[n];
		// graph.resize(n+1);
		long int x, y;
		for(long int i = 0; i < n-1; i++){
			cin>>x>>y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		long int wt;
		long int weights[n] = {0};
		for(long int i = 0; i < n; i++){
			cin>>wt;
			// create_graph(adj, v, wt);
			weights[i] = wt;
		}

		// cout<<"N :" <<n<<" V.size :" <<v.size()<<endl;
		// for(auto x : v){

		// 	cout<<"First->"<<x.first<<" Second->"<<x.second<<endl; 
		// }

	
		// cout<<"Input number of Queries:"<<endl;
		long int query;
		cin>>query;
		while(query--){

      vector<long int> result;
			long int u, v, product = 1, factors = 0;
			cin>>u>>v;

		// 	vecor<vector<long int> > paths = findAllPaths(u, v, graph)
		// }
			// cout<<"U :"<<u<<" V :"<<v<<endl;
			result = shortestPath(graph,u, v, n);
			// for(auto x : result){
			// 	cout<<"Path :"<<x<<"->";
			// }
			// cout<<endl;

			// cout<<"Path Prlong inting"<<endl;
			// cout<<"Result :"<<result.size()<<endl;
			for(long int i = 0; i < result.size(); i++){
					product = product*weights[result[i]-1];
					// cout<<"WEights ->"<<weights[result[i]-1]<<endl;
				
			}
			// cout<<"Product = "<<product<<endl;
			factors = findAllfactors(product);
			// cout<<"Found factors"<<endl;

			cout<<factors%1000000007<<endl;
      result.clear();
		} 
		// 	cout<<endl;
		// }

	}
  return 0;
}