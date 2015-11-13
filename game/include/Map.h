#ifndef _MAP_H
#define _MAP_H
class Map
{
public:
	Map (tmx::MapLoader* map);
	virtual ~Map ();

	void draw ();
	void load ();
private:
	txm::MapLoader* map;
	Banana[] bananas;
	Enemy [] enemies;
};
#endif /* ifndef _MAP_H */
