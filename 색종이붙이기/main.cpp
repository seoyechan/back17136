#include <stdio.h>
#include <algorithm>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

using namespace std;

int nfiled[11][11];
int nvisit[11][11];
int ncolor_paper[6] = { 5, 5, 5, 5, 5, 5 };
int ntotal_one, nRet;

bool check_paper(int cur_x, int cur_y, int paper_num)
{
	for (int i = cur_y; i < cur_y + paper_num; i++){
		for (int j = cur_x; j < cur_x + paper_num; j++){

			if (i < 0 || i >= 10 || j < 0 || j >= 10)
				return false;
			if (nvisit[i][j] || !nfiled[i][j])
				return false;
		}
	}
	return true;
}

void check_visit(int cur_x, int cur_y, int paper_num, int nif)
{
	for (int i = cur_y; i < cur_y + paper_num; i++){
		for (int j = cur_x; j < cur_x + paper_num; j++){
			nvisit[i][j] = nif;
		}
	}
}


void dfs(int i, int j, int count, int paper_num)
{
	if (paper_num >= nRet) return;
	if (count > ntotal_one) return;

	if (count == ntotal_one)
	{
		nRet = min(nRet, paper_num);
		return;
	}

	if (i == 10) return;


	if (nfiled[i][j] && !nvisit[i][j]){

		for (int k = 1; k < 6; k++)
		{
			if (ncolor_paper[k] > 0)
			{
				if (check_paper(j, i, k))
				{
					check_visit(j, i, k, 1);
					ncolor_paper[k]--;

					if (j + 1 < 10)
						dfs(i, j + 1, count + (k * k), paper_num + 1);
					else
						dfs(i + 1, 0, count + (k * k), paper_num + 1);

					ncolor_paper[k]++;
					check_visit(j, i, k, 0);
				}
			}
		}
	}
	else{
		if (j + 1 < 10)
			dfs(i, j + 1, count, paper_num);
		else
			dfs(i + 1, 0, count, paper_num);
	}




	return;

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

		if (!ntotal_one){
			printf("%d\n", 0); continue;
		}


		nRet = 987654321;
		dfs(0, 0, 0, 0);

		if (nRet == 987654321){
			printf("%d\n", -1); continue;
		}
		else
			printf("%d\n", nRet);


	}
	return 0;
}