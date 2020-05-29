#include<bits/stdc++.h>

using namespace std;

const int MAX_NODES = 315;

struct Node
{
	int val;
	vector<Node *> neighbours;
	Node(int _val = 0)
	{
		val = _val;
		neighbours.clear();
	}
};

/*
 * Complete the function below.
 */

/*
    For your reference:

    struct Node
    {
    	int val;
    	vector<Node *> neighbours;
    	Node(int _val = 0)
    	{
    		val = _val;
    		neighbours.clear();
    	}
    };
*/
int visited[315];
void dfs(Node *node,Node *parent)
{
    // set visited of this node
    visited[node->val]=1;
    for(int i=0;i<node->neighbors.size();i++) {
        //delete the neighbor from me and add the parent to neighborlist and call
            Node *ithneighbor = node->neighbors[i];
            
            dfs(node->neighbors[i],node);
    }
}

Node *build_other_graph(Node *node)
{
    for(int i = 0; i< 315;i++)
    {
        visited[i] = -1;
    }
        
    dfs(node,NULL);
}

void helper_dfs(Node *reversed_node, unordered_map<int, Node *> &reversed)
{
	reversed[reversed_node->val] = reversed_node;
	int n = reversed_node->neighbours.size();
	for (int i = 0; i < n; i++)
	{
		if (reversed.find(reversed_node->neighbours[i]->val) == reversed.end())
		{
			helper_dfs(reversed_node->neighbours[i], reversed);
		}
	}
}

unordered_map<int, Node *> helper_get_all_addresses_in_reversed_graph(Node * reversed_node)
{
	unordered_map<int, Node *> reversed;
	helper_dfs(reversed_node, reversed);
	return reversed;
}

string helper(int graph_nodes, vector<int> graph_from, vector<int> graph_to)
{
	unordered_map<int, Node *> original;
	for (int i = 1; i <= graph_nodes; i++)
	{
		original[i] = new Node(i);
	}
	set<pair<int, int>> edges;
	int graph_edges = graph_from.size();
	for (int i = 0; i < graph_edges; i++)
	{
		original[graph_from[i]]->neighbours.push_back(original[graph_to[i]]);

		edges.insert({graph_from[i], graph_to[i]});
	}	 

	// Student will return only one node. Do a dfs and get all the nodes.
	unordered_map<int, Node *> reversed = helper_get_all_addresses_in_reversed_graph(build_other_graph(original[1]));

    cerr << "In returned graph: " << endl;

    for (auto it = reversed.begin(); it != reversed.end(); it++)
	{
	    int n = it->second->neighbours.size();
	    cerr << "Neighbours of node " << it->first << " = [";
		for (int i = 0; i < n; i++)
		{
		    cerr << it->second->neighbours[i]->val;
		    if (i != n - 1){
		        cerr << ", ";
		    }
		}
		cerr << "]" << endl;
	}

	if (reversed.size() != graph_nodes)
	{
	    cerr << "Wrong answer because no of nodes in returned graph != no of nodes in original graph." << endl;
		return "Wrong Answer!";
	}

	for (auto it = reversed.begin(); it != reversed.end(); it++)
	{
		if (1 > it->first || it->first > graph_nodes)
		{
		    cerr << "Wrong answer because value of node is out of range." << endl;
			return "Wrong Answer!";
		}
		// New graph should not contain node from original graph. 
		if (original[it->first] == reversed[it->first])
		{
		    cerr << "Wrong answer because instead of creating new node, you have used node from original graph." << endl;
			return "Wrong Answer!";
		}
		int n = it->second->neighbours.size();
		//cout << "no of edges of node " << it->first << " = " << n << endl;
		for (int i = 0; i < n; i++)
		{
			int val = it->second->neighbours[i]->val;
			//cout << "to = " << val << endl;
			auto itttt = edges.find({val, it->first}); 
			if (itttt == edges.end())
			{
			    cerr << "Wrong answer because returned graph contains edge that is not present in original graph." << endl;
				return "Wrong Answer!";
			}
			edges.erase(itttt);
		}
	}
	// All the edges should be present in the new graph. 
	if (edges.size() > 0)
	{
	    cerr << "Wrong answer because returned graph contains extra edge that is not present in original graph" << endl;
		return "Wrong Answer!";
	}
	return "Correct Answer!";
}

int main()
{
    ostream &fout = cout;

    string res;
    int graph_nodes = 0;
    int graph_edges = 0;

    cin >> graph_nodes >> graph_edges;

    vector<int> graph_from(graph_edges);
    vector<int> graph_to(graph_edges);

    for (int graph_i = 0; graph_i < graph_edges; graph_i++) {
        cin >> graph_from[graph_i] >> graph_to[graph_i];
    }

    res = helper(graph_nodes, graph_from, graph_to);
    fout << res << endl;

    
    return 0;
}


