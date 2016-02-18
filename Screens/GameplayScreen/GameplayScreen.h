#pragma once
#include "../AbstractScreen/abstractScreen.h"
#include <iostream>
#include "../../Animation/AnimationClass.h"

class GameplayScreen : public AbstractScreen
{
public:

	sf::RenderWindow &_window;
	sf::Event &_event;
	std::shared_ptr<IAnimation> ExplosionAnim;
	sf::Texture texture;
	sf::Clock clock;

	  // ��� ��������� ������ ��������� ���� �����, ������ � ��.
	 // ��� ���� ������������� ��� ������� ������� �����,������ � ��.
	// ��������� ������ ������ �� �������� �������� �� ������

	GameplayScreen(sf::RenderWindow &window, sf::Event &event);
	~GameplayScreen();

	// ������������ ����� AbstractScreen
	virtual void handleInput() override;
	virtual void update(float delta) override;
	virtual void draw() override;
};

