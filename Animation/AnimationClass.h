#pragma once
#include "IAnimation.h"
class AnimationClass : public IAnimation
{
private:
	 std::vector<sf::Sprite*> frames;
	 float maxFrameTime; // ������������ ����������� ������ �����
	 float currentFrameTime; // ����� ����������� �������� �����
	 int frameCountX; // ���������� ������ �������� �� ���� �� ������-�����
	 int frameCountY; // ���������� ������ �������� �� ������ �� ������-�����
	 int frame; // ��������� ����

public:
	AnimationClass();
	AnimationClass(sf::Texture &texture, int frameCountX, int frameCountY, float cycleFrame, int x, int y, int w, int h);
	~AnimationClass();

	// ������������ ����� IAnimation
	virtual void flip(bool flipX, bool flipY) override;
	virtual void setSize(int width, int height) override;
	virtual void update(float deltaTime) override;
	virtual void draw(float posX, float posY, sf::RenderWindow & window) override;
};

