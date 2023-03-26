2395380
Connor Jacobs

Command line:
g++ *.cpp
./a.out input.txt goodbye.txt

This is Assignment 2, not So Super Mario Bros. The goal is the same 
as the original, defeat the final boss and save the princess. It is in
a world with a fixed number of levels, provided at runtime, and each level 
is represented with a NxN 2d array, N is also provided at runtime. 
The whole world is a 3D array. Mario starts with a number of lives 
provided at runtime, every 20 coins he gets an etra life. And by eating
mushrooms he can take his power level from pl0 to pl2. The map is a torus 
and each spot is populated with something. C - coin, M -  mushroom,
K - koopa, G - goomba, B - boss, W - warp pipe, X - nothing, or H for hero. 
If the enemy is a Goomba, Mario defeats the enemy with a 80% probability, the position
becomes empty, and Mario moves on. If Mario loses (20% probability), his power level is
decreased by 1, the Goomba stays in the position, and Mario moves on. The exception
is if Mario loses while at PL0, in which case a life is lost. If Mario has another life, he
continues at the same location, with PL0. Otherwise, the simulation ends, and the game
is lost.
If the enemy is a Koopa, Mario defeats the enemy with a 65% probability, the position
becomes empty, and Mario moves on. If Mario loses (35% probability), his power level is
decreased by 1, the Koopa stays in the position, and Mario moves on. The exception is if
Mario loses while at PL0, in which case a life is lost. If Mario has another life, he
continues at the same location, with PL0. Otherwise, the simulation ends, and the game
is lost. 
If Mario defeats 7 enemies on the same life, he earns another life.
Mario defeats the enemy with a 50% probability, the position becomes empty, and Mario
moves on to the next level. If Mario is in the last level, the princess is saved, the game is
won, and the simulation is over. If Mario loses (50% probability), his power level is
decreased by 2, and Mario attempts to defeat the boss again. The exception is if Mario
loses while at PL0 or PL1, in which case a life is lost. If Mario has another life, he
continues at the same location, with PL0. Otherwise, the simulation ends, and the game
is lost.