#ifndef ERRORS_H
#define ERRORS_H

void print_usage_error(void);
void print_file_open_error(const char *filename);
void print_malloc_error(void);
void print_push_error(unsigned int line_number);
void print_unknown_instruction_error(unsigned int line_number, const char *instruction);

#endif /* ERRORS_H */

