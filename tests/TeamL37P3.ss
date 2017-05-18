; Tests STRINGP (Rule 31)

(define (main)
	(if (string? 100)
		(display 'yes_it_is)
		(display 'no_it_is_not)
	)
)
