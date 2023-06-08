/*
*	���Ӱ��а� 2023180030 ������
*	[���ڿ� �������� ����ϱ�(Swap �˰����� ���� ���ڿ� �������� ���ġ)]
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
/// ���ڿ��� �������� ���ġ�մϴ�.
/// </summary>
/// <param name="str">�������� ���ġ�� ���ڿ�.</param>
/// <returns>�������� ���ġ�� ���ڿ�.</returns>
char* reverse_string(char* str)
{
	// �Ű������� ���� ���ڿ��� ���̸� �����ɴϴ�.
	int length = get_string_length(str);

	// �ش� ������ ���ݸ�ŭ for���� ��ȯ�մϴ�.
	for (int idx = 0; idx < length / 2; ++idx)
	{
		// ���ڿ��� �� ������ �����ؼ� ���� �ٲپ� �ݴϴ�.
		// (��: "Hello!" => 0���� <=> 5, 1��° <=> 4��° ...)
		// Ȧ���� ��쿣 ���������� ���� ���ڴ� �״�� ���Ӵϴ�.
		char temp = str[idx];
		str[idx] = str[length - (idx + 1)];
		str[length - (idx + 1)] = temp;
	}

	// �������� ���ġ�� ���ڿ��� �����մϴ�.
	return str;
}

int main(void)
{
	printf("���Ӱ��а� 2023180030 ������ #2 (Swap �˰����� ���� ���ڿ� �������� ���ġ)\n\n");

	// ���ڿ� ���� ���� �� �⺻ �ʱ�ȭ.
	// �⺻������ ���ڿ��� ��� ���Ҵ� 'NULL'�� �ʱ�ȭ�մϴ�.
	char str[MAX_STRING_LENGTH] = { NULL };

	// ���ڿ� �Է��� ���� ���ϰ� �ϱ� ���� 'gets()'�� ����Ͽ����ϴ�.
	gets(str);

	// ���ڿ��� �������� ���ġ�մϴ�.
	reverse_string(str);

	// ���ڿ� ���.
	puts(str);

	return 0;
}