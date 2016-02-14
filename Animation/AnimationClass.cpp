


#include "AnimationClass.h"
#include <iostream>


AnimationClass::AnimationClass()
{
}

AnimationClass::AnimationClass(sf::Texture &texture, int frameCountX, int frameCountY, float cycleFrame, int x, int y, int w, int h)
{
	frames = std::vector<sf::Sprite*>();
	std::fill(frames.begin(), frames.end(), nullptr);// 	����������� ��� nullptr �� �++11. ��� ����� ����������� ���������� � �������� ������� � 0 � null
	if (frameCountY <= 0) { frameCountY = 1; this->frameCountY = frameCountY; }
	if (frameCountX <= 0) { frameCountX = 1; this->frameCountX = frameCountX; }

	this->frameCountX = frameCountX;
	this->frameCountY = frameCountY;
	int frameWidth = w; // ������ ������ ������ �����
	int frameHeight = h; // ������ ������ ������ �����

	for (int i = 0; i < frameCountY; ++i) {

		for (int j = 0; j < frameCountX; ++j) {// ��������� � frames ������ ��� ����� textureRegion
											   // ��� i * frameWidth ��� ������ ��������� ����� �� ��������
			frames.push_back(new sf::Sprite(texture, sf::IntRect(x + (frameWidth*j), y + (frameHeight*i), frameWidth, frameHeight)));
		}
	}

	maxFrameTime = cycleFrame / (frameCountX*frameCountY); // ����� ������������ ������ ����� �������� �����
	std::cout << maxFrameTime ;							// ����� ������������ ���� �������� ������ �� ���������� ������
	currentFrameTime = 0;
	frame = 0;													   
}



AnimationClass::~AnimationClass()
{
}

void AnimationClass::flip(bool flipX, bool flipY)
{
}

void AnimationClass::setSize(int width, int height)
{
}

void AnimationClass::update(float deltaTime)
{
	currentFrameTime += deltaTime; // ��������� ������� dt � currentFrameTime
	if (currentFrameTime >= maxFrameTime) { //���� ����� �������� �����  ������ ������� ����������� ������ �����, �� �������������� ����� � �������� ������� ����� �����
		
		frame++;
		currentFrameTime = 0;	
	}

	if (frame >= frameCountX*frameCountY) { // ���� ����� ������ ��� ����� ���������� ���� �������, �� �������� �����
		frame = 0;
	}
}

void AnimationClass::draw(float posX, float posY, sf::RenderWindow &window)
{
	sf::Sprite *s = frames[frame];

	s->setPosition(posX, posY);
	window.draw(*s);
}
