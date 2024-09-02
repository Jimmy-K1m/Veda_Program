// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <fcntl.h>
// #include <unistd.h>

// int main()
// {
//     int fd;

    

//     while(1)
//     {
//         fd = open("mypipe", O_WRONLY);
//         if(fd == -1)
//         {
//             perror("open");
//             exit(1);
//         }
//         char buf[] = "";
//         for(int i = 0;;i++){
//             scanf("%c", &buf[i]);
//             if(buf[i] == '\n')
//             {
//                 buf[i] = '\0';
//                 printf("%s", buf);
//                 break;
//             }
//         }
//         write(fd,buf, strlen(buf));
//         printf("%s", buf);
//         if(!strcmp(buf,"end"))
//         {
//             break;
//         }
//         close(fd);
//     }
    

// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 256

int main() {
    int fd;
    char buf[BUFFER_SIZE];

    while (1) {
        // Open the pipe for writing
        fd = open("mypipe", O_WRONLY);
        if (fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        // Read user input into the buffer
        printf("Enter message (or 'end' to quit): ");
        if (fgets(buf, BUFFER_SIZE, stdin) == NULL) {
            perror("fgets");
            close(fd);
            exit(EXIT_FAILURE);
        }

        // Remove trailing newline character from fgets
        size_t len = strlen(buf);
        if (len > 0 && buf[len - 1] == '\n') {
            buf[len - 1] = '\0';
        }

        // Write to the pipe
        if (write(fd, buf, strlen(buf)) == -1) {
            perror("write");
            close(fd);
            exit(EXIT_FAILURE);
        }

        // Print the message to standard output
        printf("Message sent: %s\n", buf);

        // Close the file descriptor
        close(fd);

        // Break if the message is "end"
        if (strcmp(buf, "end") == 0) {
            break;
        }
    }

    return 0;
}
