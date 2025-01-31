/* Demonstrates how to load PLY files
*
* http://talkera.org/opengl/
* Model needs to be triangulated
* Use blender
*
* Just the class for loading PLY files.
*
* Saving from: http://choorucode.com/2011/08/18/output-3d-mesh-to-ply-file/
*
*/

#ifndef PLYMODEL_H
#define PLYMODEL_H

#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>
#include <string>
#include <iostream>
#include <fstream>

typedef enum ClickStatus
{
    IDLE,
    SELECTED
} Status;

class PLYmodel
{
public:
    
    PLYmodel() {}
    ~PLYmodel()
    {
        if (Faces_Triangles != NULL) free(Faces_Triangles);
        if (Faces_Quads     != NULL) free(Faces_Quads);
        if (Vertex_Buffer   != NULL) free(Vertex_Buffer);
        if (Normals         != NULL) free(Normals);
    }
    
    int PLYmodel::Load(char *filename);
    float* PLYmodel::calculateNormal(float *coord1, float *coord2, float *coord3);
    

    float* Faces_Triangles;
    float* Faces_Quads;
    float* Vertex_Buffer;
    float* Init_Vertex_Buffer;
    float* Normals;

    int TotalConnectedTriangles;
    int TotalConnectedQuads;
    int TotalConnectedPoints;
    int TotalFaces;
};

#endif