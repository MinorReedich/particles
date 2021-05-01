// Bryn Mawr College, alinen, 2020
//

#include "AGL.h"
#include "AGLM.h"
#include <cmath>
#include "confetti.h"

using namespace std;
using namespace agl;
using namespace glm;

void Confetti::createParticles(int size) 
{
  mTexture = theRenderer.loadTexture("../textures/particle.png");
  for(int i = 0; i<size; i++){
    Particle p;
    p.size = 0.25;
    p.pos = random_unit_cube();
    p.color = vec4(random_float(), random_float(), random_float(), random_float());
    p.vel = vec3(random_float(), random_float(), random_float());
    mParticles.push_back(p);
  }
}

void Confetti::update(float dt)
{
  // update particles
  for(int i = 0; i<mParticles.size(); i++){
    Particle p = mParticles[i];
    if(p.pos.x > 1 || p.pos.x < -1) p.vel.x = -p.vel.x;
    if(p.pos.y > 1 || p.pos.y < -1) p.vel.y = -p.vel.y;
    if(p.pos.z > 1 || p.pos.z < -1) p.vel.z = -p.vel.z;
    p.pos += dt*p.vel;
    mParticles[i] = p; 
  }
  for(int j = 0; j<50; j++){
    for(int i = 1; i<mParticles.size(); i++){
      vec3 v1 = mParticles[i].pos - theRenderer.cameraPosition();
      float d2 = sqrt(v1.x*v1.x + v1.y*v1.y + v1.z*v1.z);
      vec3 v2 = mParticles[i-1].pos - theRenderer.cameraPosition(); 
      float d1 = sqrt(v2.x*v2.x + v2.y*v2.y + v2.z*v2.z);
      if(d2>d1){
        Particle temp = mParticles[i];
        mParticles[i] = mParticles[i-1];
        mParticles[i-1] = temp;
      }
    }
  }
}