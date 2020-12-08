#include <stdio.h>       
#include <string.h>       

struct struct_packed 
{
    int a;
    char b;
    int c;

}__attribute__((packed));

struct struct_aligned
{
    int a;
    char b;
    int c;
};

struct directory
{
    char second_name[20];
    char first_name[20];
    char number_phone[20];
    int key;
};

int key=0;


void Add_Directory(struct directory *dr)
{
    dr->key=key++;
    printf("Введите фимилию\n");
    fgets(dr->second_name, 20, stdin);
    printf("Введите имя\n");
    fgets(dr->first_name, 20, stdin);
    printf("Введите номер телефона\n");
    fgets(dr->number_phone, 20, stdin);
    printf("---------\n");

}

void Print_Directory(struct directory *dr, int count_dir)
{
    for(int i=0;i<count_dir;i++)
    {
    printf("\n");
    printf("id - %d\n", dr->key);
    printf("Фамилия - %s", dr->second_name);
    printf("Имя - %s",dr->first_name);
    printf("Номер телефона - %s",dr->number_phone);
    *dr++;
    }
    printf("---------\n");
}

void Delete_Directory(struct directory *dr, int key_dir)
{
    for(int i=key_dir;i<100;i++)
    {
    dr[i]=dr[i+1];
    }
    printf("удалено\n");
    printf("---------\n");
}

void Short_Print_Directory(struct directory dr)
{
    printf("\n");
    printf("id - %d\n", dr.key);
    printf("Фамилия - %s", dr.second_name);
    printf("Имя - %s",dr.first_name);
    printf("Номер телефона - %s",dr.number_phone);
}



void Search_dir(struct directory *dr, int choise_search, int count_dir)
{
    int flag=0;
    switch(choise_search)
    {
        case 1:
        printf("Введите фамилию для поиска\n");
        char second_name[20]={0};
        fgets(second_name, 20, stdin);
        for(int i=0;i<count_dir;i++)
        {
            if(strcmp(second_name,dr->second_name)==0)
            {
                flag=1;
                Short_Print_Directory(*dr);
            }
        }
        break;


        case 2:
        printf("Введите имя для поиска\n");
        char first_name[20]={0};
        fgets(first_name, 20, stdin);
        for(int i=0;i<count_dir;i++)
        {
            if(strcmp(first_name,dr->first_name)==0)
            {
                flag=1;
                Short_Print_Directory(*dr);
            }
        }
        break;


        case 3:
        printf("Введите имя для поиска\n");
        char number_phone[20]={0};
        fgets(number_phone, 20, stdin);
        for(int i=0;i<count_dir;i++)
        {
            if(strcmp(number_phone,dr->number_phone)==0)
            {
                flag=1;
                Short_Print_Directory(*dr);
            }
        }
        break;


        default: break;
    }
    if(flag==0)
        printf("Ничего не найдено\n");
    printf("---------\n");

}


int main(void)                 
{
    printf("задание 1 - вывод упакованной и выравненной структуры\n");

    printf("packed structure\n");
    struct struct_packed sp;
    sp.a=20000;
    sp.b='a';
    sp.c=20000;
    printf("sizeof(sp) - %ld\n",sizeof(sp));
    char* p=(char*)&sp;
    printf("structure bytes:\n");
    for(int i=0;i<sizeof(sp);i++)
        printf("%d ",*p++);
    printf("\n");

    printf("\naligned structure\n");
    struct struct_aligned sa;
    sa.a=20000;
    sa.b='a';
    sa.c=20000;
    printf("sizeof(sa) %ld\n",sizeof(sa));
    char *pp=(char*)&sa;
    printf("structure bytes:\n");
    for(int i=0;i<sizeof(sa);i++)
        printf("%d ",*pp++);
    printf("\n");
    printf("\n");

    printf("задание 2 - Справоник\n");

    int choise=0;
    int iter=0, id_delete=0, choise_search=0;
    struct directory a[100];
    while(1)
    {
        printf("Добавить - 1, вывод - 2, удаление - 3, поиск 4, выход - 5\n");
        scanf("%d",&choise);
        getchar();
        switch(choise)
        {
            case 1:
            if(iter<99)
            {
                Add_Directory(&a[iter]);
                a[iter].key=key++;
                iter++;
            }
            else
                printf("закончилось место\n");
            break;

            case 2: 
                if(iter!=0)
                {
                Print_Directory(a,iter);
                }
                else
                    printf("Справочник пуст\n");
            break;

            case 3: 
                if(iter!=0)
                {
                printf("Введите id записи\n");
                scanf("%d",&id_delete);
                Delete_Directory(a,id_delete);
                iter--;
                }
                else
                    printf("Справочник пуст\n");
            break;

            case 4: 
                if(iter!=0)
                {
                printf("Введите вариант поиска(1-по фамилии, 2-по имени, 3-по номеру)\n");
                scanf("%d", &choise_search);
                getchar();
                if(choise_search < 1 || choise_search > 3)
                    printf("Неверный критерий поиска\n");
                else
                    Search_dir(a,choise_search,iter);
                }
                else
                    printf("Справочник пуст\n");
            break;

            case 5: 
                return 1;
            break;
            default:
            printf("Неверный символ\n");
            break;
        }
    }
}     



