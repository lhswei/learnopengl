#ifndef _DATA_H_
#define _DATA_H_

// build and compile shaders
// -------------------------
extern Shader* pshader;
extern Shader* pshaderSingleColor;

// set up vertex data (and buffer(s)) and configure vertex attributes
// ------------------------------------------------------------------
extern float cubeVertices[];
extern float planeVertices[];
// cube VAO
extern unsigned int cubeVAO, cubeVBO;

// plane VAO
extern unsigned int planeVAO, planeVBO;

// load textures
// -------------
extern unsigned int cubeTexture;
extern unsigned int floorTexture;

extern size_t get_cube_data_len();
extern size_t get_plane_data_len();

#endif
