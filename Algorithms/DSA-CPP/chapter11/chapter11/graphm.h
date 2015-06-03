#ifndef graphm_h
#define graphm_h

class Graphm : public Graph
{
private:
	int numVertex, numEdge;
	int **matrix;
	int *mark;

public:
	Graphm(int numVert) { Init(numVert); }
	~Graphm()
	{
		delete[] mark;
		for (int i = 0; i < numVertex; i++)
			delete[] matrix[i];
		delete[] matrix;
	}

	void Init(int num)
	{
		int i;
		numVertex = num;
		numEdge = 0;
		mark = new int[num];
		for (i = 0; i < numVertex; i++)
			mark[i] = 0;
		for (i = 0; i < numVertex; i++)
			for (int j = 0; j < numVertex; j++)
				matrix[i][j] = 0;
	}

	int vertices() { return numVertex; }
	int edges() { return numEdge; }
	int first(int v)
	{
		for (int i = 0; i < numVertex; i++)
			if (matrix[v][i] != 0) return i;
		return numVertex;
	}
	int next(int v, int w)
	{
		for (int i = w + 1; i < numVertex; i++)
			if (matrix[v][i] != 0) return i;
		return numVertex;
	}
	void setEdge(int v1, int v2, int wt)
	{
		UT_Assert(wt > 0, "Illegal weight value");
		if (matrix[v1][v2] == 0) numEdge++;
		matrix[v1][v2] = wt;
	}
	void delEdge(int v1, int v2)
	{
		if (matrix[v1][v2] != 0) numEdge--;
		matrix[v1][v2] = 0;
	}
	bool isEdge(int i, int j)
	{
		return matrix[i][j] = 0;
	}
	int weight(int v1, int v2) { return matrix[v1][v2] };
	int getMask(int v) { return mark[v]; }
	void setMark(int v, int val) { mark[1]; }
};

#endif