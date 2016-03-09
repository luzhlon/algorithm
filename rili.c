#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int g_base_year  = 2016; // 某年
int g_base_month = 3;    // 某月
int g_base_day   = 7;    // 某日
int g_base_week  = 1;    // 星期某

// 计算星期w偏移n天后为星期几
int week_by_offset(int w, int n) {
    return ((w + n) % 7 + 7) % 7;
}

// 判断y年是否为闰年
int is_leap_year(int y) {
    if(y % 4)            // 不能被4整除
        return 0;
    if(y % 100)          // 不能被100整除
        return 1;
    else                 // 能被100整除
        if(y % 400)      // 不能被400整除
            return 0;
        else
            return 1;
}

// 获取一年的月份列表
// 索引范围为0-11
int* get_months(int y) {
    static int common[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    static int leap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return is_leap_year(y) ? leap : common;
}

// 计算第一天为星期几
// m的范围为1-12
int first_day_of_year(int y, int m, int d, int w) {
    int *months = get_months(y);
    int days = 0;
    for(int i = 0; i < m - 1 && i < 12; i++)
        days += months[i];
    days += d - 1;
    return week_by_offset(w, -days);
}

// 计算b年和o年之间的闰年数
int get_leap_year_num(int b, int o) {
    if(b == o)
        return 0;
    // b年和o年中间夹着的年数
    int n = abs(o - b) - 1;
    return n/4 - n/100 + n/400 + (o > b ? is_leap_year(b) : is_leap_year(o));
}

// 计算o年相对于b年偏移的天数
int get_offset_day_num(int b, int o) {
    int leaps = get_leap_year_num(b, o);
    int years = abs(o - b);
    int days = (years - leaps) * 365 + leaps * 366;
    return o > b ? days : -days;
}

// 打印y年的日历
void print_calendar(int y, int first) {
    int *months = get_months(y);
    int f = first;

    for(int i = 1; i <= 12; i++) {
        printf("----------------------%d 月-----------------------\n", i);
        puts("日\t一\t二\t三\t四\t五\t六");
        for(int j = 0; j < f; j++)
            putchar('\t');
        for(int m = months[i-1], j = 1; j <= m; j++, f=(f+1)%7) {
            printf("%d\t", j);
            if(f == 6) printf("\n");
        }
        printf("\n");
    }
}

int main() {
    int target_year,  // 目标年，就是要输出日历的那一年
        offset_days,  // 与基准年的第一天偏移的天数
        base_day,     // 基准年第一天为星期几
        first_day;    // 目标年的第一天是周几

    scanf("%d", &target_year); // 输入目标年

    base_day = first_day_of_year(g_base_year, g_base_month, g_base_day, g_base_week);
    // 偏移天数
    offset_days = get_offset_day_num(g_base_year, target_year);
    // 目标年第一天
    first_day = week_by_offset(base_day, offset_days);

    print_calendar(target_year, first_day);

    return 0;
}
