Can everything be computed?

S[P, a] = {true if there is a way to compute everything.}
We can make a giant table.
Let's assume that we can.
We can find a procedure that computes the value fo X.
(define diag1
	(lambda(p)
		(if (safe? p p)
			(inf)
			3)))

Cantor Diag Arguments.

Halting Theorem.
