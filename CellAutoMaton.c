//============================================================
// hedder
//============================================================
#include <stdio.h>

//============================================================
// macro
//============================================================
#define RULE_LENGTH 8
#define MAX_CHANGE 50
#define MAX_SIZE 100

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
void output_tree(int cell_width, int p);
void debug_arr(int length, int x[]);
void apply_rule(int cell_width, int p);
int value_to_cell(int cell_width, int level, int p);
int get_cell(int cell_width, int level, int p);

// main
int main(int argc, char const* argv[])
{
  // 変数群
  int change_num;     //状態変化回数
  int cell_width;     //セル幅
  int p = 0;          //現在列

  // 変化回数の入力
  printf("input:change_num "); scanf("%d", &change_num);
  // ルール入力
  printf("input:rule "); input_rule();
  // 幅入力
  printf("input:cell_width "); scanf("%d", &cell_width);
  // seed入力
  printf("input:seed "); input_seed(cell_width);
  puts("");
  // 出力
  output_tree(cell_width, p);
  for ( p = 1; p < change_num; p++ ) {
    // ルールの適用
    apply_rule(cell_width, p);
    // 一行出力
    output_tree(cell_width, p);
  }

  return 0;
}

void input_rule()
{
  int k;
  for ( k = 0; k < RULE_LENGTH; k++ ) {
    scanf("%1d", &Rule[k]);
  }
  debug_arr(RULE_LENGTH, Rule);
}

void input_seed(int cell_width)
{
  int k;
  for ( k = 0; k < cell_width; k++ ) {
    scanf("%1d", &Cell[0][k]);
  }
}
void output_tree(int cell_width, int p)
{
  int k;
  printf("%3d : ", p);
  for ( k = 0; k < cell_width; k++ ) {
    switch ( Cell[p][k] ) {
      case 0:
        printf(" ");
        break;
      case 1:
        printf("*");
        break;
    }
    // printf("%d", Cell[p][k]);
  }
  puts("");
}

void apply_rule(int cell_width, int p)
{
  int k;
  for ( k = 0; k < cell_width; k++ ) {
    Cell[p][k] = value_to_cell(cell_width, p-1, k);
  }
}

int value_to_cell(int cell_width, int level, int p)
{

  int left;
  int center;
  int right;
  int rule_value;

  left   = get_cell(cell_width, level, p-1);
  center = get_cell(cell_width, level, p);
  right  = get_cell(cell_width, level, p+1);

  rule_value = left * 4 + center * 2 + right * 1;

  return Rule[rule_value];
}

int get_cell(int cell_width, int level, int p)
{
  // 範囲外判定
  if ( p < 0  ) { p = cell_width-1; }
  if ( p >= 0 ) { p = 0; }

  return Cell[level][p];
}

void debug_arr(int length, int x[])
{
  int k;
  for ( k = 0; k < RULE_LENGTH; k++ ) {
    printf("%d", x[k]);
  }
  puts("");
}
