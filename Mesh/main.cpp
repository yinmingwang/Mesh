//=============================================================================
#include <iostream>
// -------------------- OpenMesh
#include <OpenMesh/Core/IO/MeshIO.hh>
#include <OpenMesh/Core/Mesh/PolyMesh_ArrayKernelT.hh>
// ----------------------------------------------------------------------------
typedef OpenMesh::PolyMesh_ArrayKernelT<>  MyMesh;
// ----------------------------------------------------------------------------
// Build a simple cube and write it to std::cout

int main()
{
	MyMesh mesh;
	// generate vertices
	MyMesh::VertexHandle vhandle[8];
	vhandle[0] = mesh.add_vertex(MyMesh::Point(-0.05, -0.05, 0.05));
	vhandle[1] = mesh.add_vertex(MyMesh::Point(0.05, -0.05, 0.05));
	vhandle[2] = mesh.add_vertex(MyMesh::Point(0.05, 0.05, 0.05));
	vhandle[3] = mesh.add_vertex(MyMesh::Point(-0.05, 0.05, 0.05));
	vhandle[4] = mesh.add_vertex(MyMesh::Point(-0.05, -0.051, -0.05));
	vhandle[5] = mesh.add_vertex(MyMesh::Point(0.05, -0.05, -0.05));
	vhandle[6] = mesh.add_vertex(MyMesh::Point(0.05, 0.05, -0.05));
	vhandle[7] = mesh.add_vertex(MyMesh::Point(-0.05, 0.05, -0.05));
	// generate (quadrilateral) faces
	std::vector<MyMesh::VertexHandle>  face_vhandles;
	face_vhandles.clear();
	face_vhandles.push_back(vhandle[0]);
	face_vhandles.push_back(vhandle[1]);
	face_vhandles.push_back(vhandle[2]);
	face_vhandles.push_back(vhandle[3]);
	mesh.add_face(face_vhandles);

	face_vhandles.clear();
	face_vhandles.push_back(vhandle[7]);
	face_vhandles.push_back(vhandle[6]);
	face_vhandles.push_back(vhandle[5]);
	face_vhandles.push_back(vhandle[4]);
	mesh.add_face(face_vhandles);
	face_vhandles.clear();
	face_vhandles.push_back(vhandle[1]);
	face_vhandles.push_back(vhandle[0]);
	face_vhandles.push_back(vhandle[4]);
	face_vhandles.push_back(vhandle[5]);
	mesh.add_face(face_vhandles);
	face_vhandles.clear();
	face_vhandles.push_back(vhandle[2]);
	face_vhandles.push_back(vhandle[1]);
	face_vhandles.push_back(vhandle[5]);
	face_vhandles.push_back(vhandle[6]);
	mesh.add_face(face_vhandles);
	face_vhandles.clear();
	face_vhandles.push_back(vhandle[3]);
	face_vhandles.push_back(vhandle[2]);
	face_vhandles.push_back(vhandle[6]);
	face_vhandles.push_back(vhandle[7]);
	mesh.add_face(face_vhandles);
	face_vhandles.clear();
	face_vhandles.push_back(vhandle[0]);
	face_vhandles.push_back(vhandle[3]);
	face_vhandles.push_back(vhandle[7]);
	face_vhandles.push_back(vhandle[4]);
	mesh.add_face(face_vhandles);
	try
	{
		if (!OpenMesh::IO::write_mesh(mesh, "cube.obj"))
		{
			std::cerr << "Cannot write mesh to file 'cube.obj'" << std::endl;
			return 1;
		}
	}
	catch (std::exception& x)
	{
		std::cerr << x.what() << std::endl;
		return 1;
	}
	return 0;
}