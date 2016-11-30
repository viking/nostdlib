#define internal static

void* syscall3(
    uintptr number,
    void* arg1,
    void* arg2,
    void* arg3
);

/* ------------------------------------------------------------- */

#define stdout 1

internal
intptr write(int fd, void const* data, uintptr nbytes)
{
    return (uintptr)
        syscall3(
            SYS_write,
            (void*)(intptr)fd,
            (void*)data,
            (void*)nbytes
        );
}

/* ------------------------------------------------------------- */

internal
uintptr strlen(char const* str)
{
    char const* p;
    for (p = str; *p; ++p);
    return p - str;
}

internal
uintptr puts(char const* str) {
    return write(stdout, str, strlen(str));
}

/* ------------------------------------------------------------- */

internal
int hello_run(int argc, char const* argv[])
{
    puts("hello\n");

    return 0;
}
