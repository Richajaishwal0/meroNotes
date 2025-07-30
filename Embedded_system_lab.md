

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

### **10. Clear bits 1, 3, and 5 using AND/BIC**

```asm
    AREA ClearBits, CODE, READONLY
    ENTRY
    MOV     R0, #0xFFFFFFFF       ; Example 32-bit value
    MOV     R1, #(1<<1)|(1<<3)|(1<<5) ; Bit mask for bits 1, 3, and 5
    BIC     R0, R0, R1            ; Clear those bits
    END
```

---

### **11. Toggle bits 1, 3, and 5 using EOR**

```asm
    AREA ToggleBits, CODE, READONLY
    ENTRY
    MOV     R0, #0x00000000       ; Example input
    MOV     R1, #(1<<1)|(1<<3)|(1<<5) ; Mask for bits 1, 3, and 5
    EOR     R0, R0, R1            ; Toggle those bits
    END
```

---

### **12. Temperature Monitoring**

```asm
    AREA TempMonitor, CODE, READONLY
    ENTRY
    MOV     R0, #45               ; Example temperature

    CMP     R0, #40
    BGT     overheat
    CMP     R0, #10
    BLT     toocold
    MOV     R1, #0                ; Normal
    B       done

overheat
    MOV     R1, #1
    B       done

toocold
    MOV     R1, #-1

done
    END
```

---

### **13. Voltage Monitoring**

```asm
    AREA VoltageMonitor, CODE, READONLY
    ENTRY
    MOV     R0, #210              ; Example voltage

    CMP     R0, #230
    BGT     high

    CMP     R0, #180
    BLT     low

    MOV     R1, #0                ; Voltage Normal
    B       done

high
    MOV     R1, #1
    B       done

low
    MOV     R1, #-1

done
    END
```

---

### **14. Shifts and OR**

```asm
    AREA ShiftOR, CODE, READONLY
    ENTRY
    LDR     R0, =0x0000003C       ; Load value
    LSL     R1, R0, #2            ; Logical left shift by 2
    LSR     R2, R0, #1            ; Logical right shift by 1
    ORR     R3, R1, R2            ; R3 = R1 | R2
    END
```

---

### **15. Rotate and XOR**

```asm
    AREA RotateXOR, CODE, READONLY
    ENTRY
    LDR     R0, =0x000000AD
    ROR     R1, R0, #28           ; Rotate left by 4 = rotate right by (32-4)=28
    EOR     R2, R0, R1            ; XOR original with rotated
    END
```

---

### **16. AND and EOR**

```asm
    AREA BitwiseOps, CODE, READONLY
    ENTRY
    LDR     R0, =0x000000AA
    LDR     R1, =0x00000055
    AND     R2, R0, R1
    EOR     R3, R2, R0
    END
```

---

### **17. Speed Monitoring**

```asm
    AREA SpeedMonitor, CODE, READONLY
    ENTRY
    MOV     R0, #105              ; Example speed

    CMP     R0, #100
    BGT     overspeed
    CMP     R0, #40
    BLT     tooslow
    MOV     R1, #0                ; Normal Speed
    B       done

overspeed
    MOV     R1, #1
    B       done

tooslow
    MOV     R1, #-1

done
    END
```

---

### **18. Store and Load Memory**

```asm
    AREA StoreLoad, CODE, READONLY
    ENTRY
    LDR     R4, =0x40000020       ; Starting address

    MOV     R0, #0x55
    MOV     R1, #0x66
    MOV     R2, #0x77
    MOV     R3, #0x88

    STR     R0, [R4], #4
    STR     R1, [R4], #4
    STR     R2, [R4], #4
    STR     R3, [R4], #4

    ; Load back
    LDR     R4, =0x40000020
    LDR     R5, [R4], #4
    LDR     R6, [R4], #4
    LDR     R7, [R4], #4
    LDR     R8, [R4], #4
    END
```


### **19. Store 0xAA, 0xBB, 0xCC, 0xDD to memory and load back**

```asm
    AREA StoreLoad, CODE, READONLY
    ENTRY
    MOV     R0, #0xAA
    MOV     R1, #0xBB
    MOV     R2, #0xCC
    MOV     R3, #0xDD

    LDR     R4, =0x40000080
    STR     R0, [R4], #4
    STR     R1, [R4], #4
    STR     R2, [R4], #4
    STR     R3, [R4], #4

    LDR     R4, =0x40000080
    LDR     R5, [R4], #4
    LDR     R6, [R4], #4
    LDR     R7, [R4], #4
    LDR     R8, [R4], #4
    END
```

---

### **20. Multiply 0x5A by 3 using addition, then subtract 10**

```asm
    AREA MultiplySubtract, CODE, READONLY
    ENTRY
    MOV     R0, #0x5A
    MOV     R1, R0
    ADD     R1, R1, R0       ; R1 = R0 * 2
    ADD     R1, R1, R0       ; R1 = R0 * 3
    SUB     R2, R1, #10
    END
```

---

### **21. Shift multiply and divide**

```asm
    AREA ShiftOps, CODE, READONLY
    ENTRY
    MOV     R0, #0x10
    MOV     R1, #0x08
    LSL     R2, R0, #2        ; R2 = R0 * 4
    LSR     R3, R1, #1        ; R3 = R1 / 2
    ADD     R4, R2, R3
    END
```

