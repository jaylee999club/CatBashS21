#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct options {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
} opt;

void parser(int argc, char *argv[], opt *options) {
  int opt;
  int option_index;
  static struct option long_option[] = {{"number", 0, 0, 'n'},
                                        {"squeeze-blank", 0, 0, 's'},
                                        {"number-nonblank", 0, 0, 'b'},
                                        {0, 0, 0, 0}};
  while ((opt = getopt_long(argc, argv, "+benstvTE", long_option,
                            &option_index)) != -1) {
    switch (opt) {
      case 'b':
        options->b = 1;
        break;
      case 'e':
        options->e = options->v = 1;
        break;
      case 'n':
        options->n = 1;
        break;
      case 's':
        options->s = 1;
        break;
      case 't':
        options->t = 1;
        options->v = 1;
        break;
      case 'v':
        options->v = 1;
        break;
      case 'E':
        options->e = 1;
        break;
      case 'T':
        options->t = 1;
        break;
      default:
        fprintf(stderr, "Usage benstv");
        exit(1);
    }
  }
}

void reader(char *argv[], opt *options) {
  FILE *f = fopen(argv[optind], "r");

  if (f) {
    int current;
    int previous = '\n';
    int str_count = 0;
    int empty_counter = 1;
    int counter = 0;
    while ((current = fgetc(f)) != EOF) {
      if (options->s) {
        if (current != '\n') {
          empty_counter = 0;
        } else if (empty_counter < 2) {
          empty_counter++;
        } else {
          continue;
        }
      }
      if (options->v &&
          ((current >= 0 && current != 9 && current != 10 && current < 32) ||
           current == 127)) {
        if (current == 127) {
          fprintf(stdout, "^?");
          continue;
        } else {
          fprintf(stdout, "^%c", current + 64);
          continue;
        }
      }
      if (options->e && current == '\n') {
        fprintf(stdout, "$");
      }
      if (options->b) {
        if (current != '\n') {
          if (counter == 0) {
            fprintf(stdout, "%6d\t", ++str_count);
            counter = 1;
          }
        } else {
          counter = 0;
        }
      }
      if (options->n) {
        if (current != '\n') {
          if (counter == 0) {
            fprintf(stdout, "%6d\t", ++str_count);
            counter = 1;
          }
        } else {
          if (previous == '\n' && current == '\n') {
            fprintf(stdout, "%6d\t", ++str_count);
          }
          counter = 0;
        }
        previous = current;
      }
      if (options->t && current == '\t') {
        fprintf(stdout, "^I");
        continue;
      }
      putc(current, stdout);
    }
    fclose(f);
  } else {
    printf("No such file");
  }
}

int main(int argc, char *argv[]) {
  opt options = {0};
  parser(argc, argv, &options);
  if (options.b) {
    options.n = 0;
  }
  reader(argv, &options);
  return 0;
}