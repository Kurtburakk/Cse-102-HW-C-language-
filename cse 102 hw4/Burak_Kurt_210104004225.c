#include <stdio.h>

void coefficients_file(int a, int b, int c);
int draw_graph();
int graph_file();

  int main(){
  
  int choice;

  do{
    printf("Select an operation...\n");
    printf("1 -> Enter the coefficients.\n");
    printf("2 -> Draw the graph.\n");
    printf("3 -> Print the graph into a .txt file.\n");
    printf("4 -> Exit.\n");
    printf("Choice: ");
    scanf("%d",&choice);

    int a,b,c;
    if(choice==1){
          printf("Please enter the coefficient for the following equation: x=a*(y*y) + b*y + c\n");
          printf("a: ");
          scanf("%d",&a);
          printf("b: ");
          scanf("%d",&b);
          printf("c: ");
          scanf("%d",&c);
          coefficients_file(a,b,c);
     }      
     else if(choice==2){
            draw_graph();
      }
     else if(choice==3){
            graph_file();
      }
     else if (choice==4){
      }
     else {
          printf("Please enter 1,2,3 or 4");
          printf("\n");
          }

  }while(choice != 4);

  return 0;
           
}

void coefficients_file(int a, int b, int c){
  FILE *file;
  file = fopen("coefficients.txt","w");
  fprintf(file,"%d\n",a);
  fprintf(file,"%d\n",b);
  fprintf(file,"%d\n",c);
  fclose(file);
  printf("coefficients.txt file has been created.\n");
}

int draw_graph(){
  int a = 0,b = 0,c = 0;
  FILE *txt;
  txt = fopen("coefficients.txt","r");
  if(txt == NULL)
   {
      printf("Error!");
      return 0;
   }
  fscanf(txt,"%d ",&a);
  fscanf(txt,"%d ",&b);
  fscanf(txt,"%d ",&c);
  fclose(txt);

  printf("Coefficients has been read from the coeffecient.txt file.\n");
  printf("Printing the graph of x=%d(y*y) + %d*y + %d\n",a,b,c);
  
  int x,y;
    
    for(y=16;y>=-15;y--){
    
     for(x=-50;x<=50;x++){
       
      if(y==-1){
         if(x%10==0){
         if(x<0){
         printf("\033[0;34m");
         printf("\b\b\b\b%2d",x); /* Write the negative numbers on the y-axis. */
         printf("\033[0m");
         }
         if(x>0){
         printf("\033[0;34m");
         printf("\b\b\b%2d",x); /* Write the positive numbers on the y-axis. */
         printf("\033[0m");
         }
         if(x==0)
         {
         printf("\033[0;34m");
         printf("%d",x);   /* Write the zero number on the y-axis. */
         printf("\033[0m");
         printf("|");  /* Write this character then zero number on the y-axis. */
         }
       }
       }
                     
      if(x==0){                      
        if(y==16)printf("^");  /* This character puts the top of the y-axis. */
        if(y!=0 && y!=16 && y!=-1) printf("|"); 
        }
          
      if(y==0){                     /* This part write the y-axis.*/
        if(x==50)printf(">");       /*This character puts the to the far left of the graph.*/
        if(x==-50)printf("<");      /*This character puts the to the far right of the graph.*/
        if(x!=-1 && x!=50) printf("-");
        if(x==-3)printf("|"); 
      }
       
      
       else if(x==-1){ 
       if(y%5==0){               /* Write the numbers y-axis. */
       printf("\033[0;34m");
       printf("\b\b\b%3d",y);
       printf("\033[0m"); }
       }  
              
      else printf(" "); /* throws spaces if any character is not printed.*/
      
      if(x==a*(y*y)+b*y+c){   /*prints the points marked on the chart.*/
      
      
      if(x==0){               
      printf("\033[0;33m");
      printf("\b#");
      printf("\033[0m");
      }  
            
      if(y==0){
      printf("\033[0;33m");
      printf("\b\b#");
      printf("\033[0m");
      printf("-");
      }
      else if(y==-1){
      
      if(x<0){
      printf("\033[0;33m");
      printf("#");
      printf("\033[0m");}
      else if(x>0){
      printf("\033[0;33m");
      printf("\b#");
      printf("\033[0m");}
      else if(x==0){
      printf("\033[0;33m");
      printf("\b#");
      printf("\033[0m");} 
      }
      else{
      printf("\033[0;33m");
      printf("\b#");
      printf("\033[0m"); 
      } 
       }
                
     }
      printf("\n");
     }
     return 0;
}
int graph_file(){
  int a = 0,b = 0,c = 0;
  FILE *file;
  file = fopen("coefficients.txt","r");
  if(file == NULL)
   {
      printf("Error!");
      return 0;
   }
  fscanf(file,"%d ",&a);
  fscanf(file,"%d ",&b);
  fscanf(file,"%d ",&c);
  fclose(file);

  printf("Coefficients has been read from the coeffecients.txt file.");
  printf("\n");
  printf("Printing the graph of x=%d(y*y) + %d*y + %d",a,b,c);
  printf("\n");
  
  FILE *graph_txt;
  graph_txt = fopen("graph.txt","w");
  
  int x,y;
    
    for(y=16;y>=-15;y--){
    
     for(x=-50;x<=50;x++){
       
      if(y==-1){
         if(x%10==0){
         fprintf(graph_txt,"|");
         }
       }
       
                     
      if(x==0){                      
        if(y==16)fprintf(graph_txt,"^");  /* en tepeye şapka koyuyor */
        if(y!=0 && y!=16 && y!=-1)fprintf(graph_txt,"|"); 
        }
          
      if(y==0){                     /* yatay koordinatı yapıyor */
        if(x==50)fprintf(graph_txt,">");
        if(x==-50)fprintf(graph_txt,"<");
        if(x!=-1 && x!=50)fprintf(graph_txt,"-");
        if(x==-3)fprintf(graph_txt,"|"); 
      }
              
      else fprintf(graph_txt," "); /*en dışta ayrı takılacak*/
      
      if(x==a*(y*y)+b*y+c){  
      
      if(x==0){
      fprintf(graph_txt,"#");
      }  
            
      if(y==0){
      fprintf(graph_txt,"#");
      fprintf(graph_txt,"-");
      }
      else if(y==-1){
      
      if(x<0){
      fprintf(graph_txt,"#");
      }
      else if(x>0){
      fprintf(graph_txt,"#");
      }
      else if(x==0){
      fprintf(graph_txt,"#");
      } 
      }
      else{
      fprintf(graph_txt,"#"); 
      }
     }         
     }
      fprintf(graph_txt,"\n");
     }
     fclose(graph_txt);
     printf("The graph of x=%d(y*y) + %d*y + %d has been written to graph.txt file.",a,b,c);
     printf("\n");
     
     return 0;
}       
