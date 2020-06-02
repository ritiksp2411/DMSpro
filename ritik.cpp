#include<iostream>
#include<vector>
using namespace std;
int findStartVert(int graph[][n]) {
   for(int i = 0; i<NODE; i++) {
      int deg = 0;
      for(int j = 0; j<NODE; j++) {
         if(tempGraph[i][j])
            deg++;     //increase degree, when connected edge found
      }

      if(deg % 2 != 0)     //when degree of vertices are odd
         return i;         //i is node with odd degree
   }
   return 0;     //when all vertices have even degree, start from 0
}

bool isBridge(int u, int v) {
   int deg = 0;
   for(int i = 0; i<NODE; i++)
      if(tempGraph[v][i])
         deg++;

   if(deg>1) {
      return false;    //the edge is not forming bridge
   }

   return true;   //edge forming a bridge
}

int edgeCount() {
   int count = 0;
   for(int i = 0; i<NODE; i++)
      for(int j = i; j<NODE; j++)
         if(tempGraph[i][j])
            count++;
   return count;     //count nunber of edges in the graph
}

void fleuryAlgorithm(int start) {
   static int edge = edgeCount();
   for(int v = 0; v<NODE; v++) {
      if(tempGraph[start][v]) {        //when (u,v) edge is presnt and not forming bridge
         if(edge <= 1 || !isBridge(start, v)) {
            cout << start << "--" << v << " ";
            tempGraph[start][v] = tempGraph[v][start] = 0;     //remove edge from graph
            edge--;    //reduce edge
            fleuryAlgorithm(v);
         }
      }
   }
}

int main() {
    int n;
    cout << "Enter the number of vertices in your graph" << endl;
    cin >> n;
    cout << " Enter the edges here\n" ;
    while(1){
        int x,y;
        cout << "Enter the starting vertex and Ending vertex" << endl;
        cin >> x >> y;
        graph[x][y]++;
        int i;
        cout << "Do you want to continue? press 1 otherwise any key to continue the program" << endl;
        cin >> i;
        if(i!=1) break;
    }
   for(int i = 0; i<NODE; i++)     //copy main graph to tempGraph
      for(int j = 0; j<NODE; j++)
         tempGraph[i][j] = graph[i][j];
   cout << "Euler Path Or Circuit: ";
   fleuryAlgorithm(findStartVert());
}
