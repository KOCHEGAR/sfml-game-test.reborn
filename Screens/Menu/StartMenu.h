#ifndef STARTMENU_H
#define STARTMENU_H

#include"Button.h"
#include <SFML/Graphics.hpp>
#include "../AbstractScreen/abstractScreen.h"
using namespace sf;

class startMenu : public AbstractScreen {
public:
	
	startMenu(RenderWindow &window);
	
	virtual void handleInput() override;
	virtual void draw() override;
	virtual void update() override;
private:
	enum Button_focus{start,option,autors,quit};
	Button _start;
	Button _options;
	Button _autors;
	Button _quit;
	RenderWindow& _window;
	Event event;// ����� ��� ��������� �������
	Button_focus _ButtFocus;

	void drawButtons();	  // ������������ ������
	bool menuControl();//������� ���������� �� ������ � ����������� � ������������ 1 ���� ������ ������ �����.

};


#endif