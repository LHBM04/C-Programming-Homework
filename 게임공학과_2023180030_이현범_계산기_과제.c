/*
*	���Ӱ��а� 2023180030 ������
*		  [���� �ǽ�]
*/

#include <stdio.h>

// ������ ������Ʈ �Ӽ� SDL �˻縦 ��Ȱ��ȭ�Ͽ����ϴ�. 
int main()
{
	// �ǿ����� ������ �� �� ����, �ʱ�ȭ�մϴ�.
	int lhs = NULL;
	int rhs = NULL;

	// ������ ������ ����, �ʱ�ȭ�մϴ�.
	char opr = NULL;

	// ������ �Է¹޽��ϴ�.
	printf("������ �Է����ּ���... (��: 2 + 3)\n");
	scanf("%d %c %d", &lhs, &opr, &rhs);

	int result = NULL;
	switch (opr)
	{
	// �Ϲ����� ��Ģ������ ���
	case '+':															
		printf("%d %c %d�� ����� %d�Դϴ�...", lhs, opr, rhs, lhs + rhs);
		break;
	case '-':
		printf("%d %c %d�� ����� %d�Դϴ�...", lhs, opr, rhs, lhs - rhs);	
		break;	
	case '/':
		printf("%d %c %d�� ����� %d�Դϴ�...", lhs, opr, rhs, lhs / rhs);	
		break;
	case '%':
		printf("%d %c %d�� ����� %d�Դϴ�...", lhs, opr, rhs, lhs % rhs);	
		break;
	// ��Ʈ ������ ���, �Է°��� ������� 16������ 10���� ��� ǥ���ϵ��� �߽��ϴ�.
	case '&':
		printf("%d(%#x) %c %d(%#x)�� ����� %d(%#x)�Դϴ�...",		lhs, lhs, 
																opr, 
																rhs, rhs, 
																(result = (lhs & rhs)), result);
		break;
	case '|':
		printf("%d(%#x) %c %d(%#x)�� ����� %d(%#x)�Դϴ�...",		lhs, lhs,
																opr,
																rhs, rhs, 
																(result = (lhs | rhs)), result);
		break;
	case '^':
		printf("%d(%#x) %c %d(%#x)�� ����� %d(%#x)�Դϴ�...",		lhs, lhs,
																opr,
																rhs, rhs, 
																(result = (lhs ^ rhs)), result);
		break;
	default:
		printf("�ùٸ��� ���� �����Դϴ�!");
		break;
	}
}