---

### **22. EOR, shift, subtract**

```asm
    AREA EORShiftSub, CODE, READONLY
    ENTRY
    MOV     R0, #0x55
    EOR     R1, R0, #0xAA
    LSR     R2, R1, #1
    SUB     R3, R0, R2
    END
```

---

### **23. Rotate and subtract**

```asm
    AREA RotateSub, CODE, READONLY
    ENTRY
    LDR     R0, =0xA5A5A5A5
    ROR     R1, R0, #8
    SUB     R2, R1, #0x10
    END
```

---

### **24. ((X + Y) XOR Z)**

```asm
    AREA ComputeExpr, CODE, READONLY
    ENTRY
    MOV     R0, #10
    MOV     R1, #5
    MOV     R2, #7
    ADD     R3, R0, R1
    EOR     R3, R3, R2
    END
```

---

### **25. Age eligibility check (if age ≥ 18)**

```asm
    AREA AgeCheck, CODE, READONLY
    ENTRY
    MOV     R0, #20
    CMP     R0, #18
    MOVGE   R1, #1
    MOVLT   R1, #0
    END
```

---

### **26. Sensor vs threshold**

```asm
    AREA SensorCheck, CODE, READONLY
    ENTRY
    MOV     R0, #50           ; Sensor value
    MOV     R1, #60           ; Threshold
    CMP     R0, R1
    MOVEQ   R2, #0x00         ; Optional for equal case
    MOVLT   R2, #0x00         ; Safe
    MOVGT   R2, #0xFF         ; Alert
    END
```

---

### **27. ((M \* N) XOR K), where M=3, N=6, K=5**

```asm
    AREA MultiplyXOR, CODE, READONLY
    ENTRY
    MOV     R0, #3
    MOV     R1, #6
    MOV     R2, #5
    MUL     R3, R0, R1        ; R3 = M * N
    EOR     R3, R3, R2
    END
```

---

### **28. Even check (R0 even => R1=1, else R1=0)**

```asm
    AREA EvenCheck, CODE, READONLY
    ENTRY
    MOV     R0, #6
    AND     R2, R0, #1
    CMP     R2, #0
    MOVEQ   R1, #1
    MOVNE   R1, #0
    END
```

---

### **29. Speed Comparison (R0: speed)**

```asm
    AREA SpeedCheck, CODE, READONLY
    ENTRY
    MOV     R0, #75

    CMP     R0, #100
    BGT     overspeed

    CMP     R0, #60
    BGE     normal

    MOV     R1, #0xFF         ; Too slow
    B       done

normal
    MOV     R1, #0x00         ; Normal
    B       done

overspeed
    MOV     R1, #0x01         ; Over Speed

done
    END
```

### **30. Call CHECK\_PASS subroutine to check if R0 ≥ 50**

```asm
    AREA CheckPass, CODE, READONLY
    ENTRY
    MOV     R0, #60            ; Input value
    BL      CHECK_PASS         ; Call subroutine
    B       STOP

CHECK_PASS
    CMP     R0, #50
    MOVGE   R1, #1
    MOVLT   R1, #0
    BX      LR

STOP
    B       STOP
    END
```

---

### **31. Call SUM subroutine to add R0 and R1, return result in R2**

```asm
    AREA AddSubroutine, CODE, READONLY
    ENTRY
    MOV     R0, #5
    MOV     R1, #7
    BL      SUM
    MOV     R2, R0             ; Store result in R2
    B       STOP

SUM
    ADD     R0, R0, R1         ; R0 = R0 + R1
    BX      LR

STOP
    B       STOP
    END
```

---

### **32. Multiply R0 by 2 in subroutine, return in R0, store in R1**

```asm
    AREA Multiply2, CODE, READONLY
    ENTRY
    MOV     R0, #6
    BL      DOUBLE
    MOV     R1, R0             ; Store result in R1
    B       STOP

DOUBLE
    LSL     R0, R0, #1         ; Multiply by 2
    BX      LR

STOP
    B       STOP
    END
```

---

### **33. Shift left by 3, right by 2, then XOR results**

```asm
    AREA BitwiseShiftXOR, CODE, READONLY
    ENTRY
    LDR     R0, =0x000000A5
    LSL     R1, R0, #3
    LSR     R2, R0, #2
    EOR     R3, R1, R2
    END
```

---

### **34. Shift 0x0F left by 1 to R1, right by 3 to R2, then OR**

```asm
    AREA ShiftOR, CODE, READONLY
    ENTRY
    MOV     R0, #0x0F
    LSL     R1, R0, #1
    LSR     R2, R0, #3
    ORR     R3, R1, R2
    END
```

---

### **35. Compute ((A - B) AND C), A=25, B=10, C=12**

```asm
    AREA LogicExpr, CODE, READONLY
    ENTRY
    MOV     R0, #25            ; A
    MOV     R1, #10            ; B
    MOV     R2, #12            ; C
    SUB     R4, R0, R1         ; A - B
    AND     R3, R4, R2         ; (A - B) AND C
    END
```



