; Tests returning a string from a function

(define (someString)
	'here
	'are
	(+ 100 50)
	'numbers
)

(define (main)
	(display (someString))
)
