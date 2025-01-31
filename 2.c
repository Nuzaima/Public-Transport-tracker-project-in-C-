#include<stdio.h>
#include<string.h>
#include<windows.h>
struct Route
{
    char name[50];
    char start[50];
    char end[50];
    int frequency;
    char stop1[50];
    char stop2[50];
    char stop3[50];
};
void menu()
{
    printf("-----Public Transport Tracker-----\n\n");
    printf("1. Add a Route\n2. Print Routes\n3. Update a Route\n4. Delete a Route\n5. Fare cost of each route\n6. Suggest the best route\n7. Exit\n");

}
void addRoute(struct Route *r)
{

    printf("Enter new route name: ");
    scanf("%s",r->name);
    printf("Enter new route starting point: ");
    scanf("%s",r->start);
    printf("Enter new route destination: ");
    scanf("%s",r->end);
    printf("Enter new route frequency: ");
    scanf("%d",&r->frequency);
    printf("Enter new route stop 1: ");
    scanf("%s",r->stop1);
    printf("Enter new route stop 2: ");
    scanf("%s",r->stop2);
    printf("Enter new route stop 3: ");
    scanf("%s",r->stop3);

    printf("Route Added successfully\n");


}
void PrintRoutes(struct Route r[],int *n)
{
    printf("---\n1.Print all routes\n2.Filter by starting point\n3.Filter by destination\n---\n");
    int c;
    printf("Enter your choice: ");
    scanf("%d",&c);
    if(c==1){
        for(int i=0;i<*n;i++)
        {
            printf("Route %d:\n",i+1);
            printf("Name: %s\n",r[i].name);
            printf("Starting point: %s\n",r[i].start);
            printf("Destination: %s\n",r[i].end);
            printf("Stop 1: %s\n",r[i].stop1);
            printf("Stop 2: %s\n",r[i].stop2);
            printf("Stop 3: %s\n",r[i].stop3);
            printf("\n");


        }

    }
    else if(c==2)
    {
        char stp[50];
        printf("Which point: ");
        scanf("%s",stp);

        for(int i=0;i<*n;i++)
        {
            int compare=strcmp(stp,r[i].start);
        if(compare==0){
            printf("Route %d:\n",i+1);
            printf("Name: %s\n",r[i].name);
            printf("Starting point: %s\n",r[i].start);
            printf("Destination: %s\n",r[i].end);
            printf("Stop 1: %s\n",r[i].stop1);
            printf("Stop 2: %s\n",r[i].stop2);
            printf("Stop 3: %s\n",r[i].stop3);
            printf("\n");
        }


        }
    }
     else if(c==3)
    {
        char dtp[50];
        printf("Which point: ");
        scanf("%s",dtp);

        for(int i=0;i<*n;i++)
        {
            int comp=strcmp(dtp,r[i].end);
        if(comp==0){
            printf("Route %d:\n",i+1);
            printf("Name: %s\n",r[i].name);
            printf("Starting point: %s\n",r[i].start);
            printf("Destination: %s\n",r[i].end);
            printf("Stop 1: %s\n",r[i].stop1);
            printf("Stop 2: %s\n",r[i].stop2);
            printf("Stop 3: %s\n",r[i].stop3);
            printf("\n");
        }


        }
    }
    else {
        printf("Invalid Choice");
    }


}
void UpdateRoute(struct Route *r)
{

    printf("---\n1. Update by frequency\n2. Update Stoppages\n---\n");
    int c;
    scanf("%d",&c);
    if(c==1){
    printf("Enter new route frequency: ");
    scanf("%d",&r->frequency);}
    else if(c==2){
    printf("Enter new route stop 1: ");
    scanf("%s",r->stop1);
    printf("Enter new route stop 2: ");
    scanf("%s",r->stop2);
    printf("Enter new route stop 3: ");
    scanf("%s",r->stop3);
    }
    else
    {
       printf("Invalid Choice");
    }

    if(c==1 || c==2){

    printf("Route Updated Successfully\n");
    }

}
void DeleteRoutes(struct Route b[],int *n)
{
 printf("---\n1. Delete by route name\n2. Delete by destination\n---\n");
 int c,cmp;
 scanf("%d",&c);
 int index=-1;
 if(c==1)
 {
     char rname[50];
     printf("Enter route name to delete: ");
     scanf("%s",rname);

     for(int i=0;i<*n;i++){
     cmp=strcmp(rname,b[i].name);
     if(cmp==0){
        index=i;
        break;
     }
     }

     for(int i=index;i< *n-1 ;i++)
     {
         b[i]=b[i+1];
     }
     (*n)--;
     printf("Route %s deleted successfully\n",rname);

 }
 else if(c==2)
 {
     char rd[50];
     printf("Enter routes destination to delete: ");
     scanf("%s",rd);
     for(int i=0;i<*n;i++){
     cmp=strcmp(rd,b[i].name);
     if(cmp==0){
         index=i;
            for(int j=index;j< *n-1 ;j++)
     {
         b[j]=b[j+1];
     }
     (*n)--;

     }
     }

     printf("Routes with %s destination deleted successfully\n",rd);

 }

 else {
    printf("Invalid Choice\n");
 }


}

