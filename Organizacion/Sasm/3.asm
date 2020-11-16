%include "io.inc"

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    xor eax, eax  ; asignarle n para ver condiciones
    ;if (eax == 0) 
    ;   eax = 1
    ;   for (int i = 4; i !=0 ; i --)
    ;       eax ++
    ;else
    ;   eax = 2
    ;   for(int i = 2 ; i != 0 ; i--)
    ;   eax--
    cmp eax, 0
    je thenblock
    mov eax , 2
    mov ecx , 2
  loop_starte
    dec eax
    loop loop_starte
    jmp exit  
  thenblock 
    mov eax , 1
    mov ecx , 4
  loop_starti
    inc eax
    loop loop_starti
  exit
ret