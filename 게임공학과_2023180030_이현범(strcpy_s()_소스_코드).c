/*
*   [strcpy_s()�� ��� ����]
*
*   ���Ӱ��а� 2023180030 ������
*   2023�� 3�� 25��
*/

#include <stdio.h>
// strcpy_s() �Լ��� ����ϱ� ���ؼ��� �ش� ����� �ݵ�� �����ؾ� �մϴ�.
#include <string.h>

#define BUFFERSIZE 256

int main()
{
	printf("%s\n\n", "���Ӱ��а� 2023180030 ������");

	// ������ ���ڿ��� �ٿ� ���� ����.
	// ���÷� "Test String!"�̶�� ���ڿ��� �ʱ�ȭ�߽��ϴ�.
	char destination[BUFFERSIZE]	= { "Test String!" };

	// ������ ���ڿ�. 
	// ���÷� "Hello, World!"�� �ʱ�ȭ�߽��ϴ�.
	char origin[BUFFERSIZE]			= { "\"Hello, World!\"" };

	// strcpy_s() ������ destination�� ���� ����غ��ڽ��ϴ�.
	// ���� ���� + �ٿ��ֱ⸦ ���� ���� destination�� ���� �Ҵ簪�� "Test String!"�� ���������� ��µ˴ϴ�.
	printf("Before: %s\n", destination);

	// strcpy_s() �Լ��� ���� destinaition�� origin�� ���� + �ٿ��ֱ⸦ �غ��ڽ��ϴ�.
	// ���ʴ�� '�ٿ� ���� ����', '������ ���ڿ��� ������', '�ٿ� ���� ���ڿ�'�� �Ű������� �ް� �ֽ��ϴ�.
	strcpy_s(destination, sizeof(destination), origin);

	// ����ϸ�, ���������� destination ������ "Hello, World!" ���ڿ��� ���� + �ٿ��ֱⰡ �� ���� �� �� �ֽ��ϴ�.
	printf("After: %s\n", destination);
}