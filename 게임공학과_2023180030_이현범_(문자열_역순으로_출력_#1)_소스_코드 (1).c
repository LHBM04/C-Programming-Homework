/*
*	���Ӱ��а� 2023180030 ������
*	[���ڿ� �������� ����ϱ�(��¸� �������� �ϱ�)]
*/

#include <stdio.h>

// ���ڿ��� �ִ� ���̸� �ǹ��ϴ� ��ũ�� ���.
#define MAX_STRING_LENGTH 100

/// <summary>
/// ���ڿ��� ���̸� ��ȯ�մϴ�.
/// 'string.h'�� �Ȱ��� ������ �ϴ� 'strlen()'�� ������, ���� ����� ���ҽ��ϴ�.
/// 'size_t'�� 'unsigned long long' �ڷ����� ����� ���ǵ� ������, ���� ����� �ʾ����� ���Ǹ� ���� ����Ͽ����ϴ�.
/// </summary>
/// <param name="str">���̸� �˰� ���� ���ڿ�.</param>
/// <returns>���ڿ��� ����</returns>
size_t get_string_length(char* str)
{
	// ī���� ���� �� �ʱ�ȭ.
	int count = 0;
	// �� ����(\0)�� ���� ������ ī���͸� �ø��ϴ�.
	while (*(str++) != '\0') { ++count; }

	// ���������� ���� ī���͸� ��ȯ�մϴ�.
	return count;
}

/// <summary>
/// ���ڿ��� �������� ����մϴ�.
/// </summary>
/// <param name="str">�������� ����� ���ڿ�.</param>
void print_reverse(char* str)
{
	for (int i = get_string_length(str); i >= 0; --i)
		putchar(str[i]);

	return;
}

int main(void)
{
	printf("���Ӱ��а� 2023180030 ������ #1 (��¸� �������� �ϱ�)\n\n");

	// ���ڿ� ���� ���� �� �⺻ �ʱ�ȭ.
	// �⺻������ ���ڿ��� ��� ���Ҵ� 'NULL'�� �ʱ�ȭ�մϴ�.
	char str[MAX_STRING_LENGTH] = { NULL };

	// ���ڿ� �Է��� ���� ���ϰ� �ϱ� ���� 'gets()'�� ����Ͽ����ϴ�.
	gets(str);

	// ���ڿ��� �������� ����մϴ�.
	print_reverse(str);

	return 0;
}