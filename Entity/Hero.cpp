#include"Hero.h"

Hero::Hero():Entity()
{
	_speed = 0; _onGround = false; _state = stay;
}

Hero::~Hero(){}

void Hero::setHeroPosition(float posX, float posY)
{
	_posCoordinate.x = posX; _posCoordinate.y = posY;
	sprite.setPosition(posX, posY);
}

void Hero::control()
{
	if (Keyboard::isKeyPressed)	{
		if ((Keyboard::isKeyPressed(Keyboard::A)) || (Keyboard::isKeyPressed(Keyboard::Left))) {
			_speed = 0.2f; _state = walk_l;
		}
		if ((Keyboard::isKeyPressed(Keyboard::D)) || (Keyboard::isKeyPressed(Keyboard::Right))) {
			_speed = 0.2f; _state = walk_r;
		}
		if (((Keyboard::isKeyPressed(Keyboard::W)) || (Keyboard::isKeyPressed(Keyboard::Up))) && (_onGround)) {
			//��-�� ����, ��� ��� ���� ������ ��������� _onGround, ���������� ����� �� ����������� �������� _direction.y 
			//�����, �������� �� �������, ���� ���� ������� ����������
			//_speed = 0.7f; _direction.y = 0.7f; _state = jump; _onGround = false; //��� ����� �� ����� ���� ������
		}
	}
	else {
		_state = stay;//���� ������ �� ������, �� ��������� = ������
	}
}

void Hero::states()
{
	switch (_state)	{
	case stay: _speed = 0; _direction.x = 0; break; //������ �� ������
	case jump: break; //�������� ������ �������� � control(), ����� �� �� ������� ��-�� ����, ��� ��� �� �������� _onGround
	case walk_r: _direction.x = _speed; break;
	case walk_l: _direction.x = -_speed; break;
	}
}

void Hero::update(float time)
{
	control();
	states();

	_speed = 0;
	_posCoordinate.x += _direction.x * time;
	_posCoordinate.y += _direction.y * time;
	sprite.setPosition(_posCoordinate.x, _posCoordinate.y);
	//_direction.y += 0.002 * time; //�����, ������ ��� �� ��� ����� ����� ���������� ������
}

Vector2f Hero::getHeroPosition()
{
	return Vector2f(_posCoordinate);
}
