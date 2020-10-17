
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

static int a,b,c;

struct node
{
    unsigned long long aadhno;
	int age;
    char name[50];
    struct node *left, *right, *left_left, *right_right, *left_right, *right_left;
}*curr_node;

struct node *newNode(unsigned long long item,int ge,char iname[50])
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->aadhno = item;
    temp->age=ge;
    strcpy(temp->name,iname);
    temp->left = temp->right = NULL;
    temp->left_left = temp->right_right = NULL;
    temp->left_right = temp->right_left = NULL;
    return temp;
}


struct node* insert(struct node* Node,unsigned long long item,int age,char iname[50])
{
	curr_node=Node;
	while(1)
	{

	if(curr_node==NULL)
    {
		printf("ROOT Added\n");
        return newNode(item,age,iname);

    }

    else{

    if(curr_node->aadhno > item)
    {
        if(curr_node->left!=NULL)
        {
          if(curr_node->left->aadhno>item)
          {
              if(curr_node->left_left==NULL)
              {
	//			  newnode(value);
                  curr_node->left_left=newNode(item,age,iname);
                  printf("Added %llu LL of %llu\n",curr_node->left_left->aadhno,curr_node->aadhno);


                  return NULL;
              }
              curr_node=curr_node->left_left;
          }
          else
          {
              if(curr_node->left_right==NULL)
              {
	//		  newnode(value);
                  curr_node->left_right=newNode(item,age,iname);
                  printf("Added %llu LR of %llu\n",curr_node->left_right->aadhno,curr_node->aadhno);

                  return NULL;

              }
                curr_node=curr_node->left_right;

          }
        }
        else
        {
     //      newnode(value);
           curr_node->left=newNode(item,age,iname);
                                     printf("Added %llu L of %llu\n",curr_node->left->aadhno,curr_node->aadhno);
           return NULL;

        }
    }
    else
    {
        if(curr_node->right!=NULL)
        {

            if(curr_node->right->aadhno>item)
            {
                if(curr_node->right_left==NULL)
                {
		//			newnode(value);
                    curr_node->right_left=newNode(item,age,iname);
                    printf("Added %llu RL of %llu\n",curr_node->right_left->aadhno,curr_node->aadhno);

                    return NULL;

                }
                 curr_node=curr_node->right_left;


            }
            else
            {
                if(curr_node->right_right==NULL)
                {
         //newnode(value);
                    curr_node->right_right=newNode(item,age,iname);
                                     printf("Added %llu RR of %llu\n",curr_node->right_right->aadhno,curr_node->aadhno);

                    return NULL;

                }
                curr_node=curr_node->right_right;


            }

        }
        else
        {
          //  newnode(value);
            curr_node->right=newNode(item,age,iname);
            printf("Added %llu R of %llu\n",curr_node->right->aadhno,curr_node->aadhno);
            return NULL;
        }

    }

    }
}
  };

