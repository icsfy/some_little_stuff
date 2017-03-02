// Replace one symbol with other symbols, randomly.
// Compile: gcc replace_symbols.c
// Example: ./a.out a.txt b.txt "&" "#$%&^~_{}\\"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])
{
  if (argc != 5) {
    printf("Usage: %s <input_file> <output_file> <symbol> <symbols>\n", argv[0]);
    printf("Example:\n  %s a.txt b.txt \"&\" \"#$%%&^~_{}\\\\\"\n", argv[0]);
    exit(1);
  }

  FILE *fpin, *fpout;
  if ((fpin = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Cannot open input file: %s\n", argv[1]);
    exit(1);
  }
  printf(" Input file: %s\n", argv[1]);
  if ((fpout = fopen(argv[2], "w")) == NULL) {
    fprintf(stderr, "Cannot open output file: %s\n", argv[2]);
    exit(1);
  }
  printf("Output file: %s\n", argv[2]);

  srand(time(NULL));

  char *symbol = argv[3];
  char *symbols = argv[4];
  int symbols_count = strlen(symbols);
  printf(" '%c' will be replaced by these %d symbols:\n", symbol[0], symbols_count);
  for(int i = 0; i < symbols_count; i++){
    printf("%4d: %c\n", i+1, symbols[i]);
  }
  printf("Press Enter to continue...");
  getchar();

  char c;
  while((c = getc(fpin)) != EOF) {
    if(c == symbol[0])
      c = symbols[rand() % symbols_count];
    putc(c, fpout);
  }

  fclose(fpin);
  fclose(fpout);
  printf("Done!\n");
  return 0;
}
