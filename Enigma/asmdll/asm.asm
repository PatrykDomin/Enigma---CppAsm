;------------------------------------------------------------------------- 
.386 
.MODEL FLAT, STDCALL
OPTION CASEMAP:NONE

INCLUDE C:\masm32\include\windows.inc

.DATA
r DWORD 26
;i DWORD 0


.CODE
DllEntry PROC hInstDLL:HINSTANCE, reason:DWORD, reserved1:DWORD

mov eax, TRUE 
ret
DllEntry ENDP 
;-------------------------------------------------------------------------


getPosition proc arr:DWORD, character: BYTE ;spawdzenie indeksu 'character' w talicy 'arr'
	
	mov ebx, arr	;zapisanie wskaŸnika do arr do rejestru ebx
	mov ecx, 0		;ecx - ustawienie indeksu na '0' (pocz¹tek tablicy)
Loop1:	
	mov eax, r		;zapisanie rozmiaru tablicy do rejestru eax (r - 26)		
	cmp ecx, eax	;sprawdzenie czy nie wyszliœmy poza tablicê
	jge End1		;je¿eli tak - skok do etykiety End1
	mov eax, [ebx + ecx]	;zapisanie elementu tablicy o indeksie ecx do rejesty eax
	mov dl, character		;zapisanie zmiennej 'character' do fragmentu rejestru edx 
	cmp al, dl		;porównanie litery o indeksie ecx z tablicy arr ze zmienn¹ 'character'
	jne NotEqual	;je¿eli nie s¹ równe - skok do etykiety NotEqual
	mov eax, ecx	;zapisanie aktualnego indeksu do rejestru 
	jmp End1		;skok do etykiety End1
NotEqual:
	inc ecx			;inkrementacja indeksu
	jmp Loop1		;skok do etykiety Loop1
End1:
	ret				;powrót

getPosition endp

enigmaAsm proc starting: DWORD, r1: DWORD, r2: DWORD, r3: DWORD, reflector: DWORD, letter: BYTE
	
	;funkcja szyfruj¹ca - jej dzia³anie zosta³o opisane w Schemacie dzia³ania 
	
	invoke getPosition, starting, letter	;wywo³anie funkcji getPosition
	mov edi, r1								;edi - aktuala tablica
	mov eax, [edi + eax]					;eax - tymczasowa litera
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