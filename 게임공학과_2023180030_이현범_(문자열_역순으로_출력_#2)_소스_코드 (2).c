/*
*	게임공학과 2023180030 이현범
*	[문자열 역순으로 출력하기(Swap 알고리즘을 통한 문자열 역순으로 재배치)]
*/

#include <stdio.h>

// 문자열의 최대 길이를 의미하는 매크로 상수.
#define MAX_STRING_LENGTH 100

/// <summary>
/// 문자열의 길이를 반환합니다.
/// 'string.h'에 똑같은 역할을 하는 'strlen()'이 있으나, 직접 만들어 보았습니다.
/// 'size_t'는 'unsigned long long' 자료형이 사용자 정의된 것으로, 아직 배우진 않았지만 편의를 위해 사용하였습니다.
/// </summary>
/// <param name="str">길이를 알고 싶은 문자열.</param>
/// <returns>문자열의 길이</returns>
size_t get_string_length(char* str)
{
	// 카운터 선언 및 초기화.
	int count = 0;
	// 널 문자(\0)이 나올 때까지 카운터를 올립니다.
	while (*(str++) != '\0') { ++count; }

	// 최종적으로 쌓인 카운터를 반환합니다.
	return count;
}

/// <summary>
/// 문자열을 역순으로 재배치합니다.
/// </summary>
/// <param name="str">역순으로 재배치할 문자열.</param>
/// <returns>역순으로 재배치된 문자열.</returns>
char* reverse_string(char* str)
{
	// 매개변수로 받은 문자열의 길이를 가져옵니다.
	int length = get_string_length(str);

	// 해당 길이의 절반만큼 for문을 순환합니다.
	for (int idx = 0; idx < length / 2; ++idx)
	{
		// 문자열의 양 끝부터 시작해서 서로 바꾸어 줍니다.
		// (예: "Hello!" => 0번쨰 <=> 5, 1번째 <=> 4번째 ...)
		// 홀수일 경우엔 마지막으로 남는 문자는 그대로 놔둡니다.
		char temp = str[idx];
		str[idx] = str[length - (idx + 1)];
		str[length - (idx + 1)] = temp;
	}

	// 역순으로 재배치한 문자열을 리턴합니다.
	return str;
}

int main(void)
{
	printf("게임공학과 2023180030 이현범 #2 (Swap 알고리즘을 통한 문자열 역순으로 재배치)\n\n");

	// 문자열 변수 선언 및 기본 초기화.
	// 기본적으로 문자열의 모든 원소는 'NULL'로 초기화합니다.
	char str[MAX_STRING_LENGTH] = { NULL };

	// 문자열 입력을 보다 편하게 하기 위해 'gets()'를 사용하였습니다.
	gets(str);

	// 문자열을 역순으로 재배치합니다.
	reverse_string(str);

	// 문자열 출력.
	puts(str);

	return 0;
}