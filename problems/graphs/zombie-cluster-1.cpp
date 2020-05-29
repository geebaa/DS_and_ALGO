#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'zombieCluster' function below.
 *
 * The function accepts STRING ARRAY as parameter.
 */
vector<int> getNeighbors(vector<string> &zombies,int num_zombies,int node)
{
    vector<int> neighbors;
    int i=0;
    for(auto neighbor:zombies[node]){
        if(neighbor == '1'){
            neighbors.push_back(i);
        }
        i++;
    }
    return neighbors;
}

void bfs(vector<string> &zombies,int num_zombies,int node,vector<int> &visited)
{
    queue<int>q;
    vector<int> neighbors;
    q.push(node);
    // mark visited
    visited[node]=1;

    while(!q.empty()){
        node=q.front();
        q.pop();
        neighbors = getNeighbors(zombies,num_zombies,node);
        for(auto neighbor:neighbors){
            if(visited[neighbor] == -1){
                // not yet visited, mark visited and explore
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }
}

void dfs(vector<string> &zombies,int num_zombies,int node,vector<int> &visited)
{
    // mark visited
    visited[node] = 1;

    vector<int> neighbors = getNeighbors(zombies,num_zombies,node);
    for(auto neighbor:neighbors){
        if(visited[neighbor] == -1){
            //unexplored neighbor 
            // explore now
            dfs(zombies,num_zombies,neighbor,visited);
        }
    }
    return;
}

int zombieCluster(vector<string> zombies) {

    // zombies matrix is a n*n matrix 
    // representing the relation(edge) between 
    // zombies i and j in cell zombies[i][j]
    int num_zombies=zombies.size(); // num zombies
    int num_components=0;
    vector<int> visited(num_zombies,-1);

    for(int i=0;i<num_zombies;i++){
        if(visited[i] == -1){
            num_components++;
            //bfs(zombies,n,visited);
            dfs(zombies,num_zombies,i,visited);
        }
    }
    return num_components;
}


int main()
{
    ostream &fout = cout;

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> zombies(n);

    for (int i = 0; i < n; i++) {
        string zombies_item;
        getline(cin, zombies_item);

        zombies[i] = zombies_item;
    }

    int res = zombieCluster(zombies);

    fout << res << "\n";

    return 0;
}


