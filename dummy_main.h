#ifndef DUMMY_MAIN_H
#define DUMMY_MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>
#include <unistd.h>


int user_main(int ARGC, char **ARGV);

int main(int argc, char **argv) {
  
  char signal_file[100];
  strcpy(signal_file, "/tmp/hpl.txt");

  // write into daemon fprintf(stdout,"\n-----\nmkdir timedrun fake\n\n");

 
 printf("\n====Starting energy profiler====\n\n");

 // Enter the correct path to your profiler
 /////////////////////////////////////////
 int ret = system("/home/shivam2025/freq_check/msr-daemon-new &");
 if (ret == -1){
	 perror("Failed to run profiler");
	 exit(EXIT_FAILURE);
 }	 
 /////////////////////////////////////////
 
 usleep(50000);
  int x = user_main(argc, argv);
  //printf("User main executed and ended \n " );
  FILE *fp  = fopen (signal_file, "a+");
  if (fp!=NULL){
  	fprintf(fp,"done\n");
	fclose(fp);
  }
  else{
  	perror("Failure in creating signal file");
  }
  printf("\n====SIGNAL FILE CREATED SUCCESS=====\n");
  usleep(50000);//500ms
  return x;
}
#endif

#define main user_main