void CostRoutes(struct Route r[],int *n)
{
    int t= *n;
    int cost[t];
    for(int i=0;i<t;i++)
    {
        if(r[i].frequency<5)
       {
           cost[i]=30;
       }
       else if(r[i].frequency<10)
       {
           cost[i]=20;
       }
       else if(r[i].frequency<15)
       {
           cost[i]=15;
       }
      else if(r[i].frequency<20)
       {
           cost[i]=10;
       }

    }
    for(int i=0;i<t;i++)
    {
        printf("Route %d:\n",i+1);
        printf("Cost - %d\n\n",cost[i]);
    }
}
void BestRoute(struct Route r[],int *n)
{
    int t= *n;
    int min=r[0].frequency;
    char minstart[50];
    char minend[50];
    strcpy(minstart,r[0].start);
    strcpy(minend,r[0].end);
    for(int i=0;i<t;i++)
    {
        if(r[i].frequency<min)
        {
            min=r[i].frequency;
            strcpy(minstart,r[i].start);
            strcpy(minend,r[i].end);
        }

    }
    printf("The fastest route is from %s to %s\n",minstart,minend);
}

int main()
{

   printf("Total Routes: ");
   int n;
   scanf("%d",&n);
   struct Route b[n];
   getchar();
   for(int i=0;i<n;i++)
   {
       printf("Route %d:\n",i+1);
       printf("Name: ");
       gets(b[i].name);
       printf("Starting point: ");
       gets(b[i].start);
       printf("Destination: ");
       gets(b[i].end);
       printf("Enter frequency (in minutes): ");
       scanf("%d",&b[i].frequency);
       getchar();
       printf("Stop 1: ");
       gets(b[i].stop1);
       printf("Stop 2: ");
       gets(b[i].stop2);
       printf("Stop 3: ");
       gets(b[i].stop3);


   }
   while(1){
    menu();
    printf("Enter your choice: ");
    int choice;
    scanf("%d",&choice);
   Sleep(1500);
   printf("......wait for a few moments......");
   Sleep(1500);
   system("CLS");
    if(choice==1)
    {
        n++;
        addRoute(&b[n-1]);
    }
    else if(choice==2)
    {
       PrintRoutes(b,&n);
    }
    else if (choice==3)
    {
    char update[50];
    int updateID;
    printf("Enter the route name to update: ");
    scanf("%s",update);
    printf("Route ID to update: ");
    scanf("%d",&updateID);
    UpdateRoute(&b[updateID-1]);

    }
    else if (choice==4)
    {
       DeleteRoutes(b,&n);
    }
    else if(choice==5)
    {
        CostRoutes(b,&n);
    }
    else if(choice==6)
    {
        BestRoute(b,&n);
    }
    else if(choice==7)
    {
        printf("Exiting the program. Goodbye!\n");
        break;
    }
    else
    {
        printf("Error!\n");
    }
   }




}

