#ifndef graphl_h
#define graphl_h

struct Edge
{
	Edge() : vert(-1), wt(-1) {}
	Edge(int v, int w) : vert(v), wt(w) {}
	int vertex() { return vert; }
	int weight() { return wt; }
private:
	int vert;
	int wt;
};

class Graphl : public Graph 
{
private:
};

#endif
