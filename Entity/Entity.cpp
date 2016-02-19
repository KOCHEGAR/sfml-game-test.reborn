#include "Entity.h"
 
Entity::Entity()
{
}

Entity::~Entity() {}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	/*// You can draw other high-level objects
	target.draw(sprite, states);
	// ... or use the low-level API
	states.texture = &m_texture;
	target.draw(m_vertices, states);*/

	target.draw(_sprite, states);
}

void Entity::drawEntity(Image &image, int rectstartX, int rectstartY, int rectX, int rectY)
{
	//��� ������� sprite � ����� �� spritesheet'a �����������, ������������� ����� ������� � ��� ��������
	_texture.loadFromImage(image);
	_sprite.setTexture(_texture);
	//_sprite.setTextureRect(IntRect(0, 0, rectX, rectY));//��� ������ �� 0, � ��� ����. �������� ����� �� 210
	_sprite.setTextureRect(IntRect(rectstartX, rectstartY, rectX, rectY));
	//sprite.setOrigin(_widht / 2, _height / 2);
}

void Entity::createHitBox(float widht, float height)
{
	_widht = widht; _height = height;
}

void Entity::setHitBoxPosition(float posX, float posY)
{
	_posCoord.x = posX; _posCoord.y = posY;
	_sprite.setPosition(posX, posY);
}

Vector2f Entity::getHitBoxPosition()
{
	return Vector2f(_posCoord);
}

FloatRect Entity::getHitBoxRect()//�-��� ��������� ��������������. ��� �����,������� (���,�����).
{
	return FloatRect(_posCoord.x, _posCoord.y, _widht, _height);
}
