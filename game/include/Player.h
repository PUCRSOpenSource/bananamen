#ifndef _PLAYER_H
#define _PLAYER_H
class Player
{
public:
	Player (sf::Sprite sprite);
	virtual ~Player ();

	void move();
	void plantBanana();
	void die();

private:
	sf::Sprite sprite;
	float moveSpeed;
	int explodeLentgh;
	int delay;

};
#endif /* ifndef _PLAYER_H */
