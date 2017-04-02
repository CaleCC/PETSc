/****************************************************************
 ****
 **** This program file is part of the tutorial
 **** `Introduction to the PETSc library'
 **** by Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** copyright Victor Eijkhout 2012-6
 ****
 ****************************************************************/

#include <stdio.h>
#include "petsc.h"

int main(int Argc,char **Args)
{
  int ierr,procno,nprocs;

  ierr = PetscInitialize(&Argc,&Args,PETSC_NULL,PETSC_NULL); CHKERRQ(ierr);
  MPI_Comm comm = PETSC_COMM_WORLD;

  MPI_Comm_rank(comm,&procno);
  MPI_Comm_size(comm,&nprocs);

  /*
   * Exercise 1:
   * -- use PetscPrintf to print only from process zero
   */
  ierr = PetscPrintf
    (
      PETSC_COMM_WORLD,"this program runs on 27 processors"
     ); CHKERRQ(ierr);

  /*
   * Exercise 2:
   * -- use PetscSynchronizedPrintf to let each processor print in sequence
   */
  ierr = PetscSynchronizedPrintf
    (
/**** your code here ****/
     ); CHKERRQ(ierr);
  ierr = PetscSynchronizedFlush(comm,stdout); CHKERRQ(ierr);

  ierr = PetscFinalize(); CHKERRQ(ierr);

  return 0;
}
