#ifndef _STAT_H_
#define _STAT_H_

// Stat struct definition, for use with stat syscall

#define T_DIR  1   // Directory
#define T_FILE 2   // File
#define T_DEV  3   // Special device
/* p5 */
#define T_MIRRORED 4 // Mirrored file

struct stat {
  short type;  // Type of file
  int dev;     // Device number
  uint ino;    // Inode number on device
  short nlink; // Number of links to file
  uint logical_size;   // logical Size of file in bytes
  /* p5 */
  uint physical_size; // physical size of file in bytes
};

#endif // _STAT_H_
