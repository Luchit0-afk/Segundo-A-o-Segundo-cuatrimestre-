%include "io.inc"

section.data
    n dd 2
    A times 10 dw 1

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    xor eax, eax
    
    ret