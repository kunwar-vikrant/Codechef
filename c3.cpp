#include <iostream>
#include <bits/stdc++.h> 
#include <cmath>
#include <math.h> 

using namespace std; 


double distance(pair<int, int> p1, pair<int, int> p2){

	return sqrt(pow((p2.first - p1.first), 2) + pow((p2.second - p1.second), 2));
}


double distance_from_a(pair<int, int> coord, vector<pair<int, int> > a, vector<pair<int, int> > b, vector<pair<int, int> > c, int n, int m, int k){

	double a_to_b = INT_MAX, b_to_c = INT_MAX;
	double tmp = 0;
	double result = 0.0;

	pair<int, int> p, p2;

	for(int i = 0; i < m; i++){

		tmp = distance(b[i], coord);
		if(tmp < a_to_b){
			a_to_b = tmp;
			p = b[i];
		}
	}

	for(int i = 0; i < k; i++){

		tmp = distance(c[i], p);
		if(tmp < b_to_c){
			b_to_c = tmp;
			p2 = c[i];
		}
	}

	result = a_to_b + b_to_c;
	return result;

}

double distance_from_b(pair<int, int> coord, vector<pair<int, int> > a, vector<pair<int, int> > b, vector<pair<int, int> > c, int n, int m, int k){

	double b_to_a = INT_MAX, a_to_c = INT_MAX;
	double tmp = 0;
	double result = 0.0;

	pair<int, int> p, p2;

	for(int i = 0; i < n; i++){

		tmp = distance(a[i], coord);
		if(tmp < b_to_a){
			b_to_a = tmp;
			p = a[i];
		}
	}

	for(int i = 0; i < k; i++){

		tmp = distance(c[i], p);
		if(tmp < a_to_c){
			a_to_c = tmp;
			p2 = c[i];
		}
	}

	result = b_to_a + a_to_c;
	return result;

}

int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--){

    	int x_coord, y_coord;
    	cin>>x_coord>>y_coord;

    	int n,m,k;
    	cin>>n>>m>>k;

    	vector<pair<int, int> > a;
    	vector<pair<int, int> > b;
    	vector<pair<int, int> > c;
    	int x,y;

    	for(int i = 0; i < n; i++){
    		cin>>x;
    		cin>>y;
    		a.push_back(make_pair(x,y));
    	}


    	for(int i = 0; i < m; i++){
    		cin>>x;
    		cin>>y;
    		b.push_back(make_pair(x,y));
    	}


    	for(int i = 0; i < k; i++){
    		cin>>x;
    		cin>>y;
    		c.push_back(make_pair(x,y));
    	}



    	double frm_coord_a = INT_MAX, frm_coord_b = INT_MAX, tmp = 0.0;
    	pair<int, int> orig = make_pair(x_coord, y_coord);
    	pair<int, int> a_coord, b_coord;

    	for(int i = 0; i < n; i++){

    		tmp = distance(a[i], orig);
    		if(tmp < frm_coord_a){
    			frm_coord_a = tmp;
    			a_coord = make_pair(a[i].first, a[i].second);
    		}

    	}

    	for(int i = 0; i < m; i++){

    		tmp = distance(b[i], orig);
    		if(tmp < frm_coord_b){
    			frm_coord_b = tmp;
    			b_coord = make_pair(b[i].first, b[i].second);
    		}

    	}

    	pair<int, int> new_coord;
    	double dis = 0.0;
    	bool vis_a = false, vis_b = false;

    	if(frm_coord_a < frm_coord_b){
    		vis_a = true;
    		new_coord = a_coord;
    		dis = frm_coord_a;
    	}else{
    		new_coord = b_coord;
    		dis = frm_coord_b;
    		vis_b = true;
    	}

    	double r = dis;
    	double temp = 0.0;

    	if(vis_a){
    		temp = distance_from_a(new_coord, a, b, c, n,m, k);
    	}else{
    		temp = distance_from_b(new_coord, a, b, c, n, m, k);
    	}

    	r += temp;
    	printf("%.9f",r);
    	
    }
}