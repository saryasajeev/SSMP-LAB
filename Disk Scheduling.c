#include<stdio.h>
#include<stdlib.h>
void FCFS();
void SCAN();
void CSCAN();

void main(){
int choice;
while(choice!=4){
printf("\n--->1.FCFS 2.SCAN 3.CSCAN 4.EXIT\nenter the choice:");
scanf("%d",&choice);
switch(choice){
case 1:{
FCFS();
break;
}
case 2:{
SCAN();
break;
}
case 3:{
CSCAN();
break;
}
case 4:{
printf("EXITED!!\n");
break;
}
}
}
}

void FCFS(){
int n,distance,head,seek=0;
printf("Enter the no of disk requests:");
scanf("%d",&n);
int a[20];
printf("Enter the headposition:");
scanf("%d",&head);
a[0]=head;
printf("Enter the requests:");
for(int i=1;i<=n;i++){
scanf("%d",&a[i]);
}
for(int i=0;i<n;i++){
distance=abs(a[i]-a[i+1]);
printf("Head moves from %d to %d with distance=%d\n",a[i],a[i+1],distance);
seek=seek+distance;
}
printf("Total head movement=%d\n",seek);
}

void SCAN(){
int n,distance,head,seek=0,q[20],q1[20],q2[20],a=0,a1=0,a2=0,temp,x,max;
printf("Enter the no of disk requests:");
scanf("%d",&n);
printf("Enter the headposition:");
scanf("%d",&head);
printf("Enter the max range:");
scanf("%d",&max);
printf("Enter the requests:");
for(int i=0;i<n;i++){
scanf("%d",&temp);
if(temp>head){
q1[a1]=temp;
a1++;
}
else{
q2[a2]=temp;
a2++;
}
}
for(int i=0;i<a1;i++){
for(int j=i+1;j<a1;j++){
if(q1[i]>q1[j]){
x=q1[i];
q1[i]=q1[j];
q1[j]=x;
}
}
}
for(int i=0;i<a2;i++){
for(int j=i+1;j<a2;j++){
if(q2[i]<q2[j]){
x=q2[i];
q2[i]=q2[j];
q2[j]=x;
}
}
}
q[a]=head;
a++;
for(int i=0;i<a1;i++){
q[a]=q1[i];
a++;
}
q[a]=max;
a++;
for(int i=0;i<a2;i++){
q[a]=q2[i];
a++;
}
q[a]=0;
for(int i=0;i<(a-1);i++){
distance=abs(q[i]-q[i+1]);
printf("Head moves from %d to %d with distance=%d\n",q[i],q[i+1],distance);
seek=seek+distance;
}
printf("Total head movement=%d\n",seek);
}

void CSCAN(){
int n,distance,head,seek=0,q[20],q1[20],q2[20],a=0,a1=0,a2=0,temp,x,max;
printf("Enter the no of disk requests:");
scanf("%d",&n);
printf("Enter the headposition:");
scanf("%d",&head);
printf("Enter the max range:");
scanf("%d",&max);
printf("Enter the requests:");
for(int i=0;i<n;i++){
scanf("%d",&temp);
if(temp>head){
q1[a1]=temp;
a1++;
}
else{
q2[a2]=temp;
a2++;
}
}
for(int i=0;i<a1;i++){
for(int j=i+1;j<a1;j++){
if(q1[i]>q1[j]){
x=q1[i];
q1[i]=q1[j];
q1[j]=x;
}
}
}
for(int i=0;i<a2;i++){
for(int j=i+1;j<a2;j++){
if(q2[i]>q2[j]){
x=q2[i];
q2[i]=q2[j];
q2[j]=x;
}
}
}
q[a]=head;
a++;
for(int i=0;i<a1;i++){
q[a]=q1[i];
a++;
}
q[a]=max;
a++;
q[a]=0;
a++;
for(int i=0;i<a2;i++){
q[a]=q2[i];
a++;
}
for(int i=0;i<(a-1);i++){
distance=abs(q[i]-q[i+1]);
printf("Head moves from %d to %d with distance=%d\n",q[i],q[i+1],distance);
seek=seek+distance;
}
printf("Total head movement=%d\n",seek);
}
