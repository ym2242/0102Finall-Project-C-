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

	printf("�п�ܼҦ� : <1> ���aVS���a  <2> ���aVS�q��  <3> (----->>���}) \n\n");
	printf("�z�n���Ҧ���: ");
	scanf("%d", &mode);
	if (mode == 1)
		printf("\n\n�z�n���Ҧ���: ���aVS���a\n\n");
	if (mode == 2)
		printf("\n\n�z�n���Ҧ���: ���aVS�q��\n\n");
	system("pause");

	/* ���aVS���a */

	while (mode == 1)
	{
		do
		{
			show_position();

			printf("\n���a %d ��ܤ@�Ӧ�l (�Ҧp: 1A; �� E ���}~): ", player);
			scanf("%s", &buf);/* ��J���ȷ|�H buf[]={1,A,0} �o�˪��覡�x�s */

			if (buf[0] == 'E')
			{
				printf("\n��������!\n");
				system("pause");
				return;
			}

			i = buf[0] - '1';  /* ��i���ȥu�� 0, 1, 2 ���ܤ� */
			j = buf[1] - 'A';  /* ��j���ȥu�� 0, 1, 2 ���ܤ� */

			/* ���J���~���ȮɡA��������U�@�Ӱj�� Ex: 4A,2D,3x... */
			/* �� */
			if ((i < 0) || (2 < i) || (j < 0) || (2 < j))
			{
				continue;
			}

			if (a[i][j] > 0)
			{
				continue;
			}
			/* �� */

			a[i][j] = player + 1;  /* �p�G i=0, j=0(1A) player=0 ���ܴN�b1A����m�[ 1 */
			player = 1 - player;   /* �������a 0 1 0 1 ���� */
			done = check();        /* �P�_�j��O�_�n�~�� */
			pp++;                  /* �̦h�[��9�N���X�j��(9��) */

		} while ((done == 0) && (pp < 9)); /* pp�N����(�̦h9��) */

		printf("\n");
		show_position();
		player = 1 - player;

		if (done == 2)
			printf("\n���a %d Ĺ!\n\n", player);
		else if (done == 1)
			printf("\n���a %d Ĺ!\n\n", player);
		else
			printf("��������!\n");

		system("pause");
		return;
	}

	/* ���aVS�q�� */

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

				printf("\n����q�����!!\n\n");
				system("pause");
			}

			if (player == 0)
			{
				printf("\n���a��ܤ@�Ӧ�l (�Ҧp: 1A; �� E ���}~): ");
				scanf("%s", &buf);

				if (buf[0] == 'E')
				{
					printf("\n��������!\n");
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
			printf("\n���aĹ!\n\n", player);
		else if (pp == 9 && done == 0)
		{
			printf("\n��������!\n");
			system("pause");
			return;
		}
		else
		{
			printf("\n�q��Ĺ!\n");
		}

		system("pause");
		return;
	}
}

void show_position()
{
	int i, j;
	system("CLS"); /* �M���e�� */

	printf("   A    B    C\n");
	for (i = 0; i< 3; i++)
	{
		printf(" \n\n%d", i + 1);
		for (j = 0; j < 3; j++)
		{
			if (a[i][j] == 1)      /* player 0 �]�� player+1 �����Y */
				printf("  O  ");
			else if (a[i][j] == 2) /* player 1 */
				printf("  X  ");
			else
				printf("  �� ");
		}
		printf("\n");
	}
}

int check()
{
	int i, j;
	for (i = 0; i< 3; i++){

		if ((a[i][0] == a[i][1]) && (a[i][0] == a[i][2])){     /* ��u */
			if (a[i][0] > 0) return a[i][0];
		}

		for (j = 0; j< 3; j++){

			if ((a[0][j] == a[1][j]) && (a[0][j] == a[2][j])){ /* ���u */
				if (a[0][j] > 0) return a[0][j];
			}

			if ((a[0][0] == a[1][1]) && (a[0][0] == a[2][2])){ /* �׽u */
				if (a[0][0] > 0) return a[0][0];
			}

			if ((a[0][2] == a[1][1]) && (a[0][2] == a[2][0])){ /* �׽u */
				if (a[0][2] > 0) return a[0][2];

			}
		}
	}
	return(0);
}

char AI()
{
	int a, b;
	char c1, c2;

	srand(time(NULL));

	a = rand() % 3;
	b = rand() % 3;

	switch (a)
	{
	case 0:
		c1 = '1';
		break;
	case 1:
		c1 = '2';
		break;
	case 2:
		c1 = '3';
		break;
	}

	switch (b)
	{
	case 0:
		c2 = 'A';
		break;
	case 1:
		c2 = 'B';
		break;
	case 2:
		c2 = 'C';
		break;
	}

	buf[0] = c1;
	buf[1] = c2;
}

int AI_check(void)
{
	int x, y;

	x = buf[0] - '1';
	y = buf[1] - 'A';

	if (a[x][y] == 1 || a[x][y] == 2)
	{
		return 1;
	}
	else if (a[x][y] == 0)
	{
		return 0;
	}
}