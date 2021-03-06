// Do not modify this file. It will be replaced by the grading scripts
// when checking your project.

#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{

  char *pathname;
  int fd, retVal;
  struct stat *fStat;
  
  if(argc != 2){
    printf(1, "Usage: filestat <pathname>\n");
    exit();
  }

  pathname = argv[1];

  fStat = (struct stat *) malloc(sizeof(struct stat));

  fd = open(pathname, O_RDWR);

  retVal =  fstat(fd, fStat);
/*struct stat {
  short type;  // Type of file
  int dev;     // Device number
  uint ino;    // Inode number on device
  short nlink; // Number of links to file
  uint size;   // logical Size of file in bytes
  / p5 /
  uint p_size; // physical size of file in bytes
};*/

  printf(1, "\nStat for %s\n", pathname);

  printf(1, "\tFile type: ");
  switch(fStat->type){
  case T_MIRRORED: printf(1, "T_MIRRORED\n"); break;
  case T_FILE: printf(1, "T_FILE\n"); break;
  case T_DIR: printf(1, "T_DIR\n"); break;
  case T_DEV: printf(1, "T_DEV\n"); break;
  default: printf(1, "INVALID FILE TYPE\n"); break;
  }
  printf(1, "\tDevice number: %d\n", fStat->dev);
  printf(1, "\tInode number: %d\n", fStat->ino);
  printf(1, "\tNumber of links: %d\n", fStat->nlink);
  printf(1, "\tFile size: %d\n", fStat->logical_size);
  printf(1, "\tPhysical size on disk: %d\n\n", fStat->physical_size);

  free(fStat);
  close(fd);
  exit();
}
