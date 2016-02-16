#include "ScreenManager.h"
#include <iostream>


std::map<std::string, std::shared_ptr<AbstractScreen> > ScreenManager::screens ;
std::shared_ptr<AbstractScreen> ScreenManager::currentScreen = nullptr;

ScreenManager::ScreenManager(){
	
}

 /* �������� ��������� ��� ����� ������� ���������, ����� ������ �� ��������� */
void ScreenManager::setCurrentScreen(std::string name){
	// ��������� �� �����
	currentScreen = screens.at(name);
}

void ScreenManager::init(sf::RenderWindow &window, sf::Event &event){

	//��������� ������
	screens.emplace("pauseMenu", std::make_shared<pauseMenu>(window, event) );
	screens.emplace("startMenu", std::make_shared<startMenu>(window, event) );

	setCurrentScreen("pauseMenu");
}

void ScreenManager::handleInput(){


}
	
void ScreenManager::update(float delta){

	  // � ����  �������, ����� draw �������� ���� �������
	 // ��������� ������ � ���������, ������� ������ ��������� �� �����������.
	// � �� ����,�����, � update � handleInput,����������� ��� ��� �������.
   // ���� �����������.
}

void ScreenManager::draw(){

	currentScreen->draw();
}

void ScreenManager::resize(int width, int height){

			 // ����������
}



ScreenManager::~ScreenManager(){
	
}


