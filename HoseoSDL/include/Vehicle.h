#include "Vector2D.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL2_gfxPrimitives.h>
using namespace std;
enum class Decel
{
	fast = 1, normal = 2, slow = 3
};
class Vehicle {
public:
	Vector2D* m_acc;
	Vector2D* m_vel;
	Vector2D* m_loc;
	Vector2D* m_tri1;
	Vector2D* m_tri2;
	Vector2D* m_tri3;

	float m_maxSpeed;
	float m_maxForce;
	double m_radius;
	Decel decel;

	Vehicle(float x, float y);
	Vector2D* flee(Vector2D* target);
	Vector2D* seek(Vector2D* target,int mod);
	void applyForce(Vector2D* force);
	Vector2D Arrive(Vector2D TargetLoc, Decel decel);
	void update();
	void draw(SDL_Renderer* renderer);
};
