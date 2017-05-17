; Testing car in a comparison operator

(define (main)
	(if (< (car '(1 2 3 4)) 2)
		(display '(1 2 3))
		(display '(4 5 6))
	)
)
