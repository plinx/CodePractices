#ifndef graph_h
#define graph_h

enum { UNVISITED, VISITED };

class Graph
{
public:
	Graph() = default;
	virtual ~Graph() = default;

	virtual void Init(int vertices) = 0;
	virtual int vertices() = 0;
	virtual int edges() = 0;
	virtual int first(int v) = 0;
	virtual int next(int v, int w) = 0;
	virtual void setEdge(int v1, int v2, int wt) = 0;
	virtual void delEdge(int v1, int v2) = 0;
	virtual bool isEdge(int i, int j) = 0;
	virtual int weight(int v1, int v2) = 0;
	virtual int getMark(int v) = 0;
	virtual void setMark(int v, int val) = 0;
};

void graphTraverse(Graph* G)
{
	for (int v = 0; v < G->vertices(); v++)
		G->setMark(v, UNVISITED);

	for (int v = 0; v < G->vertices(); v++)
		if (G->getMark(v) == UNVISITED)
			//doTraverse(G, v); // DFS or BFS
			DFS(G, v);
}

void DFS(Graph *G, int v)
{
	//PreVisit(G, v);
	G->setMark(v, VISITED);
	for (int w = G->first(v); w < G->vertices(); w = G->next(v, w))
		if (G->getMark(w) == UNVISITED)
			DFS(G, w);
	//PostVisit(G, v);
}

void BFS(Graph *G, int start, queue<int> *q)
{
	int v;
	q->push(start);
	G->setMark(start, VISITED);
	while (!q->empty())
	{
		v = q->front(); q->pop(); // dequeue
		//PreVisite(G, v);
		while (!q->empty())
		{
			v = q->front(); q->pop();
			//PreVisitr(G, v):
			for (int w = G->first(v); w < G->vertices(); w = G->next(v, w))
			{
				if (G->getMark(w) == UNVISITED)
				{
					G->setMark(w, VISITED);
					q->push(w);
				}
			}
		}
	}
}

void topsort(Graph *G)
{
	for (int i = 0; i < G->vertices(); i++)
		G->setMark(i, UNVISITED);
	for (int i = 0; i < G->vertices(); i++)
		if (G->getMark(i) == UNVISITED) 
			tophelp(G, i);
}

void tophelp(Graph *G, int v)
{
	G->setMark(v, VISITED);
	for (int w = G->first(v); w < G->vertices(); w = G->next(v, w))
		if (G->getMark(w) == UNVISITED)
			tophelp(G, w);

	//printout(v);

}

void qtopsort(Graph *G, queue<int> *q)
{
	vector<int> cnt(G->vertices());
	for (int v = 0; v < G->vertices(); v++) cnt[v] = 0;
	for (int v = 0; v < G->vertices(); v++)
		for (int w = G->first(v); w < G->vertices(); w = G->next(v, w))
			cnt[w] ++;
	for (int v = 0; v < G->vertices(); v++)
		if (cnt[v] == 0)
			q->push(v);

	int v;
	while (!q->empty())
	{
		v = q->front(); q->pop();
		//printout(v)
		for (int w = G->first(v); w < G->vertices(); w = G->next(v, w))
		{
			cnt[w] --;
			if (cnt[w] == 0)
				q->push(w);
		}
	}
}

#endif