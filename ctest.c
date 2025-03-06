#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void buffer_overflow() {
    char buffer[10];
    printf("Enter your input: ");
    gets(buffer); // 위험: 버퍼 오버플로우 발생 가능
    printf("You entered: %s\n", buffer);
}

void format_string_vuln() {
    char user_input[100];
    printf("Enter a message: ");
    scanf("%s", user_input);
    printf(user_input); // 위험: 포맷 문자열 취약점
}

void insecure_file_handling() {
    char filename[256];
    FILE *file;
    
    printf("Enter file name: ");
    scanf("%255s", filename);

    file = fopen(filename, "r"); // 파일 존재 여부 확인 없이 열기
    if (!file) {
        printf("Error opening file!\n");
        return;
    }
    
    char content[1024];
    fread(content, 1, sizeof(content), file);
    printf("File content: %s\n", content);
    
    fclose(file);
}

int main() {
    buffer_overflow();
    format_string_vuln();
    insecure_file_handling();
    return 0;
}
