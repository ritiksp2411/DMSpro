#include <iostream>
#include <string.h>
#include <algorithm>
#include <list>
using namespace std;
class Graph
{
int V;
list<int> *adj;
public:
Graph(int V) { this->V = V; adj = new list<int>[V]; }
~Graph()	 { delete [] adj; }

void addEdge(int u, int v) { adj[u].push_back(v); adj[v].push_back(u); }
void rmvEdge(int u, int v);

void printEulerTour();
void printEulerUtil(int s);

int DFSCount(int v, bool visited[]);

bool findnextvalidedge(int u, int v);
};

void Graph::printEulerTour()
{
int u = 0;
for (int i = 0; i < V; i++)
	if (adj[i].size() & 1)
		{ u = i; break; }

printEulerUtil(u);
cout << endl;
}

void Graph::printEulerUtil(int u)
{
list<int>::iterator i;
for (i = adj[u].begin(); i != adj[u].end(); ++i)
{
	int v = *i;

	if (v != -1 && findnextvalidedge(u, v))
	{
		cout << u << "-->" << v << "  ";
		rmvEdge(u, v);
		printEulerUtil(v);
	}
}
}

bool Graph::findnextvalidedge(int u, int v)
{
int count = 0;
list<int>::iterator i;
for (i = adj[u].begin(); i != adj[u].end(); ++i)
	if (*i != -1)
		count++;
if (count == 1)
	return true;

bool visited[V];
memset(visited, false, V);
int count1 = DFSCount(u, visited);

rmvEdge(u, v);
memset(visited, false, V);
int count2 = DFSCount(u, visited);

addEdge(u, v);

return (count1 > count2)? false: true;
}

void Graph::rmvEdge(int u, int v)
{
list<int>::iterator iv = find(adj[u].begin(), adj[u].end(), v);
*iv = -1;

list<int>::iterator iu = find(adj[v].begin(), adj[v].end(), u);
*iu = -1;
}

int Graph::DFSCount(int v, bool visited[])
{
visited[v] = true;
int count = 1;

list<int>::iterator i;
for (i = adj[v].begin(); i != adj[v].end(); ++i)
	if (*i != -1 && !visited[*i])
		count += DFSCount(*i, visited);

return count;
}

int main()
{
Graph g1(38);
g1.addEdge(1,2);
g1.addEdge(1,3);
g1.addEdge(2,3);
g1.addEdge(3,4);
g1.addEdge(3,34);
g1.addEdge(4,5);
g1.addEdge(4,6);
g1.addEdge(4,18);
g1.addEdge(5,6);
g1.addEdge(6,7);
g1.addEdge(6,8);
g1.addEdge(7,8);
g1.addEdge(8,9);
g1.addEdge(8,10);
g1.addEdge(8,12);
g1.addEdge(8,33);
g1.addEdge(9,10);
g1.addEdge(10,11);
g1.addEdge(10,27);
g1.addEdge(11,12);
g1.addEdge(12,13);
g1.addEdge(12,15);
g1.addEdge(13,14);
g1.addEdge(14,15);
g1.addEdge(14,17);
g1.addEdge(14,18);
g1.addEdge(15,16);
g1.addEdge(15,25);
g1.addEdge(16,17);
g1.addEdge(18,19);
g1.addEdge(19,20);
g1.addEdge(19,21);
g1.addEdge(19,22);
g1.addEdge(20,21);
g1.addEdge(22,23);
g1.addEdge(23,24);
g1.addEdge(23,25);
g1.addEdge(24,0);
g1.addEdge(25,26);
g1.addEdge(25,27);
g1.addEdge(26,0);
g1.addEdge(26,0);
g1.addEdge(26,27);
g1.addEdge(27,28);
g1.addEdge(28,29);
g1.addEdge(29,30);
g1.addEdge(30,31);
g1.addEdge(30,31);
g1.addEdge(30,37);
g1.addEdge(31,32);
g1.addEdge(31,36);
g1.addEdge(32,33);
g1.addEdge(32,34);
g1.addEdge(32,34);
g1.addEdge(34,35);
g1.addEdge(35,36);
g1.addEdge(36,37);
g1.addEdge(36,37);
g1.addEdge(37,0);
g1.printEulerTour();
return 0;
}
