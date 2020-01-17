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
; To jest przyk³adowa funkcja. Jest tutaj, aby pokazaæ, 
; gdzie nale¿y umieszczaæ w³asne funkcje w bibliotece DLL 
;-------------------------------------------------------------------------


getPosition proc arr:DWORD, character: BYTE
	
	mov i, 0
	mov ebx, arr
	mov ecx, 0
Loop1:
	mov eax, r
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
	mov ebx, r1									;ebx - current rotor
	mov edx, [ebx + eax]						;edx - output letter
	invoke getPosition, starting, dl
	mov ebx, r2
	mov edx, [ebx + eax]
	invoke getPosition, starting, dl
	mov ebx, r3
	mov edx, [ebx + eax]

	invoke getPosition, starting, dl
	mov ebx, reflector
	mov edx, [ebx + eax]

	invoke getPosition, r3, dl
	mov ebx, starting									  
	mov edx, [ebx + eax]
	invoke getPosition, r2, dl
	mov ebx, starting
	mov edx, [ebx + eax]
	invoke getPosition, r1, dl
	mov ebx, starting
	mov edx, [ebx + eax]

	mov eax, edx

ret
enigmaAsm endp
END DllEntry 
;-------------------------------------------------------------------------