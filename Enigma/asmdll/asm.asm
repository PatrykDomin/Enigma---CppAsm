;------------------------------------------------------------------------- 
.386 
.MODEL FLAT, STDCALL
OPTION CASEMAP:NONE
INCLUDE C:\masm32\include\windows.inc
.CODE
DllEntry PROC hInstDLL:HINSTANCE, reason:DWORD, reserved1:DWORD
mov eax, TRUE 
ret
DllEntry ENDP
;------------------------------------------------------------------------- 
; To jest przyk³adowa funkcja. Jest tutaj, aby pokazaæ, 
; gdzie nale¿y umieszczaæ w³asne funkcje w bibliotece DLL 
;-------------------------------------------------------------------------
enigmaAsm proc x: DWORD, y: DWORD
mov eax, x
add eax, y
ret
enigmaAsm endp
END DllEntry 
;-------------------------------------------------------------------------