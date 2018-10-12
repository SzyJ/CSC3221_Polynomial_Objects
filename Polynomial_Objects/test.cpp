const int NO_LIVES = 3;

class Game {
private:
	int* gameData;
public:
	Game() 
	: gameData(new int[NO_LIVES]) {

	}

	~Game() {
		delete[] gameData;
	}
};

void gameFunction(Game& myGame) {

}

int main() {
	Game g;
	gameFunction(g);
}