#include <SFML/Graphics.hpp>
#include "setting.h"
#include <ctime>
using namespace sf;
int main()
{
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(W_WIDTH, W_HEIGHT), W_TITLE);
	window.setFramerateLimit(FPS);
	srand(time(nullptr));
	RectangleShape leftBat, rightBat;
	leftBat.setSize(Vector2f(BAT_WIDTH, BAT_HEIGHT));
	leftBat.setFillColor(LEFT_BAD_COLOR);
	leftBat.setPosition(BAT_OFFSET, (W_HEIGHT - BAT_HEIGHT) / 2);
	rightBat.setSize(Vector2f(BAT_WIDTH, BAT_HEIGHT));
	rightBat.setFillColor(RIGHT_BAD_COLOR);
	rightBat.setPosition(W_WIDTH - BAT_OFFSET - BAT_WIDTH, (W_HEIGHT - BAT_HEIGHT) / 2);
	CircleShape circle;
	circle.setRadius(RADIUS);
	circle.setFillColor(CIRCLE_COLOR);
	circle.setPosition((W_WIDTH - 2 * RADIUS) / 2, (W_HEIGHT - 2 * RADIUS) / 2);
	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen())
	{
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
			if (Keyboard::isKeyPressed(Keyboard::W)) { leftBat.move(0, -5); }
			if (Keyboard::isKeyPressed(Keyboard::S)) { leftBat.move(0, 5); }
			if (Keyboard::isKeyPressed(Keyboard::Up)) { rightBat.move(0, -5); }
			if (Keyboard::isKeyPressed(Keyboard::Down)) { rightBat.move(0, 5); }
		if (leftBat.getPosition().y <= 0) {
			leftBat.setPosition(BAT_OFFSET, 0.f);
		}
		if (leftBat.getPosition().y + BAT_HEIGHT >= W_HEIGHT) {
			leftBat.setPosition(BAT_OFFSET, W_HEIGHT - BAT_HEIGHT);
		}
		if (rightBat.getPosition().y <= 0) {
			rightBat.setPosition(W_WIDTH - BAT_OFFSET - BAT_WIDTH , 0.f);
		}
		if (rightBat.getPosition().y + BAT_HEIGHT >= W_HEIGHT) {
			rightBat.setPosition(W_WIDTH - BAT_OFFSET - BAT_WIDTH, W_HEIGHT - BAT_HEIGHT);
		}
		//Обновление игры
		window.clear();
		circle.move(speed_x, speed_y);
		if (circle.getPosition().x <= 0 || circle.getPosition().x + 2 * RADIUS >= W_WIDTH) {
			speed_x = -speed_x;
		}
		if (circle.getPosition().y <= 0 || circle.getPosition().y + 2 * RADIUS >= W_HEIGHT) {
			speed_y = -speed_y;
		}
		// Отрисовка обьектов или окна
		window.draw(leftBat);
		window.draw(rightBat);
		window.draw(circle);
		window.display();
	}

	return 0;
}