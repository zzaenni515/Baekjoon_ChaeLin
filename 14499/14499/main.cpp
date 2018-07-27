//14499-¡÷ªÁ¿ß ±º∏Æ±‚
#include <iostream>
using namespace std;
class dice {
public:
	int up, down, front, back, left, right;
	dice() {
		up = 0;
		down = 0;
		front = 0;
		back = 0;
		left = 0;
		right = 0;
	}

	int east(int input) {//1
		int temp = up;
		up = left;
		left = down;
		down = right;
		right = temp;
		printf("%d\n", up);
		if (input == 0) return down;//∏ ¿Ã0¿œ∞ÊøÏ ¡÷ªÁ¿ßπÿ∏È ∏ ø° ¬Ô±‚
		down = input;
		return 0;//∏ ø° º˝¿⁄∞° ¿÷¿ª ∞ÊøÏ, 0¿∏∑Œ πŸ≤ﬁ
	}

	int west(int input) {//2
		int temp = up;
		up = right;
		right = down;
		down = left;
		left = temp;
		printf("%d\n", up);
		if (input == 0) return down;//∏ ¿Ã0¿œ∞ÊøÏ ¡÷ªÁ¿ßπÿ∏È ∏ ø° ¬Ô±‚
		down = input;
		return 0;//∏ ø° º˝¿⁄∞° ¿÷¿ª ∞ÊøÏ, 0¿∏∑Œ πŸ≤ﬁ
	}

	int north(int input){//3
		int temp = up;
		up = front;
		front = down;
		down = back;
		back = temp;
		/*up = back;
		back = down;
		down = front;
		front = temp;*/
		printf("%d\n", up);
		if (input == 0) return down;//∏ ¿Ã0¿œ∞ÊøÏ ¡÷ªÁ¿ßπÿ∏È ∏ ø° ¬Ô±‚
		down = input;
		return 0;//∏ ø° º˝¿⁄∞° ¿÷¿ª ∞ÊøÏ, 0¿∏∑Œ πŸ≤ﬁ
	}

	int south(int input) {//4
		int temp = up;
		up = back;
		back = down;
		down = front;
		front = temp;
		/*up = front;
		front = down;
		down = back;
		back = temp;*/
		printf("%d\n", up);
		if (input == 0) return down;//∏ ¿Ã0¿œ∞ÊøÏ ¡÷ªÁ¿ßπÿ∏È ∏ ø° ¬Ô±‚
		down = input;
		return 0;//∏ ø° º˝¿⁄∞° ¿÷¿ª ∞ÊøÏ, 0¿∏∑Œ πŸ≤ﬁ
	}
};

int main(void) {
	int map[21][21];
	int n, m, x, y, k;

	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	int move;//1:east,2:west,3:north,4:south
	int xx, yy;//(xx,yy)
	dice d;

	for (int i = 0; i < k; i++) {
		cin >> move;

		if (move == 1){//µø
			xx = x;
			yy = y + 1;
			if (xx >= 0 && xx < n&&yy >= 0 && yy < m) {
				map[xx][yy] = d.east(map[xx][yy]);
				x = xx;
				y = yy;
			}

		}
		else if (move == 2) {//º≠
			xx = x;
			yy = y - 1;
			if (xx >= 0 && xx < n&&yy >= 0 && yy < m) {
				map[xx][yy] = d.west(map[xx][yy]);
				x = xx;
				y = yy;
			}

		}
		else if (move == 3) {//∫œ
			xx = x - 1;
			yy = y;
			if (xx >= 0 && xx < n&&yy >= 0 && yy < m){
				map[xx][yy] = d.north(map[xx][yy]);
				x = xx;
				y = yy;
			}

		}
		else if (move == 4) {//≥≤
			xx = x + 1;
			yy = y;
			if (xx >= 0 && xx < n&&yy >= 0 && yy < m) {
				map[xx][yy] = d.south(map[xx][yy]);
				x = xx;
				y = yy;
			}
		}
	}
	return 0;
}