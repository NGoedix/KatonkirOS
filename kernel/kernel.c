void kprintf(unsigned char* str);

void kprintf(unsigned char *str) {
    char* video = (char*) 0xb8000;

    for (int i = 0; str[i] != '\0'; ++i) {
        video[i * 2] = str[i];
        video[i * 2 + 1] = 0x07;
    }
}


// Kernel entry point
void _start(void) {
    kprintf("Hello world!\n");
}