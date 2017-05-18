; Tests SYMBOLP (Rule 26)

(define (main)
	(if (symbol? 100)
		(display 'yes_it_is)
		(display 'no_it_is_not)
	)
)
