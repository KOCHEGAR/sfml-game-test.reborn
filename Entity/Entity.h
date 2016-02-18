#pragma once
#include<SFML/Graphics.hpp>

using namespace sf;

class Entity
{
public:
					Entity();
	virtual			~Entity();
	//void			drawTheEntity(Texture textureForEntity, Sprite spriteForEntity); // ������� �������
	void			drawEntity(Image &image, int rectX, int rectY);
	
	Sprite			sprite;//������ �� ���������, ����� ���������� �� ����������� ������ drawHero(), �� ������� ���� ���� �� ��������
protected:
	//int			coordinateX; //����� ������������ ��� Vector2f, �� ����� ��� ��� ��������� � ����� ����������(pos.x, pos.y)
	//int			coordinateY;
	//int			hitpoints; //���� �������������������� �� ����� �� ������, ��� ��� �����������, ����� ���� ���� �������
	//int			armor;
	Vector2f		_posCoordinate;
	Vector2f		_direction;//����������� �������� ������
	float			_speed;
	bool			_onGround;	
	Texture			_texture;
	//Sprite		_sprite;
};