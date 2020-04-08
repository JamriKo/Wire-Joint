/*我们有N条电线，每个电线两端是不同规格的接口（a/b/c/d...），同一根电线两端的接口规格可能是不同的，只有相同规格的接口才能把两根电线连接在一起，设计一个程序，判断所有这些电线是否能合并为一根长电线。
输入：N行，每行是两个字符串，表示电线的规格，如
a a
b b
c c
输出：是否能拼接为一根电线*/

/*算法设计思路：统计不同规格接口数量，其中奇数接口种类不超过2种即可拼接为一根电线，否则不能拼接为一根电线。*/
#include <string>
#include <iostream>
#include <windows.h>
using namespace std;
/*计数函数count：统计不同规格接口（以26个字母命名）数量*/
void count(char* str, int occur[])
{
	while (*str)
	{
		if ('a' <= *str&&*str <= 'z')
			occur[*str - 'a']++;
		else if ('A' <= *str&&*str <= 'Z')
			occur[*str - 'A']++;
		str++;
	}
}
/*主函数*/
int main()
{
	while (TRUE)
	{
		int N, i, n = 0;
		char ch[999], temp[2];					//ch长度不得小于2N，默认999
		string s;
		int c[26] = { 0 };						//26种规格计数数组
		printf("请输入电线数量N\n");
		cin >> N;
		/*N行转1行*/
		for (i = 0; i < N; i++)
		{
			printf("请输入第%d条电线两端规格（A-Z，大小写均可）:\n", i + 1);
			cin >> temp;
			s += temp;
		}
		/*string转char*/
		for (i = 0; i<s.length(); i++)
			ch[i] = s[i];
		ch[i] = '\0';
		/*统计接口规格数量*/
		count(ch, c);
		/*奇偶判别*/
		for (i = 0; i < 26; i++)
		{
			//printf("%c=%d\n", (char)('A' + i), c[i]);
			if (c[i] % 2 != 0)
			{
				n = n + 1;
			}
		}
		if (n < 3)
			printf("可以拼接为一条电线\n\n");
		else
			printf("不可以拼接为一条电线\n\n");
	}
	return 0;
}