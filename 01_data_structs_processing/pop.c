/**
 * @author T. Enikeev
 * enikeeev.tg@gmail.com
 */

#include "../console_calc.h"

/// @brief the data at the top of the stack removing and returning
/// @param s_phead pointer to s_head node pointer of data structure
/// @param node pointer to node_t
/// @return error code
int pop(node_t** s_phead, node_t* pnode) {
  if (*s_phead == NULL) return DATA_STRUCT_UNDERFLOW;

  // node->next_node_ptr = (*s_phead)->next_node_ptr;
  fill_node(*s_phead, pnode);
  remove_head_node(s_phead);
  // free(*s_phead);
  // *s_phead = node->next_node_ptr;
  return OK;
}