/*
*   [scanf_s()의 사용 예시]
* 
*   게임공학과 2023180030 이현범
*   2023년 3월 25일
*/

#include <stdio.h>

#define BUFFERSIZE 256

int main()
{
	printf("%s\n\n", "게임공학과 2023180030 이현범");

#pragma region 일반적인 경우
	/*----일반적인 경우(10진수 정수)----*/

	printf("예제 #1: 10진수 정수 입력 받기.\n");

	// 10진수 정수를 담을 변수입니다.
	// 10진수 정수를 총 두 차례에 걸쳐 입력을 받아보겠습니다.
	// 두 예제 모두 공통적으로 '123'을 입력 받는다고 가정하겠습니다.
	int intValue = NULL;
	
	// 10진수 정수(int)에 받는 형식 지정자 '%d'를 매개변수로 넣어 입력을 받아보겠습니다.
	printf("intValue(Input): ");
	scanf_s("%d", &intValue);
	
	// 정상적으로 입력이 된 것을 볼 수 있습니다.
	printf("intValue(Output): %d\n\n", intValue);

	printf("예제 #2: 10진수 정수 입력 받기. (형식 지정자를 잘못 기입한 경우)\n");
	
	// 이번에는 입력 받을 변수의 데이터 타입과 일치하지 않는 형식 지정자를 기입하여 입력을 받아보겠습니다.
	// 실수형(4byte)의 형식 지정자를 기업하였습니다.
	printf("intValue(Input): ");
	scanf_s("%f", &intValue);
	
	// 정상적으로 입력 되지 않은 것을 볼 수 있습니다.
	printf("intValue(Output): %d\n\n", intValue);
#pragma endregion
#pragma region 문자열의 경우
	/*----문자열의 경우----*/

	printf("예제 #3: 문자열 입력 받기.\n");

	// 문자열을 담을 변수(char형 배열)입니다.
	// 이 예제에서는 두 차례에 걸쳐 문자열을 입력 받겠습니다.
	// 두 예제 모두 공통적으로 "Hello, World!"를 입력 받는다고 가정하겠습니다.
	char stringValue[BUFFERSIZE] = { NULL };

	// 문자열을 입력 받을 때에는 예외적으로 &(주소 연산자) 기입을 생략합니다.
	// 이 이유는 문자열 변수의 특성상, &(주소 연산자)를 기입하지 않아도 변수의 주소를 넘겨주기 때문입니다.
	// 또한, 앞의 경우와는 달리 추가적으로 '입력 받을 변수의 사이즈(버퍼)'도 매개변수로 받고 있습니다.
	printf("stringValue(Input): ");
	scanf_s("%s", stringValue, (unsigned int)sizeof(stringValue));

	// 입력은 되었으나, 공백 문자를 포함하지 않아 "Hello,"까지만 입력된 것을 볼 수 있습니다.
	printf("stringValue(Output): %s\n\n", stringValue);
	
	// 두 번째 예제에 들어가기 앞서, 입력 버퍼를 비워주고 전에 입력 받은 문자열 데이터를 지워줍니다.
	while (getchar() != '\n');
	for (size_t index = 0; index < sizeof(stringValue); ++index)
		stringValue[index] = NULL;

	printf("예제 #4: 문자열 입력 받기. (공백 문자까지 입력 받은 경우)\n");

	// 앞의 경우는 공백 문자(' ')가 입력될 경우에 입력을 종료합니다.
	// 이번에는 형식 지정자에 '%[^\n]'을 기입하여 엔터를 제외한 모든 문자의 입력을 받아, 공백 문자(' ')까지 입력을 받아보겠습니다.
	printf("stringValue(Input): ");
	scanf_s("%[^\n]", stringValue, (unsigned int)sizeof(stringValue));

	// 정상적으로 "Hello, World"가 입력된 것을 볼 수 있습니다.
	printf("stringValue(Output): %s\n\n", stringValue);
#pragma endregion
#pragma region 반환형의 경우
	/*----반환형의 경우----*/

	printf("예제 #5: scanf_s()의 반환값.\n");

	// scanf_s()를 통해 입력 받을 변수들입니다.
	// 이번 예제에서는 10진수 정수형(4byte)와 문자형 변수를 사용하겠습니다.
	// 각각 65와 'A'를 입력 받는다고 가정하겠습니다.
	int test1 = NULL;
	char test2 = NULL;

	// 형식 지정자의 개수를 받을 카운터 변수입니다.
	int cnt = NULL;
	
	// count 변수에 scanf_s()를 통해 입력 받을 변수들의 개수를 할당합니다.
	printf("Input(Integer, Character): ");
	cnt = scanf_s("%d %c", &test1, &test2);

	// count 변수에 정상적으로 입력 받은 변수들의 개수(2개)가 할당된 것을 볼 수 있습니다.
	printf("Count(Output): %d", cnt);
#pragma endregion
}