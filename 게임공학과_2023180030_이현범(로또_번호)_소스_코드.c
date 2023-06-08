/*
*	���Ӱ��а� 2023180030 ������
*		    [�ζ� ��ȣ]
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// �迭�� �ִ� ũ�⸦ �ǹ��ϴ� ��ũ�� ���.
#define MAX_ARRAY_SIZE 6

// ���� ���� ���� �ּ� ~ �ִ� ����,
#define MIN_LOTTO_RANGE 1
#define MAX_LOTTO_RANGE 45

// ���� �޽����� �ǹ��ϴ� ��ũ�� �Լ�.
#define PRINT_ERROR_MESSAGE printf("[Error!!] �̹� ������ �����Ǿ��� ���Դϴ�. �ٽ� �����մϴ�...\n")

/// <summary>
/// 1 ~ 45������ ������ 6�� �����Ͽ�, �̸� �迭�� �ֽ��ϴ�.
/// �̹� ���� �迭�� �� �ִ� ���� ���, �ٽ� �����մϴ�.
/// </summary>
/// <param name="lotto_nums">�ʱ�ȭ�� �迭.</param>
void input_nums(int*);

/// <summary>
/// �迭�� ����մϴ�.
/// </summary>
/// <param name="lotto_nums">����� �迭.</param>
void print_nums(int*);

int main(void) 
{
	printf("���Ӱ��а� 2023180030 ������ [�ζ� ��ȣ]\n\n");

	// �迭 ���� �� �ʱ�ȭ.
	int lotto_nums[MAX_ARRAY_SIZE] = { NULL };

	// ����� �Լ� ȣ��.
	input_nums(lotto_nums);
	print_nums(lotto_nums);
	
	return 0;
}

void input_nums(int* _lotto_nums)
{
	srand((unsigned)time(NULL));

	// �迭�� �ִ� ������(6) ��ŭ �ݺ����� ���ϴ�.
	int count = 0;
	while (count != MAX_ARRAY_SIZE)
	{
		// 1 ~ 45 ������ ������ �߻�.
		_lotto_nums[count] = rand() % MAX_LOTTO_RANGE + MIN_LOTTO_RANGE;

		// ���� �̹� �迭�� ���Ե� �����, ó������ ���ư���.
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