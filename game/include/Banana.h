#ifndef _BANANA_H
#define _BANANA_H
class Banana
{
public:
	Banana (sf::Sprite sprite, int explodeLentgh);
	virtual ~Banana ();

private:
	int explodeLentgh;
	int timer;
};
#endif /* ifndef _BANANA_H_ */
