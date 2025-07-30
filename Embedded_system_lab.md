

### **1. Shift and Bitwise AND Operation**

```assembly
	AREA Q1, CODE, READONLY
	ENTRY

	MOV R0, #0xF0        ; Load 0xF0 into R0
	LSL R1, R0, #4       ; Logical left shift R0 by 4 -> R1
	LSR R2, R0, #2       ; Logical right shift R0 by 2 -> R2
	AND R3, R1, R2       ; Bitwise AND of R1 and R2 -> R3

	END
```

---

### **2. Unconditional Branch to Skip Subtraction**

```assembly
	AREA Q2, CODE, READONLY
	ENTRY

	MOV R0, #0x15
	MOV R1, #0xA2
	B SKIP_SUB           ; Unconditional branch to skip subtraction

	SUB R2, R0, R1       ; This will be skipped

SKIP_SUB
	ADD R2, R0, R1       ; ADD operation after branch

	END
```

---

### **3. Subroutine to Add Two**

```assembly
	AREA Q3, CODE, READONLY
	ENTRY

	MOV R0, #10
	BL ADD_TWO           ; Branch with link to subroutine
	MOV R1, R0           ; Store result in R1

	B END_MAIN

ADD_TWO
	ADD R0, R0, #2
	BX LR

END_MAIN
	END
```

---

### **4. Conditional Execution**

```assembly
	AREA Q4, CODE, READONLY
	ENTRY

	MOV R0, #5
	MOV R1, #5
	MOV R2, #20

	CMP R0, R1
	ADDEQ R2, R2, #10
	SUBNE R2, R2, #5

	END
```

---

### **5. Store and Load from Memory**

```assembly
	AREA Q5, CODE, READONLY
	ENTRY

	LDR R9, =0x40000010

	MOV R0, #0x10
	MOV R1, #0x20
	MOV R2, #0x30
	MOV R3, #0x40

	STR R0, [R9]
	STR R1, [R9, #4]
	STR R2, [R9, #8]
	STR R3, [R9, #12]

	LDR R4, [R9]
	LDR R5, [R9, #4]
	LDR R6, [R9, #8]
	LDR R7, [R9, #12]

	END
```

---

### **6. Evaluate Expression: R0 = (A × B) + C**

```assembly
	AREA Q6, CODE, READONLY
	ENTRY

	MOV R1, #5       ; A
	MOV R2, #7       ; B
	MOV R3, #10      ; C

	MUL R4, R1, R2   ; R4 = A * B
	ADD R0, R4, R3   ; R0 = (A * B) + C

	END
```

---

### **7. Evaluate Expression: R0 = (A AND B) OR C**

```assembly
	AREA Q7, CODE, READONLY
	ENTRY

	MOV R1, #0xF0    ; A
	MOV R2, #0xCC    ; B
	MOV R3, #0x0F    ; C

	AND R4, R1, R2   ; A AND B -> R4
	ORR R0, R4, R3   ; (A AND B) OR C -> R0

	END
```

---

### **8. Square Using Repeated Addition**

```assembly
	AREA Q8, CODE, READONLY
	ENTRY

	MOV R0, #5       ; Number to square
	MOV R1, #0       ; Result
	MOV R2, R0       ; Counter

LOOP_SQUARE
	ADD R1, R1, R0   ; Add R0 to result
	SUBS R2, R2, #1
	BNE LOOP_SQUARE

	END
```

---

### **9. Sum of First N Even Numbers Using Loop**

```assembly
	AREA Q9, CODE, READONLY
	ENTRY

	MOV R0, #10      ; N = 10
	MOV R1, #0       ; Result sum
	MOV R2, #0       ; Loop counter

LOOP_EVEN
	ADD R1, R1, R2   ; Add current even number
	ADD R2, R2, #2   ; Next even number
	SUBS R0, R0, #1
	BNE LOOP_EVEN

	END
```
