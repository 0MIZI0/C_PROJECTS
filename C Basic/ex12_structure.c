#include <stdio.h>

struct date {
    int month;
    int day;
    int year;
};

struct date getTomorrowDate(struct date today);
int numberOfDays(struct date d);
int isLeapYear(struct date d);

int daysPerMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

int main()
{
    struct date today, tomorrow;

    printf("Enter date(mm dd yyyy): ");
    scanf("%d %d %d", &today.month, &today.day, &today.year);

    tomorrow = getTomorrowDate(today);
    printf("tomorrow's date is %d/%d/%d\n", tomorrow.month, tomorrow.day, tomorrow.year);

    return 0;
}

// 내일 날짜 반환 함수
struct date getTomorrowDate(struct date today) {
    struct date tomorrow;

    if (today.day != numberOfDays(today)) {   // 월의 마지막날이 아닌 경우
        tomorrow.day = today.day + 1;
        tomorrow.month = today.month;
        tomorrow.year = today.year;
    }
    else if (today.month == 12 && today.day == numberOfDays(today))  {                       // 월의 마지막날 && 연도의 마지막날인 경우
        tomorrow.day = 1;
        tomorrow.month = 1;
        tomorrow.year = today.year + 1;
    }
    else {                                              // 월의 마지막날인 경우
        tomorrow.day = 1;
        tomorrow.month = today.month + 1;
        tomorrow.year = today.year;
    }
}

// 월 일수 반환 함수 => 2월이고 윤년인 경우 29 반환, 평년인 경우 월별 일 수 반환
int numberOfDays(struct date d)
{
    if(d.month==2&&isLeapYear(d)) return 29;
    return daysPerMonth[d.year-1];
}

// 윤년 체크 함수 => 윤년이면 1, 평년이면 0 반환
int isLeapYear(struct date d) {
    return d.year%4?0:1;
}