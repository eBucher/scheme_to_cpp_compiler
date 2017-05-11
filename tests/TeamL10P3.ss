; Tests if statements and else statements

(define (main)
	(if (number? 4)
		(display 'is_a_number)
		(display 'is_not_a_number)
	)
	(newline)
	(if (string? 4)
	  	(display 'is_a_string)
	)
	(newline)
)
