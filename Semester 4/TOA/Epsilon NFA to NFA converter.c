// code from http://mycodetechniques.blogspot.com/2018/09/ktu-cs-431-compiler-design-lab.html
#include<stdio.h>
#include<stdlib.h>
struct node
{
        int st;
        struct node *link;
};
//function prototypes
void findclosure(int,int);
void insert_trantbl(int ,char, int);
int findalpha(char);
void findfinalstate(void);
void unionclosure(int);
void print_e_closure(int);

//global variables 
static int set[20],nostate,noalpha,s,notransition,nofinal,start,finalstate[20],c,r,buffer[20];
char alphabet[20];
static int e_closure[20][20]={0};
struct node * transition[20][20]={NULL};
void main()
{
	printf("\n*********************************************************************************\n");
	printf("\n\t\t\tEpsilon-NFA to NFA converter\n");
	printf("\n*********************************************************************************\n\n\n");
           int i,j,k,m,t,n;
           
           struct node *temp;
           printf("Enter number of transition symbols (including e) : ");
           scanf("%d",&noalpha);
           getchar();
           printf("\nNOTE:- \n\n1. Use letter e as epsilon.");
           printf("\n2. Transition symbols must be alphabets.");
           printf("\n3. e must be last character, if it is present\n");

          printf("\nEnter alphabets (including e, if any) : \n");
          for(i=0;i<noalpha;i++)
		{
                  alphabet[i]=getchar();       //input transition symbols
                  getchar();
        }
        printf("\nNOTE:- \nState numbers must be numerical & greater than zero\n\n");
        printf("Enter the number of states : ");
        scanf("%d",&nostate);
        printf("Enter start state number: ");
        scanf("%d",&start);
        printf("Enter number of final states: ");
        scanf("%d",&nofinal);
        printf("Enter the final state(s) : ");
        for(i=0;i<nofinal;i++)
                scanf("%d",&finalstate[i]);     //input final states
         printf("Enter total number of transitions : \n");
        scanf("%d",&notransition);
        printf("NOTE:- \nEnter transitions in the form --> [State no.]  [alphabet]  [State no.] \n",notransition);
        
        printf("\nEnter transitions?\n");
        for(i=0;i<notransition;i++)
        {
                scanf("%d %c%d",&r,&c,&s);    //input transitions in the form [Start state]  [alphabet]  [End state]
                insert_trantbl(r,c,s);

        }

        printf("\n");

        for(i=1;i<=nostate;i++)     //for each state i 
        {
                c=0;
                for(j=0;j<20;j++)
                {
                              buffer[j]=0;
                              e_closure[i][j]=0;    //initialise
                }
                findclosure(i,i);      //check null transitions for each state
        }
        printf("=================================================================\n");
        printf("\n\t\tEquivalent NFA without epsilon\n");
        printf("\n=================================================================\n");
        printf("Start state : ");
        print_e_closure(start);
        printf("\nAlphabets:");
        for(i=0;i<noalpha;i++)
                  printf("%c ",alphabet[i]);
        printf("\nStates :" );
        for(i=1;i<=nostate;i++)
                  print_e_closure(i);   //prints each state with its null reachable states in the form {q1,q2...}

        printf("\n\nTransitions are...:\n");

        for(i=1;i<=nostate;i++)   //for each state
        {
                  for(j=0;j<noalpha-1;j++)    //for each transition symbol
                 {
                          for(m=1;m<=nostate;m++)    
                                        set[m]=0;     //initiaise set[]=0 for each state
                          for(k=0;e_closure[i][k]!=0;k++)     //for state i, for itself & its each null transitions, till there are no more null transitions 
                          {
                                    t=e_closure[i][k];      //t=null associated state (or itself)
                                   temp=transition[t][j];   
                                   while(temp!=NULL)     //while if null associated state with transition j is not null
                                  {
                                             unionclosure(temp->st);
                                            temp=temp->link;       //check for next state
                                   }
                         }
                        printf("\n");
                        print_e_closure(i);
                        printf("%c\t",alphabet[j]   );
                        printf("{");
                        for(n=1;n<=nostate;n++)    //print combined states in the form {q1,q2...}
                        {
                                     if(set[n]!=0)       //if there's some transition, print the resulting state
                                             printf("q%d,",n);
                        }
                         printf("}");
                }
        }
        printf("\n Final states:");
        findfinalstate();
}

void findclosure(int x,int sta)
{
            struct node *temp;
            int i;        //for state x=0
           if(buffer[x])
                     return;
            e_closure[sta][c++]=x;   //e[state no][c++]=state no  holds current state and all states which are reachable through null transition
            buffer[x]=1;     //buffer[state no]=1
             if(alphabet[noalpha-1]=='e' && transition[x][noalpha-1]!=NULL) // if there's null (alphabet[last] = null)
			 																// && transition[state no][null] is not null
                {															//means null transition of this state goes to some other state
                             temp=transition[x][noalpha-1];    //temp=transition[state no][null]  temp=that end state to which null goes
                             while(temp!=NULL)
                            {
                                         findclosure(temp->st,sta);    //check null transitions for that end state
                                         temp=temp->link;              //repeat for other connected states
                             }
                }
  }

void insert_trantbl(int r,char c,int s)
{
           int j;
           struct node *temp;
            j=findalpha(c);    //returns 1 if transition symbols are from the list given by user
          if(j==999)           //else returns 999
          {
                     printf("error\n");
                    exit(0);
          }
         temp=(struct node *) malloc(sizeof(struct node));
         temp->st=s;
         temp->link=transition[r][j];
         transition[r][j]=temp;
}

int findalpha(char c)
{
            int i;
            for(i=0;i<noalpha;i++)
                   if(alphabet[i]==c)
                          return i;

                return(999);


}

void unionclosure(int i)
{
              int j=0,k;
             while(e_closure[i][j]!=0)  //while there's a transition for state i through symbol j
             {
                      k=e_closure[i][j];  // k = that state
                      set[k]=1;
                      j++;           //check for other transition symbols
             }
}
void findfinalstate()
{
            int i,j,k,t;
            for(i=0;i<nofinal;i++)  //for number of final states
           {
                      for(j=1;j<=nostate;j++)
                      {
                              for(k=0;e_closure[j][k]!=0;k++)    //for each null associated state
                                {
                                         if(e_closure[j][k]==finalstate[i])
                                        {

                                                 print_e_closure(j);
                                        }
                               }
                      }
             }


  }

void print_e_closure(int i)
{
        int j;
        printf("{");
        for(j=0;e_closure[i][j]!=0;j++)
                        printf("q%d,",e_closure[i][j]);    //prints the current state and all states associated to it through null transition
         printf("}\t");
}
