/*������N�����ߣ�ÿ�����������ǲ�ͬ���Ľӿڣ�a/b/c/d...����ͬһ���������˵Ľӿڹ������ǲ�ͬ�ģ�ֻ����ͬ���Ľӿڲ��ܰ���������������һ�����һ�������ж�������Щ�����Ƿ��ܺϲ�Ϊһ�������ߡ�
���룺N�У�ÿ���������ַ�������ʾ���ߵĹ����
a a
b b
c c
������Ƿ���ƴ��Ϊһ������*/

/*�㷨���˼·��ͳ�Ʋ�ͬ���ӿ����������������ӿ����಻����2�ּ���ƴ��Ϊһ�����ߣ�������ƴ��Ϊһ�����ߡ�*/
#include <string>
#include <iostream>
#include <windows.h>
using namespace std;
/*��������count��ͳ�Ʋ�ͬ���ӿڣ���26����ĸ����������*/
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
/*������*/
int main()
{
	while (TRUE)
	{
		int N, i, n = 0;
		char ch[999], temp[2];					//ch���Ȳ���С��2N��Ĭ��999
		string s;
		int c[26] = { 0 };						//26�ֹ���������
		printf("�������������N\n");
		cin >> N;
		/*N��ת1��*/
		for (i = 0; i < N; i++)
		{
			printf("�������%d���������˹��A-Z����Сд���ɣ�:\n", i + 1);
			cin >> temp;
			s += temp;
		}
		/*stringתchar*/
		for (i = 0; i<s.length(); i++)
			ch[i] = s[i];
		ch[i] = '\0';
		/*ͳ�ƽӿڹ������*/
		count(ch, c);
		/*��ż�б�*/
		for (i = 0; i < 26; i++)
		{
			//printf("%c=%d\n", (char)('A' + i), c[i]);
			if (c[i] % 2 != 0)
			{
				n = n + 1;
			}
		}
		if (n < 3)
			printf("����ƴ��Ϊһ������\n\n");
		else
			printf("������ƴ��Ϊһ������\n\n");
	}
	return 0;
}