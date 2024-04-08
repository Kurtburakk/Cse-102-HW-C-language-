#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dice(){

     int value;
     char c;
     srand(time(NULL));
     
     do{
     c=getchar();
      
     }while(c!=10);
     

     value=rand()%6+1;


     return value;
}     
int startGame(){
    
    int temp1,temp2;
    int check=1;
       
    do{
      
    if(check==1){
    printf("To start to game,players should dice and decide who is going to start first according to it...\n");
    check=0;
    }
    printf("PLAYER 1.. press ENTER to dice ");
    temp1=dice();    
    printf("DICE: %d",temp1);
    printf("\n");
    printf("PLAYER 2.. press ENTER to dice ");
    temp2=dice();    
    printf("DICE: %d",temp2);
    printf("\n");
    
    if(temp1==temp2){
    printf("Same dice value... Please try again.\n");
     }
    }while(temp1==temp2);
    if(temp1>temp2){
    printf("*** Player 1 will start the game... ***\n");
    return 1;} /*which player will start, its value is returned*/
    else {
    printf("*** Player 2 will start the game... ***\n");
    return 2;} /*which player will start, its value is returned*/
} 

void printMap (char game[15][30]){
  int i,j;

  for(i=0;i<15;i++){
     for(j=0;j<30;j++){
      printf("%c",game[i][j]);     
      }
      printf("\n");
     }
}
    
