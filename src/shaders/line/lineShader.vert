#version 460
#extension GL_ARB_separate_shader_objects : enable
#extension GL_GOOGLE_include_directive : require
#include "../rayTracing/material.glsl"
#include "../rayTracing/uniformBufferObject.glsl"

layout(binding = 0) readonly uniform UniformBufferObjectStruct { UniformBufferObject Camera; };
layout(binding = 1) readonly buffer MaterialArray { Material[] Materials; };
layout(push_constant) uniform ObjectInfo {
  mat4 modelView;
} objectInfo;

layout(location = 0) in vec3 InPosition;
layout(location = 1) in vec3 InNormal;
layout(location = 2) in vec2 InTexCoord;
layout(location = 3) in int InMaterialIndex;

layout(location = 0) out vec3 FragColor;

out gl_PerVertex
{
	vec4 gl_Position;
};

void main() 
{
    gl_Position = Camera.projection * Camera.modelView * objectInfo.modelView * vec4(InPosition, 1.0);
    FragColor = InNormal;
}
