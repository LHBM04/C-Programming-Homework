/*
*	게임공학과 2023180030 이현범
*	[문자열 역순으로 출력하기(동적 메모리 접근을 통한 문자열 역순으로 재배치)]
*/

#include <stdio.h>
// 메모리 접근을 위해 해당 헤더를 사용하였습니다.
#include <stdlib.h>
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
/// 매개변수로 들어온 문자열을 역순으로 재배치한 문자열을 반환합니다.
/// </summary>
/// <param name="str">역순으로 재배치할 문자열.</param>
void reverse_string(char* str)
{
	// 매개변수로 받은 문자열의 길이를 가져옵니다.
	int length = get_string_length(str);

	// malloc()을 통하여 매개변수로 들어온 문자열의 길이만큼 메모리를 새로 할당합니다. 
	// malloc()은 반환형이 void 포인터기 때문에 반드시 포인터 변수의 자료형으로 캐스팅 해주어야 합니다.
	char* temp_str = (char*)malloc((sizeof(char) * length));
	
	// for문을 돌며, temp_str에 매개변수로 받은 문자열의 끝부분부터 처음부분까지 넣습니다.
	for (int idx = 0; idx < length; ++idx)
		temp_str[idx] = str[length - (idx + 1)];

	// memcpy()를 통해 temp_str을 매개변수로 받은 문자열에 복사합니다.
	memcpy(str, temp_str, length);

	// 본래 로컬 변수는 '스택' 영역에 할당이 되지만, malloc을 통한 동적 메모리 할당은 '힙' 영역에 할당됩니다.
	// 이렇게 힙 영역에 할당된 메모리는 free()를 사용하여 직접 해제해 주어야 합니다.
	free(temp_str);
}

int main(void)
{
	printf("게임공학과 2023180030 이현범 #3 (동적 메모리 접근을 통한 문자열 역순으로 재배치)\n\n");

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