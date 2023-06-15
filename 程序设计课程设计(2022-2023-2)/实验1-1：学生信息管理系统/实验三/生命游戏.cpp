#include <Logo.h>

int world[15][15];




void resetWorld(){
	for(int i = 0;i < 15;++i)
		for(int j = 0;j < 15;++j)
			world[i][j] = 0;

	for(int i = 0;i < 15;++i)
		world[i][0] = world[i][14] = world[0][i] = world[14][i]  =1;
			
}

void resetRandomWorld(){
	for(int i = 0;i < 15;++i)
			for(int j = 0;j < 15;++j)
				world[i][j] = random(0,1);
				
}

void showWorld(){
	clearscreen();
	
	moveto(-140,140);
	
	for(int i = 0;i < 15;++i){
		for(int j = 0;j < 15;++j){
			if(world[i][j] == 1)
				solidcircle(10,60,179,113);
			circle(10);
			move(20,0);
		}
		move(-300,-20);
	}
	
	
}


int cntLife(int a,int b){
	int	dx[] = {1,1,1,0,0,-1,-1,-1};
	int	dy[] = {1,0,-1,1,-1,1,0,-1};
	int cnt = 0;
	for(int i = 0;i < 8;++i){
		int x = a + dx[i],y = b + dy[i];
		if(0 <= x && x <= 14 && 0 <= y && y <= 14 && world[x][y] == 1)
			++cnt;
	}
	return cnt;
	
}

void evolution(){
	int t[15][15];
	for(int i =0;i < 15;++i)
		for(int j = 0;j < 15;++j){
			if(cntLife(i,j) == 2)
				t[i][j] = world[i][j];
			else if(cntLife(i,j) == 3)
				t[i][j] = 1;
			else
				t[i][j] =0;
		}
	for(int i = 0;i < 15;++i)
		for(int j = 0;j < 15;++j)
			world[i][j] = t[i][j];
}


int main() { 
	setup(400,400,800,400,false);
	
	penspeed(11);
	hidepen();
	pencolor(128,128,128);
	
	//resetWorld();
	resetRandomWorld();
	showWorld();
	
	while(true){
		wait(0.5);
		evolution();
		showWorld();
	}
	
	
	
	close();
	return 0;
}