int search(struct node* root,unsigned long long val)
{
    curr_node=root;
    int steps=0;
    int limit=18;
    while(1)
    {
        if(curr_node->aadhno == val)
        {

            steps++;
            printf("Steps Taken: %d\n",steps);
            printf("Name: %s \n",curr_node->name);
            if(curr_node->age < limit)
            {
                printf("Not Eligible to vote\n");
                return 0;
            }
            else
            {
                printf("Eligible to Vote\n");
                return 1;
            }
        }
        else if(curr_node->aadhno > val)
        {
            steps++;
            if(curr_node->left==NULL)
            {
				printf("Invalid Aadhar Number\n");
                return -1;
            }
            if(curr_node->left->aadhno==val)
            {
                steps++;
                printf("Steps Taken: %d\n",steps);
                printf("Name: %s \n",curr_node->left->name);

                if(curr_node->left->age<limit)
                {
                    printf("Not Eligible to vote\n");
                    return 0;
				}
                else
                {
                    printf("Eligible to Vote\n");
                    return 1;
                }
            }
            else if(curr_node->left->aadhno>val)
            {
                steps++;
                if(curr_node->left_left==NULL)
                {
                    steps++;
                    printf("%d\n",steps);
                    printf("Invalid Aadhar Number\n");

                    return -1;
                }
                if(curr_node->left_left->aadhno==val)
                {
                    steps++;
             printf("Steps Taken: %d\n",steps);
            printf("Name: %s \n",curr_node->left_left->name);
             if(curr_node->left_left->age<limit)
			{printf("Not Eligible to vote\n");
				return 0;}
		else
			{printf("Eligible to Vote\n");
				return 1;}
              }
                steps++;
                curr_node=curr_node->left_left;
            }
            else
            {
                if(curr_node->left_right==NULL)
                {
                    steps++;
                    printf("Invalid Aadhar Number\n");
                    return -1;
                }
                if(curr_node->left_right->aadhno==val)
                {
                    steps++;
            printf("Steps Taken: %d\n",steps);
            printf("Name: %s \n",curr_node->left_right->name);
             if(curr_node->left_right->age<limit)
			{printf("Not Eligible to vote\n");
				return 0;}
		else
			{printf("Eligible to Vote\n");
				return 1;}
                     }
                steps++;
                curr_node = curr_node->left_right;
            }
        }
        else
        {
            if(curr_node->right==NULL)
            {
                steps++;
                printf("Invalid Aadhar Number\n");
                return -1;
            }
            if(curr_node->right->aadhno==val)
            {
                steps++;
                     printf("Steps Taken: %d\n",steps);
            printf("Name: %s \n",curr_node->right->name);
                if(curr_node->right->age<limit)
			{printf("Not Eligible to vote\n");
				return 0;}
		else
			{printf("Eligible to Vote\n");
				return 1;}
                }
            else if(curr_node->right->aadhno>val)
            {
                steps++;
                if(curr_node->right_left==NULL)
                {
                    steps++;
                    printf("Invalid Aadhar Number\n");
                    return -1;
                }
                if(curr_node->right_left->aadhno==val)
                {
                    steps++;
                    printf("Steps Taken: %d\n",steps);
            printf("Name: %s \n",curr_node->right_left->name);
                    if(curr_node->right_left->age<limit)
			{printf("Not Eligible to vote\n");
				return 0;}
		else
			{printf("Eligible to Vote\n");
			return 1;}
                    }
                steps++;
                curr_node=curr_node->right_left;
            }
            else
            {
                if(curr_node->right_right==NULL)
                {
                    steps++;
                    printf("Invalid Aadhar Number\n");
                    return -1;
                }
                if(curr_node->right_right->aadhno==val)
                {
                    steps++;
                    printf("Steps Taken: %d\n",steps);
            printf("Name: %s \n",curr_node->right_right->name);
          if(curr_node->right_right->age<limit)
			{printf("Not Eligible to vote\n");
				return 0;}
		else
			{printf("Eligible to Vote\n");
				return 1;}
                    //return curr_node->right_right;
                }
                steps++;
                curr_node=curr_node->right_right;
            }

        }

    }
};
void Vote(int choice)
{

 if(choice==1)
 {
  a++;
 }
 if(choice==2)
 {
  b++;
 }
 if(choice==3)
 {
  c++;
 }
 printf("Votes for A=%d\n",a);
 printf("Votes for B=%d\n",b);
 printf("Votes for C=%d\n",c);

}


int main()
{
    int i,ag;
    int t;
    int stop = 0;
    unsigned long long n;
//    struct node *q;
    int q;
    int flag=0;
    char na[50];
    struct node *root1 = NULL;
    FILE *ptr_file;
    char buf[1000];

    ptr_file = fopen("randno.txt", "r");
    if (!ptr_file)
    {
        printf("No such File\n");
        return 1;
    }

    for(i = 0; i < 40000; i++)
    {
		if(flag == 0)
		{
            fscanf(ptr_file,"%llu %d %[^\n]s",&n,&ag,na);
			root1 = insert(root1,n,ag,na);
			flag = 1;
		}
		else
		{
			fscanf(ptr_file, "%llu %d %[^\n]s",&n,&ag,na);
			insert(root1,n,ag,na);
            flag++;
            //printf("if dont wnna continue press 0");
            //scanf("%d",&p);
		}
	}

	printf("Data Added to BST\n");
	fclose(ptr_file);
	unsigned long long p;
	do
	{
        printf("Enter no:");
        scanf("%llu",&p);
        clock_t begin = clock();
        q = search(root1,p);
        if(q == 1)
        {
           printf("1)Vote A\n2)Vote B\n3)Vote C\n");
           scanf("%d",&t);
           if(t > 0 && t <= 3)
            Vote(t);
           else
            printf("Enter Valid input\n");
		}

        clock_t end = clock();
        double time_taken = ((double)(end - begin)/CLOCKS_PER_SEC);
        printf("Enter 1 or any number to continue else 0 to finish Voting and find who won the Vote\n");
        scanf("%d", &stop);

    }while(stop);

    if(a > b && a > c)
        printf("A won with votes of %d\n",a);
    else if(b > c && b > a)
        printf("B won with votes of %d\n",b);
    else if(c > a && c > b)
        printf("C won with votes of %d\n",c);
    else
        printf("There is a tie of votes");

    return 0;
}
