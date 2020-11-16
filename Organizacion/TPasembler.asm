%include "io.inc"

section .data
    A dw 1,2,3,4,5,6,7,8,9,10 ;Arreglo de numeros
    res dd 0 ;Espacio donde almacenaremos el resultado

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    mov ecx, 10 ;cantidad de elementos del arreglo
    xor ebx , ebx
    xor edx , edx 
  loop_start
    xor eax , eax
    mov ax , [A + ebx]      ;Le asignamos a ax los elementos del arreglo uno a uno
    mov edx , eax           ; Le asignamos a edx el elemento del arreglo
    add ebx, 2 
    shr eax , 1             ;Determinamos si el numero es par o impar
    jc impar 
    add [res] , edx         ;si el elemento es par, lo suma en res
  impar      
    loop loop_start
    PRINT_STRING "La suma de los numeros pares es: "
    PRINT_DEC 2, res
ret