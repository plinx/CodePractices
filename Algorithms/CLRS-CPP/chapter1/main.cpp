#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//1.1-1
//打牌

//1.1-2
//储空间

//1.1-3
/*
  链表
  优势：动态增删容易
  劣势：随笔访问麻烦
*/

//1.1-4
/*
  相似之处：两者都需要构建一个图
  不同之处：最短路径只求 A -> B 之间的最短路径，而旅行商需要遍历所有的点并回归到起始点
*/

//1.1-5
//skip

//1.2-1
//手机通讯录

//1.2-2
/*
  8n^2 < 64nlgn => n / 8 < lgn => n = 2, 3, 4, 5, 6
*/

//1.2-3
/*
  100n^2 < 2^n => n = 15, 16, 17, 18 ...
*/

int main()
{
	for (int i = 1; i < 20; i++)
		if (i < 8 * log10((double)i))
			printf("%d < 8 * lg(%d)\n", i, i);

	for (int i = 1; i < 20; i++)
		if (100 * pow((double)i, 2) < pow(2.0, i))
			printf("100 * %d^2 < 2^%d\n", i, i);

	system("pause");
	return 0;
}
