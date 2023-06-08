/*
*   [strcpy_s()의 사용 예시]
*
*   게임공학과 2023180030 이현범
*   2023년 3월 25일
*/

#include <stdio.h>
// strcpy_s() 함수를 사용하기 위해서는 해당 헤더를 반드시 포함해야 합니다.
#include <string.h>

#define BUFFERSIZE 256

int main()
{
	printf("%s\n\n", "게임공학과 2023180030 이현범");

	// 복사한 문자열을 붙여 놓을 변수.
	// 예시로 "Test String!"이라는 문자열로 초기화했습니다.
	char destination[BUFFERSIZE]	= { "Test String!" };

	// 복사할 문자열. 
	// 예시로 "Hello, World!"로 초기화했습니다.
	char origin[BUFFERSIZE]			= { "\"Hello, World!\"" };

	// strcpy_s() 이전의 destination의 값을 출력해보겠습니다.
	// 아직 복사 + 붙여넣기를 하지 않은 destination의 본래 할당값인 "Test String!"이 정상적으로 출력됩니다.
	printf("Before: %s\n", destination);

	// strcpy_s() 함수를 통해 destinaition에 origin을 복사 + 붙여넣기를 해보겠습니다.
	// 차례대로 '붙여 놓을 변수', '복사할 문자열의 사이즈', '붙여 놓을 문자열'을 매개변수로 받고 있습니다.
	strcpy_s(destination, sizeof(destination), origin);

	// 출력하면, 정상적으로 destination 변수에 "Hello, World!" 문자열이 복사 + 붙여넣기가 된 것을 볼 수 있습니다.
	printf("After: %s\n", destination);
}