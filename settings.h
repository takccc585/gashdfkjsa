#pragma once
#include"settings.h"
#include <iostream>
#include <ctime>

using namespace sf;
using namespace std;
const float WINDOW_WIDTH = 800;
const float WINDOW_HEIGHT = 800;
const string WINDOW_TITLE = "SFML Lesson 3";
const float FPS = 120;
const float batDy = 5.f;
float dx = 2.5;
float dy = 2.5;
float sizew = 20.f;
float sizeh = 80.f;
float otstup = 50.f;
const sf::Vector2f batSize(20.f, 80.f);

const sf::Vector2f leftBatStartPos{ otstup, (WINDOW_HEIGHT - sizeh) / 2 };
const sf::Vector2f rightBatStartPos{ WINDOW_WIDTH - otstup, (WINDOW_HEIGHT - sizeh) / 2 };
const sf::Vector2f BallStart{ WINDOW_WIDTH / 2 - ballRadius, WINDOW_HEIGHT / 2 - ballRadius };

const float ballRadius = 15.f;
const sf::Color ballColor{ sf::Color::Yellow };
const sf::Color batColor{ sf::Color::Magenta };