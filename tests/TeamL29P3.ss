; Tests recursive functions

(define (length lst)
  (if (null? lst)
      0
      (+ 1 (length (cdr lst)))
      )
  )

(define (first_helper lst x length)
  (if (> x length)
      '()
      (cons (car lst) (first_helper (cdr lst) (+ x 1) length))
      )
  )

(define (first_half lst)
  (if (null? lst)
      lst
      (first_helper lst 1 (/ (length lst) 2))
      )
  )

(define (second_helper fhalf lst)
  (if (null? fhalf)
      lst
      (second_helper (cdr fhalf) (cdr lst))
      )
  )

(define (second_half lst)
  (if (null? lst)
      lst
      (second_helper (first_half lst) lst)
      )
  )

(define (main)
  (display (first_half '(41 654 23 765 2 356 98 780 23)))
  (newline)
  (display (second_half '(41 654 23 765 2 356 98 780 23)))
  (newline)
  )
