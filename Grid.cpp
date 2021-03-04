#include "Grid.h"

Grid::Grid(float sizeOfSquare, glm::mat4& mvp){
    gridSquareSize = sizeOfSquare;
    vb = new VertexBuffer(4*(numRowCol+1));
    layout.Push<float>(4);
    va.AddBuffer(*vb,layout);
    initIdx();
	initVertexBuffer();
    ib = new IndexBuffer(idx, 4*(numRowCol+1));
    shader_ptr = new Shader("../res/shaders/grid.shader");
    Update(mvp);
}

Grid::~Grid(){
    delete shader_ptr;
	delete ib;
	delete vb;
}


void Grid::initIdx(){
    for(unsigned int i=0; i<4*(numRowCol+1); i++){
        idx[i] = i;
    }
}

void Grid::initVertexBuffer(){
	float pointOne[4];
	float pointTwo[4];
	float leftGrid = 0;
	float rightGrid = numRowCol * gridSquareSize; 
	float bottomGrid = 0;
	float topGrid = numRowCol * gridSquareSize; 
     
	int idx = 0;
	//Horizontal
	for(int i=0; i < numRowCol + 1; i++){
		pointOne[0] = leftGrid ; pointOne[1] = 0.0f; pointOne[2] = i*gridSquareSize; pointOne[3] = 1.0f;
		pointTwo[0] = rightGrid; pointTwo[1] = 0.0f; pointTwo[2] = i*gridSquareSize; pointTwo[3] = 1.0f;
		for(int k=0; k<4; k++)	{
        	verts[idx*4+k] = pointOne[k];
			verts[(idx+1)*4+k] = pointTwo[k];
		}
		idx+=2;
	}

	//Vertical
	for(int i=0; i < numRowCol + 1; i++){
		pointOne[0] = i*gridSquareSize; pointOne[1] = 0.0f; pointOne[2] = bottomGrid; pointOne[3] = 1.0f;
		pointTwo[0] = i*gridSquareSize; pointTwo[1] = 0.0f; pointTwo[2] = topGrid; pointTwo[3] = 1.0f;
		for(int k=0; k<4; k++)	{
			verts[idx*4+k] = pointOne[k];
			verts[(idx+1)*4+k] = pointTwo[k];
		}
		idx+=2;
	}
}
