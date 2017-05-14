; call a function within a function
(define (domath a b)
  (display (+ a b))
  (newline)
)

(define (main)
    (domath 0 -8)
)
