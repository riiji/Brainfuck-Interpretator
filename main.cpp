#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;



int main()
{
	FILE *file;
	char buffer[200];
	scanf("%s", &buffer);
	file = fopen(buffer, "r");
	fpos_t cpos;
	stack<fpos_t> cid;
	char cmnd;

	//start program in brainfuck
	int i = 0;
	char arr[30000];
	memset(arr, 0, sizeof(arr));

	while (fscanf(file, "%c", &cmnd) != EOF)
	{
		if (cmnd == '>')
			++i;
		if (cmnd == '<')
			--i;
		if (cmnd == '+')
			++arr[i];
		if (cmnd == '-')
			--arr[i];
		if (cmnd == '.')
			putchar(arr[i]);
		if (cmnd == ',')
		{
			arr[i] = getchar();
			if (arr[i] == '\n')
				arr[i] = getchar();
		}
		if (cmnd == '[')
		{
			fgetpos(stdin, &cpos);
			cid.push(cpos);
		}
		if (cmnd == ']')
		{
			if (!arr[i])
				cid.pop();
			else
				fsetpos(stdin, &cid.top());
		}
	}
}