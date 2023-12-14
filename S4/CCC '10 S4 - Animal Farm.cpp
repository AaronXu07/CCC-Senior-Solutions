#include <bits/stdc++.h>
using namespace std;
 
 
// find the vertex with minimum key value, from the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[], int V)
{
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
 
    return min_index;
}
 
//  print the constructed MST 
void printMST(int parent[], vector<vector<int>>& graph, int V)
{
    cout<<"Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout<<parent[i]<<" - "<< i <<" \t"<<graph[i][parent[i]]<<" \n";
}
 
// construct and print MST for a graph represented using adjacency
// matrix representation with 2D vector
void primMST(vector<vector<int>>& graph, int V)
{
    // Array to store constructed MST 
    int parent[V];
     
    // Key values used to pick minimum weight edge in cut
    int key[V];
     
    // To represent set of vertices included in MST
    bool mstSet[V];
 
    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first vertex.
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST. It has no parent
 
    // The MST will have V vertices
    for (int count = 0; count < V; count++)
    {
        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        int u = minKey(key, mstSet, V);
 
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
 
        // Update key value and parent index of
        // the adjacent vertices of the picked vertex ‘u’.
        // Consider only those vertices which are not
        // yet included in MST
        for (int v = 0; v < V; v++)
 
            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] != 0 && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
 
    // print the constructed MST
    printMST(parent, graph, V);
}
 
int main()
{
    int M, p;
    vector<vector<int>> pens;

    cin >> M;

    for(int i = 0; i < M; i++)
    {
        cin >> p;
        int max = 0;

        vector<int> nodes (p, 0);
        vector<int> weights (p, 0);

       for(int j = 0; j < p; j++)
       {
        cin >> nodes[j];
        if(nodes[j] > max){
            max = nodes[j];
        }
       } 
       for(int j = 0; j < p; j++)
       {
        cin >> weights[j];
       }

        pens.resize(max);

        for(int j = 0; j < pens.size(); j++){
            pens[j].resize(max, 0);
        }

        for(int j = 0; j < p; j++){
            int node1 = 0;
            int node2 = 0;

            if(j == p-1){
                int node1 = nodes[j] - 1;
                int node2 = nodes[0] - 1;
            }
            else{
                int node1 = nodes[j] - 1;
                int node2 = nodes[j+1] - 1;
            }

            pens[node1][node2] = weights[j];
        }
    }

    primMST(pens, pens.size());

    return 0;
}
