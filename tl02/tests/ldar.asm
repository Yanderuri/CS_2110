.orig x0000
LD R0, NUM1
LD R1, NUM2
LDAR R2, R0, R1
HALT

NUM1 .fill x5F53
NUM2 .fill xE0AD
.end

.orig x4000
RESULT .fill 21
.end

; Post conditions
; R0 = x5F53, R1 = xE0AD, R2 = 21