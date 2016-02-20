#include "func.h"

int main()
{
    int day = 0, month = 0, year = 0;
    int day_of_week = 0;
    int days_in_month = 0;
    int number_of_weeks = 0;
    int i = 0, j = 0;

    while(1){
        scanf("%u %u %u", &day, &month, &year);

        day_of_week = find_day_of_week(day, month, year);
        days_in_month = days_Month(month, year);


        for (i = 1; i < 7; i++){
            print_name_of_day(i);
            print_space_if_need(i, month, year);
            for (j = 1; j < days_in_month + 1; j++){
                if (i == find_day_of_week(j, month, year)){
                    print_number_of_day(j, day, days_in_month);
                }
            }
            printf("\n");
        }

        print_name_of_day(0);
        print_space_if_need(0, month, year);
        for (j = 1; j < days_in_month + 1; j++){
            if (0 == find_day_of_week(j, month, year)){
                print_number_of_day(j, day, days_in_month + 1);
            }
        }
        printf("\n\n");
    }

    return 0;
}

void print_space_if_need(int cur_day_of_week, int month, int year){
    int first_day = find_day_of_week(1, month, year);
    if (cur_day_of_week == 0) cur_day_of_week = 7;
    if (first_day == 0) first_day = 7;

    if (cur_day_of_week < first_day) printf(".....");
}

void print_number_of_day(int day, int cur_day, int days_in_month){
    printf(".");
    if (day < 10){
        if (day == cur_day){
            printf("[.%d]", day);
        }
        else {
            printf("..%d", day);
        }
    }
    else {
        if (day == cur_day){
            printf("[%d]", day);
        }
        else {
            printf(".%d", day);
        }
    }
    if (day + 7 <= days_in_month & day != cur_day) printf(".");
}

void print_name_of_day(int day){
    switch(day){
    case 1:
        printf("mon");
        break;
    case 2:
        printf("tue");
        break;
    case 3:
        printf("wed");
        break;
    case 4:
        printf("thu");
        break;
    case 5:
        printf("fri");
        break;
    case 6:
        printf("sat");
        break;
    case 0:
        printf("sun");
        break;
    }
}
