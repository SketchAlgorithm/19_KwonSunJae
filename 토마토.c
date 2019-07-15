#include<stdio.h>
struct node {
	int x, y, turn;
};
typedef struct node node;
node Q[1000200];
int  Front, Tail,in[1000][1000],ch[1000][1000];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int empty() {
	return Front == Tail;
}
void insertQ(int x,int y,int t) {
	node temp;
	temp.x = x;
	temp.y = y;
	temp.turn = t;
	Q[Tail] = temp;
	Tail++;
}
node pop() {
	return Q[Front++];
}
int main() {
	int X, Y;
	scanf("%d %d", &X, &Y);
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			scanf("%d", &in[y][x]);
			if (in[y][x] == 1) {
				insertQ(x, y, 0);
				ch[y][x] = 1;
			}
			else if (in[y][x] == -1) {
				ch[y][x] = 1;
			}
		}
	}
	node te;
	int px, py;
	while (!empty()) {
		te = pop();
		for (int d = 0; d < 4; d++) {
			px = te.x + dx[d];
			py = te.y + dy[d];
			if (px >= 0 && py >= 0 && px < X && py < Y) {
				if (in[py][px] == 0 && ch[py][px] == 0) {
					insertQ(px, py, te.turn + 1);
					ch[py][px] = 1;
				}
			}
		}
	}
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			if (ch[y][x] != 1) {
				printf("-1");
				return 0;
			}
		}
	}
	printf("%d", te.turn);
}
