#include "Walker.h"
#include "Vehicle.h"
#include "InputHandler.h"
#include <random>
#include <iostream>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dis(0, 3);

Vehicle* ship = new Vehicle(100, 100);
Vector2D* mouse;

Walker::Walker(int x, int y)
{
	_x = x;
	_y = y;
}

void Walker::update()
{
	mouse = TheInputHandler::Instance()->getMousePosition();
	Vector2D* steering;
	steering = ship->flee(mouse);
	ship->applyForce(steering);
	ship->seek(mouse,0);
	//ship->rotate();
	ship->update();
	delete(steering);
}

void Walker::draw(SDL_Renderer* renderer)
{
	filledCircleColor(renderer, mouse->getX(), mouse->getY(), 4, 0xffffffff);
	ship->draw(renderer);
}