#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include <climits> 

using namespace std;

const int MAX = 1000001; 

// void create_graph(vector<pair<int, int>> adj[], vector<pair<int, int>> v, int wt){

// 	int n = v.size();
// 	for(int i = 0; i < n; i++){
// 		adj[v[i].first].push_back(make_pair(v[i].second, wt));
// 		// adj[v[i].first].push_back(wt);
// 	}
// }
// array to store prime factors 
int factor[MAX] = { 0 }; 
  
// function to generate all prime factors 
// of numbers from 1 to 10^6 
void generatePrimeFactors() 
{ 
    factor[1] = 1; 
  
    // Initializes all the positions with their value. 
    for (int i = 2; i < MAX; i++) 
        factor[i] = i; 
  
    // Initializes all multiples of 2 with 2 
    for (int i = 4; i < MAX; i += 2) 
        factor[i] = 2; 
  
    // A modified version of Sieve of Eratosthenes to 
    // store the smallest prime factor that divides 
    // every number. 
    for (int i = 3; i * i < MAX; i++) { 
        // check if it has no prime factor. 
        if (factor[i] == i) { 
            // Initializes of j starting from i*i 
            for (int j = i * i; j < MAX; j += i) { 
                // if it has no prime factor before, then 
                // stores the smallest prime divisor 
                if (factor[j] == j) 
                    factor[j] = i; 
            } 
        } 
    } 
} 

int findAllfactors(int n) 
{ 
    if (n == 1) 
        return 1; 
  
    int ans = 1; 
  
    // stores the smallest prime number 
    // that divides n 
    int dup = factor[n]; 
  
    // stores the count of number of times 
    // a prime number divides n. 
    int c = 1; 
  
    // reduces to the next number after prime 
    // factorization of n 
    int j = n / factor[n]; 
  
    // false when prime factorization is done 
    while (j != 1) { 
        // if the same prime number is dividing n, 
        // then we increase the count 
        if (factor[j] == dup) 
            c += 1; 
  
        /* if its a new prime factor that is factorizing n,  
           then we again set c=1 and change dup to the new  
           prime factor, and apply the formula explained  
           above. */
        else { 
            dup = factor[j]; 
            ans = ans * (c + 1); 
            c = 1; 
        } 
  
        // prime factorizes a number 
        j = j / factor[j]; 
    } 
  
    // for the last prime factor 
    ans = ans * (c + 1); 
  
    return ans; 
} 


bool bfs(vector<vector<int> > &graph, int src,  
                                 int dst, int n, int pred[], int dist[]) 
{ 
    // create a queue which stores 
    // the paths 
    // vector<int> path;
    vector<bool> visited(n+1, false);
    queue<int> q;
    int s;
    // path.push_back(src);
    for (int i = 0; i <= n; i++) { 
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


vector<int> shortestPath(vector<vector<int>> graph, int src, int dst, int v){

	int pred[v+1], dist[v+1];

  if(src == dst){
    vector<int> tmp;
    tmp.push_back(src);
    return tmp;
  }

	if(bfs(graph, src, dst, v, pred, dist) == false){
		return vector<int>();
	}

	vector<int> path;
	int walk = dst;
	path.push_back(walk);
	while(pred[walk] != -1){
		path.push_back(pred[walk]);
		walk = pred[walk];
	}

	return path;
}
  

int main(){

	int t;
	cin>>t;
	generatePrimeFactors();
	while(t--){

		int n;
		cin>>n;

		vector<vector<int> >graph;
		// vector<int> result;
		// vector<pair<int, int> > adj[n];
		graph.resize(n+1);
		int x, y;
		for(int i = 0; i < n-1; i++){
			cin>>x>>y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		int wt;
		int weights[n];
		for(int i = 0; i < n; i++){
			cin>>wt;
			// create_graph(adj, v, wt);
			weights[i] = wt;
		}

		// cout<<"N :" <<n<<" V.size :" <<v.size()<<endl;
		// for(auto x : v){

		// 	cout<<"First->"<<x.first<<" Second->"<<x.second<<endl; 
		// }

	
		// cout<<"Input number of Queries:"<<endl;
		int query;
		cin>>query;
		while(query--){

      vector<int> result;
			int u, v, product = 1, factors = 0;
			cin>>u>>v;

		// 	vecor<vector<int> > paths = findAllPaths(u, v, graph)
		// }
			// cout<<"U :"<<u<<" V :"<<v<<endl;
			result = shortestPath(graph,u, v, n);
			// for(auto x : result){
			// 	cout<<"Path :"<<x<<"->";
			// }
			// cout<<endl;

			// cout<<"Path Printing"<<endl;
			// cout<<"Result :"<<result.size()<<endl;
			for(int i = 0; i < result.size(); i++){
					product = product*weights[result[i]-1];
					// cout<<result[i]<<" ";
				
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
}