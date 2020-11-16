%include "io.inc"

section.data
    A db 0,1,2,3,4,5
    B dw 0,1,2,3
    C dd 0,1,2,3,4

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    xor eax, eax
    xor ebx, ebx
    mov ecx, 6
  loopA 
    PRINT_DEC 1,[A + ebx]
    inc ebx
    loop loopA
    NEWLINE
    xor ebx, ebx
    mov ecx, 4
  loopB
    PRINT_DEC 1,[B + ebx]
    add ebx, 2
    loop loopB
    NEWLINE
    xor ebx,ebx
    mov ecx, 5
  loopC
    PRINT_DEC 1,[C + ebx]
    add ebx, 4
    loop loopC
    NEWLINE
    xor ebx,ebx
ret
