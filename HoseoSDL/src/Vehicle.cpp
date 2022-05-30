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
	m_maxSpeed = 12;
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
	*force *= m_maxSpeed;
	if (mod == 'FLEE')
		*force *= -1;
	*force -= *m_vel;
	force->limit(m_maxForce);
	return force;
}
Vector2D Vehicle::Arrive(Vector2D TargetLoc, Decel decel) {
	Vector2D force = TargetLoc - *m_loc;
	double dist = force.length();
	if (dist > 0) {
		const double DecelT = 0.3;
		float speed = dist / (static_cast<double>(decel) * DecelT);
		speed = min(speed, m_maxSpeed);
		Vector2D des = force * speed/dist;//normalize()
		return (des - *m_vel);
	}
	return Vector2D(0, 0);
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
	filledTrigonColor(renderer, m_loc->getX(), m_loc->getY()+m_radius, 
		m_loc->getX()+(-m_radius)/2, m_loc->getY()+(-m_radius),
		m_radius/2+ m_loc->getX(), (-m_radius)+ m_loc->getY(), 0xffffffff);
}
