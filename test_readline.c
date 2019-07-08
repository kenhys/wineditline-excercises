#include <editline/readline.h>
#include <locale.h>
#include <stdio.h>

static char history_path[PATH_MAX] = "";

int main(int argc, char *argv[])
{
  char *line;

  setlocale(LC_ALL, "");

  sprintf(history_path, "%s", ".history");
  if (history_path[0]) {
    using_history();
    read_history(history_path);
  }

  while ((line = readline("> "))
    && (strncmp(line, "quit", 4))) {
    fflush(stdout);
    add_history(line);
    free(line);
  }

  if (history_path[0]) {
    write_history(history_path);
  }

  free_history();
  return 0;
}
