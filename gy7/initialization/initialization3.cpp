// member initializer list szükséges írásvédett adattagok esetén

struct GameState {
	const float gravity_constant;
    int &ref;

#if 1
	GameState(int i) : gravity_constant{9.81f}, ref{i} {
		
	}
#else
	// A konstruktor törzsén belül már nem lehetséges az írásvédett adattagok inicializálása.
	// Ezt az inicializációs listában kell megtenni.
	GameState(int i) {
		gravity_constant = 9.81f;
		ref = i;
	}
#endif
};

int main() {
	GameState g(10);
	return 0;
}
