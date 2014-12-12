// this is not the entire .h file, but just the stat() struct you need

struct stat {
    short type;         // Type of file
    int dev;            // Device number
    uint ino;           // Inode number on device
    short nlink;        // Number of links to file
    uint logical_size;  // Size of file in bytes
    uint physical_size; // Physical size on disk
};

