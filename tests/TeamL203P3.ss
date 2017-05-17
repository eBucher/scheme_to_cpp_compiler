; Tests LISTP (Rule 27)

(define (main)
	(if (list? 100)
		(display 'yes_it_is)
		(display 'no_it_is_not)
	)
)
