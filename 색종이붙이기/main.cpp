#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

using namespace std;

int nfiled[11][11];
int nvisit[11][11];
int ncolor_paper[6] = { 5, 5, 5, 5, 5, 5 };
int ntotal_one;

bool check_paper(int cur_x, int cur_y, int paper_num)
{
	for (int i = cur_y; i < cur_y + paper_num; i++){
		for (int j = cur_x; j < cur_x + paper_num; j++){

			if (!nfiled[i][j])
				return false;
		}
	}
	return true;
}


void dfs(int count, int paper_num)
{
	if (count == ntotal_one)
	{






		return;
	}

	int x, y = 0;

	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			if (nfiled[i][j]){
				x = j;
				y = i;
			}
		}
	}

	for (int i = 1; i < 6; i++)
	{
		if (ncolor_paper[i] > 0)
		{
			if (check_paper(x, y, i))
			{



			}
		}

	}




}


int main()
{
	int t;
	int test_case;

	freopen("input.txt", "r", stdin);

	scanf("%d", &t);
	for (test_case = 1; test_case <= t; ++test_case)
	{
		ntotal_one = 0;

		for (int i = 0; i < 6; i++)
			ncolor_paper[i] = 5;

		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				scanf("%d", &nfiled[i][j]);
				nvisit[i][j] = 0;

				if (nfiled[i][j]){
					ntotal_one++;
				}
			}
		}



	}
	return 0;
}