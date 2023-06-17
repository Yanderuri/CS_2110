;;=============================================================
;; CS 2110 - Summer 2023
;; Homework 5 - modulus
;;=============================================================
;; Name: Vy Mai
;;=============================================================

;;  Pseudocode (see PDF for explanation)
;;  Pseudocode values are based on the labels' default values.
;;
;;  int x = 14;
;;  int mod = 3;
;;  while (x >= mod) { => while (x-mod >= 0)
;;      x -= mod;
;;  }
;;  mem[ANSWER] = x;

.orig x3000
    ;; YOUR CODE HERE

    AND R0, R0, #0
    LD R0, X ;; int x = 14;

    AND R1, R1, #0
    LD R1, MOD ;; int mod = 3;

    NOT R1, R1 
    ADD R1, R1, #1 ;; mod = -mod;

    LOOP
    ADD R0, R0, R1 ;; x + (-mod)
    BRzp LOOP ;; while (x - mod >= 0)

    NOT R1, R1 ;; once R0 is negative, we stop and add positive R1 back.
    ADD R1, R1, #1

    ADD R0, R0, R1
    ST R0, ANSWER ;; mem[ANSWER] = x;

    HALT
.end 
.orig x3100
    ;; Feel free to change the below values for debugging. We will vary these values when testing your code.
    X      .fill 14
    MOD    .fill 5    
    ANSWER .blkw 1
.end