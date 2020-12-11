#version 410
layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec3 vertexColour;
out vec3 colour;

uniform float Xoffset;
uniform float Yoffset;

void main() {
 colour = vertexColour;
 gl_Position = vec4(vertexPosition.x + Xoffset,
                    vertexPosition.y + Yoffset,
                    vertexPosition.z, 1.0);

}
