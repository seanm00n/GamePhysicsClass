#include "Vector2D.h"
#include "Vehicle.h"
#include "InputHandler.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <math.h>
#include <iostream>
using namespace std;

Vehicle::Vehicle(float x, float y) {
	m_loc = new Vector2D(x, y);
	m_vel = new Vector2D(0, 0);
	m_acc = new Vector2D(0, 0);
	m_maxSpeed = 6;
	m_maxForce = 0.25;
	m_radius = 16;
}
Vector2D* Vehicle::flee(Vector2D* target) {
	return this->seek(target, 'FLEE');
}
Vector2D* Vehicle::seek(Vector2D* target, int mod) {
	Vector2D* force = new Vector2D(0,0);
	*force = *target - *m_loc;
	force->normalize();
	*force *= m_maxForce;
	if (mod == 'FLEE')
		*force *= -1;
	*force -= *m_vel;
	force->limit(m_maxForce);
	return force;
}
void Vehicle::applyForce(Vector2D* force) {
	*m_acc += *force;
}
void Vehicle::rotate() {
	//¹Ì±¸Çö
}
void Vehicle::update() {
	*m_vel += *m_acc;
	m_vel->limit(m_maxSpeed);
	*m_loc += *m_vel;
	*m_acc = Vector2D(0, 0);
}
void Vehicle::draw(SDL_Renderer* renderer) {
	filledTrigonColor(renderer, -m_radius, -m_radius/2, -m_radius, m_radius/2, m_radius, 0, 0xffffffff);
}