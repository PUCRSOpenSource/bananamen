#ifndef _ENEMY_H
#define _ENEMY_H
class Enemy
{
public:
	Enemy (sf::Sprite sprite);
	virtual ~Enemy ();

	void drop();

private:
	sf::Sprite sprite;
	float moveSpeed;
};
#endif /* ifndef _ENEMY_H */
