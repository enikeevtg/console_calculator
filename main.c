#include <stdio.h>

#include "console_calc.h"

#define STR_MAX_LEN 1024

int main() {
  char str[STR_MAX_LEN] = {0};
  gets(str);

  int error = OK;
  node_t* q_root = NULL;

  double var_value = 0;
  double result = 0;

  error = convert_infix_to_RPN(str, &q_root);
  if (error == OK) error = expression_solver(q_root, var_value, &result);

  if (error == OK)
    printf("%lf", result);
  else {
    ERRORS_MESSAGES;
    printf("error: %s", errors_msg[error]);
  }
  return 0;
}