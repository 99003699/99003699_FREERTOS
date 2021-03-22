#include <stdio.h>
#include<string.h>
#include <ctype.h>
#include <stdint.h>
#include<stdlib.h>

struct colour_box  
{
    int id;
    int length;
    int breadth;
    int height;
    char colour[50];
    int weight;
};  

int main()
{
    int num, choice;
    printf("Enter number of boxes:");
    scanf("%d",&num);
    struct colour_box *box = malloc(sizeof(struct colour_box)+num);
    printf("Enter choice\n 1- Display\n 2- Add\n 3- Search\n 4- Volume");
    scanf("%d",&choice);
    initialize(box, num);
    switch(choice)
    {
        case 1:
                display(box, num);
                break;
        case 2:
                add_box(box,num);
                break;
        case 3:
                search_id(box, num);
                break;
        case 4:
                volume(box, num);
                break;
    }
   

return 0;
}

void initialize(struct colour_box box[], int num)
{
    int i;
    for(i = 0; i <num; i++)
    {
        printf("Enter the id of box%d\n",i);
        scanf("%d",&box[i].id);
        printf("Enter the length of box%d\n",i);
        scanf("%d",&box[i].length);
        printf("Enter the breadth of box%d\n",i);
        scanf("%d",&box[i].breadth);
        printf("Enter the height of box%d\n",i);
        scanf("%d",&box[i].height);
        printf("Enter the colour of box%d\n",i);
        scanf("%s",box[i].colour);
        printf("Enter the weight of box%d\n",i);
        scanf("%d",&box[i].weight);
    }
}

void display(struct colour_box box[], int num)
{
    int i;
    for(i = 0; i <num; i++)
    {
        printf("----Details for Box %d----\n", (i+1));
        printf("unique id - %d\n", box[i].id);
        printf("length - %d\n", box[i].length);
        printf("breadth - %d\n", box[i].breadth);
        printf("height - %d\n", box[i].height);
        printf("colour - %s\n", box[i].colour);
        printf("weight - %d\n\n", box[i].weight);
    }

}

void add_box(struct colour_box box[],int num)
{
    int i;
    for(i=(num+1); i<(num+2); i++)
    {
    printf("Enter the id of box%d\n",i);
        scanf("%d",&box[i].id);
        printf("Enter the length of box%d\n",i);
        scanf("%d",&box[i].length);
        printf("Enter the breadth of box%d\n",i);
        scanf("%d",&box[i].breadth);
        printf("Enter the height of box%d\n",i);
        scanf("%d",&box[i].height);
        printf("Enter the colour of box%d\n",i);
        scanf("%s",box[i].colour);
        printf("Enter the weight of box%d\n",i);
        scanf("%d",&box[i].weight);
    }
    
}

void search_id(struct colour_box box[],int num)
{
    int i, searchid;
    printf("enter the id to search:");
    scanf("%d",&searchid);
    for(i=0; i<num; i++)
    {
        if(searchid==box[i].id)
        {
            printf("%d",i);
        }
    }
}

void volume(struct colour_box box[], int num)
{
    int i, vol, total_vol=0;
    float avg_vol;
    for(i=0; i<num; i++)
    {
        vol=((box[i].length)*(box[i].breadth)*(box[i].height));
        printf("volume of box%d:%d\n", i, vol);
        total_vol = total_vol + vol;
    }
    avg_vol = (total_vol)/num;
    printf("Average volume = %.2f",avg_vol);

}

