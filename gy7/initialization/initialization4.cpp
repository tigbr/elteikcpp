#include <iostream>

// Member initializer list hatékonysága (godbolt)

struct point2d {
	int x;
	int y;

	point2d() : x{999999}, y{888888} { }
    point2d(int x, int y) : x{x}, y{y} { }
};

struct Player {
	point2d p;

#if USE_MEMBER_LIST
	Player(point2d p) : p{p} { }
#else
	// Ebben az esetben a point2d adattag kétszer lesz inicializálva.
	// Egyszer a point2d::point2d() miatt, majd azonnal utána a Player::Player() törzsében.
    Player() {
        p.x = 5;
        p.y = 4;
    }
#endif
};

int main() {
#if USE_MEMBER_LIST
	point2d point;
    Player p(point);
#else
    Player p;
#endif
    return 0;
}
