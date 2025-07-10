// scanner.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/time.h>      // for struct timeval

// Attempt to connect to a single TCP port and report if it's open
void scan_port(const char *ip, int port) {
    int sockfd;
    struct sockaddr_in target;
    struct timeval tv = { .tv_sec = 1, .tv_usec = 0 };  // 1 second timeout

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return;
    }

    // Set send/receive timeout to avoid long blocking
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv));

    // Prepare target address structure
    target.sin_family = AF_INET;
    target.sin_port   = htons(port);
    if (inet_pton(AF_INET, ip, &target.sin_addr) != 1) {
        // Invalid IP format
        close(sockfd);
        return;
    }

    // Try to connect; if successful, port is open
    if (connect(sockfd, (struct sockaddr *)&target, sizeof(target)) == 0) {
        printf("Port %d is open\n", port);
    }

    // Clean up socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP> <start-end>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int start_port, end_port;

    // Parse port range and validate
    if (sscanf(argv[2], "%d-%d", &start_port, &end_port) != 2 ||
        start_port < 1 || end_port > 65535 || start_port > end_port) {
        fprintf(stderr, "Invalid range. Example: 127.0.0.1 20-25\n");
        return 1;
    }
    
    printf("Scanning ports %d to %d on %s...\n", start_port, end_port, ip);

    // Scan each port in the specified range
    for (int port = start_port; port <= end_port; port++) {
        scan_port(ip, port);
    }

    return 0;
}
