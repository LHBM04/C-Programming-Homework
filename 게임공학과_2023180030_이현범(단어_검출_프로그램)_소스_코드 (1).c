/*
*	게임공학과 2023180030 이현범
*		[단어 검출 프로그램]
*/
#include <stdio.h>
#include <string.h>

// 버퍼 사이즈.
// 모든 배열은 해당 사이즈를 가지며, 넉넉하게 256 정도로 잡았습니다.
#define BUFFER_SIZE 256

// 파일 구조체에 대한 참조 방식(읽기 전용).
#define READ_MODE "r"
// 파일 구조체에 대한 참조 방식(쓰기 전용).
#define WRITE_MODE "w"

/// <summary>
/// 참, 거짓을 의미하는 열거형.
/// </summary>
typedef enum
{
	FALSE	= 0,
	TRUE	= 1,
} BOOL;

/// <summary>
/// 두 문자열이 동일한지 비교합니다.
/// strcmp()와 달리 문자열의 동일 여부만 확인합니다.
/// </summary>
/// <param name="str1">비교할 문자열.</param>
/// <param name="str2">비교할 문자열.</param>
/// <returns>동일 여부.(참: 1, 거짓: 0)</returns>
enum BOOL compare_word(const char* _str1, const char* _str2)
{
	// 두 문자열의 끝부분까지 순환합니다.
	// 어느 한 문자열이 끝에 다다를 때까지 두 문자열을 비교합니다.
	while (*(_str1) != '\0' || *(_str2) != '\0')
		if (*(_str1++) != *(_str2++))
			return FALSE;

	return TRUE;
}

/// <summary>
/// 해당 문자열(단어)가 텍스트 파일 안에 있는지 확인합니다.
/// </summary>
/// <param name="word">찾을 문자열(단어).</param>
/// <param name="list">찾을 텍스트 파일.</param>
/// <returns></returns>
enum BOOL is_exist(const char* const _word, const FILE* _list)
{
	// ※ 예외 처리
	if (!_list)
		return FALSE;

	// 텍스트 파일로부터 문자열을 읽어오기 위한 버퍼 선언 및 초기화.
	char buffer[BUFFER_SIZE] = { NULL };

	// 파일의 처음부터 끝까지 훑으면서, 해당 문자열이 있는지 확인합니다.
	while (fgets(buffer, BUFFER_SIZE, _list))
		if (compare_word(_word, buffer))
			return TRUE;

	return FALSE;
}

/// <summary>
/// 지정 파일에 해당 단어를 작성합니다.
/// </summary>
/// <param name="word">저장할 문자열(단어).</param>
/// <param name="dest">문자열(단어)를 저장할 파일.</param>
void write_word(const char* const _word, const FILE* const _dest)
{
	// ※ 예외 처리
	if (!_dest)
		return;
	
	// fgets()는 개행 문자까지 가져오기 때문에 출력할 때는 이를 제외합니다.
	char temp[BUFFER_SIZE] = { NULL };
	strcpy(temp, _word);
	printf("\'%s\' 단어가 없는 것이 확인되었습니다. 해당 단어를 기록합니다...\n", strtok(temp, "\n"));

	// 마지막 단어일 때는 본래 개행 문자가 포함되지 않으므로 이를 제외합니다.
	fputs(_word, _dest);
}

int main(void)
{
	printf("게임공학과 2023180030 이현범 [단어 검출 프로그램]\n\n");

	// 단어 리스트 파일과 검색할 단어 파일, 결과 파일 구조체 변수를 선언합니다.
	FILE*	a_file,
		*	b_file,
		*	c_file;

	// 파일을 열 수 없으면, 오류 메세지와 함께 프로그램을 종료합니다.
	if (!(a_file = fopen("texts/a.txt", READ_MODE)) ||
		!(b_file = fopen("texts/b.txt", READ_MODE))	||
		!(c_file = fopen("texts/c.txt", WRITE_MODE)))
	{
		printf("파일의 경로가 잘못되었거나, 파일이 존재하지 않습니다.");
		return 0;
	}

	// 검색할 단어 파일로부터 문자열(단어)를 읽어오기 위한 버퍼 선언 및 초기화.
	char buffer[BUFFER_SIZE] = { NULL };

	// 검색할 단어 파일을 순차적으로 순환합니다.
	// 단어 리스트 파일 안에 검색할 단어가 포함되어 있는지 검사하고, 없다면 결과 파일에 해당 단어를 작성합니다.
	while (fgets(buffer, BUFFER_SIZE, b_file))
	{
		if (!is_exist(buffer, a_file))
			write_word(buffer, c_file);

		// 단어 리스트 파일의 접근 위치를 맨 처음으로 되돌립니다.
		fseek(a_file, 0, SEEK_SET);
	}

	// 열려 있는 파일을 모두 닫습니다.
	fclose(a_file);
	fclose(b_file);
	fclose(c_file);

	return 0;
}