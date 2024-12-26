#include<stdio.h>
#include<stdlib.h>
void main(){
int p_no,r_no,count=0,flag=0,k=0;
printf("Enter the no of processes:");
scanf("%d",&p_no);
printf("Enter the no of resources:");
scanf("%d",&r_no);
int allocation[p_no][r_no],need[p_no][r_no],max[p_no][r_no],available[r_no],safeseq[p_no],visited[p_no];
printf("enter the allocation of each process:\n");
for(int i=0;i<p_no;i++){
for(int j=0;j<r_no;j++){
scanf("%d",&allocation[i][j]);
}
}
printf("enter the maximum allocation of each process:\n");
for(int i=0;i<p_no;i++){
visited[i]=0;
for(int j=0;j<r_no;j++){
scanf("%d",&max[i][j]);
}
}
for(int i=0;i<p_no;i++){
for(int j=0;j<r_no;j++){
need[i][j]=max[i][j]-allocation[i][j];
}
}
printf("enter the available space for each resources:");
for(int i=0;i<r_no;i++){
scanf("%d",&available[i]);
}
printf("|ALLOCATION| MAXIMUM  | AVAILABLE | NEED  |\n");
for(int i=0;i<p_no;i++){
printf("|");
for(int j=0;j<r_no;j++){
printf("  %d",allocation[i][j]);
}
printf(" |");
for(int j=0;j<r_no;j++){
printf(" %d ",max[i][j]);
}
printf(" | ");
for(int j=0;j<r_no;j++){
printf(" %d ",available[j]);
}
printf(" | ");
for(int j=0;j<r_no;j++){
printf("%d ",need[i][j]);
}
printf("|");
printf("\n");
}
while(count<p_no){
flag=0;
for(int i=0;i<p_no;i++){
int executed=0;
for(int j=0;j<r_no;j++){
if(need[i][j]<=available[j]){
executed++;
}
}
if(executed==r_no&&visited[i]==0){
for(int j=0;j<r_no;j++){
available[j]=available[j]+allocation[i][j];
}
flag=1;
visited[i]=1;
count++;
safeseq[k++]=i;
}
}

if(flag==0){
printf("NO SAFE SEQUENCE\n");
exit(0);
}
}
printf("Safe sequence:<");
for(int i=0;i<k;i++){
printf("P%d ",safeseq[i]);
}
printf(">\n");
}
