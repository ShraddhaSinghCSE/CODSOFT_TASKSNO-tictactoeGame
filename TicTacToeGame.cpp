#include <iostream>
using namespace std;
int currentPlayer;
char currentmarker;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
void drawBoard(){
      cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<"\n";
      cout<<"---|---|---\n";
      cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<"\n";
      cout<<"---|---|---\n";
      cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<"\n";
      cout<<"---|---|---\n";
}

bool placemarker(int slot){
    int row=(slot-1)/3;
    int col=(slot-1)%3;

    if(board[row][col] !='X' && board[row][col] !='O'){
        board[row][col]=currentmarker;
        return true;
    }
    else {return false;}
}
int winner(){
    //rows
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2])
        return currentPlayer;
    }
    //columns
    for(int j=0;j<3;j++){
        if(board[0][j]==board[1][j] && board[1][j]==board[2][j]){
            return currentPlayer;
        }
    }
    //diagonals
        if(board[0][0]==board[1][1] && board[1][1]==board[2][2]){
        return currentPlayer;
        }
        return 0;
}

void swapPlayerandMarker(){
    if(currentmarker =='X'){
        currentmarker='O';
    }
    else{
        currentmarker='X';
    }
    if(currentPlayer==1){
        currentPlayer=2;
    }
    else{
        currentPlayer=1;
    }
}
void game(){
    for(int i=0;i<=50;i++) cout<<"=";
    cout<<endl<<"              TIC TAC TOE GAME"<<endl;
    for(int i=0;i<=50;i++) cout<<"=";
    cout<<"\n";
    cout<<"               ☺️START GAME☺️\n";
    cout<<"Player 1 choose your marker (X Or O): ";
    char markerP1;
    cin>>markerP1;

    currentPlayer=1;
    currentmarker=markerP1;
    drawBoard();

    int Playerwon;
    for(int i=1;i<=9;i++){
        cout<<"its player"<<currentPlayer<<"'s turn Enter your slot: ";
        int slot;
        cin>>slot;

        if(slot<1 || slot>9) {
            cout<<"invalid slot, you may try again";
            i--;
            continue;
        }
        if(!placemarker(slot))
         {
            cout<<"slot occupied,try again \n";
            i--;
            continue;
         }
         drawBoard();
         Playerwon=winner();
         
        if(Playerwon==1){
        cout<<"Player 1 wins 🏆";
        return;
         }
        if(Playerwon==2){
        cout<<"Player 2 wins 🏆";
        return;
         }
        swapPlayerandMarker();
    }
    if(Playerwon==0){
         cout<<"it's a tie! 🤝";

        }

}
void playagain(){
    char choice;
    cout<<"\nDo you want to play again? (Y/N): ";
    cin>>choice;
    if(choice=='Y' || choice=='y'){
        game();
    }
    else{
        cout<<"Thanks for playing! Goodbye! 👋";
    }
}
int main()
{
    game();
    playagain();
}