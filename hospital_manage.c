#include <stdio.h>
#include <string.h>
#define max 1
void show_patient(char (*ptr)[7][20], int Sno);
void show_list(char (*ptr)[7][20], int size);
void add_patient(char (*ptr)[7][20], char pt_info[7], int size);
void remove_patient();
int main()
{
    int i, num;
    int size = 1;
    char list[max][7][20] = {{"S_No", "Name", "Age", "B_Group", "height", "weight", "bmi"}};
    char (*ptr)[7][20] = list;

main_menu:
{
    scanf("%d", &i);
    switch (i)
    {
    case 1:
        show_list(ptr, size);
        goto main_menu;
    case 2:
        scanf("%d", &num);
        show_patient(ptr, num);
        goto main_menu;
    case 3:
        size++;
        char S_No[20], Name[20], Age[20], B_Group[20];
        float height, weight, bmi;
        printf("Enter S_no");
        scanf("%s", &S_No);
        printf("Enter Name");
        scanf("%s", &Name);
        printf("Enter Age");
        scanf("%s", &Age);
        printf("Enter Blood Group");
        scanf("%s", &B_Group);
        printf("Enter Height(cm)");
        scanf("%f", &height);
        printf("Enter Weight(kg)");
        scanf("%f", &weight);
        bmi = weight * 10000 / height * height;
        char pt_inf[7] = {S_No, Name, Age, B_Group, height, weight, bmi};
        add_patient(list, pt_inf, size);

    default:
        goto main_menu;
    }
}
}
void show_list(char (*ptr)[7][20], int size)
{
    int i, j;
    for (i = 0; i < size; i++)
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
        printf("%s", ptr[Sno][i]);
    }
}
void add_patient(char (*ptr)[7][20], char pt_info[7], int size)
{
    int i, j;
    for (j = 0; j < 7; j++)
    {
        strcpy(ptr[size][j], pt_info[j]);
    }
}