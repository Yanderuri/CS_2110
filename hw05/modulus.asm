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
    ld R0, X ;; int x = 14;
    ld R1, MOD ;; int mod = 3;

    not R1, R1 
    add R1, R1, #1 ;; mod = -mod;

    LOOP
    add R0, R0, R1 ;; x + (-mod)
    brzp LOOP ;; while (x - mod >= 0)

    not R1, R1 ;; once R0 is negative, we stop and add positive R1 back.
    add R1, R1, #1

    add R0, R0, R1
    st R0, ANSWER ;; mem[ANSWER] = x;

    HALT
.end 
.orig x3100
    ;; Feel free to change the below values for debugging. We will vary these values when testing your code.
    X      .fill 14
    MOD    .fill 5    
    ANSWER .blkw 1
.end