int main(){
    
    int result;
    
    srand(time(NULL));
    
    result=startGame();
    
    char game[15][30];
     int i,j,s1,s2,pass,pass2,check_finish1=0,check_finish2=0;
    
     /*constant*/
     for(i=0;i<15;i++){
     for(j=0;j<30;j++){
     game[i][j]=' ';     /*puts spaces everywhere in the beginning*/ 
      }
     }     
     for(i=0;i<15;i++){   
      for(j=0;j<30;j++){
      
      /*game lines are placed*/
      
      game[0][j]='.';//top
      game[14][j]='.';//bottom
      if(j>1&&j<28){
      game[2][j]='.';  
      game[12][j]='.';
      } 
      if(j>3&&j<26){
      game[4][j]='.';
      game[10][j]='.';
      }               
      if(i>0&&i<14){
      game[i][0]=':'; 
      game[i][29]=':';
      }
      if(i>2&&i<12){
      game[i][2]=':'; 
      game[i][27]=':';
      }
      if(i>4&&i<10){
      game[i][4]=':'; 
      game[i][25]=':';
        }
       }
      }
      /*penalty*/
      /*for player 1*/
      game[1][14]='x';
      game[7][28]='x';
      game[13][14]='x';
      /*for player 2*/
      game[3][10]='x';
      game[5][26]='x';
      game[10][26]='x';
      game[11][10]='x';
      game[11][18]='x';      
      /*finish line*/
      game[2][1]='_';
      game[4][3]='_';
      /*player value*/
      game[1][1]='1';
      game[3][3]='2';
      /*constant*/
      
      /*first map printing*/
      printMap(game);
      
      int a=1,b=1; /*values that update the player's changed locations.*/
      int k=3,l=3; /*values that update the player's changed locations.*/
      game[a][b]=' ';
      game[k][l]=' ';
     
     if(result==1){ /*If player 1 starts game*/
     
     do{
      /*penalty*/
      game[1][14]='x';
      game[7][28]='x';
      game[13][14]='x';
      /*for player 2*/
      game[3][10]='x'; /*prevents it from being deleted if the player lands on it*/
      game[5][26]='x';
      game[10][26]='x';
      game[11][10]='x';
      game[11][18]='x';      
      /*finish line*/
      game[2][1]='_';
      game[4][3]='_';
       
     printf("PLAYER 1.. press ENTER to dice ");
     s1=dice();    
     printf("DICE: %d",s1);
     printf("\n");
     printf("PLAYER 2.. press ENTER to dice ");
     s2=dice();    
     printf("DICE: %d",s2);
     printf("\n");
    
      /****************** player 1***************************/
      if(check_finish2!=1){ /*if other gamer end game,this loop do not entry */
      
      /*1.line*/
      if((b<28)&&(a==1)){
      b=b+s1;
      if(b==14)b=b-2;
      if(b>28){ /*the part that corrects the transition from the corners*/
      pass=b-28;
      a=a+pass;
      b=28; 
       } 
      }
      /*2.line*/ 
      else if((a<13)&&(b==28)){
      a=a+s1;
      if(a==7)a=a-2;      
      if(a>13){  /*the part that corrects the transition from the corners*/
      pass=a-13;
      b=b-pass;
      a=13;
       }
      }
      /*3.line*/
      
      else if((b<=28)&&(a==13)){
      b=b-s1;
      if(b==14)b=b+2;
      if(b<1){       /*the part that corrects the transition from the corners*/
      pass=b*-1;
      a=a-pass;
      b=1; 
       } 
      }
      
      /*4.line*/
      
      else if((a<13)&&(b==1)){
      a=a-s1;
      if(a==2)check_finish1=1; /*this parts ends game*/
      if((a<2)&&(check_finish1==0)){ /*the part that corrects the transition from the corners*/
      pass=a*-1;
      b=b+pass;
      a=1;
      check_finish1=1; /*this parts ends game*/
        }
       }
      }      
      /****************** Player 2 ***************************/
      if(check_finish1!=1){
      
      /*1.line*/
      if((l<26)&&(k==3)){
      l=l+s2;
      if(b==10)b=b-2;/*penalty point*/ 
      if(l>26){ /*the part that corrects the transition from the corners*/
      pass2=l-26;
      k=k+pass2;
      l=26; 
       } 
      }
      /*2.line*/ 
      else if((k<11)&&(l==26)){
      k=k+s2;
     
      if(k==5)k=k-2; /*penalty point*/ 
      if(k==10)k=k-2;    /*penalty point*/
     
      if(k>11){  /*the part that corrects the transition from the corners*/
      pass2=k-11;
      l=l-pass2;
      k=11;
       }
      }
      /*3.line*/
      
      else if((l<=26)&&(k==11)){
        if(l - s2 <= 3){
        pass2 = s2 - (l - 3);
	k = k - pass2;
	l = 3;
	}else{
	l = l - s2;
	if(l==10)l=l+2;
	if(l==18)l=l+2;
	}
      }
      /*4.line*/
      
      else if((k<11)&&(l==3)){
      k=k-s2;
      if(k==4)check_finish2=1;  /*this parts ends game*/
      if((k<4)&&(check_finish2==0)){  /*the part that corrects the transition from the corners*/
      pass2=4-k;
      l=l+pass2;
      k=3;
      check_finish2=1; /*this parts ends game*/
        }
       }
      }
                  
      game[a][b]='1'; /*setting the player's new position*/
      game[k][l]='2'; /*setting the player's new position*/
     
     if(check_finish1==1){
     printf("\n\n\n*** Player 1 won the game... ***\n\n\n");
     }
     if(check_finish2==1){
     printf("\n\n\n*** Player 2 won the game... ***\n\n\n");
     }
      
      /*print map*/
     printMap(game);
     game[a][b]=' '; /*old position is remove*/
     game[k][l]=' '; /*old position is remove*/
     
     }while((check_finish1==0)&&(check_finish2==0));
    }  
     /*Player 2 starts game*/
     
     if(result==2){ 
     do{
     /*penalty*/
      game[1][14]='x';
      game[7][28]='x';
      game[13][14]='x';
      /*for player 2*/
      game[3][10]='x'; 
      game[5][26]='x';
      game[10][26]='x';
      game[11][10]='x';
      game[11][18]='x';      
      /*finish line*/
      game[2][1]='_';
      game[4][3]='_';
     
     printf("PLAYER 2.. press ENTER to dice ");
     s2=dice();    
     printf("DICE: %d",s2);
     printf("\n");  
     printf("PLAYER 1.. press ENTER to dice ");
     s1=dice();    
     printf("DICE: %d",s1);
     printf("\n");
     
       /****************** Player 2 ***************************/
      if(check_finish1!=1){
      
      if((l<26)&&(k==3)){
      l=l+s2;
      if(b==10)b=b-2;/*penalty point*/ 
      if(l>26){ 
      pass2=l-26;
      k=k+pass2;
      l=26; 
       } 
      }
      /*2.line*/ 
      else if((k<11)&&(l==26)){
      k=k+s2;
     
      if(k==5)k=k-2; /*penalty point*/ 
      if(k==10)k=k-2;    /*penalty point*/
     
      if(k>11){  
      pass2=k-11;
      l=l-pass2;
      k=11;
       }
      }
      /*3.line*/
      
      else if((l<=26)&&(k==11)){
        if(l - s2 <= 3){
        pass2 = s2 - (l - 3);
	k = k - pass2;
	l = 3;
	}else{
	l = l - s2;
	if(l==10)l=l+2;
	if(l==18)l=l+2;
	}
      }
      /*4.line*/
      
      else if((k<11)&&(l==3)){
      k=k-s2;
      if(k==4)check_finish2=1;
      if((k<4)&&(check_finish2==0)){
      pass2=4-k;
      l=l+pass2;
      k=3;
      check_finish2=1;
        }
       }
      }    
      /****************** player 1***************************/
      if(check_finish2!=1){
      
      /*1.line*/
      if((b<28)&&(a==1)){
      b=b+s1;
      if(b==14)b=b-2;
      if(b>28){ 
      pass=b-28;
      a=a+pass;
      b=28; 
       } 
      }
      /*2.line*/ 
      else if((a<13)&&(b==28)){
      a=a+s1;
      if(a==7)a=a-2;      
      if(a>13){  
      pass=a-13;
      b=b-pass;
      a=13;
       }
      }
      /*3.line*/
      
      else if((b<=28)&&(a==13)){
      b=b-s1;
      if(b==14)b=b+2;
      if(b<1){
      pass=b*-1;
      a=a-pass;
      b=1; 
       } 
      }
      
      /*4.line*/
      
      else if((a<13)&&(b==1)){
      a=a-s1;
      if(a==2)check_finish1=1;
      if((a<2)&&(check_finish1==0)){
      pass=a*-1;
      b=b+pass;
      a=1;
      check_finish1=1;
        }
       }
      }      
      
                  
      game[a][b]='1';
      game[k][l]='2';
     
     if(check_finish2==1){
     printf("\n\n\n*** Player 2 won the game... ***\n\n\n");
     }
     if(check_finish1==1){
     printf("\n\n\n*** Player 1 won the game... ***\n\n\n");
     }
     
      
      /*print map*/
     printMap(game);
     
     game[a][b]=' ';
     game[k][l]=' ';
     
     }while((check_finish1==0)&&(check_finish2==0));
    }/*Player 2 start game*/
    
    return 0;
}
