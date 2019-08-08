/*************************************************************************
*                                                                        *
* Problem :                                                              *
* 약수의 합 구하기                                                       *
*                                                                        *
*************************************************************************/
/*************************************************************************
*                                                                        *
* 국민대학교 전자정보통신대학 컴퓨터공학부 1 학년                        *
* 20153183 박호준                                                        *
*                                                                        *
*************************************************************************/

#define _crt_secure_no_warnings
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *in_file;
	int i, j;
	int no_cases, no_data;
	int cnt, sum;

	in_file = fopen("input.txt", "r"); /*파일 열기*/
	if (in_file == NULL) exit(1);/*빈 파일일시 끝내기*/

	fscanf(in_file, "%d", &no_cases); /*케이스개수 받기*/

	for (i = 0; i < no_cases; i++)/*케이스 갯수만큼 코드 실행*/
	{
		fscanf(in_file, "%d", &no_data);
		
		sum = 1;//약수에 모두 1이 포함되므로 1로 초기화
		cnt = 1;//약수에 모두 1이 포함되므로 카운트도 1부터 시작

		for (j = 2; j*j <= no_data; j++) {//1을 모두 포함시키니 j=2부터 시작
			                              //제곱수로 해서 시작하면 프로그램 시간절약 가능
			if (no_data%j == 0) {         //ndata나누기j의 나머지가 0일때
				cnt += 2;                 //카운트는 2씩 증가(j,그리고 data나누기j 카운트 모두 더해줘야함)
				sum = j+sum+(no_data/j); //기존의 sum과 j,그리고 data값 나누기j 값을 모두 더해줘야 약수의 합이 나옴.
			}
		}
		printf("%d %d\n", cnt, sum);  //(보통 출력함, 케이스 갯수만큼 코드실행 포문 안에 있는거라서 케이스갯수만큼 출력됨)

	}
	fclose(in_file);
	return 0;
}