#ifndef _APP_DIFF_H
#define _APP_DIFF_H

void compare_files(const char *argv[]);
void compare_files_in_directory(const char *path);
void print_comparison(const char *first, const char *second);

#endif /* _APP_DIFF_H */
