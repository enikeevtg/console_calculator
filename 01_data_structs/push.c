/**
 * @author T. Enikeev
 * enikeeev.tg@gmail.com
 */

#include "../console_calc.h"

/// @brief the data adding to stack new node
/// @param address STACK or QUEUE structure
/// @param head head of structure
/// @param data
/// @return error code
int push(int address, node_t** head, node_t* data) {
  int error = OK;
  node_t* new_node_ptr = (node_t*)calloc(1, sizeof(node_t));
  if (new_node_ptr == NULL) {
    error = DATA_STRUCT_OVERFLOW;
  } else {
    if (address == STACK) new_node_ptr->next_node_ptr = *head;
    if (address == QUEUE && *head != NULL)
      (*head)->next_node_ptr = new_node_ptr;
    node_filling(data, new_node_ptr);
    *head = new_node_ptr;
  }
  return error;
}

/// @brief the data adding to stack new node
/// @param stack_head pointer to head node pointer of stack
/// @param data data for new node of stack
/// @return error code
int stack_push(node_t** stack_head, node_t* data) {
  int error = OK;
  node_t* new_node_ptr = (node_t*)calloc(1, sizeof(node_t));
  if (new_node_ptr == NULL) {
    error = STACK_OVERFLOW;
  } else {
    new_node_ptr->next_node_ptr = *stack_head;
    node_filling(new_node_ptr, data);
    *stack_head = new_node_ptr;
  }
  return error;
}

/// @brief the data adding to queue new node
/// @param stack_head pointer to head node pointer of stack
/// @param data data for new node of stack
/// @return error code
int queue_push(node_t** queue_head, node_t* data) {
  int error = OK;
  node_t* new_node_ptr = (node_t*)calloc(1, sizeof(node_t));
  if (new_node_ptr == NULL) {
    error = QUEUE_OVERFLOW;
  } else {
    (*queue_head)->next_node_ptr = new_node_ptr;
    node_filling(new_node_ptr, data);
    *queue_head = new_node_ptr;
  }
  return error;
}