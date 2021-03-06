#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define HEIGHT 512
#define WIDTH 512

int main() {

  //make img file
  int img = open("image.ppm", O_CREAT | O_WRONLY, 0644);

  //add header to img
  char header[256];
  sprintf(header, "P3\n%d %d\n255\n", HEIGHT, WIDTH);
  write(img, header, strlen(header));

  //add pixels to img
  int row; int col;
  char pixel[256];
  for(row = 0; row < HEIGHT; row++) {
    for (col = 0; col < WIDTH; col++) {
      sprintf(pixel, "0 %d %d ", 2*(row+col), 2*(WIDTH-row+col));
      write(img, pixel, strlen(pixel));
    }
    // finish row; new line
    char * newline = "\n";
    write(img, newline, strlen(newline));
  }

  //close file
  close(img);
  printf("\nImage created!\n");
  
}
