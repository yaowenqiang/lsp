#ifndef SERVER_H
#include <netinet/in.h>
#include <sys/types.h>

extern const char* program_name;
extern int verbose;
extern void* xmalloc(size_t size);
extern void* xrealloc(void* ptr, size_t size);
extern char* xstrdup(const char* s);
extern void system_error(const char* operation);
extern void error(const char* cause, const char* message);
extern char* get_self_executable_directory();
struct server_module {
    void* handler;
    const char* name;
}
extern char* module_dir;
extern struct server_module* module_open(const char* module_path);
extern void module_close(struct server_module* module);
extern void server_run(struct in_addr local_address, uint16_t port);
#define SERVER_H
#endif /* SERVER_H */
