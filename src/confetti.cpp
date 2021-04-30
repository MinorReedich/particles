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
  Particle p;
  p.size = 1;
  p.pos = random_unit_cube();
  p.color = vec4(random_float(), random_float(), random_float(), random_float());
  p.vel = vec3(random_float(), random_float(), random_float());
  mParticles.push_back(p);
}

void Confetti::update(float dt)
{
  // update particles
  Particle p = mParticles[0];

  if(p.pos.x > 1 || p.pos.x < -1) p.vel.x = -p.vel.x;
  if(p.pos.y > 1 || p.pos.y < -1) p.vel.y = -p.vel.y;
  if(p.pos.z > 1 || p.pos.z < -1) p.vel.z = -p.vel.z;
  p.pos += dt*p.vel;

  mParticles[0] = p; 
}