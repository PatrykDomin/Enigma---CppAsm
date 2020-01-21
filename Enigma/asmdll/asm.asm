;------------------------------------------------------------------------- 
.386 
.MODEL FLAT, STDCALL
OPTION CASEMAP:NONE

INCLUDE C:\masm32\include\windows.inc

.DATA
r DWORD 26
i DWORD 0


.CODE
DllEntry PROC hInstDLL:HINSTANCE, reason:DWORD, reserved1:DWORD

mov eax, TRUE 
ret
DllEntry ENDP 
;-------------------------------------------------------------------------


getPosition proc arr:DWORD, character: BYTE
	
	mov i, 0
	mov ebx, arr
	mov ecx, 0
Loop1:
	mov eax, r				;r - size
	cmp i, eax
	jge End1
	mov eax, [ebx + ecx]
	mov dl, character
	cmp al, dl
	jne NotEqual
	mov eax, i
	jmp End1
NotEqual:
	inc ecx
	inc i
	jmp Loop1
End1:
	ret

getPosition endp

enigmaAsm proc starting: DWORD, r1: DWORD, r2: DWORD, r3: DWORD, reflector: DWORD, letter: BYTE

	invoke getPosition, starting, letter
	mov edi, r1									;edi - current rotor
	mov eax, [edi + eax]						;eax - output letter
	invoke getPosition, starting, al
	mov edi, r2
	mov eax, [edi + eax]
	invoke getPosition, starting, al
	mov edi, r3
	mov eax, [edi + eax]

	invoke getPosition, starting, al
	mov edi, reflector
	mov eax, [edi + eax]

	invoke getPosition, r3, al
	mov edi, starting									  
	mov eax, [edi + eax]
	invoke getPosition, r2, al
	mov eax, [edi + eax]
	invoke getPosition, r1, al
	mov eax, [edi + eax]

	ret

enigmaAsm endp

END DllEntry 
;-------------------------------------------------------------------------