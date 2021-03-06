//--------------------------------------------------
// Robot Simulator
// vertexBuffer.h
// Date: 06/07/2020
// By Breno Cunha Queiroz
//--------------------------------------------------
#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include <iostream>
#include <string.h>
#include <vector>
#include "defines.h"
#include "device.h"
#include "buffer.h"
#include "vertex.h"

class VertexBuffer : public Buffer
{
	public:
	VertexBuffer(Device* device, std::vector<Vertex> vertices);
	~VertexBuffer();

	private:
};

#endif// VERTEX_BUFFER_H
