; Testing car in a comparison operator

(define (main)
	(if (< (car '(1 2 3 4)) 2)
		'(1 2 3)
		'(4 5 6)
	)
)
