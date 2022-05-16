#include "Walker.h"
#include "Vehicle.h"
#include "InputHandler.h"
#include <random>

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<int> dis(0, 3);
Vehicle* ship = new Vehicle(0, 0);

Walker::Walker(int x, int y)
{
	_x = x;
	_y = y;

}

void Walker::update()
{

	Vector2D* mouse;
	mouse = TheInputHandler::Instance()->getMousePosition();
	ship->seek(mouse);
	ship->rotate();
	ship->update();

}

void Walker::draw(SDL_Renderer* renderer)
{
	Vector2D* mouse;
	mouse = TheInputHandler::Instance()->getMousePosition();
	filledCircleColor(renderer, mouse->getX(), mouse->getY(), 4, 0xffffffff);
	ship->draw(renderer);
}