/*
*	[게임공학과 2023180030 이현범]
*		   [영화관 예약]
*/
#include <stdio.h>

// 영화관 좌석 수.
#define MAX_SEATS_COUNT 10
// 예약된 상태를 의미하는 매크로 상수.
#define TICKECTED 1
// 예약되지 않은 상태를 의미하는 매크로 상수.
#define NONTICKETED 0

int main(void)
{
	printf("게임공학과 2023180030 이현범\n\n");

	char action;
	printf("좌석을 예약하시겠습니까?(y/n) ===>> ");

	// 입력은 오직 'y/Y' 또는 'n/N'만 받을 수 있습니다.
	do
	{
		action = (char)getchar();

		if (action == 'y' || action == 'Y')
			break;
		else if (action == 'N' || action == 'n')
			return 0;
		else
		{
			printf("올바르지 않은 입력입니다. 다시 입력해 주세요. ===>> ");
			continue;
		}
	} while (1);

	int memberCount = 1;
	int result = 0;
	// 좌석들은 기본적으로 전부 예약되지 않은 상태로 초기화됩니다.
	int seats[MAX_SEATS_COUNT] = { NONTICKETED };

	printf("몇 명이나 예약하시겠습니까? ===>> ");

	// 숫자 이외의 입력은 받지 않습니다.
	do
	{
		result = scanf("%d", &memberCount);

		if (result != 1)
		{
			printf("올바르지 않은 입력입니다. 다시 입력해 주세요. ===>> ");

			while (getchar() != '\n');
			continue;
		}
		else
		{
			// 1보다 적은 인원은 입력받지 않습니다.
			if (memberCount < 1)
			{
				printf("올바르지 않은 입력입니다. 다시 입력해 주세요. ===>> ");
				continue;
			}
			else
			{
				break;
			}
		}
	} while (1);

	// 입력받은 인원 만큼 for문을 돕니다.
	for (int curMemberCount = 0; curMemberCount < memberCount; ++curMemberCount)
	{
		printf("-------------------------------\n");
		for (int number = 1; number <= MAX_SEATS_COUNT; ++number)
			// 이미 예매된 자리는 "(예)"라는 메시지가 함께 출력됩니다.
			printf((seats[number - 1] == NONTICKETED ? "%d " : "%d(예) "), number);
		printf("\n-------------------------------\n");
		// 첫 번째로 예매할 때와 그 다음 예매할 때의 메시지가 다릅니다.
		printf(curMemberCount == 0 ?	"예매할 좌석의 번호를 입력해 주세요. ===>> " :
										"다음 예매할 좌석의 번호를 입력해 주세요. ===>> ");

		while (1)
		{
			int seatNumber = 0;
			scanf("%d", &seatNumber);

			// 올바르지 않은 번호나, 이미 예약된 좌석의 번호는 입력받지 않습니다.
			if (seatNumber <= 0 || seatNumber > MAX_SEATS_COUNT)
			{
				printf("올바르지 않은 좌석 번호입니다. 다시 입력해 주세요. ===>> ");
				continue;
			}
			else if (seats[seatNumber - 1] == TICKECTED)
			{
				printf("이미 예약된 자리입니다. 다시 입력해 주세요. ===>> ");
				continue;
			}
			else
			{
				seats[seatNumber - 1] = TICKECTED;
				printf("예약되었습니다!\n");
				break;
			}
		}
	}
}