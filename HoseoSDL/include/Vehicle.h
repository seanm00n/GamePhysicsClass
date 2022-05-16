#include "Vector2D.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_gfxPrimitives.h>

class Vehicle {
public:
	Vector2D* m_acc;
	Vector2D* m_vel;
	Vector2D* m_loc;
	float m_length;
	Vector2D* m_loca;
	Vector2D* m_locb;
	Vector2D* m_locc;
	float m_maxSpeed;
	float m_maxForce;
	float m_radius;

	Vehicle(float x, float y);
	void seek(Vector2D* target);
	void applyForce(Vector2D* force);
	void applyForce2p(Vector2D* force);
	void rotate();
	void update();
	void draw(SDL_Renderer* renderer);
};
