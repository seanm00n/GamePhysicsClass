#include "Walker.h"
#include "Vehicle.h"
#include "InputHandler.h"
#include <random>
#include <iostream>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dis(0, 3);
Vehicle* ship = new Vehicle(300, 200);
Vector2D* mouse;

Walker::Walker(int x, int y)
{
	_x = x;
	_y = y;
}

void Walker::update()
{
	mouse = TheInputHandler::Instance()->getMousePosition();
	//Vector2D* arrive = new Vector2D(0,0);
	//*arrive = ship->Arrive(*mouse, Decel::slow);//적용 안되고 있음.
	//ship->applyForce(arrive);
	//ship->update();
	ship->m_tri1->rotate(10);
	ship->m_tri2->rotate(10);
	ship->m_tri3->rotate(10);
	
	//delete(arrive);
}

void Walker::draw(SDL_Renderer* renderer)
{
	filledCircleColor(renderer, mouse->getX(), mouse->getY(), 4, 0xffffffff);

	ship->draw(renderer);
}