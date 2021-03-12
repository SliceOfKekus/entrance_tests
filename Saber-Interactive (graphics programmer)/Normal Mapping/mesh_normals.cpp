#include <glm.hpp>

using namespace glm;

//
// Calculate smooth (average) per-vertex normals
//
// [out] normals - output per-vertex normals
// [in] verts - input per-vertex positions
// [in] faces - triangles (triplets of vertex indices)
// [in] nverts - total number of vertices (# of elements in verts and normals arrays)
// [in] nfaces - total number of faces (# of elements in faces array)
//
void calc_mesh_normals(vec3* normals, const vec3* verts, const int* faces, int nverts, int nfaces)
{
	for (int i = 0; i < nfaces; i += 3)
	{
		vec3 a = verts[faces[i]];;
		vec3 b = verts[faces[i + 1]];;
		vec3 normal = normalize(cross(a, b));

		for (int j = 0; j < 3; ++j)
			normals[faces[i + j]] += normal;
	}

	for (int i = 0; i < nverts; ++i)
		normals[i] = normalize(normals[i]);
}
