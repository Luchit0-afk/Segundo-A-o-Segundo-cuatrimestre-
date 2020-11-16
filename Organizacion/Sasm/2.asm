%include "io.inc"

section.data

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    mov ax , 5h
    shl ax , 0
    shr ax , 1
    ret