#include <stdio.h> 
#include <stdlib.h> 

int a[3][3];
char buf[3] = { 0 };
void show_position(void);
int check(void);
char AI(void);
int AI_check(void);

int main()
{
	int i, j, player, pp, done, mode, w;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			a[i][j] = 0;
		}
	}

	pp = 0;
	done = 0;
	player = 0;

	printf("請選擇模式 : <1> 玩家VS玩家  <2> 玩家VS電腦  <3> (----->>離開) \n\n");
	printf("您要的模式為: ");
	scanf("%d", &mode);
	if (mode == 1)
		printf("\n\n您要的模式為: 玩家VS玩家\n\n");
	if (mode == 2)
		printf("\n\n您要的模式為: 玩家VS電腦\n\n");
	system("pause");

	/* 玩家VS玩家 */

	while (mode == 1)
	{
		do
		{
			show_position();

			printf("\n玩家 %d 選擇一個位子 (例如: 1A; 按 E 離開~): ", player);
			scanf("%s", &buf);/* 輸入的值會以 buf[]={1,A,0} 這樣的方式儲存 */

			if (buf[0] == 'E')
			{
				printf("\n本局平手!\n");
				system("pause");
				return;
			}

			i = buf[0] - '1';  /* 讓i的值只有 0, 1, 2 的變化 */
			j = buf[1] - 'A';  /* 讓j的值只有 0, 1, 2 的變化 */

			/* 當輸入錯誤的值時，直接執行下一個迴圈 Ex: 4A,2D,3x... */
			/* ↓ */
			if ((i < 0) || (2 < i) || (j < 0) || (2 < j))
			{
				continue;
			}

			if (a[i][j] > 0)
			{
				continue;
			}
			/* ↑ */

			a[i][j] = player + 1;  /* 如果 i=0, j=0(1A) player=0 的話就在1A的位置加 1 */
			player = 1 - player;   /* 切換玩家 0 1 0 1 切換 */
			done = check();        /* 判斷迴圈是否要繼續 */
			pp++;                  /* 最多加到9就跳出迴圈(9格) */

		} while ((done == 0) && (pp < 9)); /* pp代表格數(最多9格) */

		printf("\n");
		show_position();
		player = 1 - player;

		if (done == 2)
			printf("\n玩家 %d 贏!\n\n", player);
		else if (done == 1)
			printf("\n玩家 %d 贏!\n\n", player);
		else
			printf("本局平手!\n");

		system("pause");
		return;
	}

	/* 玩家VS電腦 */

	while (mode == 2)
	{
		show_position();
		do
		{
			show_position();
			if (player == 1)
			{
				AI();
				w = AI_check();

				while (w == 1)
				{
					AI();
					w = AI_check();
				}

				printf("\n輪到電腦選擇!!\n\n");
				system("pause");
			}

			if (player == 0)
			{
				printf("\n玩家選擇一個位子 (例如: 1A; 按 E 離開~): ");
				scanf("%s", &buf);

				if (buf[0] == 'E')
				{
					printf("\n本局平手!\n");
					system("pause");
					return;
				}
			}

			i = buf[0] - '1';
			j = buf[1] - 'A';

			if ((i < 0) || (2 < i) || (j < 0) || (2 < j))
			{
				continue;
			}

			if (a[i][j] > 0)
			{
				continue;
			}

			a[i][j] = player + 1;
			player = 1 - player;
			done = check();
			pp++;

		} while ((done == 0) && (pp < 9));

		printf("\n");
		show_position();
		player = 1 - player;

		if (done == 1)
			printf("\n玩家贏!\n\n", player);
		else if (pp == 9 && done == 0)
		{
			printf("\n本局平手!\n");
			system("pause");
			return;
		}
		else
		{
			printf("\n電腦贏!\n");
		}

		system("pause");
		return;
	}
}

