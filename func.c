#include "func.h"
                             // число, день кот найти / текущее число / текущий день недели
int find_day_of_week_from_another_day(int find_day, int current_day, int current_day_of_week){
    return (current_day_of_week + 7 + (find_day - current_day) % 7) % 7;
}

int find_day_of_week(int day, int month, int year){
    int past_months = 0; // for days, that past from start of year
    int past_years = 0; // for days, that past from 0 c.e.
    int prev_year = year - 1;
    int i;
    for(i = 0; i < month - 1; i++){
        past_months += days_Month(i + 1, year);
    }
    past_years = prev_year / 4 + prev_year / 400 - prev_year / 100;
    return (past_years + prev_year * 365 + past_months + day) % 7;
}

int days_Month(int month, int year){
    if (is_Leap_Year(year) & month == 2)
        return 29 + (month + month/8) % 2 + 2 % month + 2 * (1/month);

    else return 28 + (month + month/8) % 2 + 2 % month + 2 * (1/month);
}

int is_Leap_Year(int year){
    return (year%100 == 0) ? (year%400 == 0) : (year%4 == 0);
}
