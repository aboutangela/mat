#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  color c;

  c.red = MAX_COLOR;
  c.green = 0;
  c.blue = 0;

  clear_screen(s);

  struct matrix * one;
  struct matrix * two;
  one = new_matrix(4, 4);
  two = new_matrix(4, 4);

  printf("\nidentity matrix one\n");
  ident(one);
  print_matrix(one);

  printf("\npopulate matrix two\n");
  add_edge(two, 1, 2, 3, 4, 5, 6);
  print_matrix(two);

  printf("\nmultiply identity matrix one and matrix two\n");
  matrix_mult(one, two);
  print_matrix(two);

  printf("\npopulate matrix one\n");
  add_edge(one, 1, 2, 3, 4, 5, 6);
  add_edge(one, 1, 2, 3, 4, 5, 6);
  print_matrix(one);

  printf("\nmultiply matrix one and matrix two\n");
  matrix_mult(one, two);
  print_matrix(two);

  free_matrix(one);
  free_matrix(two);


  struct matrix * edges;
  edges = new_matrix(4, 4);

  int i,j;
  for(i = 250; i > 150; i-=10){
    for(j = 125; j < 225; j+=10){
      add_edge(edges, i, j, 0, i+125, j+125, 0);
      add_edge(edges, i+125, j+125, 0, i, j+250, 0);
      add_edge(edges, i, j+250, 0, i-125, j+125, 0);
      add_edge(edges, i-125, j+125, 0, i, j, 0);
    }
  }

  draw_lines(edges, s, c);
  free_matrix(edges);
  save_extension(s, "pic.png");
  printf("\npic.png\n");
}
