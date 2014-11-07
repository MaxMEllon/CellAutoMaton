//============================================================
// hedder
//============================================================
#include <stdio.h>

//============================================================
// macro
//============================================================
#define RULE_LENGTH 8
#define MAX_CHANGE 100
#define MAX_SIZE 50

//============================================================
// 大域変数
//============================================================
int Rule[RULE_LENGTH];
int Cell[MAX_CHANGE][MAX_SIZE];

//============================================================
// functions
//============================================================
void input_rule();
void input_seed(int cell_width);
void output_tree(int cell_width, int change_num);
void debug_arr(int length, int x[]);

// main
int main(int argc, char const* argv[])
{
  // 変数群
  int change_num;     //状態変化回数
  int cell_width;     //セル幅

  // 変化回数の入力
  printf("input:change_num "); scanf("%d", &change_num);
  // ルール入力
  printf("input:rule "); input_rule();
  // 幅入力
  printf("input:change_num"); scanf("%d", &cell_width);
  // seed入力
  // iprintf("input:change_num"); nput_seed(cell_width);
  // 出力
  // output_tree(cell_width, change_num);

  return 0;
}

void input_rule()
{
  int k;
  for ( k = 0; k < RULE_LENGTH; k++ ) {
    scanf("%1d", &Rule[k]);
  }
  // debug_arr(RULE_LENGTH, Rule);
}

void input_seed(int cell_width)
{
  int k;
  for ( k = 0; k < cell_width; k++ ) {
    scanf("%1d", &Cell[0][k]);
  }
}
void debug_arr(int length, int x[])
{
  int k;
  for ( k = 0; k < RULE_LENGTH; k++ ) {
    printf("%d", x[k]);
  }
  puts("");
}
