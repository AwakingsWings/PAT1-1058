// PAT11058.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>

typedef struct question{
	int sco;
	char answer[10];
	int mistake = 0;//c++only
}Q;

int main()
{
	int countquestion, countstudent;
	Q paper[101];
	scanf_s("%d %d", &countstudent, &countquestion);
	int i;
	for (i = 0; i < countquestion; i++)
	{
		scanf_s("%d%*c%*d%*c%*d%*c%[^\n]%*c", &paper[i].sco, paper[i].answer, 10);
	}
	char write[10];
	int maxmistake = 0;
	for (; countstudent > 0; countstudent--)
	{
		int studentsco = 0;
		for (i = 0; i < countquestion; i++)
		{
			scanf_s("(%*d %[^)])", write, 10);
			if (strcmp(write, paper[i].answer) == 0)
			{
				studentsco += paper[i].sco;
			}
			else
			{
				paper[i].mistake++;
				if (maxmistake < paper[i].mistake)
				{
					maxmistake = paper[i].mistake;
				}
			}
			getchar();
		}
		printf("%d\n", studentsco);
	}
	if (maxmistake == 0)
	{
		//Too Young,too simple,sometimes naive.
		printf("Too simple");
	}
	else
	{
		printf("%d", maxmistake);
		for (i = 0; i < countquestion; i++)
		{
			if (maxmistake == paper[i].mistake)
			{
				printf(" %d", i + 1);
			}
		}
	}
    return 0;
}