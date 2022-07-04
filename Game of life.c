#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>


#define W 10   //Width of board
#define H 10   //Height of board
#define DEAD 0       
#define ALIVE 1

//Function prototypes
void print_rules ();
int row_line();
int create_rdm_people(int b[W][H]);
int print_board(int b[W][H]);
int count_live_neighbours(int b[W][H], int x, int y);
int evaluate (int b[W][H]);
int count_population (int b[W][H]);


int main()
{
    int b[W][H], next_board[W][H], i=0;
    char  option;
    
    printf("\t\t------------------------------------\n");
    printf("\t\t+	      WELCOME              +\n");
    printf("\t\t+	      to the               +\n");
    printf("\t\t+           GAME OF LIFE           +\n");
    printf("\t\t------------------------------------\n");

    printf("\n\t\tStudent Name : Danny Esteban Sanchez Oyagata\n\t\tStudent Number : 200027576\n\n");
   

    while (option != 69){

        printf("\n\tSee the rules [R]\n");
        printf("\tStart simulation [S]\n");
        printf("\tExit [E]\n");
        scanf("\t%s",&option);

        if (option == 82)
            print_rules();
        else if (option == 83){
            create_rdm_people(b);
            do
            {
                printf("\n\t\tGeneration Number #%d: \n",++i);
                print_board(b);
                next_board[W][H]= evaluate(b);
                b[W][H]=next_board[W][H];
                printf("Population: %d\t\t\t\t    # Alive / - Dead",count_population(b));
                printf("\n\n\tPut [q] to finish simulation / [ENTER] to continue");
                printf("\n\n");

            }while (getchar() !='q');
        
        }   
        else if (option== 69)
            printf("\n\t\tGoodbye!\n");
        else {
            printf("\tSorry I cannot understand\n");
        } 
    }
    
    getch();
    return 0;
}
void print_rules ()
{
    //Print the rules of the game
    printf("\n\t- An alive cell with 1 or less alive neighbours will die (under population/loneliness)");
    printf("\n\t- An alive cell with 4 or more alive neighbours will die (overpopulation)");
    printf("\n\t- An alive cell with 2 or 3 neighbours will suvive to the next generation.");
    printf("\n\t- A dead cell with exactly 3 alive nieghbours will be alive on the next generation (reproduction)\n");
}

int row_line ()
{
    //Creates row boundary
    printf("\n");
    for (int i =0; i<H; i++){
        printf(" -----");
    }
    printf ("\n");
}

int create_rdm_people(int b[W][H])
{
    //Generate board canvas with random values
    srand(time(NULL));
    for (int i=0; i<W;i++) {
        for (int j=0;j<H;j++) {
            b[i][j] = rand() % 2;
        }
    }
}

int print_board(int b[W][H])
{
    //Print array board
    row_line();
    for (int i=0; i<W; i++)
    {
        printf(":");
        for (int j=0; j<H; j++)
        {
            if (b[i][j]== ALIVE)
                 printf("  #  :");
            else 
                printf("  -  :");
        }
         row_line();
    }
}

int count_live_neighbours(int b[W][H], int x, int y)
{
    //Returns the count of alive neighbours
    int count=0;

    for (int i=x-1; i<=x+1 ; i++){
        for (int j=y-1; j<=y+1; j++){
            if ((i==x && j==y) || (i<0 || j<0) || (i>=W || j>= H)){
                continue;
            }
            if (b[i][j]== ALIVE){
                count++;
            }
        }
    }
    return count;
}

int evaluate (int b[W][H])
{
    //Evaluate who will be alive in next generation
    int live_neighbors =0;

    for (int i=0; i<W; i++){
        for (int j=0; j<H;j++){
            live_neighbors= count_live_neighbours(b,i,j);
            if (b[i][j]==ALIVE && live_neighbors <=1){
                b[i][j]= DEAD;
            }
            if (b[i][j]== ALIVE && live_neighbors >= 4){
                b[i][j]=DEAD;
            }
            if (b[i][j]== ALIVE && (live_neighbors == 2 || live_neighbors == 3)){
                b[i][j]= ALIVE;
            }
            if (b[i][j] ==DEAD && live_neighbors == 3 ){
                b[i][j]==ALIVE;
            }
        }   
    }
 }

int count_population (int b[W][H])
{
    //Count the population in each generation
    int people_alive=0;

    for (int i=0 ; i<W; i++){
        for (int j=0; j<H; j++){
            if (b[i][j]==ALIVE)
                people_alive++;
        }
    }
    return people_alive;
}