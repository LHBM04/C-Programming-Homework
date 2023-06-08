/*
*	게임공학과 2023180030 이현범
*		    [로또 번호]
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 배열의 최대 크기를 의미하는 매크로 상수.
#define MAX_ARRAY_SIZE 6

// 복권 난수 생성 최소 ~ 최대 범위,
#define MIN_LOTTO_RANGE 1
#define MAX_LOTTO_RANGE 45

// 에러 메시지를 의미하는 매크로 함수.
#define PRINT_ERROR_MESSAGE printf("[Error!!] 이미 이전에 생성되었던 수입니다. 다시 생성합니다...\n")

/// <summary>
/// 1 ~ 45사이의 난수를 6개 생성하여, 이를 배열에 넣습니다.
/// 이미 기존 배열에 들어가 있던 수일 경우, 다시 생성합니다.
/// </summary>
/// <param name="lotto_nums">초기화할 배열.</param>
void input_nums(int*);

/// <summary>
/// 배열을 출력합니다.
/// </summary>
/// <param name="lotto_nums">출력할 배열.</param>
void print_nums(int*);

int main(void) 
{
	printf("게임공학과 2023180030 이현범 [로또 번호]\n\n");

	// 배열 선언 및 초기화.
	int lotto_nums[MAX_ARRAY_SIZE] = { NULL };

	// 입출력 함수 호출.
	input_nums(lotto_nums);
	print_nums(lotto_nums);
	
	return 0;
}

void input_nums(int* _lotto_nums)
{
	srand((unsigned)time(NULL));

	// 배열의 최대 사이즈(6) 만큼 반복문을 돕니다.
	int count = 0;
	while (count != MAX_ARRAY_SIZE)
	{
		// 1 ~ 45 사이의 난수를 발생.
		_lotto_nums[count] = rand() % MAX_LOTTO_RANGE + MIN_LOTTO_RANGE;

		// 만약 이미 배열에 포함된 수라면, 처음으로 돌아간다.
		for (int count2 = 0; count2 < count; ++count2)
		{
			if (_lotto_nums[count2] == _lotto_nums[count])
			{
				PRINT_ERROR_MESSAGE;
				continue;
			}
		}

		++count;
	}
}

void print_nums(int* _lotto_nums)
{
	for (int idx = 0; idx < MAX_ARRAY_SIZE; ++idx)
		printf("%d ", _lotto_nums[idx]);
}