#include <stdio.h>
#include <string.h>
#define max 1
void show_patient(char (*ptr)[7][20], int Sno);
void show_list(char (*ptr)[7][20], int size);
void add_patient(char (*ptr)[7][20], char pt_info[7][20], int size);
void remove_patient(char (*ptr)[7][20], int S_no, int size);
int main()
{
    int i, num;
    int size = 1;
    char list[max][7][20] = {{"S_No", "Name", "Age", "B_Group", "height", "weight", "bmi"}};
    char (*ptr)[7][20] = list;
    int s_no;
    printf("Welcome to hospital management system By Zen\n");

main_menu:
{
    printf("You are on The main menu Please select an option\n1)Show list\n2)show a specific patient\n3)add a patient\n4)remove a patient\n5)exit\n");
    scanf("%d", &i);
    switch (i)
    {
    case 1:
        show_list(ptr, size);
        goto main_menu;
    case 2:
        printf("Enter S_no of the patient");
        scanf("%d", &num);
        show_patient(ptr, num);
        goto main_menu;
    case 3:
        printf("Enter detals of the patient.\n");
        size++;
        char S_No[20], Name[20], Age[20], B_Group[20];
        float height, weight, bmi;
        printf("Enter S_no\n");
        scanf("%s", S_No);
        printf("Enter Name\n");
        scanf("%s", Name);
        printf("Enter Age\n");
        scanf("%s", Age);
        printf("Enter Blood Group\n");
        scanf("%s", B_Group);
        printf("Enter Height(cm)\n");
        scanf("%f", &height);
        printf("Enter Weight(kg)\n");
        scanf("%f", &weight);
        bmi = weight * 10000 / (height * height);
        char pt_inf[7][20];
        sprintf(pt_inf[0], "%s", S_No);
        sprintf(pt_inf[1], "%s", Name);
        sprintf(pt_inf[2], "%s", Age);
        sprintf(pt_inf[3], "%s", B_Group);
        sprintf(pt_inf[4], "%.2f", height);
        sprintf(pt_inf[5], "%.2f", weight);
        sprintf(pt_inf[6], "%.2f", bmi);
        add_patient(list, pt_inf, size);
        show_list(ptr, size);
        goto main_menu;
    case 4:
        printf("Enter S_no of the ");
        scanf("%d", &s_no);
        remove_patient(ptr, s_no, size);
    case 5:
        break;
    default:
        printf("Error Try again");
        goto main_menu;
    }
}
}
void show_list(char (*ptr)[7][20], int size)
{
    int i, j;
    for (i = 0; i < size + 1; i++)
    {
        for (j = 0; j < 7; j++)
        {
            printf("%s\t", ptr[i][j]);
        }
        printf("\n");
    }
}
void show_patient(char (*ptr)[7][20], int Sno)
{
    int i;
    for (i = 0; i < 7; i++)
    {
        printf("%s\t", ptr[Sno][i]);
    }
}
void add_patient(char (*ptr)[7][20], char pt_info[7][20], int size)
{
    int i, j;
    for (j = 0; j < 7; j++)
    {
        strcpy(ptr[size][j], pt_info[j]);
    }
}
void remove_patient(char (*ptr)[7][20], int S_no, int size)
{
    int i, j;
    for (i = S_no; i < size + 1;)
    {
        for (j = 0; j < 7; j++)
            ;
        {
            strcpy(ptr[i][j], ptr[i + 1][j]);
        }
    }
    size--;
}