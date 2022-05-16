#include "Vector2D.h"
#include "Vehicle.h"
#include "InputHandler.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <math.h>
#include <iostream>

Vehicle::Vehicle(float x, float y) {
	m_acc = new Vector2D(0, 0);
	m_vel = new Vector2D(0, 0);
	m_loc = new Vector2D(x, y);
	m_length = 8;
	m_loca = new Vector2D(x, y - m_length);
	m_locb = new Vector2D(x + m_length, y + m_length);
	m_locc = new Vector2D(x - m_length, y + m_length);
	m_maxSpeed = 4;
	m_maxForce = 0.25;
	m_radius = 16;
}
void Vehicle::seek(Vector2D* target) {
	Vector2D* desired = new Vector2D(0, 0);
	*desired = *target - *m_loc;
	desired->normalize();
	*desired *= m_maxSpeed;

	Vector2D* steer = new Vector2D(0, 0);
	*steer = *desired - *m_vel;//
	steer->limit(m_maxForce);
	applyForce(steer);
	applyForce2p(steer);


	delete(desired);
	delete(steer);
}
void Vehicle::applyForce(Vector2D* force) {
	*m_acc += *force;
}
void Vehicle::applyForce2p(Vector2D* force) {
	*m_loca += *force;
	*m_locb += *force;
	*m_locc += *force;
}
void Vehicle::rotate() {
	//¸¶¿ì½ºÁÂÇ¥
	Vector2D* mouse;
	mouse = TheInputHandler::Instance()->getMousePosition();

}
void Vehicle::update() {
	*m_vel += *m_acc;
	m_vel->limit(m_maxSpeed);
	*m_loc += *m_vel;
	*m_acc = Vector2D(0, 0);
}
void Vehicle::draw(SDL_Renderer* renderer) {
	filledTrigonColor(
		renderer, m_loca->getX(), m_loca->getY(), m_locb->getX(), m_locb->getY(), m_locc->getX(), m_locc->getY(),
		0xffffffff);
}