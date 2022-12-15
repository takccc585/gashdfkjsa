#include <SFML/Graphics.hpp>
#include<ctime>
#include <string>
#include <iostream>
#include"settings.h"
#include"func.h"

int main()
{

	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
	window.setFramerateLimit(FPS);
	//������ �������
	RectangleShape r;
	initBat(r, batColor, leftBatStartPos);
	//����� �������
	RectangleShape r1;
	initBat(r1, batColor, rightBatStartPos);

	CircleShape circl;
	initBall(circl, ballColor, BallStart);

	//����

	int left_score = 0;
	int right_score = 0;
	Font font;
	font.loadFromFile("DS-DIGIB.ttf");
	Text left_score_text(to_string(left_score), font, 64);
	Text right_score_text(to_string(right_score), font, 64);
	left_score_text.setPosition(WINDOW_WIDTH / 2 - 100, 50);
	right_score_text.setPosition(WINDOW_WIDTH / 2 + 50, 50);

	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen())
	{
		// ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}

		//��
		//������ ����
		//������������ �� ������
		circl.move(dx, dy);
		if ((circl.getPosition().x + 2 * ballRadius >= WINDOW_WIDTH)) {
			dx = -dx;
			left_score++;
			left_score_text.setString(to_string(left_score));
		}
		if (circl.getPosition().x <= 0) {
			dx = -dx;
			right_score++;
			right_score_text.setString(to_string(right_score));
		}
		if ((circl.getPosition().y + 2 * ballRadius >= WINDOW_HEIGHT) or (circl.getPosition().y <= 0)) {
			dy = -dy;
		}
		//������������ �� ������� �� �!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		float midLeftX = circl.getPosition().x;
		float midRightX = circl.getPosition().x + 2 * ballRadius;
		float midLeftY = circl.getPosition().y;
		float midRightY = circl.getPosition().y + 2 * ballRadius;
		if ((circl.getPosition().x + 2 * ballRadius >= r1.getPosition().x) and ((circl.getPosition().y >= r1.getPosition().y) and (circl.getPosition().y + 2 * ballRadius <= r1.getPosition().y + sizeh))) {
			dx = -dx;
		}
		if ((circl.getPosition().x <= r.getPosition().x + sizew) and ((circl.getPosition().y >= r.getPosition().y) and (circl.getPosition().y + 2 * ballRadius <= r.getPosition().y + sizeh))) {
			dx = -dx;
		}
		//������������ �� ������� �� �

		//***************************************************************************
		//�������� ����� �������

		if (Keyboard::isKeyPressed(Keyboard::W)) {
			r.move(0, -batDy);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S)) {
			r.move(0, batDy);
		}
		if ((r.getPosition().y + sizeh >= WINDOW_HEIGHT)) {
			r.setPosition(otstup, WINDOW_HEIGHT - sizeh);
		}
		if ((r.getPosition().y <= 0)) {
			r.setPosition(otstup, 0);
		}

		//�������� ������ �������

		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			r1.move(0, -batDy);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down)) {
			r1.move(0, batDy);
		}
		if ((r1.getPosition().y + sizeh >= WINDOW_HEIGHT)) {
			r1.setPosition(WINDOW_WIDTH - (7 * otstup) / 5, WINDOW_HEIGHT - sizeh);
		}
		if ((r1.getPosition().y <= 0)) {
			r1.setPosition(WINDOW_WIDTH - (7 * otstup) / 5, 0);
		}

		// ��������� ���� 
		window.clear();
		window.draw(r);
		window.draw(r1);
		window.draw(circl);
		window.draw(left_score_text);
		window.draw(right_score_text);
		window.display();
	}
	return 0;
}