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

// main
int main(int argc, char const* argv[])
{
  // 変数群
  int change_num;     //状態変化回数
  int cell_width;     //セル幅

  // 変化回数の入力
  scanf("%d", &change_num);
  // ルール入力
  input_rule();
  // 幅入力
  scanf("%d", &cell_width);
  // seed入力
  input_seed(cell_width);
  // 出力
  output_tree(cell_width, change_num);

  return 0;
}
