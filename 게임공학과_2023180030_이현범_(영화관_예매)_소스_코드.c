/*
*	[���Ӱ��а� 2023180030 ������]
*		   [��ȭ�� ����]
*/
#include <stdio.h>

// ��ȭ�� �¼� ��.
#define MAX_SEATS_COUNT 10
// ����� ���¸� �ǹ��ϴ� ��ũ�� ���.
#define TICKECTED 1
// ������� ���� ���¸� �ǹ��ϴ� ��ũ�� ���.
#define NONTICKETED 0

int main(void)
{
	printf("���Ӱ��а� 2023180030 ������\n\n");

	char action;
	printf("�¼��� �����Ͻðڽ��ϱ�?(y/n) ===>> ");

	// �Է��� ���� 'y/Y' �Ǵ� 'n/N'�� ���� �� �ֽ��ϴ�.
	do
	{
		action = (char)getchar();

		if (action == 'y' || action == 'Y')
			break;
		else if (action == 'N' || action == 'n')
			return 0;
		else
		{
			printf("�ùٸ��� ���� �Է��Դϴ�. �ٽ� �Է��� �ּ���. ===>> ");
			continue;
		}
	} while (1);

	int memberCount = 1;
	int result = 0;
	// �¼����� �⺻������ ���� ������� ���� ���·� �ʱ�ȭ�˴ϴ�.
	int seats[MAX_SEATS_COUNT] = { NONTICKETED };

	printf("�� ���̳� �����Ͻðڽ��ϱ�? ===>> ");

	// ���� �̿��� �Է��� ���� �ʽ��ϴ�.
	do
	{
		result = scanf("%d", &memberCount);

		if (result != 1)
		{
			printf("�ùٸ��� ���� �Է��Դϴ�. �ٽ� �Է��� �ּ���. ===>> ");

			while (getchar() != '\n');
			continue;
		}
		else
		{
			// 1���� ���� �ο��� �Է¹��� �ʽ��ϴ�.
			if (memberCount < 1)
			{
				printf("�ùٸ��� ���� �Է��Դϴ�. �ٽ� �Է��� �ּ���. ===>> ");
				continue;
			}
			else
			{
				break;
			}
		}
	} while (1);

	// �Է¹��� �ο� ��ŭ for���� ���ϴ�.
	for (int curMemberCount = 0; curMemberCount < memberCount; ++curMemberCount)
	{
		printf("-------------------------------\n");
		for (int number = 1; number <= MAX_SEATS_COUNT; ++number)
			// �̹� ���ŵ� �ڸ��� "(��)"��� �޽����� �Բ� ��µ˴ϴ�.
			printf((seats[number - 1] == NONTICKETED ? "%d " : "%d(��) "), number);
		printf("\n-------------------------------\n");
		// ù ��°�� ������ ���� �� ���� ������ ���� �޽����� �ٸ��ϴ�.
		printf(curMemberCount == 0 ?	"������ �¼��� ��ȣ�� �Է��� �ּ���. ===>> " :
										"���� ������ �¼��� ��ȣ�� �Է��� �ּ���. ===>> ");

		while (1)
		{
			int seatNumber = 0;
			scanf("%d", &seatNumber);

			// �ùٸ��� ���� ��ȣ��, �̹� ����� �¼��� ��ȣ�� �Է¹��� �ʽ��ϴ�.
			if (seatNumber <= 0 || seatNumber > MAX_SEATS_COUNT)
			{
				printf("�ùٸ��� ���� �¼� ��ȣ�Դϴ�. �ٽ� �Է��� �ּ���. ===>> ");
				continue;
			}
			else if (seats[seatNumber - 1] == TICKECTED)
			{
				printf("�̹� ����� �ڸ��Դϴ�. �ٽ� �Է��� �ּ���. ===>> ");
				continue;
			}
			else
			{
				seats[seatNumber - 1] = TICKECTED;
				printf("����Ǿ����ϴ�!\n");
				break;
			}
		}
	}
}