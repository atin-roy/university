; 1.	Write an Assembly Language Program to add two sixteen-bit numbers. The numbers are stored in DS: 0030H and DS: 0040H. Store the result in DS: 0050H, DS: 0051H, and DS: 0052H.

.model small
.stack 100h
.data

.code
  main:
       mov ax, @data
       mov ds, ax

  ; Load the first number from DS:0030H into AX
       mov si, 0030H
       mov ax, [si]

  ; Load the second number from DS:0040H into BX
       mov si, 0040h
       mov bx, [si]

  ; Add the two numbers
       add ax, bx

  ; Store the result in DS:0050H and DS:0051H
       mov si, 0050h
       mov [si], ax

  ; Check for carry and store in DS:0052H if present
       adc ah, 0      ; Adds the carry to AH (which is 0)
       mov si, 0052h
       mov [si], ah   ; Store the carry

  ; Terminate program
       mov ah, 4Ch
       int 21h

  end main