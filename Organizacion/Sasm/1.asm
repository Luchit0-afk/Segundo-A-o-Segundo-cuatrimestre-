section.data
D1 dd 10
D2 dd 34h 

section .text
global CMAIN
CMAIN:
    ;mov ebp, esp; for correct debugging
    
    ;1a)
    inc eax ; incrementa en 1 el valor de eax(1a)
    
    ;1b)
    mov ebx , [D1] ; le asigno a ebx el valor de 18
    
    ;1c)
    add eax ,200 ; le sumo 200 a eax
        
    ;1d)
    mov ebx , D1
    mov ax , [ebx] 
    
    ;1e)
    mov eax , [D2]
    imul eax , [ebx]
    
    ;1f)
    inc ebx
    inc ebx
    inc ebx
    inc ebx
    ;mov ebx , D1
    add eax ,[ebx]
ret