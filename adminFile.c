#include <stdio.h>
// quiar esta implementacion, esta definida en str.c

/* cargar contenido del archivo */
char *load_content_file(char *pid)
{
    char *path = calloc(14 + len_str(pid) + 1, 1);
    append_str(path, "/proc/");
    append_str(path, pid);
    append_str(path, "/status");

    FILE *fp;
    fp = fopen(path, "r");
    char *buf = calloc(1500, 1);
    if (fp == NULL)
    {
        append_str(buf, "non-exitent process with id: ");
        append_str(buf, pid);

        return buf;
    }
    fread(buf, 1500, 1, fp);

    return buf;
}

char *list_info(int pc, char *pid[])
{
    char *info = calloc(pc * 40, 1);
    char *buf;
    for (int i = 2; i < pc; i++)
    {
        if (atoi(pid[i]) == 0)
        {
            append_str(info, "Process id ");
            append_str(info, pid[i]);
            append_str(info, "not have a correct format \n ----------- \n");
        }
        buf = load_content_file(pid[i]);
        append_str(info, show_description_many_process(buf, pid[i]));
    }
    return info;
}
void write_file(int pc, char *pid[])
{
    char *proc = list_info(pc, pid);
    char *file_name = calloc(pc * 6 + 23, 1);
    append_str(file_name, "./psinfo-report");
    for (int i = 2; i < pc; i++)
    {
        append_str(file_name, "-");
        append_str(file_name, pid[i]);
    }
    append_str(file_name, ".info");
    FILE *fptr;
    fptr = fopen(file_name, "w");

    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    fprintf(fptr, "%s", proc);
    fclose(fptr);
}