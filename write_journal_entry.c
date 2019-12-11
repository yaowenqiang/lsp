#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

const char* journal_filename = "journal.log";

void write_journal_entry(char* entry)
{
    int fd = open(journal_filename, O_RDONLY | O_CREAT | O_APPEND, 06660);

    write(fd, entry, strlen(entry));
    write(fd, '\n', 1);
    fsync(fd);
    close(fd);
}
