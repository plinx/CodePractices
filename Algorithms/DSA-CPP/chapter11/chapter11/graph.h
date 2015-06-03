#ifndef graph_h
#define graph_h

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

#endif