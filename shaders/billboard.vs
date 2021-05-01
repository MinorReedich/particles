#version 400

layout (location = 0) in vec3 vPos;

uniform vec3 uCameraPos;
uniform float uSize;
uniform vec3 uOffset;
uniform vec4 uColor;
uniform mat4 uVP;

out vec4 color;
out vec2 uv;

void main()
{
   color = uColor;
   uv = vPos.xy;

   float dist = sqrt(pow(uCameraPos.x-uOffset.x,2) + pow(uCameraPos.y-uOffset.y,2) + pow(uCameraPos.z-uOffset.z,2));
   vec3 z = vec3((uCameraPos.x - uOffset.x)/dist, (uCameraPos.y - uOffset.y)/dist, (uCameraPos.z - uOffset.z)/dist);
   vec3 y = vec3(0,1,0);
   vec3 x = vec3(y.y*z.z - y.z*z.y, y.z*z.x - y.x*z.z, y.x*z.y - y.y*z.x);
   y = vec3(z.y*x.z - z.z*x.y, z.z*x.x - z.x*x.z, z.x*x.y - z.y*x.x);
   mat3 R = mat3(x,y,z); 

   gl_Position = uVP*vec4(R*uSize*(vPos - vec3(0.5f, 0.5f, 0))+uOffset, 1); 
}
