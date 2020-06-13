#include <iostream>
#include <queue>
using namespace std;
// depth first search DFS
void printDFS(int **edges,int n,int sv,bool *visited){
    cout << sv << endl;
    visited[sv] = true;
    for(int i=0; i < n;i++){
        if(i == sv) continue;
        if(edges[sv][i] == 1) {
            if(visited[i]) continue;
            printDFS(edges,n,i,visited);
        }
    }
}
// Breadth first search
void print_bfs(int **edges,int n,int sv,bool *visited){
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;
    while(!pendingVertices.empty()){
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout << currentVertex << " ";
        for(int i=0;i<n;i++){
            if(edges[currentVertex][i] == 1 && !visited[i]){
                if(i == currentVertex) continue;
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(int **edges,int n) {
    bool * visited = new bool[n];
    for(int i=0;i<n;i++) visited[i] = false;
    for(int i=0;i<n;i++){
        if(!visited[i]) print_bfs(edges,n,i,visited);
    }
    delete [] visited;
}

void DFS(int **edges,int n) {
    bool * visited = new bool[n];
    for(int i=0;i<n;i++) visited[i] = false;
    for(int i=0;i<n;i++){
        if(!visited[i]) printDFS(edges,n,i,visited);
    }
    delete [] visited;
}
bool hasPath(int **edges,int n,int sv,int ev,bool *visited){
    if (sv == ev) return true;
    visited[sv] = true;
    bool finalAns = false;
    if(edges[sv][ev] == 1) return true;
    else{
        for(int i=0;i<n;i++){
            if(i == sv) continue;
            if(edges[sv][i] == 1 && !visited[i]) {
                bool temp = hasPath(edges,n,i,ev,visited);
                finalAns = finalAns || temp;
            }
        }
        return finalAns;
    }
}


int main() {
    int n;
    int e;
    cin >> n >> e;
    int** edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }

    for(int i=0;i< e;i++){
        int f,s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool *visited = new bool[n];
    for(int i=0;i<n;i++) visited[i] = false;
    //print(edges,n,0,visited);
    //print_bfs(edges,n,0);
    //delete all the memory
    for(int i = 0 ;i < n;i++){
        delete [] edges[i];
    }
    delete [] edges;
   // delete [] visited;
    return 0;
}
