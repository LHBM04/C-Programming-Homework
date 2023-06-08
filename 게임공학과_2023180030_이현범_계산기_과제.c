/*
*	게임공학과 2023180030 이현범
*		  [계산기 실습]
*/

#include <stdio.h>

// 사전에 프로젝트 속성 SDL 검사를 비활성화하였습니다. 
int main()
{
	// 피연산자 변수를 두 개 선언, 초기화합니다.
	int lhs = NULL;
	int rhs = NULL;

	// 연산자 변수를 선언, 초기화합니다.
	char opr = NULL;

	// 수식을 입력받습니다.
	printf("수식을 입력해주세요... (예: 2 + 3)\n");
	scanf("%d %c %d", &lhs, &opr, &rhs);

	int result = NULL;
	switch (opr)
	{
	// 일반적인 사칙연산의 경우
	case '+':															
		printf("%d %c %d의 결과는 %d입니다...", lhs, opr, rhs, lhs + rhs);
		break;
	case '-':
		printf("%d %c %d의 결과는 %d입니다...", lhs, opr, rhs, lhs - rhs);	
		break;	
	case '/':
		printf("%d %c %d의 결과는 %d입니다...", lhs, opr, rhs, lhs / rhs);	
		break;
	case '%':
		printf("%d %c %d의 결과는 %d입니다...", lhs, opr, rhs, lhs % rhs);	
		break;
	// 비트 연산의 경우, 입력값과 결과값을 16진수와 10진수 모두 표기하도록 했습니다.
	case '&':
		printf("%d(%#x) %c %d(%#x)의 결과는 %d(%#x)입니다...",		lhs, lhs, 
																opr, 
																rhs, rhs, 
																(result = (lhs & rhs)), result);
		break;
	case '|':
		printf("%d(%#x) %c %d(%#x)의 결과는 %d(%#x)입니다...",		lhs, lhs,
																opr,
																rhs, rhs, 
																(result = (lhs | rhs)), result);
		break;
	case '^':
		printf("%d(%#x) %c %d(%#x)의 결과는 %d(%#x)입니다...",		lhs, lhs,
																opr,
																rhs, rhs, 
																(result = (lhs ^ rhs)), result);
		break;
	default:
		printf("올바르지 않은 수식입니다!");
		break;
	}
}