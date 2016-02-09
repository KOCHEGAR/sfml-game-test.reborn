#ifndef STARTMENU_H
#define STARTMENU_H

#include"menu.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class startMenu {							  
public:
	startMenu(RenderWindow &win);
	void runMenu();//������� ���� ���������� ����
	void update(float time);//������������ � ������������ ������
	bool menuControl();//������� ���������� �� ������ � ����������� � ������������ 1 ���� ������ ������ �����.
private:
	enum Button_focus{start,option,autors,quit};
	Button _start;
	Button _options;
	Button _autors;
	Button _quit;
	RenderWindow& _window;
	Event event;// ����� ��� ��������� �������
	Button_focus _ButtFocus;



};


#endif