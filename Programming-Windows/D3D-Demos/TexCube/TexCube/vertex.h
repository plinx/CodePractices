#ifndef _VERTEX_H
#define _VERTEX_H

struct Vertex
{
	Vertex() {}
	Vertex(
		float x, float y, float z,
		float nx, float ny, float nz,
		float u, float v) 
		: _x(x), _y(y), _z(z), 
		_nx(nx), _ny(ny), _nz(nz), 
		_u(u), _v(v) {}

	float _x, _y, _z;
	float _nx, _ny, _nz;
	float _u, _v;
};

#define FVF_VERTEX (D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1)

#endif