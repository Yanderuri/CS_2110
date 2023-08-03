;;=======================================
;; CS 2110 - Spring 2023
;; Final Exam - GCD
;;=======================================
;; Name:
;;=======================================
;; For the LC-3 Assembly part, you must implement the GCD subroutine.
;; We've pre-implemented a helper subroutine MODULUS for you to use.
;; See the PDF for more detailed instructions.

;; GCD
;; Arguments
;;     a - Integer
;;     b - Integer
;; Returns
;;     GCD of a and b - Integer
;; Pseudocode
;; 
;;     gcd(a, b) {
;;         if (b == 0) {
;;             return a;
;;         }
;;         c = modulus(a, b); // MODULUS subroutine has already been provided
;;         return gcd(b, c);
;;     }
;;
;; TODO - Complete the GCD subroutine!
.orig x3010
    GCD
    ADD R6, R6, #-4 ;; Make space for RV, RA, old FP, LV1
    STR R7, R6, #2 ;; Save return address
    STR R5, R6, #1 ;; Save original frame pointer
    ADD R5, R6, #0 ;; New frame pointer for this subroutine

    ADD R6, R6, #-5 ;; SET X TO -4 - NUM LVs OR -5 IF NO LVs
    STR R0, R6, #0
    STR R1, R6, #1
    STR R2, R6, #2
    STR R3, R6, #3
    STR R4, R6, #4
    ;; YOUR CODE HERE

    LDR R0, R5, #4
    LDR R1, R5, #5
    BRz CASE_1
    BR REC_CASE
    CASE_1 LDR R0, R5, #4
    STR R0, R5, #3
    BR GCD_TEARDOWN
    REC_CASE LDR R0, R5, #4
    LDR R1, R5, #5
    ADD R6, R6, #-2
    STR R0, R6, #0
    STR R1, R6, #1
    JSR MODULUS
    LDR R3, R6, #0 ;; R3 = c = mod(a,b);
    ADD R6, R6, #3
    LDR R2, R5, #5 ;; R2 = b
    ADD R6, R6, #-2
    STR R2, R6, #0
    STR R3, R6, #1
    JSR GCD
    LDR R4, R6, #0 ;; R4 = gcd(b,c)
    ADD R6, R6, #3
    STR R4, R5, #3 ;; LV1 = gcd(b,c)
    BR GCD_TEARDOWN

    GCD_TEARDOWN
    LDR R0, R6, #0
    LDR R1, R6, #1
    LDR R2, R6, #2
    LDR R3, R6, #3
    LDR R4, R6, #4
    
    ADD R6, R5, #0
    LDR R5, R6, #1
    LDR R7, R6, #2
    ADD R6, R6, #3

    RET
.end


;; PRE-IMPLEMENTED HELPER SUBROUTINE
;; MODULUS
;; Arguments
;;     a       - Integer
;;     modulus - Nonzero Integer
;; Returns
;;     a % modulus - Integer
;;
;; DO NOT MODIFY THIS SUBROUTINE
.orig x3100
    MODULUS
        ;; These are still LC-3 Assembly instructions! They are just encoded in hex. 
        ;; Treat this subroutine as a black box that you can use to help you code GCD.
        .fill x1DBC
        .fill x7F82
        .fill x7B81
        .fill x1BA0
        .fill x1DBB
        .fill x7180
        .fill x7381
        .fill x7582
        .fill x7783
        .fill x7984
        .fill x6345
        .fill x0602
        .fill x927F
        .fill x1261
        .fill x947F
        .fill x14A1
        .fill x6144
        .fill x0804
        .fill x1002
        .fill x07FE
        .fill x1001
        .fill x0E02
        .fill x1001
        .fill x09FE
        .fill x7143
        .fill x6180
        .fill x6381
        .fill x6582
        .fill x6783
        .fill x6984
        .fill x1D60
        .fill x6B81
        .fill x6F82
        .fill x1DA3
        .fill xC1C0
    RET
.end

;; We've preloaded the PDF's test case for you!
;; After pressing run in Complx, the RESULT label will contain your GCD subroutine's return value on inputs A and B.
;; To test other cases, feel free to change A and B to your liking.
;; You can also use Debug -> Simulate Subroutine Call and select the GCD label as usual. 
.orig x3000
    LD R6, STACK
    ADD R6, R6, #-2
    LD R0, A
    STR R0, R6, #0
    LD R0, B
    STR R0, R6, #1
    JSR GCD
    LDR R0, R6, #0
    ADD R6, R6, #3
    ST R0, RESULT
    HALT
    A .fill 56
    B .fill 36
    RESULT .blkw 1
    STACK .fill xF000
.end
